/*Problem: Create and Traverse Singly Linked List

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

typedef struct node{
    int data;
    struct node *next;
} node;

int main() {
    int size;
    scanf("%d",&size);

    node *head, *P;
    head = (node*)malloc(sizeof(node));
    scanf("%d",&head->data);
    head->next = NULL;

    P = head;
    for (int i=1 ; i<size ; i++) {
        P->next= (node*)malloc(sizeof(node));
        P = P->next;
        scanf("%d",&P->data);
        P->next = NULL;
    }
    P = head;
    node *temp;
    while (P != NULL) {
        temp = P;
        printf("%d ",P->data);
        P=P->next;
        free(temp);
    }
}
