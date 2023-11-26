#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
};
struct node* start = NULL; 

void createNodeEnd()
{
    struct node *temp ,*ptr;
    
    temp = (struct node*)malloc(sizeof(struct node));
    
    if(temp == NULL)
    {
        printf("\nNO SPACE AVAILABLE");
        exit(0);
    }
    printf("\nENTER NUMBER");
    scanf("%d",&temp->data);
    temp->next=NULL;
    if(start == NULL)
    {
        start =temp;
    }
    else
    {
        ptr = start;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=temp;
    }
}

void createNodeBeginning()
{
    struct node *temp;
    
    temp = (struct node*)malloc(sizeof(struct node));
    
    if(temp == NULL)
    {
        printf("\nNO SPACE AVAILABLE");
        exit(0);
    }
    printf("\nENTER NUMBER");
    scanf("%d",&temp->data);
    if(start == NULL){
        start = temp;
    } else{
    temp->next=start;
    start = temp;
    }
    
}

void displayList()
{
    struct node *ptr;
    if(start==NULL)
    {
        printf("\nLIST IS EMPTY");
        return;
    }
    else
    {
        ptr = start ; 
        printf("\nLIST ELEMENTS IS:");
        while(ptr != NULL)
        {
            printf("%d ",ptr->data);
            ptr=ptr->next;
        }
    }
}

void deleteHead()
{
    struct node *ptr;
    if(start==NULL)
    {
        printf("\nLIST IS EMPTY");
        return;
    }
    else
    {
        ptr =start;
        start = ptr->next;
        printf("\nDELETED HEAD NODE IS %d",ptr->data);
        free(ptr);
    }
}

void deleteEnd()
{
    struct node *rrj,*ptr;
    if(start==NULL)
    {
          printf("\nLIST IS EMPTY");
            return;
    }
    else
    {
        ptr= start;
        while(ptr->next != NULL)
        {
            rrj=ptr;
            ptr=ptr->next;
        }
        rrj->next=NULL;
        printf("\nEND OF THE LIST IS %d",ptr->data);
        free(ptr);  
    }
}
int searchNode(){
    struct node *ptr;
    int count = 0,key;

    if(start==NULL){
        printf("\nLIST IS EMPTY");
    } else{
        printf("Enter the node data you want to search");
        scanf("%d",&key);

        ptr=start;
        while (ptr!=NULL)
        {
            count++;
            if(ptr->data==key){
                printf("\nElement found at position : %d\n",count);
                return 0;
            }
            ptr=ptr->next;
        }

        printf("\nElement not found");
        return 0;
        
    }
    
}
int main() {
    int ch;
    while(1)
    {
        printf("\nMENU");
        printf("\n1. CREATE NODE at End\n2.CREATE NODE at Beginning \n3.DISPLAY\n4.DELETE HEAD NODE\n5.DELETE END NODE\n 6.Exit\n");
        printf("ENTER YOUR CHOICE :");
        scanf("%d",&ch);
        
        switch(ch)
        {
            case 1: createNodeEnd();
                break;
            case 2: createNodeBeginning();
                break;
            case 3: displayList();
                break;
            case 4: deleteHead();
                break;
            case 5: deleteEnd();
                break;
            case 6: exit(0);
                break;
            default:
                printf("\nWRONG CHOICE! \n");
          }
    }
     
}