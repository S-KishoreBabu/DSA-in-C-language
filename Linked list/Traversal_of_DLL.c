#include <stdio.h> //completed - insertion and display of doubly linked list
#include <stdlib.h>

struct lnode
{
    int data;
    struct lnode *prev;
    struct lnode *next;
};
typedef struct lnode node;

node *head;
node *tail;

void insertf(int val)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = val;
    newNode->next = NULL;
    tail = newNode;
    head = newNode;
    newNode->prev = NULL;
}

int main()
{
    int value, valu, num, i;
    //printf("\n                                                                                    LINKED LIST \n\n");
    printf("No. of Element need to Input : ");
    scanf("%d", &num);
    printf("\n\nEnter value for 1 : ");
    scanf("%d", &value);
    insertf(value);
    for (i = 1; i < num; i++)
    {
        printf("Enter value for %d : ", i + 1);
        scanf("%d", &valu);
        node *newNode = (node *)malloc(sizeof(node));
        tail->next = newNode;
        newNode->data = valu;
        newNode->prev = tail;

        tail = newNode;
        newNode->next = NULL;
    }

    node *current = head;
    printf("\n NULL <-> ");
    while (current != NULL)
    {
        printf("%d <-> ", current->data);
        current = current->next;
    }
    printf("NULL\n\n");
    return 0;
}