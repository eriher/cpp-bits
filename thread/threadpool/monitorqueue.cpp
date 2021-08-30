#include <monitor.h>
template <typename T>
class ThreadSafeQueueMonitor: public Monitor{    
    private:
        queue<T> data;
    public:
        void push(T val){
            lock();
            data.push(val);
            unlock();
            notify_one();
        }

        T wait_and_pop() {
            while(data.empty()) wait();
            lock();
            T val = data.front();
            data.pop();
            unlock();
            return val;
        }

        void wait_and_pop(T& val){
            while(data.empty()) wait();
            lock();
            val = data.front();
            data.pop();
            unlock();
        }        
  
        bool empty() {
            lock();
            bool empty = data.empty();
            unlock();
            return empty;
        }
};