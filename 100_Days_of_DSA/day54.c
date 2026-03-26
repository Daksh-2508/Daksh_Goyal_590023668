/*Perform zigzag (spiral) level order traversal of a binary tree. 
Alternate levels should be traversed left-to-right and right-to-left.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 indicates NULL)

Output Format:
- Print traversal in zigzag order

Example:
Input:
7
1 2 3 4 5 6 7

Output:
1 3 2 4 5 6 7

Explanation:
Level 1 is printed left-to-right, level 2 right-to-left, and so on.*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Node {
    int data;
    struct Node *left, *right;
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

void zigzag(struct Node* root) {
    if (!root) return;

    struct Node* q[MAX];
    int f = 0, r = 0;

    q[r++] = root;
    int leftToRight = 1;

    while (f < r) {
        int size = r - f;
        int temp[MAX];

        for (int i = 0; i < size; i++) {
            struct Node* cur = q[f++];

            int idx = leftToRight ? i : size - 1 - i;
            temp[idx] = cur->data;

            if (cur->left) q[r++] = cur->left;
            if (cur->right) q[r++] = cur->right;
        }

        for (int i = 0; i < size; i++)
            printf("%d ", temp[i]);

        leftToRight = !leftToRight;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int a[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    struct Node* root = build(a, n);
    zigzag(root);

    return 0;
}
