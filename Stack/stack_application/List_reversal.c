// * Completed - Reversing a list

#include <stdio.h>
#include <conio.h>

#define MAXSIZE 10
int stack[MAXSIZE];

int top = -1;

void push(int val)
{
    if (top != MAXSIZE - 1)
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
    if (top != -1)
    {
        int temp = stack[top];
        top--;
        return temp;
    }
    printf("\n stack is empty");
    return -1;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};

    for (int i = 0; i < (sizeof(arr) / sizeof(arr[0])); i++){push(arr[i]);}
    for (int i = 0; i < (sizeof(arr) / sizeof(arr[0])); i++){arr[i] = pop();}

    printf("\n Reversed List : [");
    for (int i = 0; i < (sizeof(arr) / sizeof(arr[0])); i++)
    {
        printf(" %d ", arr[i]);
    }
    printf("]");
    return 0;
}
