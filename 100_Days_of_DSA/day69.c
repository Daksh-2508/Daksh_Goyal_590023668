/*Problem: Given weighted graph with non-negative edges, compute shortest path from source using priority queue.*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

typedef struct {
    int node, dist;
} HeapNode;

typedef struct {
    HeapNode arr[MAX * MAX];
    int size;
} MinHeap;

void swap(HeapNode *a, HeapNode *b) {
    HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

void push(MinHeap *h, int node, int dist) {
    int i = h->size++;
    h->arr[i].node = node;
    h->arr[i].dist = dist;

    while (i > 0 && h->arr[(i - 1) / 2].dist > h->arr[i].dist) {
        swap(&h->arr[i], &h->arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

HeapNode pop(MinHeap *h) {
    HeapNode root = h->arr[0];
    h->arr[0] = h->arr[--h->size];

    int i = 0;
    while (1) {
        int left = 2 * i + 1, right = 2 * i + 2, smallest = i;

        if (left < h->size && h->arr[left].dist < h->arr[smallest].dist)
            smallest = left;
        if (right < h->size && h->arr[right].dist < h->arr[smallest].dist)
            smallest = right;

        if (smallest != i) {
            swap(&h->arr[i], &h->arr[smallest]);
            i = smallest;
        } else break;
    }
    return root;
}

int graph[MAX][MAX];

void dijkstra(int n, int src) {
    int dist[MAX];
    for (int i = 0; i < n; i++) dist[i] = INT_MAX;

    MinHeap h;
    h.size = 0;

    dist[src] = 0;
    push(&h, src, 0);

    while (h.size > 0) {
        HeapNode curr = pop(&h);
        int u = curr.node;

        for (int v = 0; v < n; v++) {
            if (graph[u][v] != 0) {
                int newDist = dist[u] + graph[u][v];
                if (newDist < dist[v]) {
                    dist[v] = newDist;
                    push(&h, v, dist[v]);
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        printf("Node %d -> %d\n", i, dist[i]);
    }
}

int main() {
    int n, e;
    scanf("%d %d", &n, &e);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            graph[i][j] = 0;

    for (int i = 0; i < e; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
    }

    int src;
    scanf("%d", &src);

    dijkstra(n, src);

    return 0;
}
