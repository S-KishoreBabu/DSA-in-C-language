#include<stdio.h>
#include<stdlib.h>

struct queue{
    int data;
    struct queue *next;
};

typedef struct queue q;
q *head = NULL;

q* createqnode(int val){
    q* node=(q*)malloc(sizeof(q));
    node->data=val;
    node->next=NULL;
    return node;
}

void enqueue(int val){
    if(head==NULL){
        head=createqnode(val);
        return;
    }
    q* newnode=createqnode(val);
    newnode->next=head;
    head=newnode;
}


