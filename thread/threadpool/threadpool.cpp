
#include <iostream>
#include <utils.h>
#include <functional>
#include <thread>
#include <chrono>
#include <future>
#include<vector>
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

        template<typename FuncType>
        void submit(FuncType f)
        {
            work_queue.push(function<void()>(f));
        }
        
        template<typename FuncType, typename... A>
        void submit(FuncType f, A &...args)
        {
            //create lambda with provided function and arguments and submit
            submit( [f, args...](){ f(args...); });
        }
        template <typename FuncType, typename... A, typename RetType = invoke_result_t<FuncType, A...>>
        future<RetType> submitTask(FuncType f, A &...args){
            auto prom = make_shared< promise<RetType> >();
            auto fut = prom->get_future();
            submit([f,args...,prom]() {prom->set_value(f(args...));});
            return fut;
        }




};

void print_int(int p)
{
    cout << p << endl;
}

int main() {
    vector<int> values(100000);
    generate(values.begin(), values.end(), []() -> int { return rand() % 10000; });

    auto start = high_resolution_clock::now();

    // {
    //     ThreadPool tp;
    //     for(auto i = 0; i < 100; i++){tp.submit(print_int, i);};
    //     future<int> fut = tp.submitTask([]{return 8;});
    //     fut.wait();
    //     cout << fut.get() << endl;
    // }
    
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << "Time taken by function: "
         << duration.count() << " milliseconds" << endl;
    return 0;
}