#include <stdio.h>
#include <string.h>

char input[100];
int i = 0;

/* Function declarations */
int E();
int EP();
int T();
int TP();
int F();

int main()
{
    printf("\nRecursive descent parsing for the following grammar\n");
    printf("\nE->TE'\nE'->+TE'/@\nT->FT'\nT'->*FT'/@\nF->(E)/a \n");

    printf("\nEnter the string to be checked: ");
    fgets(input, sizeof(input), stdin);

    // Remove newline from fgets
    input[strcspn(input, "\n")] = '\0';

    if (E())
    {
        if (input[i] == '\0')
            printf("\nString is accepted\n");
        else
            printf("\nString is not accepted\n");
    }
    else
        printf("\nString not accepted\n");

    return 0;
}

int E()
{
    if (T())
        return EP();
    return 0;
}

int EP()
{
    if (input[i] == '+')
    {
        i++;
        if (T())
            return EP();
        return 0;
    }
    return 1;  // epsilon
}

int T()
{
    if (F())
        return TP();
    return 0;
}

int TP()
{
    if (input[i] == '*')
    {
        i++;
        if (F())
            return TP();
        return 0;
    }
    return 1;  // epsilon
}

int F()
{
    if (input[i] == '(')
    {
        i++;
        if (E())
        {
            if (input[i] == ')')
            {
                i++;
                return 1;
            }
            return 0;
        }
        return 0;
    }
    else if ((input[i] >= 'a' && input[i] <= 'z') ||
             (input[i] >= 'A' && input[i] <= 'Z'))
    {
        i++;
        return 1;
    }
    return 0;
}