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


    return 0;
}
