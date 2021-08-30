#include <queue>
#include <condition_variable>
#include <mutex>
#include <iostream>
template <typename T>
class ThreadSafeQueue{
    private:
        mutable std::mutex mut;
        std::queue<T> data;
        std::condition_variable cond;
    public:
        ThreadSafeQueue(){}
        ThreadSafeQueue(ThreadSafeQueue const& other){
            std::scoped_lock lk(other.mut);
            data = other.data;
        }
        void push(T val){
            std::scoped_lock lk(mut);
            data.push(val);
            cond.notify_one();
        }
        void wait_and_pop(T& val){
            std::unique_lock lk(mut);
            cond.wait(lk,[&]{return !data.empty();});
            val = data.front();
            data.pop();
        }
        T wait_and_pop(){
            std::unique_lock lk(mut);
            cond.wait(lk,[&]{return !data.empty();});
            T res = data.front();
            data.pop();
            return res;
        }
        bool try_pop(T& val){
            std::scoped_lock lk(mut);
            if(data.empty())
                return false;
            val=data.front();
            data.pop();
            return true;
        }
        bool empty() const {
            std::scoped_lock lk(mut);
            return data.empty();
        }
};