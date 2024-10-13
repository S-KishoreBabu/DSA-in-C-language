#include<stdio.h>// not completed
#include<stdlib.h>

struct lnode{
    int data;
    struct lnode * next;
};
typedef struct lnode node;

node* head = NULL;
void insertatbeginning(int val){
    node* newnode = (node*)malloc(sizeof(node));
    if(head==NULL){
        newnode->data=val;
        newnode->next=NULL;
        head=newnode;
    }
    else{
        newnode->data=val;
        newnode->next=head;
        head=newnode;
    }
}


void display(){
    node* temp;
    node* prev;
    
    //prev=head;
    temp=head;
    printf("[ ");
    while(temp!=NULL){
        printf("%d ",temp->data);
        //prev=prev->next;
        temp=temp->next;
    }
    printf(" ]");
    //printf("%d",temp->data);
}

void insertatpos(int pos,int val){
    node* newnode = (node*)malloc(sizeof(node));
    node* temp;
    newnode->data=val;
    if(pos == 0){
        insertatbeginning(val);
    }
    else{
        temp=head;
        for(int i = 0;i < pos;i++){
            temp->next=temp;
        }
        printf("\nval = %d",temp->data);
        
    }

}

void insertatend(int val){
    node* newnode=(node*)malloc(sizeof(node));
    if(head==NULL){
        insertatbeginning(val);
    }
    else{
        node* temp;
        temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        newnode->data=val;
        newnode->next=NULL;
        temp->next=newnode;
    }
}


int main(){
    int option=0;
    
    printf("\n choose the option to perform operation on array :- ");
    printf("\n 1) Display \n 2) Insert node at end \n 3) insert node at specific postion \n 4) Insert node at beginning \n 5) Delete the last node \n 6) Delete a specific node by value \n 7) delete a specific node by pos \n 8) delete a beginning node \n 9) Search a specific value in linked list \n 10) Exit ");
    while(option!=10){
        printf("\n Enter option : ");
        scanf("%d",&option);
        int val,pos;
        switch(option){
            case 1: 
                display();
                break;
            case 2:
                printf("Enter the value : ");
                scanf("%d",&val);
                insertatend(val);            
                break;
            case 3:
                printf("Enter the value : ");
                scanf("%d",&val);
                printf("Enter the postion : ");
                scanf("%d",&pos);
                insertatpos(val,pos);
                
                break;
            case 4:
                printf("Enter the value : ");
                scanf("%d",&val);
                insertatbeginning(val);            
                break;
            case 5:

                break;
            case 6:

                break;
            case 7:

                break;
            case 8:

                break;  
            case 9:

                break;  
            default:
                printf("You Entered wrong input");
                break;
        }

    }
    return 0;
}