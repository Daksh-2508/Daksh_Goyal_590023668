/*Problem: Delete First Occurrence of a Key - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers
- Third line: integer key

Output:
- Print the linked list elements after deletion, space-separated

Example:
Input:
5
10 20 30 40 50
30

Output:
10 20 40 50*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

int main() {
    node *head,*temp,*newNode;

    int n;
    scanf("%d", &n);

    if (n <= 0) {
        return 0;
    }

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
    int key;
    scanf("%d",&key);

    temp = head;
    while (temp!=NULL) {
        if (temp->next->data == key) {
            temp->next = temp->next->next;
            break;
        }
        temp = temp->next;
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
