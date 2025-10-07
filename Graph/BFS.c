#include<stdio.h>
#include<stdlib.h>

struct gnode{
    int val;
    char alpha;
    struct gnode*next;
};

typedef struct gnode node;

struct graph{
    int verticesNum;
    char *array;
    node**list;
};
typedef struct graph Graph;

node* createNode(int value,char alphabet){
    node* newNode = (node*)malloc(sizeof(node));
    newNode->val=value;
    newNode->alpha = alphabet;
    newNode->next = NULL;
    return newNode;
}

Graph* createGraph(int NumberOfVertices){
    Graph* newGraph = (Graph*)malloc(sizeof(Graph));
    char input;
    newGraph->verticesNum = NumberOfVertices;
    newGraph->list = (node**)malloc(NumberOfVertices*sizeof(node*));
    newGraph->array = (char*)malloc(NumberOfVertices*sizeof(char));
    for(int i = 0;i<NumberOfVertices;i++){
        newGraph->list[i] = NULL;
        printf("\n Enter character for %dth vertex : ",i);
        scanf(" %c",&input);
        newGraph->array[i] = input;
    }
    return newGraph;
}

void addEdge(Graph *graph,int i,int j,char a,char b){
    node* newNode = createNode(j,b);
    if(graph->list[i]==NULL){
        graph->list[i] = newNode;
    }
    else{
        node * temp = graph->list[i];
        while(temp->next!= NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }

    newNode = createNode(i,a);
    if(graph->list[j]==NULL){
        graph->list[j] = newNode;
    }
    else{
        node * temp = graph->list[j];
        while(temp->next!= NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void display(Graph *graph) {
    for (int i = 0; i < graph->verticesNum; i++) {
        node* temp = graph->list[i];
        printf("%c ->", graph->array[i]);
        while (temp) {
            printf(" %c", temp->alpha);
            temp = temp->next;
        }
        printf("\n");
    }
}


void BFS(Graph *graph) {
    int size = graph->verticesNum;
    int queue[size], visited[size];// hash
    int front = 0, rear = 0;

    for (int i = 0; i < size; i++)
        visited[i] = 0;

    queue[rear++] = 0;
    visited[0] = 1;

    printf("\nBFS = ");
    while (front < rear) {
        int current = queue[front++];
        printf("%c ", graph->array[current]);

        node* temp = graph->list[current];
        while (temp) {
            if (!visited[temp->val]) {
                queue[rear++] = temp->val;
                visited[temp->val] = 1;
            }
            temp = temp->next;
        }
    }
}

int main(){
    int v;
    printf("Enter no. of vertices : ");
    scanf("%d",&v);
    Graph* graph = createGraph(v);
    display(graph);
    printf("\n\n");
    addEdge(graph, 0, 1, graph->array[0], graph->array[1]);
    addEdge(graph, 2, 3, graph->array[2], graph->array[3]);
    addEdge(graph, 1, 2, graph->array[1], graph->array[2]);
    addEdge(graph, 3, 4, graph->array[3], graph->array[4]);
    addEdge(graph, 0, 4, graph->array[0], graph->array[4]);
    addEdge(graph, 1, 4, graph->array[1], graph->array[4]);
    display(graph);
    BFS(graph);
    return 0;
}

