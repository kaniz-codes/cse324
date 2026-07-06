#include <stdio.h>
#include <string.h>

#define MAX 100

void displayStack(char stack[], int top) {
    for (int i = 0; i <= top; i++)
        printf("%c", stack[i]);
    printf("\t");
}

void displayInput(char input[], int pos) {
    for (int i = pos; i < strlen(input); i++)
        printf("%c", input[i]);
    printf("\n");
}

int main() {
    char stack[MAX], input[MAX];
    int top = -1, pos = 0;

    // Sample input and setup
    strcpy(input, "abba$"); // append '$' to mark end of input
    stack[++top] = '$';
    stack[++top] = 'A';     // start symbol is A

    printf("Stack\tInput\n");
    printf("-----\t-----\n");

    while (top >= 0) {
        displayStack(stack, top);
        displayInput(input, pos);

        char topSymbol = stack[top];
        char currInput = input[pos];

        // If stack top and input symbol match, pop and move input pointer
        if (topSymbol == currInput) {
            top--;
            pos++;
        }
        // Apply grammar rules based on the parsing table
        else if (topSymbol == 'A' && currInput == 'a') {
            top--;                  // pop A
            stack[++top] = 'a';     // push in reverse order: aCa
            stack[++top] = 'C';
            stack[++top] = 'a';
        }
        else if (topSymbol == 'C' && currInput == 'b') {
            top--;                  // pop C
            stack[++top] = 'C';     // push in reverse order: bC
            stack[++top] = 'b';
        }
        else if (topSymbol == 'C' && (currInput == 'a' || currInput == '$')) {
            top--; // pop C, apply epsilon production
        }
        else {
            printf("Error: Invalid input or grammar rule.\n");
            return 1;
        }
    }

    if (pos == strlen(input))
        printf("Parsing successful!\n");
    else
        printf("Error: Input not fully consumed.\n");

    return 0;
}