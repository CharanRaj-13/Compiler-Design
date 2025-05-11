#include <stdio.h>
#include <string.h>
#include <ctype.h>

void keyword(char str[])
{
    if (strcmp("for", str) == 0 || strcmp("while", str) == 0 || strcmp("do", str) == 0 ||
        strcmp("int", str) == 0 || strcmp("float", str) == 0 || strcmp("char", str) == 0 ||
        strcmp("double", str) == 0 || strcmp("static", str) == 0 || strcmp("switch", str) == 0 ||
        strcmp("case", str) == 0 || strcmp("void", str) == 0 || strcmp("printf", str) == 0)
    {
        printf("\n%s is a keyword", str);
    }
    else
    {
        printf("\n%s is an identifier", str);
    }
}

int main()
{
    FILE *f1, *f2, *f3;
    char c, str[10];
    int num[100], lineno = 1, tokenvalue = 0, i = 0, j = 0, k = 0;

    printf("\nEnter the C program (Press Ctrl+D to finish input):\n");
    f1 = fopen("input.txt", "w");
    while ((c = getchar()) != EOF)
    {
        putc(c, f1);
    }
    fclose(f1);

    f1 = fopen("input.txt", "r");
    f2 = fopen("identifiers.txt", "w");
    f3 = fopen("specialchars.txt", "w");

    while ((c = getc(f1)) != EOF)
    {
        if (isdigit(c))
        {
            tokenvalue = c - '0';
            while (isdigit(c = getc(f1)))
            {
                tokenvalue = tokenvalue * 10 + (c - '0');
            }
            num[i++] = tokenvalue;
            ungetc(c, f1);
        }
        else if (isalpha(c))
        {
            str[k++] = c;
            while (isalnum(c = getc(f1)) || c == '_' || c == '$')
            {
                str[k++] = c;
            }
            str[k] = '\0';
            fputs(str, f2);
            fputc(' ', f2);
            keyword(str);
            k = 0;
            ungetc(c, f1);
        }
        else if (c == '\n')
            lineno++;
        else if (!isspace(c))
        {
            putc(c, f3);
        }
    }
    fclose(f2);
    fclose(f3);
    fclose(f1);

    printf("\n Numers in the program: ");
    for (j = 0; j < i; j++)
    {
        printf("%d", num[j]);
    }
    printf("\n Total Number of Lines : %d", lineno);
    return 0;
}