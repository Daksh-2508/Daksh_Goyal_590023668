/*roblem: Find Intersection Point of Two Linked Lists - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers (first list)
- Third line: integer m
- Fourth line: m space-separated integers (second list)

Output:
- Print value of intersection node or 'No Intersection'

Example:
Input:
5
10 20 30 40 50
4
15 25 30 40 50

Output:
30*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n, m, i, value;

    struct Node *head1 = NULL, *head2 = NULL;
    struct Node *temp, *newNode;

    // First list
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        if (head1 == NULL) {
            head1 = newNode;
        } else {
            temp = head1;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
    }

    // Second list
    scanf("%d", &m);
    for (i = 0; i < m; i++) {
        scanf("%d", &value);

        // Check if this value exists in first list
        temp = head1;
        struct Node* match = NULL;

        while (temp != NULL) {
            if (temp->data == value) {
                match = temp;
                break;
            }
            temp = temp->next;
        }

        if (match != NULL) {
            head2 = match;  // Create intersection
            break;
        }

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        if (head2 == NULL) {
            head2 = newNode;
        } else {
            temp = head2;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
    }

    // Find lengths
    int len1 = 0, len2 = 0;
    temp = head1;
    while (temp != NULL) {
        len1++;
        temp = temp->next;
    }

    temp = head2;
    while (temp != NULL) {
        len2++;
        temp = temp->next;
    }

    // Move longer list ahead
    struct Node *p1 = head1, *p2 = head2;
    int diff = abs(len1 - len2);

    if (len1 > len2) {
        for (i = 0; i < diff; i++)
            p1 = p1->next;
    } else {
        for (i = 0; i < diff; i++)
            p2 = p2->next;
    }

    // Traverse together
    while (p1 != NULL && p2 != NULL) {
        if (p1 == p2) {
            printf("%d\n", p1->data);
            return 0;
        }
        p1 = p1->next;
        p2 = p2->next;
    }

    printf("No Intersection\n");

    return 0;
}
