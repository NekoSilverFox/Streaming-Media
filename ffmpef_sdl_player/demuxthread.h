#ifndef DEMUXTHREAD_H
#define DEMUXTHREAD_H

#include "thread.h"

class DemuxThread : public Thread
{
public:
    DemuxThread();

    int start();
    int stop();
    void run();

};

#endif // DEMUXTHREAD_H
