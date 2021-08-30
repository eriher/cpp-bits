
#include <iostream>
#include <utils.h>
#include <functional>
#include <thread>
#include <chrono>
using namespace std;
using namespace std::chrono;


class ThreadPool {
    atomic_bool done;
    //ThreadSafeQueueMonitor<std::function<void()>> work_queue;
    ThreadSafeQueue<std::function<void()>> work_queue;
    vector<thread> threads;

    void worker_thread()
    {
        while(!done){
            function<void()> task;
            if(work_queue.try_pop(task)){
                task();
            }
            else{
                this_thread::yield();
            }
            //work_queue.wait_and_pop()();
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
};

static int i;
void print_i()
{
    cout << i++ << endl;
}

int main() {
    auto start = high_resolution_clock::now();
    {
        ThreadPool tp;
        while(i < 1000){tp.submit(print_i);};
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << "Time taken by function: "
         << duration.count() << " milliseconds" << endl;
    return 0;
}