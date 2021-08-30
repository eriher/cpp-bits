#include <thread>
#include <future>
#include <vector>
#include <threadsafequeue.cpp>
using namespace std;

class ThreadPool {
    atomic_bool done;
    ThreadSafeQueue<std::function<void()>> work_queue;
    vector<thread> threads;
    void worker_thread()
    {
        while(!done){
            function<void()> task;
            if(work_queue.try_pop(task))
                 task();
            else
                std::this_thread::yield();
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
            done=true;
            int i = 0;
            for(auto& thread:threads) 
            {
                if(thread.joinable())
                {
                    thread.join(); 
                }
            } 
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