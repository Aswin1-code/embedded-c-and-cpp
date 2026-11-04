#include<stdio.h>
#include<stdlib.h>
void addMatrx(int **,int **,int **,int,int);
int main(){
    int rows,cols;
    void (*ptr)(int **,int **,int **,int,int)=&addMatrx;
    printf("\nEnter rows and cols: ");
    scanf("%d %d",&rows,&cols);
    int **A=(int **)malloc(rows*(sizeof(int *)));
    int **B=(int **)malloc(rows*(sizeof(int *)));
    int **C=(int **)malloc(rows*(sizeof(int *)));
    for(int i=0;i<rows;i++){
        A[i]=(int *)malloc(cols*(sizeof(int)));
        B[i]=(int *)malloc(cols*(sizeof(int)));
        C[i]=(int *)malloc(cols*(sizeof(int)));
        if(A[i]==NULL || B[i]==NULL || C[i]==NULL){ printf("Mem unallocated");return 1;}
    }
    printf("\nMatrix 1: ");     // input matrix 1
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            scanf("%d",&A[i][j]);
        }
    }
    printf("\nMatrix 2: ");     // input matrix 2
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            scanf("%d",&B[i][j]);
        }
    }
    (*ptr)(A,B,C,rows,cols);     // calling the function
    printf("\nResult:\n ");
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            printf("%d ",C[i][j]);
        }
        printf("\n");
    }
    for(int i=0;i<rows;i++){
            free(A[i]);
            free(B[i]);
            free(C[i]);
    }
    free(A);free(B);free(C);
}
void addMatrx(int **A,int **B,int **C,int rows,int cols){
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            C[i][j]=A[i][j]+B[i][j];
        }
    }
}