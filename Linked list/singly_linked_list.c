/*
completed - Singly linked list

1) Display the list
 2) Insert newnode at end
 3) insert newnode at specific postion
 4) Insert newnode at beginning
 5) Delete the last node
 6) Delete a specific node by value
 7) delete a specific node by position
 8) delete a beginning node
 9) Search a specific value in linked list
 10) Exit

*/


#include <stdio.h> // completed
#include <stdlib.h>

struct lnode
{
    int data;
    struct lnode *next;
};
typedef struct lnode node;

node *head = NULL;
void insertatbeginning(int val)
{
    node *newnode = (node *)malloc(sizeof(node));
    if (head == NULL)
    {
        newnode->data = val;
        newnode->next = NULL;
        head = newnode;
    }
    else
    {
        newnode->data = val;
        newnode->next = head;
        head = newnode;
    }
}

void display()
{
    node *temp;
    node *prev;
    temp = head;
    printf("[ ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        // prev=prev->next;
        temp = temp->next;
    }
    printf(" ]");
}

void insertatpos(int val, int pos)
{
    node *newnode = (node *)malloc(sizeof(node));
    node *temp;
    newnode->data = val;
    if (pos == 0)
    {
        insertatbeginning(val);
    }
    else
    {
        temp = head;
        for (int i = 0; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
}

void insertatend(int val)
{
    node *newnode = (node *)malloc(sizeof(node));
    if (head == NULL)
    {
        insertatbeginning(val);
    }
    else
    {
        node *temp;
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        newnode->data = val;
        newnode->next = NULL;
        temp->next = newnode;
    }
}

deleteatbeginning()
{
    node *temp;
    temp = head;
    head = head->next;
    free(temp);
}

void deletebypos(int pos)
{
    node *newnode = (node *)malloc(sizeof(node));
    if (pos == 0)
    {
        deleteatbeginning();
    }
    else
    {
        node *temp;
        node *prev;
        prev = head;
        temp = prev->next;
        for (int i = 0; i < pos - 1; i++)
        {
            prev = prev->next;
            temp = temp->next;
        }
        prev->next = temp->next;
        free(temp);
    }
}

void deletelastnode()
{
    node *temp;
    node *prev;
    prev = head;
    temp = head->next;
    printf("\n Temp data = %d", temp->data);
    while (temp->next != NULL)
    {
        temp = temp->next;
        prev = prev->next;
    }
    printf("\n Temp data = %d", temp->data);
    prev->next = NULL;
    free(temp);
}

int search(int val)
{
    node *temp;
    temp = head;
    int pos = 0;
    int searchval = -1;
    while (temp->next != NULL)
    {
        temp = temp->next;
        pos++;
        if (temp->data == val)
        {
            searchval = pos;
        }
    }
    return searchval;
}

int main()
{
    int option = 0;

    printf("\n choose the option to perform operation on array :- ");
    printf("\n 1) Display \n 2) Insert node at end \n 3) insert node at specific postion \n 4) Insert node at beginning \n 5) Delete the last node \n 6) Delete a specific node by value \n 7) delete a specific node by pos \n 8) delete a beginning node \n 9) Search a specific value in linked list \n 10) Exit ");
    while (option != 10)
    {
        printf("\n Enter option : ");
        scanf("%d", &option);
        int val, pos;
        switch (option)
        {
        case 1: // display
            display();
            break;
        case 2: // Insert node at end
            printf("Enter the value : ");
            scanf("%d", &val);
            insertatend(val);
            break;
        case 3: // Insert at specific position
            printf("Enter the value : ");
            scanf("%d", &val);
            printf("Enter the postion : ");
            scanf("%d", &pos);
            insertatpos(val, pos);
            break;
        case 4: // Insert node at beginning
            printf("Enter the value : ");
            scanf("%d", &val);
            insertatbeginning(val);
            break;
        case 5: // Delete the last Node
            deletelastnode();
            break;
        case 6: // Delete a specific node by value
            printf("\n Enter the  value to search : ");
            scanf("%d", &val);
            int pos = search(val);
            if (pos != -1)
            {
                deletebypos(pos);
            }
            else
            {
                printf("\n Value %d not found", val);
            }
            break;
        case 7: //  Delete a specific node by pos
            printf("Enter the postion : ");
            scanf("%d", &pos);
            deletebypos(pos);
            break;
        case 8: //  Delete a beginning node

            deleteatbeginning();
            break;
        case 9: //  Search a specific value in linked list
            printf("\n Enter the  value to search : ");
            scanf("%d", &val);
            int pos = search(val);
            if (pos != -1)
            {
                printf("\n Value %d found at position %d", val, pos);
            }
            else
            {
                printf("\n Value %d not found", val);
            }
            break;
        default: // Invalid option
            printf("You Entered wrong input");
            break;
        }
    }
    return 0;
}