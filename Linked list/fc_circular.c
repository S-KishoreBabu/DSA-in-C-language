#include<stdio.h>
#include<stdlib.h>

struct lnode{
    int data;
    struct lnode * next;
};

typedef struct lnode node;

node * head = NULL;
node * tail = NULL;

node * createNode(int val){
    node * newNode = (node*)malloc(sizeof(node));
    newNode->data = val;
    newNode->next = NULL;
}

void insertAtbeginning(int val){
    node* newnode = createNode(val);
    if(head == NULL){
        head = newnode;
        tail = newnode;
    }
    else{
        newnode->next = head;
        head = newnode;
    }
    tail->next = head;

    printf("\n\n Answer : \n %d ",head->data);
    printf("%d\n",tail->data);
    
}

void display(){
    node* temp = tail;
    if(head!=NULL){
        printf("display : ");
        do{
            temp = temp->next;
            printf("%d ->",temp->data);
            
        }while(temp!=tail);
    }
    else{
        printf("list is Empty");
    }
}

void traversing(int pos){
    if(head!= NULL){
        int stack[10] = {0};
        int top = -1;
        node * temp = head;
        for(int i = 0;i<pos-1;i++){
            temp = temp->next;
        }
        printf("\n\n Forword Printing : \n");
        node * compare = temp;
        do{
            temp = temp->next;
            stack[++top] = temp->data;
            printf("%d ->",temp->data);
            
        }while(temp!=compare);
        printf("\n\n Reverse printing : \n");
        for(int i = top;i>=0;i--){
            printf("%d -> ",stack[i]);
        }
    }
    else{
        printf("\n list is empty");
    }
}

int main(){
    // insertAtbeginning(3);
    // insertAtbeginning(2);
    insertAtbeginning(1);
    display();
    // traversing(1);
    printf("\n");
    return 0;
}