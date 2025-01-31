// Online C compiler to run C program online
#include <stdio.h>
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
        printf(" %d ",root->data);
        inorder(root->left);
        // printf(" %d ",root->data);
        inorder(root->right);
        // printf(" %d ",root->data);
    }
    return;
}
int sum=0;
int max=-1;
void count(node* root){
    if(root!=NULL){
        sum++;
        printf("\n %d ",sum);
        if(max<sum){max=sum;}
        count(root->left);
        sum--;
        count(root->right);  
        
    }else{
        // sum--;
        // printf(" %d ",sum);
    }
    
    
    
    return ;
}

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



int main() {
    insert(&Root,6);
    insert(&Root,1);
    insert(&Root,3);
    insert(&Root,5);
    insert(&Root,9);
    insert(&Root,2);
    insert(&Root,0);
    insert(&Root,7);
    inorder(Root);
    printf("\n");
    count(Root);
    
    printf("\n height= ");
    // printf("s = %d ",sum);
    leaf(Root);
    printf("\nsum = %d ",sum);

    return 0;
}
