// 미해결
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct _Vertex{
    int index;
    struct _Vertex *next;
}Vertex;

typedef struct _Graph{
    int size;
    Vertex **heads;
}Graph;

// 문제 특성상 정점이 1부터 시작하기 때문에 1-based index로 구성
Graph* createGraph(int size){
    Graph* newGraph = (Graph*)malloc(sizeof(Graph*));
    newGraph->heads = (Vertex**)malloc(sizeof(Vertex*)*size);
    newGraph->size = size;
    for(int i = 1; i <= size; i++){
        newGraph->heads[i] = (Vertex*)malloc(sizeof(Vertex));
        newGraph->heads[i]->next = NULL;
        newGraph->heads[i]->index = i;
    }
    return newGraph;
}

void removeGraph(Graph *graph){
    Vertex *tmp;
    for(int i = 0; i < graph->size; i++){
        while (graph->heads[i] != NULL) {
            tmp = graph->heads[i];
            graph->heads[i] = graph->heads[i]->next;
            free(tmp);
        }
    }
    free(graph->heads);
    free(graph);
}

void appendVertex(Vertex *head, int index){
    Vertex *adj = (Vertex*)malloc(sizeof(Vertex));
    adj->index = index;
    adj->next = head->next;
    head->next = adj;
}

void addEdge(Graph *graph, int u, int v){
    appendVertex(graph->heads[u], v);
    appendVertex(graph->heads[v], u);
}

void printGraph(Graph *graph) {
  Vertex *travel;
  for (int i = 1; i <= graph->size; i ++) {
    printf("Vertex(%d): ", i);
    travel = graph->heads[i]->next;
    while (travel != NULL) {
      printf("-> %d ", travel->index);
      travel = travel->next;
    }
    printf("\n");
  }
}

void dfs(Graph* graph, int *isvisit, int start){
    isvisit[start] = true;
    printf("%d ", graph->heads[start]->index);
    Vertex *travel = graph->heads[start]->next;
    while(travel != NULL){
        if(!isvisit[travel->index])
            dfs(graph, isvisit, travel->index);
        travel = (travel->next != NULL) ? travel->next : travel;
    }
}

int main(){
    int vertex, edges, start;
    int v1, v2;
    scanf("%d %d %d", &vertex, &edges, &start);
    Graph *g = createGraph(vertex);

    for(int i = 0; i < edges; i++){
        scanf("%d %d", &v1, &v2);
        addEdge(g, v1, v2);
    }

    int* isVisit = (int*)malloc(sizeof(int)*vertex);
    dfs(g, isVisit, start);

    removeGraph(g);
    free(isVisit);
    return 0;
}