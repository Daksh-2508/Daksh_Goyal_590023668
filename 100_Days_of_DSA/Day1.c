/*Insert an Element in an Array

Problem: Write a C program to insert an element x at a given 1-based position pos in an array of n integers. Shift existing elements to the right to make space.

Input:
- First line: integer n
- Second line: n space-separated integers (the array)
- Third line: integer pos (1-based position)
- Fourth line: integer x (element to insert)

Output:
- Print the updated array (n+1 integers) in a single line, space-separated.*/

#include <stdio.h>

int main() {
    int n; // n= size of array.
    scanf("%d",&n);

    int array[n];  // Declare array of size n.
    for (int i=0 ; i<n ; i++) {
        scanf("%d",&array[i]);
    }

    int pos,x;  // Declare position (1-based) in which element is inserted and the element that is to be inserted.
    scanf("%d",&pos);
    scanf("%d",&x);

    array[n+1];  // Change the size of array from n to n+1.

    for (int i=n+1 ; i>(pos-1) ; i--) {  // Right shift the element from (pos-1) to n. to insert an element.
        array[i] = array[i-1];
    }
    array[pos-1] = x;  // Insert element at position pos(1- based) i.e at (pos-1) position.
    
    for (int i=0 ; i<n+1 ; i++) { // Prints the new array.
        printf("%d ",array[i]);
    }
    
    return 0;
}
