#include <monitor.h>
#include <queue>
template <typename T>
class ThreadSafeQueueMonitor{    
    private:
        std::queue<T> data;
        Monitor monitor;
    public:
        void push(T val){
            monitor.lock();
            data.push(val);
            monitor.unlock();
            monitor.notify_one();
        }

        T wait_and_pop() {
            while(data.empty()) monitor.wait();
            monitor.lock();
            T val = data.front();
            data.pop();
            monitor.unlock();
            return val;
        }

        void wait_and_pop(T& val){
            while(data.empty()) monitor.wait();
            monitor.lock();
            val = data.front();
            data.pop();
            monitor.unlock();
        } 

        bool try_pop(T& val){
            monitor.lock();
            if(data.empty())
                return false;
            val = data.front();
            data.pop();
            monitor.unlock();
            return true;
        } 
  
        bool empty() {
            monitor.lock();
            bool empty = data.empty();
            monitor.unlock();
            return empty;
        }
};