#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct queue{
    int data;
    struct queue *next;
    struct queue *prev;
};

typedef struct queue q;
q *head = NULL;
q *tail = NULL;

q* createqnode(int val){
    q* node=(q*)malloc(sizeof(q));
    node->data=val;
    node->next=NULL;
    node->prev=NULL;
    return node;
}

void enqueue(int val){
    if(head==NULL){
        head=createqnode(val);
        tail=head;
        return;
    }
    q* newnode=createqnode(val);
    newnode->next=head;
    head->prev=newnode;
    head=newnode;
}

q* dequeue(){
    q* temp=tail;
    tail=tail->prev;
    tail->next=NULL;
    temp->prev=NULL;
    return temp;
}


void display(){
    if(head!=NULL){
        q* temp=head;
        printf("NULL <-> ");
        while(temp!=NULL){
            printf("%d <-> ",temp->data);
            temp=temp->next;
        }
        printf("NULL");
        return;
    }
    printf("\n Queue is empty");
}


int queuePeek(){
    if(head!=NULL){
        return tail->data;
    }
    printf("\n Queue is empty");
}

bool isqueueempty(){
    return head==NULL;
}


int main(){
    int n,val;
    system("cls");
    printf("\n 1) Enqueue \n 2) Dequeue \n 3) Peek \n 4 display the queue \n 5) Exit \n Select the Operation to Perform : ");
    scanf("%d",&n);
    while(n!=5){
        switch(n){
            case 1:
                printf("\n Enter the value to enqueue : ");
                scanf("%d",&val);
                break;
            case 2:
                if(head!=NULL){
                    q* node = dequeue();
                    printf("\n Dequeued node value is %d ",node->data);
                }
                else{
                    printf("\n Queue is empty");
                }
                break;
            case 3:
                printf("\n peek value = %d ",queuePeek());
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("\n You Entered wrong input ");
        }
    }
    return 0;
}




