#include<stdio.h>
#include<stdlib.h>
int main(){   // 2d array using pointer to pointer
    int n;
    printf("No of elements( rows and cols )=>(rows=cols) ?: ");
    scanf("%d",&n);
    int **arr=(int**)malloc(n*sizeof(int*));
    for(int i=0;i<n;i++){
        arr[i]=(int*)malloc(n*sizeof(int));
    }
    printf("Enter elements: ");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",(arr[i]+j));
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf(" %d ",*(*(arr+i)+j));
        }
        printf("\n");
    }   
    for (int i = 0; i < n; i++) {
        free(arr[i]); 
    }
    free(arr); 
    return 0; 

}

