/*Problem: Write a program to find the maximum and minimum values present in a given array of integers.

Input:
- First line: integer n
- Second line: n integers

Output:
- Print the maximum and minimum elements

Example:
Input:
6
3 5 1 9 2 8

Output:
Max: 9
Min: 1*/

#include <stdio.h>

int main() {
    int n;
    scanf("%d",&n);

    int array[n];
    for (int i=0 ; i<n ; i++) {
        scanf("%d",&array[i]);
    }
    int max = array[0];
    int min = array[0];

    for (int i=0 ; i<n ; i++) {
        if (array[i]>max) {
            max = array[i];
        }
        if (array[i]<min) {
            min = array[i];
        }
    }
    printf("Max: %d\n",max);
    printf("Min: %d",min);
    return 0;
}
