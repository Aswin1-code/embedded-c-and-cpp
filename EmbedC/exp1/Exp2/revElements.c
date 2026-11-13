#include<stdio.h>
#include<stdlib.h>
int main(){
    int n;
    printf("No of elem? : ");
    scanf("%d",&n);
    int arr[n];
    printf("\nEnter elements: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int *ptr=&arr[n-1];
    for(int i=0;i<n;i++){
        printf("%d ",*ptr);
        ptr--;        
    }
}


