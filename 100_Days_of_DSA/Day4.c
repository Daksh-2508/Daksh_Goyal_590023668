/*Problem: Given an array of n integers, reverse the array in-place using two-pointer approach.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the reversed array, space-separated

Example:
Input:
5
1 2 3 4 5

Output:
5 4 3 2 1
*/

#include <stdio.h>

int main() {
    int n;
    scanf("%d",&n);  // Input hte size of array.

    int array[n];
    for (int i=0 ; i<n ; i++) {
        scanf("%d",&array[i]); // Input the elements by the user in the array.
    }
    int *left = array;  // points to the first element.
    int *right = array + n - 1; // Points to the last element.

    while (left < right) {
        int temp = *left;  // Swaps the pair (1,5) and (2,4) for the input mention above.
        *left = *right;
        *right = temp;

        left++;
        right--;
    }
    for (int i=0 ; i<n ; i++) {
        printf("\n%d ",array[i]); // Prints your new reverse array.
    }
    return 0;
}
