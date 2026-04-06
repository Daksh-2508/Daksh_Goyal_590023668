/*Problem: Using DFS and parent tracking, detect if undirected graph has a cycle.

Output:
- YES or NO*/

#include <stdio.h>

#define MAX 100

int adj[MAX][MAX];
int visited[MAX];
int n;

int dfs(int v, int parent) {
    visited[v] = 1;

    for(int i = 0; i < n; i++) {
        if(adj[v][i] == 1) {
            if(visited[i] == 0) {
                if(dfs(i, v))
                    return 1;
            }
            else if(i != parent) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    int edges, u, v;

    scanf("%d", &n);
    scanf("%d", &edges);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
        visited[i] = 0;
    }

    for(int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    int hasCycle = 0;

    for(int i = 0; i < n; i++) {
        if(visited[i] == 0) {
            if(dfs(i, -1)) {
                hasCycle = 1;
                break;
            }
        }
    }

    if(hasCycle)
        printf("YES");
    else
        printf("NO");

    return 0;
}
