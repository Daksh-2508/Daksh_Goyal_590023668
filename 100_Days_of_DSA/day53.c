/*Given a binary tree, print its vertical order traversal. 
Nodes that lie on the same vertical line should be printed together from top to bottom and from left to right.

Input Format:
- First line contains integer N (number of nodes)
- Second line contains N space-separated integers representing level-order traversal (-1 indicates NULL)

Output Format:
- Print nodes column by column from leftmost to rightmost vertical line

Example:
Input:
7
1 2 3 4 5 6 7

Output:
4
2
1 5 6
3
7

Explanation:
Vertical lines are formed based on horizontal distance from root. Nodes sharing the same distance are printed together.*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Node {
    int data;
    struct Node *left, *right;
};

struct QNode {
    struct Node* node;
    int hd;
};

struct Node* newNode(int data) {
    struct Node* t = (struct Node*)malloc(sizeof(struct Node));
    t->data = data;
    t->left = t->right = NULL;
    return t;
}

struct Node* build(int a[], int n) {
    if (n == 0 || a[0] == -1) return NULL;

    struct Node* root = newNode(a[0]);
    struct Node* q[MAX];
    int f = 0, r = 0;

    q[r++] = root;
    int i = 1;

    while (i < n) {
        struct Node* cur = q[f++];

        if (a[i] != -1)
            q[r++] = cur->left = newNode(a[i]);
        i++;

        if (i < n && a[i] != -1)
            q[r++] = cur->right = newNode(a[i]);
        i++;
    }
    return root;
}

void vertical(struct Node* root) {
    struct QNode q[MAX];
    int f = 0, r = 0;

    int res[200][MAX] = {0}, cnt[200] = {0};
    int off = 100;

    q[r++] = (struct QNode){root, 0};

    while (f < r) {
        struct QNode t = q[f++];
        int idx = t.hd + off;

        res[idx][cnt[idx]++] = t.node->data;

        if (t.node->left)
            q[r++] = (struct QNode){t.node->left, t.hd - 1};
        if (t.node->right)
            q[r++] = (struct QNode){t.node->right, t.hd + 1};
    }

    for (int i = 0; i < 200; i++) {
        if (cnt[i]) {
            for (int j = 0; j < cnt[i]; j++)
                printf("%d ", res[i][j]);
            printf("\n");
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int a[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    struct Node* root = build(a, n);
    vertical(root);

    return 0;
}
