/*Problem: Write a recursive function fib(n) to compute the n-th Fibonacci number where fib(0)=0 and fib(1)=1.

Input:
- Single integer n

Output:
- Print the n-th Fibonacci number

Example:
Input:
6

Output:
8*/

#include <stdio.h>

int fib(int n) {
    if (n==0) {   // Base case.
        return 0;
    }
    if (n==1) {  // Base case.
        return 1;
    }
    return fib(n-1) + fib(n-2);  // Recursive statement.
}
int main() {
    int n; //   It is the position of the number which the user wants to access.
    scanf("%d",&n);

    printf("%d",fib(n));  // Prints the number at position n.
    return 0;
}
