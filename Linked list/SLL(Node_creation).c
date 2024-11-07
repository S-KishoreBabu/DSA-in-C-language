#include<stdio.h>
#include<stdlib.h>

struct lnode{
    int data;
    struct lnode *next;
};


typedef struct lnode node;

node *head=NULL;

node* createnode(int val){
    node *newnode = (node*)malloc(sizeof(node));
    newnode->data=val;
    newnode->next=NULL;
    return newnode;
}

void insertatbegin(int val){
    if(head==NULL){
        head=createnode(val);
    }
    else{
        node *newnode = createnode(val);
        newnode->next=head;
        head=newnode;
    }
}

void insertnode(int val){
        if(head==NULL){
            head=createnode(val);
        }
        else{
            if(head->data>val){
                insertatbegin(val);
            }
            else{
                node *prev=head;
                node *temp=head->next;
                while(temp!=NULL && temp->data<val){
                    prev=temp;
                    temp=temp->next;
                }
                node* newnode = createnode(val);
                newnode->next=temp;
                prev->next=newnode;
            }
        }
}

void display(){
    node *temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}

int main(){
    int n;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    int x;
    for(int i=0;i<n;i++){
        printf("Enter Value : ");
        scanf("%d",&x);
        insertnode(x);
    }
    display();
    return 0;
}