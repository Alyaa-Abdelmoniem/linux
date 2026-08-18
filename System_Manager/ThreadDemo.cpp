#include "ThreadDemo.h"
#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

void work(int number)
{
    cout << "Thread " << number << " started" << endl;

    this_thread::sleep_for(
        chrono::seconds(2));

    cout << "Thread " << number << " finished" << endl;
}

void ThreadDemo::run()
{
    thread t1(work, 1);
    thread t2(work, 2);
    thread t3(work, 3);

    t1.join();
    t2.join();
    t3.join();
}
