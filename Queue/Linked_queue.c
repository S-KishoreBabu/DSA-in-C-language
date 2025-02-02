#include<stdio.h>
#include<stdlib.h>

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
    if(head!=NULL){
        q* temp=tail;
        tail=tail->prev;
        tail->next=NULL;
        temp->prev=NULL;
        return temp;
    }
    printf("\n queue is Empty");
}


