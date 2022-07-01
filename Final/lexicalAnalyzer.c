#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

char keywords[14][10] = {"if", "while", "int", "float", "for", "else", "do", "switch", "stdio", "include", "goto", "break", "printf", "scanf"};
char operators[12][10] = {"==", "<=", ">=", "<", ">", "!=", "+", "-", "*", "/", "%", "="};

void removeComments(FILE *fptr, char str[10])
{
    char c;
    bool chk = true;

    if (strcmp(str, "//") == 0)
    {
        c = fgetc(fptr);
        while (c != '\n')
        {
            c = fgetc(fptr);
        }
    }

    if (strcmp(str, "/*") == 0)
    {
        c = fgetc(fptr);
        while (chk)
        {
            if (c == '*')
            {
                c = fgetc(fptr);
                if (c == '/')
                {
                    chk = false;
                }
            }
            else
            {
                c = fgetc(fptr);
            }
        }
    }
}

bool chkKeyword(FILE *fptr, char str[10])
{
    bool flag = false;
    for (int i = 0; i < 14; i++)
    {
        if (strcmp(str, keywords[i]) == 0)
        {
            flag = true;
            break;
        }
    }

    return flag;
}

bool chkoperators(char str[10])
{
    bool flag = false;
    for (int i = 0; i < 12; i++)
    {
        if (strcmp(str, operators[i]) == 0)
        {
            flag = true;
            break;
        }
    }

    return flag;
}

bool chkVariable(char str[10])
{
    bool flag = true;
    int len = strlen(str);
    if (str[0] == '_' || (str[0] >= 'a' && str[0] <= 'z') || (str[0] >= 'A' && str[0] <= 'Z'))
    {

        for (int i = 1; i < strlen(str); i++)
        {
            if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= '0' && str[i] <= '9'))
            {
            }
            else
            {
                flag = false;
            }
        }

        if (!(str[len - 1] >= '0' && str[len - 1] <= '9'))
        {
            flag = false;
        }
    }
    else
    {
        flag = false;
        return flag;
    }

    return flag;
}

bool chkDigits(char str[10])
{

    bool flag = false;
    int i = 0;
    int j = 0;

    if ((str[0] >= '0' && str[0] <= '9'))
    {

        for (i = 1; i < strlen(str); i++)
        {
            if ((str[i] >= '0' && str[i] <= '9'))
            {
            }
            else if (str[i] == '.')
            {

                for (j = i + 1; j < strlen(str); j++)
                {
                    if ((str[j] >= '0' && str[j] <= '9'))
                    {
                    }
                    else
                    {
                        flag = false;
                    }
                }
                i = j;
            }
            else if (str[i] == 'e' || str[i] == 'E')
            {
                i = i + 1;
                if (str[i] == '+' || str[i] == '-')
                {

                    for (j = i + 1; j < strlen(str); j++)
                    {
                        if ((str[j] >= '0' && str[j] <= '9'))
                        {
                        }
                        else
                        {
                            flag = false;
                        }
                    }
                    i = j;
                }
                else
                {
                    flag = false;
                }
            }
            else
            {
                flag = false;
            }
        }
    }
    else
    {
        flag = false;
        return flag;
    }

    return flag;
}

int main()
{
    char str[10];
    FILE *fptr;

    fptr = fopen("./input.txt", "a+");
    if (fptr == NULL)
    {
        printf("Error opening file");
    }

    while (fscanf(fptr, "%s", str) != EOF)
    {
        removeComments(fptr, str);

        if (chkKeyword(fptr, str))
        {
            printf("keyword %s\n", str);
        }
        else if (chkVariable(str))
        {
            printf("Variable %s\n", str);
        }
        else if (chkoperators(str))
        {
            printf("Operators %s\n", str);
        }
        else if (chkDigits(str))
        {
            printf("Digits %s\n", str);
        }
        else
        {
            printf("Special Character %s\n", str);
        }
    }

    return 0;
}