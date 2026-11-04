#include<stdio.h>
#include<stdlib.h>
int **allocateMatrix(int r,int c)
{
    int **mtx = (int **)malloc(r*sizeof(int *));
    for (int i=0;i<r;i++){
        mtx[i] = (int *)malloc(c * sizeof(int));
    } 
    return mtx;
}
void input(int **mtx, int r, int c){
    printf("\nEnter elements: ");
    for (int i=0;i<r;i++){
        for (int j=0;j<c;j++){
            printf(" \nElement: [%d][%d]: ", i, j);
            scanf("%d", &mtx[i][j]);
        }
    }
}
void display(int **mtx, int r, int c){
    printf("\nThe elements are: ");
    for (int i=0;i<r;i++){
        for (int j=0;j<c;j++)
            printf("%d ", mtx[i][j]);
        printf("\n");
    }
}
int **multiply(int **A, int **B, int r1, int c1, int c2){
    int **res = allocateMatrix(r1, c2);
    for(int i=0;i<r1;i++){
        for(int j=0;j<c2;j++){
            res[i][j] = 0;
            for (int k=0;k<c1;k++)
            {
                res[i][j]+=A[i][k]*B[k][j];
            }
        }
    }
    return res;
}
void freeM(int **mtx, int r)
{
    for (int i=0;i<r;i++)
        free(mtx[i]);
        free(mtx);
}
int main(){
    int r1,r2,c1,c2;
    int **A,**B,**C;
    printf("Enter no.of row and column of m1: ");
    scanf("%d %d",&r1,&c1);
    printf("Enter no.of row and column of m2: ");
    printf("%d %d",&r2,&c2);
    A=allocateMatrix(r1,c1);
    B=allocateMatrix(r2,c2);
    input(A,r1,c1);
    input(B,r2,c2);
    C=multiply(A,B,r1,c1,c2);
    display(C,r1,c2);
    freeM(A,r1);
    freeM(B,r2);
    freeM(C,r1);
}
