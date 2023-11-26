#include<stdio.h>
int factorial(int n);

void main(){
    int n;
    printf("Enter a Number: ");
    scanf("%d",&n);
    printf("Factorial is %d\n",factorial(n));
}

int factorial(int n) {
    if(n==1){
        return 1;
    }

    return n * factorial(n-1);
}

