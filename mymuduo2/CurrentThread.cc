#include "CurrentThread.h"

namespace CurrentThread
{
    // __thread表示每个线程都有一份自己的拷贝
    __thread int t_cachedTid = 0;  

    void cacheTid()
    {
        if (t_cachedTid == 0)
        {
            // 通过linux系统调用，获取当前线程的tid值
            t_cachedTid = static_cast<pid_t>(::syscall(SYS_gettid));
        }
    }
}