#include<stdio.h>
#include<stdlib.h>
int InGlVar1=10;
float unGlVar;
int func(){
   return 12*12;
}
int main(){
        int local;
        int *heap;
        heap=(int*)malloc(3*sizeof(int));
        int n=20;
        heap=&n;
        local=1;
        printf("Sample output: ");
        // ------------------------------------------
        printf("\nStack memory data: %d",local);
        
        printf("\nStack memory address of data: %p",&local);
        // ------------------------------------------
        printf("\nHeap memory data: %d",heap);
        
        printf("\nHeap memory address of data: %p",&heap);
        // ------------------------------------------
        printf("\nUninitialized global data: %d",unGlVar);
        
        printf("\nUninitialized global data address: %p",&unGlVar);
        // ------------------------------------------
        printf("\nInitialized global data: %d",InGlVar1);
        
        printf("\nInitialized global data address: %p",&InGlVar1);
        // ------------------------------------------
        printf("\nCode segment function data: %d ",func());
        
        printf("\nCode segment address of function: %p",&func);
        // ------------------------------------------
        free(heap);
}