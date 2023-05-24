#include <stdio.h>

#define INF 99999
#define V 5 // 정점의 수

void allPairShortestPath(int graph[][V]) {
    int dist[V][V];
    int i, j, k;

    // 초기 거리 행렬 설정
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            dist[i][j] = graph[i][j];
        }
    }

    // 모든 정점들을 경유하여 최단 거리를 갱신
    for (k = 0; k < V; k++) {
        for (i = 0; i < V; i++) {
            for (j = 0; j < V; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // 결과 출력
    printf("도시 간 최단 거리:\n");
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            if (dist[i][j] == INF) {
                printf("%-5s", "INF");
            }
            else {
                printf("%-5d", dist[i][j]);
            }
        }
        printf("\n");
    }
}

int main() {
    int graph[V][V] = {
      {0, 4, 2, 5, INF},
      {INF, 0, 1, INF, 4},
      {1, 3, 0, 1, 2},
      {-2, INF, INF, 0, 2},
      {INF, -3, 3, 1, 0}
    };

    allPairShortestPath(graph);

    return 0;
}
