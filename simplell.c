#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

void main(){
    struct node *head=NULL;
    head = (struct node*)malloc(sizeof(struct node));
    head->data = 45;

    struct node *rrj=NULL;
    rrj = (struct node*)malloc(sizeof(struct node));
    rrj->data = 45;
    head->link = rrj;

    struct node *jrr=NULL;
    jrr = (struct node*)malloc(sizeof(struct node));
    jrr->data = 45;
    jrr->link = NULL;
    rrj->link = jrr;

    struct node *ptr = head;

    while(ptr != NULL){
        printf("%d \n",ptr->data);  
        ptr = ptr->link; 
    }
}