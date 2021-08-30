#include <mutex>
#include <queue>
#include <atomic>
#include <condition_variable>
#include <thread>
#include <mutex>

using namespace std;
using lk_guard  = lock_guard<mutex>;
using unique_lk = unique_lock<mutex>;

class join_threads 
{ 
 vector<thread>& threads; 
public: 
 explicit join_threads(vector<thread>& threads_): threads(threads_) {} 
 
    ~join_threads() 
    { 
        for(unsigned long i=0;i<threads.size();++i) 
        { 
            if(threads[i].joinable()) 
                threads[i].join(); 
        } 
    } 
};

template <typename T>
class threadSafeQueue{
    private:
        mutable mutex mut;
        queue<T> data;
        condition_variable cond;
    public:
        thread_safe_queue(){}
        thread_safe_queue(thread_safe_queue const& other){
            scoped_lock lk(other.mut);
            data = other.data;
        }
        void push(T val){
            scoped_lock lk(mut);
            data.push(val);
            cond.notify_one();
        }
        void wait_and_pop(T& val){
            unique_lk lk(mut);
            cond.wait(lk,[&]{return !data.empty();});
            val = data.front();
            data.pop();
        }
        T wait_and_pop(){
            unique_lk lk(mut);
            cond.wait(lk,[&]{return !data.empty();});
            T res = data.front();
            data.pop();
            return res;
        }
        bool try_pop(T& val){
            lk_guard lk(mut);
            if(data.empty())
                return false;
            val=data.front();
            data.pop();
            return true;
        }
        T try_pop(){
            lk_guard lk(mut);
            if(data.empty())
                return shared_ptr<T>();
            T res data.front();
            data.pop();
            return res;
        }
        bool empty() const {
            lk_guard lk(mut);
            return data.empty();
        }
};

//template <typename T>
class Monitor {
    mutable mutex mut;
    mutable condition_variable_any cond;

    public:
        void const lock(){
            mut.lock();
        }
        void const unlock(){
            mut.unlock();
        }
        void const notify_one() noexcept {
            cond.notify_one();
        }
        void const wait(){            
            unique_lock<mutex> monitorLock(mut);
            cond.wait(monitorLock);
        }

};

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