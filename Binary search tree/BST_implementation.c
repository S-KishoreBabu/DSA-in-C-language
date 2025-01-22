#include<stdio.h>
#include<stdlib.h>

// Not Completed - binary search tree implementation

struct lnode{
    int data;
    struct lnode *right;
    struct lnode *left;
};

typedef struct lnode node;

node *root = NULL;

node* createNode(int val){
    node *newNode = (node*)malloc(sizeof(node));
    newNode->data = val;
    newNode->right = NULL;
    newNode->left = NULL;
    return newNode;
}

void insert(int val,node *root){
    node *newnode = createNode(val);
    node *temp;
    if(root == NULL ){
        root = newnode;
        root = newnode;
    }
    else if(val < root->data){
        temp = root;
        insert(val,temp->left);
    }
    else if(val > root->data){
        temp = root;
        insert(val,temp->right);
    }
    else{
        printf("value already exists\n");
    }
}

//level order traversal of binary search tree

// void display(){
//     if(root == NULL){
//         printf("Tree is empty\n");
//     }
//     else{
//         printf("Level Order Traversal of Binary Search Tree:\n");
//         //int h = height(root);
//         int i;
//         for(i=1;i<=h;i++){
//             printf("Level %d: ",i);
//             //printGivenLevel(root,i);
//             printf("\n");
//         }
//     }
// }

// int height(node *root){
//     if(root == NULL){
//         return 0;
//     }
//     else{
//         int left_height = height(root->left);
//         int right_height = height(root->right);
//         if(left_height>right_height){
//             return left_height+1;
//         }
//         else{
//             return right_height+1;
//         }
//     }
// }

void preordertraversal(node* root){
    if(root==NULL){
        return;
    }
    else{
        printf("%d ",root->data);
        preordertraversal(root->left);
        preordertraversal(root->right);
    }
}




int main(){
    int n;
    printf("Enter the number of elements you want to insert in the binary search tree:");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int val;
        printf("Enter the element you want to insert : ");
        scanf("%d",&val);
        insert(val,root);
    }
    printf("Preorder traversal of the binary search tree is : ");
    preordertraversal(root);
    return 0;
}