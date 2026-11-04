#include<iostream>
#include<thread>
#include<chrono>
using namespace std;

void displayBrightness(int value,int maxValue) {
    int barLength=50;
    int pos=(value*barLength)/maxValue;
    cout<<"[";
    for(int i=0;i<barLength;i++){
        if(i<pos)
            cout<<"=";
        else
            cout<<" ";
    }
    cout<<"]"<<(value*100)/maxValue<<"%\r";
    cout.flush();
}
int main(){
    const int maxPWM = 1023;
    cout<<"Simulating LED brightness using PWM..."<<endl;
    while(true){
        for(int i=0;i<=maxPWM;i++){
            displayBrightness(i,maxPWM);
            this_thread::sleep_for(chrono::milliseconds(100));
        }
        for(int i=maxPWM;i>=0;i--){
            displayBrightness(i,maxPWM);
            this_thread::sleep_for(chrono::milliseconds(100));
        }
    }
    return 0;
}
/*
Simulating LED brightness using PWM...
[========================                          ]49%%

Simulating LED brightness using PWM...
[=========================================         ]83%%

*/