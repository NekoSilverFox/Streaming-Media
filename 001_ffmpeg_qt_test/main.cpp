#include <iostream>

// 包含ffmpeg头文件，MacOS 下测试必须加 extern "C" 不然报错
#ifdef __cplusplus
extern "C"{
#include <libavutil/avutil.h>
}
#endif

using namespace std;


int main()
{
    printf("Hello ffmpeg, version is %s\n", av_version_info());
    return 0;
}
