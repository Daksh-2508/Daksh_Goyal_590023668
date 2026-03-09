/*Problem: Circular Queue Using Array - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of elements to enqueue)
- Second line: n space-separated integers
- Third line: integer m (number of dequeue operations)

Output:
- Print queue elements from front to rear after operations, space-separated

Example:
Input:
5
10 20 30 40 50
2

Output:
30 40 50 10 20
*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int main()
{
    struct node *front = NULL, *rear = NULL, *temp, *newnode;
    int n, m, x, i;

    scanf("%d", &n);

    // Enqueue elements
    for(i = 0; i < n; i++)
    {
        scanf("%d", &x);

        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = x;
        newnode->next = NULL;

        if(front == NULL)
        {
            front = rear = newnode;
            rear->next = front;
        }
        else
        {
            rear->next = newnode;
            rear = newnode;
            rear->next = front;
        }
    }

    scanf("%d", &m);

    // Dequeue operations
    for(i = 0; i < m; i++)
    {
        if(front != NULL)
        {
            temp = front;
            front = front->next;
            rear->next = front;
            free(temp);
        }
    }

    // Display queue
    temp = front;
    for(i = 0; i < n; i++)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}
