#include<stdio.h>
#include<stdlib.h>

struct queue{
    int data;
    struct queue *next;
};

typedef struct queue q;

q* createqnode(int val){
    q* node=(q*)malloc(sizeof(q));
    node->data=val;
    node->next=NULL;
    return node;
}


