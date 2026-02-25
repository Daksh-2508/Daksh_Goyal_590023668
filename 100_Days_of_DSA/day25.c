/*Problem: Count Occurrences of an Element in Linked List - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of nodes)
- Second line: n space-separated integers (linked list elements)
- Third line: integer key (element to be counted)

Output:
- Print the number of times the key appears in the linked list

Example:
Input:
6
10 20 30 20 40 20
20

Output:
3*/

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

    node *head, *temp, *newNode;

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

    int element,count = 0;
    scanf("%d",&element);

    //Count the element
    temp = head;
    while (temp != NULL) {
        if (temp->data == element) count++;
        temp = temp->next;
    }
    printf("\n%d",count);

    // Free memory
    temp = head;
    while (temp != NULL) {
        node *del = temp;
        temp = temp->next;
        free(del);
    }

    return 0;
}
