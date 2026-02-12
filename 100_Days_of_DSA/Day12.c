/*Problem: Write a program to check whether a given matrix is symmetric. 
A matrix is said to be symmetric if it is a square matrix and is equal to its transpose (i.e., element at position [i][j] is equal to element at position [j][i] for all valid i and j).

Input:
- First line: two integers m and n representing the number of rows and columns
- Next m lines: n integers each representing the elements of the matrix

Output:
- Print "Symmetric Matrix" if the given matrix is symmetric
- Otherwise, print "Not a Symmetric Matrix"

Example:
Input:
3 3
1 2 3
2 4 5
3 5 6

Output:
Symmetric Matrix*/

#include <stdio.h>

int main() {
    int rows, columns;
    scanf("%d %d",&rows,&columns);

    if (rows!=columns) {
        printf("Error! Rows must be equal to columns.");
        return 0;
    }
    int matrix[rows][columns];

    for (int i=0 ; i<rows ; i++) {
        for (int j=0 ; j<columns ; j++) {
            scanf("%d",&matrix[i][j]);
        }
    }
    
    for (int i=0 ; i<rows ; i++) {
        for (int j=0 ; j<columns ; j++) {
            if (matrix[i][j] != matrix[j][i]) {
                printf("\nNot a Symmetric Matrix");
                return 0;
            }
        }
    }
    printf("\nSymmetric Matrix");
    return 0;   
}
