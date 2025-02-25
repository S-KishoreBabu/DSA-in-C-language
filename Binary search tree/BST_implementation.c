#include<stdio.h>
#include<stdlib.h>



struct ltree{
    int data;
    struct ltree *left;
    struct ltree *right;
};

typedef struct ltree node;
void inorderTraversal(node* root);

//node *Root=NULL;

node* createNode(int val){
    node* nn=(node*)malloc(sizeof(node));
    nn->data=val;
    nn->left=NULL;
    nn->right=NULL;
    return nn;
}

// void inorder(node* root){
//     if(root!=NULL){
//         // printf(" %d ",root->data);
//         inorder(root->left);
//         printf(" %d ",root->data);
//         inorder(root->right);
//         // printf(" %d ",root->data);
//     }
//     return;
// }

// void preorder(node* root){
//     if(root!=NULL){
//         printf(" %d ",root->data);
//         inorder(root->left);
//         // printf(" %d ",root->data);
//         inorder(root->right);
//         // printf(" %d ",root->data);
//     }
//     return;
// }

// void postorder(node* root){
//     if(root!=NULL){
//         // printf(" %d ",root->data);
//         inorder(root->left);
//         // printf(" %d ",root->data);
//         inorder(root->right);
//         printf(" %d ",root->data);
//     }
//     return;
// }

// int sum=0;

// void leaf(node* root){
//     if(root!=NULL){
//         if(root->right==NULL && root->left == NULL){
//             sum+=root->data;
//         }
//         leaf(root->left);
//         leaf(root->right);
//     }
//     return;
// }


node* insertBST(node *root,int val){
    node *nn=createNode(val);
    node *curr=root;
    node *prev=NULL;
    if (root == NULL) {
        return nn; // If the tree is empty, the new node becomes the root
    }
    while(curr != NULL){
        prev=curr;
        if(curr->data<val){
            curr=curr->right;
        }else{
            curr=curr->left;
        }
    }
    if(prev->data<val){
        prev->right=nn;
    }else{
        prev->left=nn;
    }

    return root;
}

void inorderTraversal(node* root) {
    if (root == NULL) return;
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

int main(){
    int n,val;
    system("cls");
    printf("\n Enter of Number of value to enter :  ");
    scanf("%d",&n);
    node *Root = NULL;
    for(int i=0;i<n;i++){
        printf("\n Enter = ");
        scanf("%d",&val);
        insertBST(Root,val);
    }
    inorderTraversal(Root);
    return 0;
}
