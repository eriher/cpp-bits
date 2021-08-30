#include <monitor.h>

void const Monitor::lock(){
    mutex.lock();
}
void const Monitor::unlock(){
    mutex.unlock();
}
void const Monitor::notify_one() {
    condVar.notify_one();
}
void const Monitor::wait(){            
    std::unique_lock<std::mutex> monitorLock(mutex);
    condVar.wait(monitorLock);
}