#include<stdio.h>
#include<stdlib.h>
int add(int,int);
int main(){
    int (*ptr)(int,int)=&add;
    int res=(*ptr)(5,2); //5+2=7
    printf("%d",res);
}
int add(int a,int b){
    return a+b;
}
