#include <monitor.h>

void const Monitor::lock(){
    mut.lock();
}
void const Monitor::unlock(){
    mut.unlock();
}
void const Monitor::notify_one() noexcept {
    cond.notify_one();
}
void const Monitor::wait(){            
    unique_lock<mutex> monitorLock(mut);
    cond.wait(monitorLock);
}