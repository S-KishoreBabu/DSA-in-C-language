/*
Not completed - Doubly linked list

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
#include<stdio.h>
#include<stdlib.h>

struct lnode{
    int data;
    struct lnode *next;
    struct lnode *prev;
};

typedef struct lnode node;
node*  head = NULL;
node*  tail = NULL;

void display(){
    node* temp = head;
    printf("\n [ ");
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf(" ]");
}

void  insertatend(int val){
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = val;
    if(head==NULL){
        newnode->next=NULL;
        newnode->prev=NULL;
        head = newnode;
        tail=newnode;

    }else{
        newnode->next = NULL;
        newnode->prev = tail;
        tail->next=newnode;
        tail = newnode;
    }
}

void   insertatpos(int val, int pos){
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = val;
    if(pos==0){
        insert_begin(val);
    }
    else{
        node* temp = head;
        for(int i=0;i<pos-1;i++){
            temp = temp->next;
        }
        if(temp->next==NULL){
            insertatend(val);
        }
        else{
            newnode->next=temp->next;
            temp->next->prev=newnode;
            temp->next=newnode;
            newnode->prev=temp;
        }
        
    }
}

void    insert_begin(int val){
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = val;
    newnode->prev =  NULL;
    if(head!=NULL){
        newnode->next = head;
        head->prev=newnode;
    }
    else{
        newnode->next = NULL;
    }
    head = newnode;
}

void deletebypos(int pos){
    if(pos==0){
        if(head->next!=NULL){
            node* temp=head;
            head->next->prev = NULL;
            head=head->next;
            free(temp);  
        }
        else{
            free(head);
            head=NULL;
        }
    }
    else{
        node* temp = head;
        for(int i=0;i<pos;i++){
            temp = temp->next;
        }
        if(temp->next==NULL){
            //node*  temp2 = temp;
            tail=temp->prev;
            temp->prev->next=NULL;
            free(temp);
        }
        else{
            temp->next->prev=temp->prev;
            temp->prev->next=temp->next;
            free(temp);
        }
    }
}

void deleteatbeginning(){
  if(head!=NULL){
    deletebypos(0);
  }
  else{
    printf("Liiist is Empty");
  }
}

void deletelastnode(){
    if(head==NULL){
        printf("\n Liist is empty");
    }
    else{
        if(head->next==NULL){
            free(head);
            head=NULL;
        }
    }
}

int search(int val){
    node* temp;
    if(head!=NULL){
        temp=head;
        int pos=-1;
        while(temp!=NULL){
            pos++;
            if(temp->data==val){
                return pos;
            }
            temp=temp->next;
        }
    }
    return -1;
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
            insert_begin(val);
            break;
        case 5: // Delete the last Node
            deletelastnode();
            break;
        case 6: // Delete a specific node by value
            printf("\n Enter the  value to delete : ");
            scanf("%d", &val);
            pos = search(val);
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
            if(head==NULL){
                printf("\n List is empty");
            }
            else{
                printf("Enter the postion : ");
                scanf("%d", &pos);
                deletebypos(pos);           
            }
            break;

        case 8: //  Delete a beginning node

            deleteatbeginning();
            break;
        case 9: //  Search a specific value in linked list
            printf("\n Enter the  value to search : ");
            scanf("%d", &val);
            pos = search(val);
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
            //break;
        }
    }
    return 0;
}