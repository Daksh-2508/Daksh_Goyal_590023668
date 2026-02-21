/*Problem: Write a program to perform addition of two matrices having the same dimensions. The sum of two matrices is obtained by adding corresponding elements of the matrices.

Input:
- First line: two integers m and n representing the number of rows and columns
- Next m lines: n integers each representing the elements of the first matrix
- Next m lines: n integers each representing the elements of the second matrix

Output:
- Print the resultant matrix after addition, with each row on a new line and elements separated by spaces

Example:
Input:
3 3
1 2 3
4 5 6
7 8 9
9 8 7
6 5 4
3 2 1

Output:
10 10 10
10 10 10
10 10 10
*/

#include <stdio.h>

int main() {
    int rows,columns;
    scanf("%d %d",&rows,&columns);

    int matrix1[rows][columns],matrix2[rows][columns];

    for (int i=0 ; i<rows ; i++) {
        for (int j=0 ; j<columns ; j++) {
            scanf("%d",&matrix1[i][j]);
        }
    }
    for (int i=0 ; i<rows ; i++) {
        for (int j=0 ; j<columns ; j++) {
            scanf("%d",&matrix2[i][j]);
        }
    }
    // Matrix Addition.
    printf("\n");
    for (int i=0 ; i<rows ; i++) {
        for (int j=0 ; j<columns ; j++) {
            printf("%d ",matrix1[i][j] + matrix2[i][j]);
        }printf("\n");
    }

    return 0;
}

