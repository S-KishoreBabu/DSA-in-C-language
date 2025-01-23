//Not - Completed
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <malloc.h>

struct lnode
{
    int data;
    struct lnode *next;
};
int n = -1;
typedef struct lnode node;

node *top = NULL;

node *createnode(int val)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = val;
    newnode->next = NULL;
    return newnode;
}

void push(int val)
{
    node *newnode = createnode(val);
    if (top != NULL)
    {
        newnode->next = top;
    }
    top = newnode;
    n++;
}

int pop()
{
    if (top != NULL)
    {
        node *temp = top;
        int val = temp->data;
        top = top->next;
        free(temp);
        return val;
        n--;
    }
    printf("\n Stack is empty\n");
    return -1;
}
void display()
{
    if (top != NULL)
    {
        node *temp = top;
        printf("\n|'''|");
        while (temp != NULL)
        {
            printf("\n| %d |", temp->data);
            printf("\n|___|");
            temp = temp->next;
        }
    }
    else
    {
        printf("\n Stack is empty\n");
    }
}

int peek()
{
    if (top != NULL)
    {
        int val = top->data;
        return val;
    }
    printf("stack is empty");
}

void posofStack()
{
    printf("\n Position of top is %d ", n);
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
            x = peek();
            if (top != NULL)
            {
                printf("Top value = %d", x);
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
