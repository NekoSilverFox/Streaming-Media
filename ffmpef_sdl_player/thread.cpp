#include "thread.h"


Thread::Thread()
{

}

Thread::~Thread()
{
    if (thread_) Thread::stop();
}

int Thread::stop()
{
    abort_ = 1;
    if (thread_)
    {
        thread_->join();  // 阻塞当前线程，直至当前完成
        delete thread_;
        thread_ = nullptr;
    }
}
