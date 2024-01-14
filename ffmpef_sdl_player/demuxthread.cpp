#include "demuxthread.h"
#include "log.h"

DemuxThread::DemuxThread()
{
    LogInfo("DemuxThread");
}

DemuxThread::~DemuxThread()
{
    LogInfo("~DemuxThread");
    if (thread_ != nullptr)
    {
        stop();
    }
}

int DemuxThread::init(const char* url)
{
    LogInfo("url: %s", url);
    int ret = 0;

    // ============= 1. 分配上下文信息 =============
    url_ = url;
    ifmt_ctx_ = avformat_alloc_context();

    // ============= 2. 打开文件，正常返回 0 =============
    ret = avformat_open_input(&ifmt_ctx_, url_.c_str(), NULL, NULL);
    if (ret != 0)
    {
        av_strerror(ret, err_buffer_, sizeof(err_buffer_));
        LogError("avformat_open_input failed, ret: %d, err_buffer_: %s", ret, err_buffer_);
        return -1;
    }

    // ============= 3. 获取文件信息 =============
    ret = avformat_find_stream_info(ifmt_ctx_, NULL);
    if (ret != 0)
    {
        av_strerror(ret, err_buffer_, sizeof(err_buffer_));
        LogError("avformat_find_stream_info failed, ret: %d, err_buffer_: %s", ret, err_buffer_);
        return -1;
    }
    // 打印上下文（流）中的信息
    av_dump_format(ifmt_ctx_, 0, url_.c_str(), 0);

    // ============= 4. 获取音频包和视频包的编号（用于识别在 AVPacket 中这个包是音频还是视频）=============
    i_audio_ = av_find_best_stream(ifmt_ctx_, AVMEDIA_TYPE_AUDIO, -1, -1, NULL, 0);
    i_video_ = av_find_best_stream(ifmt_ctx_, AVMEDIA_TYPE_VIDEO, -1, -1, NULL, 0);
    // 这里假设视频中必须有音视频流
    if (i_audio_ == -1 || i_video_ == -1)
    {
        LogError("This video do not have audio or video");
        return -1;
    }

    LogInfo("DemuxThread::init done");
    return 0;
}

int DemuxThread::start()
{
    thread_ = new std::thread(&DemuxThread::run, this);  // 线程对象被构造时，会调用 DemuxThread 类的 run 方法，并将当前对象的指针（this）作为参数传递给 run 方法。这种用法通常用于将对象的成员函数作为线程函数。
    if (thread_ == nullptr)
    {
        LogError("new std::thread(&DemuxThread::run, this) failed");
        return -1;
    }

    return 0;
}

int DemuxThread::stop()
{
    Thread::stop();
    avformat_close_input(&ifmt_ctx_); // 释放资源
}

/**
 * @brief 读取视频包
 */
void DemuxThread::run()
{
    LogInfo("Run info:");
    int ret = 0;
    AVPacket pkt;

    while (abort_ != 1)
    {
        ret = av_read_frame(ifmt_ctx_, &pkt);
        if (ret != 0)
        {
            av_strerror(ret, err_buffer_, sizeof(err_buffer_));
            LogError("av_read_frame failed, ret: %d, err_buffer_: %s", ret, err_buffer_);
            break;
        }

        if (pkt.stream_index == i_audio_) LogInfo("Audio pkt");
        else if (pkt.stream_index == i_video_) LogInfo("Video pkt");
        else LogError("Unknow pkt");

        av_packet_unref(&pkt);  // 释放包
    }
    LogInfo("Run finish");
}
