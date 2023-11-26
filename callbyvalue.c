#include<stdio.h>
void change(int *a,int *b);

void main(){
    int a=1, b=2;
    change(&a,&b);
    printf("a = %d, b = %d\n",a,b);
}

void change(int *a, int *b){
    *a=2;
    *b=1;
}