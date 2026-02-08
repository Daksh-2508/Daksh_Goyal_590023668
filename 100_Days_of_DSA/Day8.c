/*Problem: Given integers a and b, compute a^b using recursion without using pow() function.

Input:
- Two space-separated integers a and b

Output:
- Print a raised to power b

Example:
Input:
2 5

Output:
32*/

#include <stdio.h>

int power(int a, int b) {
    if (b==0){   // Decreasing b till zero to get a^b.
        return 1;
    }
    return a*power(a,b-1);   
}

int main() {
    int a,b;
    scanf("%d %d",&a,&b); // Input numbers as elemeents

    printf("%d",power(a,b)); // Prints the output.
    return 0;
}
