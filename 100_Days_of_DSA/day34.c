/*Problem: Evaluate Postfix Expression - Implement using linked list with dynamic memory allocation.

Input:
- Postfix expression with operands and operators

Output:
- Print the integer result

Example:
Input:
2 3 1 * + 9 -

Output:
-4

Explanation:
Use stack to store operands, apply operators by popping operands, push result back. Final stack top is result.*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

// Push operation
void push(int x) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = top;
    top = temp;
}

// Pop operation
int pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        return -1;
    }
    struct Node* temp = top;
    int value = temp->data;
    top = top->next;
    free(temp);
    return value;
}

// Evaluate postfix expression
int evaluatePostfix(char* exp) {
    int i = 0;
    
    while (exp[i] != '\0') {
        
        // If operand
        if (isdigit(exp[i])) {
            push(exp[i] - '0');
        }
        
        // If operator
        else if (exp[i]=='+' || exp[i]=='-' || exp[i]=='*' || exp[i]=='/') {
            int b = pop();
            int a = pop();
            
            switch(exp[i]) {
                case '+': push(a + b); break;
                case '-': push(a - b); break;
                case '*': push(a * b); break;
                case '/': push(a / b); break;
            }
        }
        
        i++;
    }
    
    return pop();
}

int main() {
    char exp[100];
    
    printf("Enter postfix expression: ");
    scanf("%[^\n]", exp);

    int result = evaluatePostfix(exp);
    
    printf("Result = %d\n", result);
    
    return 0;
}
