/*Problem: Merge Two Sorted Linked Lists - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers (first list)
- Third line: integer m
- Fourth line: m space-separated integers (second list)

Output:
- Print the merged linked list elements, space-separated

Example:
Input:
5
10 20 30 40 50
4
15 25 35 45

Output:
10 15 20 25 30 35 40 45 50*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

int main() {
    int n, m;
    node *head1 = NULL, *head2 = NULL;
    node *temp, *newNode;

    /* First list */
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        newNode = (node*)malloc(sizeof(node));
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if (head1 == NULL) {
            head1 = newNode;
            temp = newNode;
        }
        else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    /* Second list */
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        newNode = (node*)malloc(sizeof(node));
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if (head2 == NULL) {
            head2 = newNode;
            temp = newNode;
        }
        else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    /* Merge */
    node *merged = NULL, *last = NULL;

    while (head1 != NULL && head2 != NULL) {
        if (head1->data < head2->data) {
            newNode = head1;
            head1 = head1->next;
        } else {
            newNode = head2;
            head2 = head2->next;
        }

        if (merged == NULL)
            merged = last = newNode;
        else {
            last->next = newNode;
            last = newNode;
        }
    }

    if (head1 != NULL)
        last->next = head1;
    else if (head2 != NULL)
        last->next = head2;

    /* Print */
    temp = merged;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}

