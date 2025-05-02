// * completed - stack implementation

// ! don't push decimal values 

#include <stdio.h> 
#include <stdlib.h>
#include <stdbool.h>

#define MAXSIZE 10

int stack[MAXSIZE];
int top = -1;

bool isEmpty(){
    return (top == -1)?true:false;
}

bool isFull(){
    return (top == MAXSIZE - 1)?true:false;
}

void push(int val)
{
    if (!isFull())
    {
        stack[++top] = val;
    }
    else
    {
        printf("\n stack is full");
    }
}

int pop()
{
    if (!isEmpty())
    {
        int temp = stack[top];
        top--;
        return temp;
    }
    printf("\n stack is empty");
    return -1;
}

int peek(){
    return (!isEmpty())?stack[top]:-1;
}

void posofStack()
{
    printf("\n Top = %d ", top);
}

void display()
{
    if (!isEmpty())
    {
        printf("\n\n");
        for (int i = top; i >= 0; i--)
        {
            printf("\n | %d | ", stack[i]);
        }
    }
    else
    {
        printf("\n stack is empty");
    }
}

int main()
{
    int n, x;
    printf("\n Choose the option :-  \n 1) push()  2) pop()  3) peek()  4) display  5) position of top 6) Exit");
    do
    {
        printf("\n Enter option : ");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            printf("Enter  the value to push in stack :- ");
            scanf("%d", &x);
            push(x);
            break;
        case 2:
            pop();
            break;
        case 3:
            if (peek() != -1)
            {
                printf("Top value = %d", peek());
            }else{
                printf("stack is empty");
            }
            break;
        case 4:
            display();
            break;
        case 5:
            posofStack();
            break;
        default:
            printf("\n You have entered wrong option");
        }
    } while (n != 6);
    return 0;
}
