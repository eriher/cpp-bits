#include <mutex>
#include <queue>
#include <atomic>
#include <condition_variable>
#include <thread>
#include <mutex>
#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

mutex mut;
condition_variable_any cond;

void f1(){
    cout << "f1 start" << endl;
    this_thread::sleep_for(chrono::milliseconds(500));
    cout << "f1 after sleep" << endl;
    mut.lock();
    cout << "f1 locked" << endl;
    cout << "f1" << endl;
    mut.unlock();
    cout << "f1 unlocked" << endl;
    cond.notify_one();
    cout << "f1 notify" << endl;
}

void f2(){
    cout << "f2 start" << endl;
    mut.lock();
    cout << "f2 locked" << endl;
    unique_lock<mutex> lock(mut);
    cout << "f2 unique lock" << endl;
    cond.wait(lock);
    cout << "f2 waited" << endl;
    cout << "f2" << endl;
    mut.unlock();
}

int main() {
    auto start = high_resolution_clock::now();
    auto t1 = thread(f1);
    auto t2 = thread(f2);
    t1.join();
    t2.join();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << "Time taken by function: "
         << duration.count() << " milliseconds" << endl;
    return 0;
}