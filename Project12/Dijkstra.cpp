#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>

#define V 10 // 그래프의 정점 수
#define INF INT_MAX

// 정점을 나타내는 구조체
typedef struct Node {
    int vertex;
    int weight;
    struct Node* next;
} Node;

// 그래프를 나타내는 구조체
typedef struct Graph {
    Node* list[V];
} Graph;

void initializeGraph(Graph* graph) {
    for (int i = 0; i < V; i++) {
        graph->list[i] = NULL;
    }
}

void addEdge(Graph* graph, int src, int dest, int weight) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = dest;
    newNode->weight = weight;
    newNode->next = graph->list[src];
    graph->list[src] = newNode;

    newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = src;
    newNode->weight = weight;
    newNode->next = graph->list[dest];
    graph->list[dest] = newNode;
}

void dijkstra(Graph* graph, int src) {
    int dist[V];
    bool sptSet[V];

    for (int i = 0; i < V; i++) {
        dist[i] = INF;
        sptSet[i] = false;
    }

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int minDist = INF;
        int u;

        for (int v = 0; v < V; v++) {
            if (!sptSet[v] && dist[v] <= minDist) {
                minDist = dist[v];
                u = v;
            }
        }

        sptSet[u] = true;

        Node* current = graph->list[u];
        while (current != NULL) {
            int v = current->vertex;
            if (!sptSet[v] && dist[u] != INF && dist[u] + current->weight < dist[v]) {
                dist[v] = dist[u] + current->weight;
            }
            current = current->next;
        }
    }

    printf("Dijkstra Algorithm\nDistance: ");
    for (int i = 0; i < V; i++) {
        printf("%02d ", dist[i]);
    }
    printf("\nFound: ");
    for (int i = 0; i < V; i++) {
        printf("%d ", sptSet[i]);
    }
    printf("\n");
}

int main() {
    Graph graph;
    initializeGraph(&graph);

    addEdge(&graph, 0, 1, 3);
    addEdge(&graph, 0, 5, 11);
    addEdge(&graph, 0, 6, 12);
    addEdge(&graph, 1, 2, 5);
    addEdge(&graph, 1, 3, 4);
    addEdge(&graph, 1, 4, 1);
    addEdge(&graph, 1, 5, 7);
    addEdge(&graph, 1, 6, 8);
    addEdge(&graph, 2, 3, 2);
    addEdge(&graph, 2, 6, 6);
    addEdge(&graph, 2, 7, 5);
    addEdge(&graph, 3, 4, 13);
    addEdge(&graph, 3, 7, 14);
    addEdge(&graph, 3, 9, 16);
    addEdge(&graph, 4, 5, 9);
    addEdge(&graph, 4, 8, 18);
    addEdge(&graph, 4, 9, 17);
    addEdge(&graph, 5, 6, 9);
    addEdge(&graph, 6, 7, 13);
    addEdge(&graph, 6, 8, 13);
    addEdge(&graph, 7, 9, 15);
    addEdge(&graph, 8, 9, 10);

    dijkstra(&graph, 0);
    return 0;
}
