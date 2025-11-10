#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct gnode{
    int val;
    struct gnode*next;
};
typedef struct gnode node;

struct graph{
    int verticesNum;
    node **list;
};

typedef struct graph Graph;

node* createNode(int value){
    node* newNode = (node*)malloc(sizeof(node));
    newNode->val= value;
    newNode->next = NULL;
    return newNode;
}

Graph* createGraph(int numberOfVertices){
    Graph* graph =(Graph*)malloc(sizeof(Graph));
    graph->verticesNum=numberOfVertices;
    graph->list = (node**)malloc(numberOfVertices*sizeof(node*));
    for(int i = 0;i<numberOfVertices;i++){
        graph->list[i] = NULL;
    }
    return graph;
}

void addEdge(Graph *graph,int i, int j){
    node* newNode = createNode(j);
    newNode->next = graph->list[i];
    graph->list[i] = newNode;

    newNode = createNode(i);
    newNode->next = graph->list[j];
    graph->list[j] = newNode;
}

void display(Graph *graph){
    for(int i = 0;i<graph->verticesNum;i++){
        printf("[ %d ]",i);
        node* temp = graph->list[i];
        while(temp){
            printf("-> %d",temp->val);
            temp = temp->next;
        }
        printf("\n");
    }
}
int visited[10];
int top= -1;

bool wasVisited(int x){
    if(top>-1){
        for(int i = 0;i<=top;i++){
            if(x == visited[i]){
                return true;
            }
        }
    }
    return false;
}

void displayBFS(){
    printf("\n DFS Traversal : ");
    for(int i =0;i<=top;i++){
        printf("%d ",visited[i]);
    }
    printf("\n");
}


void depthFirstSearch(Graph *graph,int i){
    printf("%d",i);
    visited[++top] = i;
    node *temp = graph->list[i];

    while(temp!=NULL && wasVisited(temp->val)){
        temp = temp->next;
    }
    if(temp!= NULL){
        depthFirstSearch(graph, temp->val);
    }
    // displayBFS();
    return;
}


int main(){
    int v;
    printf("Enter no. of vertices : ");
    scanf("%d",&v);
    Graph* graph = createGraph(v);
    display(graph);
    printf("\n\n");
    addEdge(graph,0,1);
    addEdge(graph,0,4);
    addEdge(graph,1,4);
    addEdge(graph,1,2);
    addEdge(graph,2,3);
    addEdge(graph,3,4);
    display(graph);
    depthFirstSearch(graph,0);
    return 0;
}