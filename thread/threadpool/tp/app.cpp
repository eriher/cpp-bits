#include <iostream>
#include <threadpool.hpp>
main(){
    std::cout << "hello world" << std::endl;
    ThreadPool tp;
    auto fut = tp.submitTask([]{return 8;});
    fut.wait();
    std::cout << fut.get() << endl;
    return 0;
}