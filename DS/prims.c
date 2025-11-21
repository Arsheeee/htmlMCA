#include <stdio.h>

#define INF 9999
#define MAX 20

int main() {
    int n;
    int graph[MAX][MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix (enter 0 for no edge):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
            if (graph[i][j] == 0)
                graph[i][j] = INF;  // no edge = INF
        }
    }

    int selected[MAX] = {0};
    selected[0] = 1;   // start from vertex 0

    int edges = 0;
    int totalCost = 0;

    printf("\nEdges in Minimum Spanning Tree:\n");

    while (edges < n - 1) {
        int min = INF;
        int x = -1, y = -1;

        // find the smallest edge connecting selected → unselected
        for (int i = 0; i < n; i++) {
            if (selected[i]) { 
                for (int j = 0; j < n; j++) {
                    if (!selected[j] && graph[i][j] < min) {
                        min = graph[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
        }

        printf("%d -- %d  (cost = %d)\n", x, y, graph[x][y]);
        totalCost += graph[x][y];
        selected[y] = 1;
        edges++;
    }

    printf("\nTotal Cost of MST = %d\n", totalCost);

    return 0;
}