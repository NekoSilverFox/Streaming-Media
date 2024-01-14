#include "log.h"
#include "demuxthread.h"

#include <iostream>

#ifdef __cplusplus
    extern "C"{
        #include <libavutil/avutil.h>
    }
#endif

using namespace std;




int main(int argc, char* argv[])
{
    printf("Hello ffmpeg, version is %s\n", av_version_info());

    int ret = 0;

    // 初始化 log
    LogInit();

    // 1. 解复用
    DemuxThread demux_thread;
    ret = demux_thread.init(argv[1]);
    if (ret != 0)
    {
        LogError("demux_thread.init() failed");
        return -1;
    }

    ret = demux_thread.start();
    if (ret != 0)
    {
        LogError("demux_thread.start() failed");
        return -1;
    }

    // 休眠两秒
    std::this_thread::sleep_for(std::chrono::microseconds(2000));
    demux_thread.stop();


    return 0;
}
