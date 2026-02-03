/*Problem: Implement linear search to find key k in an array. Count and display the number of comparisons performed.

Input:
- First line: integer n (array size)
- Second line: n space-separated integers
- Third line: integer k (key to search)

Output:
- Line 1: "Found at index i" OR "Not Found"
Line 2: "Comparisons = c"

Example:
Input:
5
10 20 30 40 50
30

Output:
Found at index 2
Comparisons = 3*/

#include <stdio.h>

int main() {
    int n;
    scanf("%d",&n); // Input size of array.

    int array[n];
    for (int i=0 ; i<n ; i++) {
        scanf("%d",&array[i]); // Input elements in elements.
    }
    int k, comparisons = 0; // comparisons variable count how many times comparisons occur.
    scanf("%d",&k); // Input the element you want to search.
    for (int j=0 ; j<n ; j++) {
        if (array[j] == k) {
            printf("Found at index %d\n",j); // Prints the index in which k is found.
        } comparisons +=1 ;
    }
    printf("Comparisons = %d",comparisons); // Prints no. of comparisons occur.
    return 0;
}
