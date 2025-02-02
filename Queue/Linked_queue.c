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
    if (tail == NULL) {
        return NULL; // Return NULL if the queue is empty
    }
    q* temp = tail;
    tail = tail->prev;
    if (tail != NULL) {
        tail->next = NULL; // Set next of new tail to NULL
    } else {
        head = NULL; // If the queue is now empty, set head to NULL
    }
    temp->prev = NULL; // Clear the previous pointer of the dequeued node
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
    if (isqueueempty()) {
        return -1; // Return an error value if the queue is empty
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
