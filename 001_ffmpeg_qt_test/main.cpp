#include <iostream>

// 包含ffmpeg头文件
extern "C"{
#include <libavutil/avutil.h>
}

using namespace std;


int main()
{
    printf("Hello ffmpeg, version is %s\n", av_version_info());
    return 0;
}
