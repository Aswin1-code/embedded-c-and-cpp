#include<stdio.h>
#include<stdlib.h>
void prodMatrx(int **,int **,int **,int,int);
int main(){
    void (*ptr)(int **,int **,int **,int,int)=&prodMatrx;
    int r,c;
    printf("\nRows and Columns enter: ");
    scanf("%d %d",&r,&c);
    int **A=(int **)malloc(r*(sizeof(int *)));
    int **B=(int **)malloc(r*(sizeof(int *)));
    int **C=(int **)malloc(r*(sizeof(int *)));
    for(int i=0;i<r;i++){
        A[i]=(int *)malloc(c*(sizeof(int)));
        B[i]=(int *)malloc(c*(sizeof(int)));
        C[i]=(int *)malloc(c*(sizeof(int)));
        if(A[i]==NULL || B[i]==NULL || C[i]==NULL){
            printf("\nMem alloc failed"); return 1;
        }
    }
    printf("\nMatrix 1: ");     // input matrix 1
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            scanf("%d",&A[i][j]);
        }
    }
    printf("\nMatrix 2: ");     // input matrix 2
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            scanf("%d",&B[i][j]);
        }
    }
    (*ptr)(A,B,C,r,c);     // calling the function
    printf("\nResult: ");
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            printf("%d ",C[i][j]);
        }
        printf("\n");
    }
    for(int i=0;i<r;i++){
            free(A[i]);
            free(B[i]);
            free(C[i]);
    }
    printf("\nAddress of matrix A: %p",&A);
    printf("\nAddress of matrix B: %p",&B);
    printf("\nAddress of matrix C: %p",&C);
    printf("\nStack memory data: %d",r);
    printf("\nStack memory address: %p",&r);
    printf("\nCode segment address: %p",&prodMatrx);
    free(A);free(B);free(C);
}
void prodMatrx(int **A,int **B,int **C,int r,int c){
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            C[i][j]=0;
            for(int k=0;k<c;k++){
                C[i][j]+=A[i][k]*B[k][j];
            }
        }
    }
}


