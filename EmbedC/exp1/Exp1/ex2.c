#include <stdio.h>
#include <math.h>
int chkArmstrong(int num) {
    int orig,rem,n = 0;
    double res = 0.0;
    orig=num;
    for (orig=num; orig!=0; orig/=10,++n);
    orig=num;
    while (orig != 0) {
        rem=orig % 10;
        res+=pow(rem, n);
        orig/=10; 
    }
    if ((int)res==num)
        return 1;
    else
        return 0;
}
int main() {
    int n,i;
    printf("Enter a positive integer n: ");
    scanf("%d",&n);
    printf("Armstrong numbers from 1 to %d are:\n",n);
    for (i=1;i<=n;++i) {
        if (chkArmstrong(i)) {
            printf("%d\n", i);
        }
    }
    printf("\nStack mem data: %d",n);
    printf("\nStack data address: %p",&n);
    printf("\nCode segment address: %p",&chkArmstrong);
    return 0;
}
