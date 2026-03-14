/*Problem Statement:
Given a queue of integers, reverse the queue using a stack.

Input Format:
- First line contains integer N
- Second line contains N space-separated integers

Output Format:
- Print the reversed queue

Example:
Input:
5
10 20 30 40 50

Output:
50 40 30 20 10*/

#include <stdio.h>

#define MAX 100

int main() {
    int queue[MAX], stack[MAX];
    int n, i, top = -1;

    // Input size of queue
    scanf("%d", &n);

    // Input queue elements
    for(i = 0; i < n; i++) {
        scanf("%d", &queue[i]);
    }

    // Push queue elements into stack
    for(i = 0; i < n; i++) {
        stack[++top] = queue[i];
    }

    // Pop elements from stack (reversed order)
    while(top >= 0) {
        printf("%d ", stack[top--]);
    }

    return 0;
}
