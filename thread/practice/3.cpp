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


void tr1()
{
    while(true){
        cout << 1 << endl;
        cout << 2 << endl;
        cout << 3 << endl;
    }
}

void tr2()
{
    while(true){
        cout << 5 << endl;
        cout << 6 << endl;
        cout << 7 << endl;
    }
}  

int main()
{    
    thread t1(tr1);
    thread t2(tr2);

    t1.join();
    t2.join();

    return 0;
}