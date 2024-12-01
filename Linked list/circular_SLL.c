/*
Not Completed - Circular Singly linked list

1) Display the list
2) Insert newnode at end
3) Insert newnode at specific postion
4) Insert newnode at beginning
5) Delete the last node
6) Delete a specific node by value
7) Delete a specific node by position
8) Delete a beginning node
9) Search a specific value in linked list
10) Exit

*/

#include <stdio.h>
#include <stdlib.h>

struct lnode
{
    int data;
    struct node *next;
};

typedef struct lnode node;

node *last = NULL;
node *first = NULL;

void display()
{
    if (first == NULL)
    {
        printf("List is empty\n");
        return;
    }
    node *temp = first;
    printf("\n [ ");
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != first);
    printf(" ] \n");
}

void insertAtEnd(int val)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = val;
    newnode->next = NULL;
    if (first == NULL)
    {
        first = newnode;
        last = newnode;
        newnode->next = first;
    }
    else
    {
        last->next = newnode;
        last = newnode;
        last->next = first;
    }
}

void insertAtPos(int val, int pos)
{
    if (pos == 0)
    {
        insertAtbegin(val);
    }
    else
    {
        node *temp;
        temp = first;
        for (int i = 0; i <= pos; i++)
        {
            temp = temp->next;
        }
        printf("\n data = %d", temp->data);
    }
}

void insertAtpos(int val, int pos)
{
    if (pos == 0)
    {
        insertAtbegin(val);
    }
    else
    {
        node *newnode = (node *)malloc(sizeof(node));
        newnode->data = val;
        node *temp = first;
        for (int i = 0; i < pos - 1; i++)
        {

            temp = temp->next;
        }
        if (temp == last)
        {
            insertAtEnd(val);
        }
    }
}

int main()
{
    int option = 0;

    printf("\n choose the option to perform operation on list :- ");
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
            insertAtEnd(val);
            break;
        case 3: // Insert at specific position
            printf("Enter the value : ");
            scanf("%d", &val);
            printf("Enter the postion : ");
            scanf("%d", &pos);
            insertAtPos(val, pos);
            break;
        case 4: // Insert node at beginning
            // printf("Enter the value : ");
            // scanf("%d", &val);
            // insert_begin(val);
            break;
        case 5: // Delete the last Node
            // deletelastnode();
            break;
        case 6: // Delete a specific node by value
            // printf("\n Enter the  value to delete : ");
            // scanf("%d", &val);
            // pos = search(val);
            // if (pos != -1)
            // {
            //     deletebypos(pos);
            // }
            // else
            // {
            //     printf("\n Value %d not found", val);
            // }
            break;
        case 7: //  Delete a specific node by pos
            // if (head == NULL)
            // {
            //     printf("\n List is empty");
            // }
            // else
            // {
            //     printf("Enter the postion : ");
            //     scanf("%d", &pos);
            //     deletebypos(pos);
            // }
            break;

        case 8: //  Delete a beginning node

            // deleteatbeginning();
            break;
        case 9: //  Search a specific value in linked list
            // printf("\n Enter the  value to search : ");
            // scanf("%d", &val);
            // pos = search(val);
            // if (pos != -1)
            // {
            //     printf("\n Value %d found at position %d", val, pos);
            // }
            // else
            // {
            //     printf("\n Value %d not found", val);
            // }
            break;
        default: // Invalid option
            printf("You Entered wrong input");
            break;
        }
    }
    return 0;
}