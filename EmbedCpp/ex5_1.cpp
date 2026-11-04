
#include <iostream>
#include <thread>
#include <string>
using namespace std;

void threadfunc(int id, string message) {
    cout<<"Thread "<<id<<": "<<message<<"\n";
}

int main() {
    int n = 3;
    thread threads[n];
    for(int i=0;i<n;++i) {
        threads[i]=thread(threadfunc,i+1,"Hello "+to_string(i+1));
    }
    for(int i=0;i<n;++i) {
        threads[i].join();
    }
    return 0;
}
