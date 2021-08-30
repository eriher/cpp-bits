#include <string>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>

using namespace std;

mutex mut;
string var = "foo";
condition_variable data_cond;
vector<string> lines;


void reader()
{
    while(true){
        std::lock_guard<std::mutex> lk(mut);
        cout << "current lines: " << lines.size() << endl;
        cout << "provide input" << endl;
        string s;
        cin >> s;
        lines.push_back(s);
        data_cond.notify_one();
        Sleep(100);
    }
}

void writer()
{
    while(true){ 
        unique_lock<mutex> lk(mut);
        data_cond.wait(lk, [&]{return lines.size() > 3;});
        for(auto& s : lines){
            cout << "Output:" << s << endl;
        }
        lines = {};
        lk.unlock();
        cout << "sleeping" << endl;
        Sleep(500);
    }
}  

int main()
{    
    thread t1(reader);
    thread t2(writer);

    t1.join();
    t2.join();

    return 0;
}