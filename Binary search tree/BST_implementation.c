#include<stdio.h>
#include<stdlib.h>

struct ltree{
    int data;
    struct ltree *left;
    struct ltree *right;
};

typedef struct ltree node;

node *Root=NULL;

node* createNode(int val){
    node* nn=(node*)malloc(sizeof(node));
    nn->data=val;
    nn->left=NULL;
    nn->right=NULL;
    return nn;
}

void inorder(node* root){
    if(root!=NULL){
        // printf(" %d ",root->data);
        inorder(root->left);
        printf(" %d ",root->data);
        inorder(root->right);
        // printf(" %d ",root->data);
    }
    return;
}

void preorder(node* root){
    if(root!=NULL){
        printf(" %d ",root->data);
        inorder(root->left);
        // printf(" %d ",root->data);
        inorder(root->right);
        // printf(" %d ",root->data);
    }
    return;
}

void postorder(node* root){
    if(root!=NULL){
        // printf(" %d ",root->data);
        inorder(root->left);
        // printf(" %d ",root->data);
        inorder(root->right);
        printf(" %d ",root->data);
    }
    return;
}

int sum=0;

void leaf(node* root){
    if(root!=NULL){
        if(root->right==NULL && root->left == NULL){
            sum+=root->data;
        }
        leaf(root->left);
        leaf(root->right);
    }
    return;
}


void insert(node **root,int val){
    if(*root==NULL){
        *root=createNode(val);
        //printf(" %d ",(*root)->data);
        return;
    }
    if((*root)->data<val){
        insert(&((*root)->right),val);
    }else if(val<(*root)->data){
        insert(&((*root)->left),val);
    }
    
}

int main(){
    int n,val;
    system("cls");
    printf("\n Enter of Number of value to enter :  ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&n);
        insert(&Root,val);
    }
    printf("\n Inorder   Traversal : ");
    inorder(Root);
    printf("\n preorder  Traversal : ");
    preorder(Root);
    printf("\n postorder Traversal : ");
    postorder(Root);
    leaf(Root);
    printf("\nsum of leaf Node Values = %d ",sum);
    return 0;
}
