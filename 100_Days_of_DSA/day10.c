/*Problem: Read a string and check if it is a palindrome using two-pointer comparison.

Input:
- Single line: string s

Output:
- Print YES if palindrome, otherwise NO

Example:
Input:
level

Output:
YES*/

#include <stdio.h>
#include <string.h>

int main() {
    char str[100],reverse[100];
    scanf("%s",str); // Input the string by the user.
 
    strcpy(reverse,str); // Copy the data of str in reverse
    int start = 0;
    int end = strlen(str)-1;
    printf("%d\n",end);

    

    while (start<end) {  // Reverse your str string to compare it with original.
        char temp = reverse[start];
        reverse[start] = reverse[end];
        reverse[end] = temp;

        start++;
        end--;
    }
    if (strcmp(str,reverse) == 0) { // if str and reverse are equal menas string is a palindrome otherwise no.
        printf("YES");
    }
    else {
        printf("NO");
    }
    return 0;
}
