#include<iostream>
#include "display.h"
#include<string>
using namespace std;
void show(string &inp){
    cout<<"enter a string:"<<endl;
    getline(cin,inp);
    cout<<"showing the content here"<<endl;
    cout<<inp<<endl;
}
