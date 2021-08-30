#include <Windows.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <thread>

using namespace std;

class Hello {
    string s;
    int t;
    public:
        Hello(string s,int t = 0):s{s},t{t}{
        }

        void print(){
            cout << s << " is tired, will sleep" << endl;
            Sleep(t);
            cout << s << " slept for " << t << "ms" << endl;
        };
        
        Hello operator() () {
            print();
        }
};

void print(int t,string s){
    cout << s << " is tired, will sleep" << endl;
    Sleep(t);
    cout << s << " slept for " << (t/100) << endl;
}

void test(){
    cout << "Tired" << endl;
    Sleep(5000);
    cout << "Woke Up" << endl;
}

main()
{
    srand (time(NULL));
    int r = rand() % 10000 + 500;
    cout << "Start! r: " << r << endl;
    thread first (Hello("Lennart",5000));
    thread second (Hello("Benny",3000));
    thread third (Hello("Kenny",1000));
    first.join();
    second.join();
    third.join();
    cout << "joined" << endl;
}
