/*Problem: Count Nodes in Linked List

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the result

Example:
Input:
5
10 20 30 40 50

Output:
10 20 30 40 50*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

int main() {
    int n;
    scanf("%d", &n);

    if (n <= 0) {
        return 0;
    }

    node *head = NULL;
    node *temp = NULL;
    node *newNode = NULL;

    // Create first node
    head = (node*)malloc(sizeof(node));
    scanf("%d", &head->data);
    head->next = NULL;

    temp = head;

    // Create remaining nodes
    for (int i = 1; i < n; i++) {
        newNode = (node*)malloc(sizeof(node));
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        temp->next = newNode;
        temp = newNode;
    }

    // Print linked list
    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    // Free memory
    temp = head;
    while (temp != NULL) {
        node *del = temp;
        temp = temp->next;
        free(del);
    }

    return 0;
}
