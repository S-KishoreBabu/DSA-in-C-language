#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 20

int queue[MAXSIZE];
int front=-1;
int rear=-1;

void enqueue(int val){
    if(rear==MAXSIZE-1){
        printf("Overflow");
    }
    else if(front==-1 && rear==-1){
        rear=front=0;
    }
    else{
        front++;
    }
    queue[rear]=val;
}

int dequeue(){
    if(front==-1 && rear==-1){
        printf("\n UNDERFLOW");
        return -1;
    }

    int temp=queue[front];

    if(front==rear)
        front=rear=-1;
    else
        front++;
    
    return temp;
}

int peek(){
    if(front==-1 && rear==-1){
        printf("\n UNDERFLOW");
        return -1;
    }
    else{
        return queue[front];
    }
}

void display(){
    if(front==-1 && rear==-1){
        printf("\n Queue is empty");
    }
    else{
        for(int i=front;i<=rear;i++){
            printf(" %d |",queue[i]);
        }
    }
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
                val= dequeue();
                if(val!=-1)
                    printf("\n Dequeued node value is %d ",val);
                break;
            case 3:
                val= peek();
                if(val!=-1)
                    printf("\n Dequeued node value is %d ",val);
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

