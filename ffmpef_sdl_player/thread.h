#ifndef THREAD_H
#define THREAD_H

#include <thread>

class Thread
{
public:
    Thread();
    ~Thread();

    int start();
    int stop();
    virtual void run() = 0;  // = 0： 表示这是一个纯虚函数，没有默认的实现。任何包含纯虚函数的类都是抽象类，不能被实例化。派生类必须提供一个实际的实现来使该类变为可实例化的具体类。

protected:
    int abort_ = 0;
    std::thread* thread_ = nullptr;

};

#endif // THREAD_H
