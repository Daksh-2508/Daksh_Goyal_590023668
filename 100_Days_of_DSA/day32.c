/*Problem: Implement push and pop operations on a stack and verify stack operations.

Input:
- First line: integer n
- Second line: n integers to push
- Third line: integer m (number of pops)

Output:
- Print remaining stack elements from top to bottom

Example:
Input:
5
10 20 30 40 50
2

Output:
30 20 10*/

#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

int main() {
    int n, m, i, value;

    // number of elements to push
    scanf("%d", &n);

    // push elements
    for(i = 0; i < n; i++) {
        scanf("%d", &value);
        top++;
        stack[top] = value;
    }

    // number of pops
    scanf("%d", &m);

    // pop elements
    for(i = 0; i < m; i++) {
        if(top == -1) {
            printf("Stack Underflow\n");
            return 0;
        }
        top--;
    }

    // display remaining stack from top to bottom
    for(i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }

    return 0;
}
