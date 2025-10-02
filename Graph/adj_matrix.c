#include<stdio.h>
#include<stdlib.h>

void addEdge(int **matrix,int i,int j){
    matrix[i][j] = 1;
    matrix[j][i] = 1;
}

void display(int **matrix){
    for(int i = 0;i<5;i++){
        for(int j = 0;j<5;j++){
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int v;
    printf("\n Enter No. of Vertices : ");
    scanf("%d",&v);
    int **matrix = (int**)malloc(v*sizeof(int *));
    for(int i= 0;i<v;i++){
        matrix[i] = (int*)calloc(v,sizeof(int)); // * using calloc for assign zeroes
    }
    display(matrix);
    printf("\n\n");
    addEdge(matrix,0,1);
    addEdge(matrix,0,4);
    addEdge(matrix,1,4);
    addEdge(matrix,1,2);
    addEdge(matrix,2,3);
    addEdge(matrix,3,4);
    display(matrix);
    return 0;
}