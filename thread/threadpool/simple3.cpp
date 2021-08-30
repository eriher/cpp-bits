
#include <iostream>
#include <utils.h>
#include <functional>
#include <thread>
#include <chrono>
using namespace std;
using namespace std::chrono;

class ThreadPool {
    atomic_bool done;
    ThreadSafeQueueMonitor<std::function<void()>> work_queue;
    vector<thread> threads;
    void worker_thread()
    {
        while(!done){
            function<void()> task = work_queue.wait_and_pop();
            task();
        }
    }

    public:
        ThreadPool():done(false){
            auto const thread_count = thread::hardware_concurrency();
            try{
                for(auto i = 0; i < thread_count;i++){
                    threads.push_back(thread(&ThreadPool::worker_thread,this));
                }
            }
            catch(...){
                done=true;
                throw;
            }
        }
        ~ThreadPool(){
            for(auto& thread:threads) 
            { 
                if(thread.joinable()) 
                    thread.join(); 
            } 
            done=true;
        }

        template<typename FunctionType>
        void submit(FunctionType f)
        {
            work_queue.push(std::function<void()>(f));
        }
        
        template<typename FuncType, typename... A>
        void submit(FuncType f, A &...args)
        {
            submit( [f, args...] { f(args...); });
        }
};

void print_int(int p)
{
    cout << p << endl;
}

int main() {
    auto start = high_resolution_clock::now();
    {
        ThreadPool tp;
        for(auto i = 0; i < 100; i++){tp.submit(print_int, i);};
        while(true);
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << "Time taken by function: "
         << duration.count() << " milliseconds" << endl;
    return 0;
}