#include <condition_variable>
#include <mutex>
class Monitor {
    mutable mutex mut;
    mutable condition_variable_any cond;

    public:
        void const lock();
        void const unlock();
        void const noexcept notify_one();
        void const wait();
};