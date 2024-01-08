#include "log.h"
#include <iostream>

#ifdef __cplusplus
    extern "C"{
        #include <libavutil/avutil.h>
    }
#endif

using namespace std;




int main()
{
    printf("Hello ffmpeg, version is %s\n", av_version_info());

    // 初始化 log
    LogInit();

    // 1. 解复用

    return 0;
}
