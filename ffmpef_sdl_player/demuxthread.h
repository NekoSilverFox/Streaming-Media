#ifndef DEMUXTHREAD_H
#define DEMUXTHREAD_H

#include "thread.h"

#ifdef __cplusplus
extern "C"{
    #include <libavutil/avutil.h>
    #include <libavformat/avformat.h>
}
#endif


/**
 * @brief 解复用器
 */

class DemuxThread : public Thread
{
public:
    DemuxThread();
    ~DemuxThread();
    int init(const char* url);  // 初始化不写在构造函数中是为了方便
    int start();
    int stop();
    void run();

private:
    char err_buffer_[1024] = {0};  // 错误缓冲区
    std::string url_;  // 文件名

    int i_audio_ = -1;  // 音/视频流包的编号，-1 说明没找到
    int i_video_ = -1;

//    AVPacketQueue* audio_queue = null;
//    AVPacketQueue* video_queue = null;
    AVFormatContext* ifmt_ctx_ = nullptr;  // FFmpeg库中的一个结构体，表示音视频格式的上下文信息。包含和管理音视频文件的相关信息，如容器格式、流信息、时间基、元数据等
};

#endif // DEMUXTHREAD_H
