/*
Completed - Circular Singly linked list

1) Display
2) Insert node at end
3) insert node at specific postion
4) Insert node at beginning
5) Delete the First Node
6) Delete the last node
7) Exit

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
int count = -1;

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
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != first);
    printf(" %d ] \n",temp->data);
}

node* createnode(int val){
    node *newnode = (node*)malloc(sizeof(node));
    newnode->data = val;
    newnode->next = NULL;
    return newnode;
}

void insertAtEnd(int val)
{
    node *newnode = createnode(val);
    if (first == NULL)
    {
        first = last = newnode;
        newnode->next = first;
    }
    else
    {
        last->next = newnode;
        newnode->next=first;
        last = newnode;
    }
}

void insertAtPos(int val, int pos)
{
    if (pos == 0 || first==NULL)
    {
        insert_begin(val);
    }
    else if(pos >=count){
        insertAtEnd(val);
    }
    else
    {
        node *newnode = createnode(val);
        node *temp = first;
        for (int i = 0; i < pos-1; i++)
        {
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
}

void insert_begin(int val){
    if(first!=NULL){
    node *temp = last;
    insertAtEnd(val);
    first = last;
    last = temp;
    }
    else{
        insertAtEnd(val);
    }
}

void deleteAtBegin(){
    if(first==NULL){return;}
    else if(first==last){deleteAtEnd(); return;}
    node *temp = first;
    while(temp->next != first){
        temp = temp->next;
    }
    temp->next = first -> next;
    free(first);
    first = temp->next;
}
void deleteAtEnd(){
    if(first == NULL){ return;}
    if(first->next == first){ //only one node
    free(first);
    first = NULL;
    last = NULL;
    return;
    }

    node *temp, *prev;
    temp = first;
    while(temp->next != first){
        prev = temp;
        temp = temp->next;
    }
    prev-> next = temp -> next;
    free(temp);
    last = prev;
}

// display the first value and last value function

void displayFirstLast(){
    if(first == NULL){printf("List is empty");return;}
    printf("First value: %d\n", first->data);
    printf("Last value: %d\n", last->data);
}

int main()
{
    int option = 0;

    printf("\n choose the option to perform operation on list :- ");
    printf("\n 1) Display \n 2) Insert node at end \n 3) insert node at specific postion \n 4) Insert node at beginning \n 5) Delete the First Node \n 6) Delete the last node \n 7) Exit ");
    while (option != 7)
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
            count++;
            break;
        case 3: // Insert at specific position
            printf("Enter the value : ");
            scanf("%d", &val);
            printf("Enter the postion : ");
            scanf("%d", &pos);
            insertAtPos(val, pos);
            count++;
            break;
        case 4: // Insert node at beginning
            printf("Enter the value : ");
            scanf("%d", &val);
            insert_begin(val);
            count++;
            break;
        case 5: // Delete a beginning node
            deleteAtBegin();
            count--;
            display();
            // displayFirstLast();
            break;
        case 6: //  Delete a last node
            deleteAtEnd();
            count--;
            display();
            // displayFirstLast();
            break;

        default: // Invalid option
            printf("You Entered wrong input");
            break;
        }
    }
    return 0;
}