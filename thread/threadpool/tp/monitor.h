#pragma once
#include <condition_variable>
#include <mutex>

class Monitor {
    mutable std::mutex mutex;
    mutable std::condition_variable_any condVar;

    public:
        void const lock();
        void const unlock();
        void const notify_one();
        void const wait();
};