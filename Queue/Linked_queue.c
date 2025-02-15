// Completed - doubly linked queue 
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool isqueueempty();

struct queue{
    int data;
    struct queue *next;
    struct queue *prev;
};

typedef struct queue q;
q *head = NULL;
q *tail = NULL;

q* createqnode(int val);
void enqueue(int val);
q* dequeue();
void display();
int queuePeek();
bool isqueueempty();



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
    if (tail == NULL) {
        return NULL; 
    }
    q* temp = tail;
    tail = tail->prev;
    if (tail != NULL) {
        tail->next = NULL; 
    } else {
        head = NULL; 
    }
    temp->prev = NULL; 
    return temp;
}

void display(){
    if(head!=NULL){
        q* temp=tail;
        printf("NULL <-> ");
        while(temp!=NULL){
            printf("%d <-> ",temp->data);
            temp=temp->prev;
        }
        printf("NULL");
        return;
    }
    printf("\n Queue is empty");
}

int queuePeek(){
    if (isqueueempty()) {
        return -1; 
    }
    return tail->data;
}

bool isqueueempty(){
    return head==NULL;
}

int main(){
    int n=0,val;
    system("cls");
    printf("\n 1) Enqueue \n 2) Dequeue \n 3) Peek \n 4 display the queue \n 5) Exit");
    while(n!=5){
        printf("\n Select the Operation to Perform : ");
        scanf("%d",&n);
        switch(n){
            case 1:
                printf("\n Enter the value to enqueue : ");
                scanf("%d",&val);
                enqueue(val); // Enqueue the value after reading it
                break;
            case 2:
                if(head!=NULL){
                    q* node = dequeue();
                    printf("\n Dequeued node value is %d ",node->data);
                    free(node); // Free the memory of the dequeued node
                }
                else{
                    printf("\n Queue is empty");
                }
                break;
            case 3:
                if(head!=NULL){
                    printf("\n peek value = %d ",queuePeek());
                }
                else{
                    printf("\n Queue is empty");
                }
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
