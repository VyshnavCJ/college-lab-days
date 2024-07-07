// Construct a Shift Reduce Parser for a given language.

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char a[10], stk[10];
int i = 0, j = 0, z = 0, c;

void check()
{
    for (z = 0; z < c - 1; z++)
    {
        if (stk[z] == 'i' && stk[z + 1] == 'd')
        {
            printf("Reduce to E=id\n");
            stk[z] = 'E';
            stk[z + 1] = '\0';
            j++;
            printf("\n$%s\t%s$", stk, a);
        }
    }
    for (z = 0; z < c - 2; z++)
    {
        if (stk[z] =='E' && stk[z + 1] == '+' && stk[z + 2] == 'E')
        {
            printf("Reduce to E=E+E\n");
            stk[z] = 'E';
            stk[z + 1] = '\0';
            stk[z + 2] = '\0';
            i = i - 2;
            printf("\n$%s\t%s$", stk, a);
        }
    }
    for (z = 0; z < c - 2; z++)
    {
        if (stk[z] == 'E' && stk[z + 1] == '*' && stk[z + 2] == 'E')
        {
            printf("Reduce to E=E*E\n");
            stk[z] = 'E';
            stk[z + 1] = '\0';
            stk[z + 2] = '\0';
            i = i - 2;
            printf("\n$%s\t%s$", stk, a);
        }
    }
    for (z = 0; z < c - 2; z++)
    {
        if (stk[z] == '(' && stk[z + 1] == 'E' && stk[z + 2] == ')')
        {
            printf("Reduce to E=(E)\n");
            stk[z] = 'E';
            stk[z + 1] = '\0';
            stk[z + 2] = '\0';
            i = i - 2;
            printf("\n$%s\t%s$", stk, a);
        }
    }
}

int main()
{
    printf("Grammar is \nE=E+E\nE=E*E\nE=(E)\nE=id");
    printf("\nEnter the input string: ");
    scanf("%s", a);
    c = strlen(a);
    printf("\nStack\tInput\tAction");
    printf("\n$\t%s$\t", a);
    for (i = 0; j < c; i++, j++)
    {

        printf("shift");

        if (a[j] == 'i' && a[j + 1] == 'd')
        {
            stk[i] = a[j];
            stk[i + 1] = a[j + 1];
            stk[i + 2] = '\0';
            a[j] = ' ';
            a[j + 1] = ' ';
        }
        else
        {
            stk[i] = a[j];
            stk[i + 1] = '\0';
            a[j] = ' ';
        }
        printf("\n$%s\t%s$\t", stk, a);
        check();
    }
    check();

    if (stk[0] == 'E' && stk[1] == '\0')
    {
        printf("\nInput Accepted!");
    }
    else
    {
        printf("\nInput Rejected!");
    }
    return 0;
}
