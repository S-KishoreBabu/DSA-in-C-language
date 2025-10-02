#include<stdio.h>
#include<stdlib.h>

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
    return 0;
}