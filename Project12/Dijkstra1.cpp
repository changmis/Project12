#include <stdio.h>
#include <stdbool.h>

#define INF 9999
#define V 10  // �׷����� ��� ��

int parent[V];

void dijkstra(int graph[V][V], int startNode) {
    int distance[V];
    bool found[V];

    // �ʱ�ȭ
    for (int i = 0; i < V; i++) {
        distance[i] = INF;
        found[i] = false;
        parent[i] = -1;
    }

    distance[startNode] = 0;

    for (int count = 0; count < V - 1; count++) {
        int minDistance = INF;
        int u = -1;

        // ���� MST�� ���Ե��� ���� ��� �߿��� �ּ� �Ÿ��� ���� ��带 ã��
        for (int v = 0; v < V; v++) {
            if (!found[v] && distance[v] < minDistance) {
                minDistance = distance[v];
                u = v;
            }
        }

        found[u] = true;

        // u�� ���ļ� ���� ��θ� ����Ͽ� distance[]�� ������Ʈ
        for (int v = 0; v < V; v++) {
            if (!found[v] && graph[u][v] != INF && distance[u] + graph[u][v] < distance[v]) {
                distance[v] = distance[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    printf("Dijkstra Algorithm\n");

    printf("Distance: ");
    for (int i = 0; i < V; i++) {
        if (distance[i] == INF) {
            printf("* ");
        }
        else {
            printf("%d ", distance[i]);
        }
    }
    printf("\n");

    printf("Found:    ");
    for (int i = 0; i < V; i++) {
        printf("%d ", found[i]);
    }
    printf("\n");
}

int main() {
    int graph[V][V] = {
        {0, 3, INF, INF, INF, 11, 12, INF, INF, INF},
        {3, 0, 5, 4, 1, 7, 8, INF, INF, INF},
        {INF, 5, 0, 2, INF, INF, 6, 5, INF, INF},
        {INF, 4, 2, 0, 13, INF, INF, 14, INF, 16},
        {INF, 1, INF, 13, 0, 9, INF, INF, 18, 17},
        {11, 7, INF, INF, 9, 0, INF, INF, INF, INF},
        {12, 8, 6, INF, INF, INF, 0, 13, INF, INF},
        {INF, INF, 5, 14, INF, INF, 13, 0, INF, 15},
        {INF, INF, INF, INF, 18, INF, INF, INF, 0, 10},
        {INF, INF, INF, 16, 17, INF, INF, INF, 15, 10}
    };

    int startNode = 0;
    dijkstra(graph, startNode);

    return 0;
}

