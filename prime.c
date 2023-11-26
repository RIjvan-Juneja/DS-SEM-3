#include<stdio.h>

void main(){
    int n,count=0,i;
    printf("Enter a Number: ");
    scanf("%d",&n);

    for(i=2;i<n;i++){
        if(n%i == 0){
            count++;
        }
    }

    if(count>0){
        printf("\n Not prime");
    }else{
        printf("\n prime");
    }
}