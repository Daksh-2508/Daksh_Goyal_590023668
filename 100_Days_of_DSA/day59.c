/*Construct a binary tree from given inorder and postorder traversal arrays.

Input Format:
- First line contains integer N
- Second line contains inorder traversal
- Third line contains postorder traversal

Output Format:
- Print preorder traversal of constructed tree

Example:
Input:
5
4 2 5 1 3
4 5 2 3 1

Output:
1 2 4 5 3 write c code for beginner*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// build tree
struct Node* build(int inorder[], int postorder[], int inStart, int inEnd, int* postIndex) {
    if (inStart > inEnd)
        return NULL;

    struct Node* root = (struct Node*)malloc(sizeof(struct Node));

    root->data = postorder[*postIndex];
    (*postIndex)--;

    root->left = root->right = NULL;

    // find root in inorder
    int i;
    for (i = inStart; i <= inEnd; i++) {
        if (inorder[i] == root->data)
            break;
    }

    // build right first, then left
    root->right = build(inorder, postorder, i + 1, inEnd, postIndex);
    root->left = build(inorder, postorder, inStart, i - 1, postIndex);

    return root;
}

// preorder traversal
void preorder(struct Node* root) {
    if (root == NULL)
        return;

    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

int main() {
    int n;
    scanf("%d", &n);

    int inorder[n], postorder[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &inorder[i]);

    for (int i = 0; i < n; i++)
        scanf("%d", &postorder[i]);

    int postIndex = n - 1;

    struct Node* root = build(inorder, postorder, 0, n - 1, &postIndex);

    preorder(root);

    return 0;
}
