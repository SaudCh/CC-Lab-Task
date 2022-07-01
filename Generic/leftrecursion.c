#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char terminals[50];
char alpha[50][10];
char beta[50][10];
int numRules = 0; // total number of rules
int num = 0;      // total number of recursive rules

bool chkTerminal(char alp)
{
    int i = 0;
    bool chk = false;
    for (i = 0; i < numRules; i++)
    {
        if (terminals[i] == alp)
        {
            chk = true;
            break;
        }
    }

    return chk;
}

bool chkIndirectRecursion(char t1, char t2, int ind, char rule[][10])
{
    int i = 0, j = 0;

    bool chk = false;
    for (i = ind + 1; i < numRules; i++)
    {
        if (rule[i][0] == t2)
        {
            if (rule[i][2] == t1)
            {
                chk = true;
                break;
            }
            else if (chkTerminal(rule[i][2]))
            {
                chk = chkIndirectRecursion(t1, rule[i][2], i, rule);
                if (chk)
                    break;
            }
        }
    }

    return chk;
}

int main()
{
    int i = 0, j = 0, k = 0, t, num;
    int chk = false, chk1 = false;
    char input[50][10];

    printf("Enter the number of rules: ");
    scanf("%d", &numRules);

    for (i = 0; i < numRules; i++)
    {
        printf("Rule %d: ", i + 1);
        scanf("%s", input[i]);
        terminals[i] = input[i][0];
    }
    for (i = 0; i < numRules; i++)
    {
        if (chkTerminal(input[i][2]) && input[i][0] != input[i][2])
        {
            num++;
            if (chkIndirectRecursion(input[i][0], input[i][2], i, input))
                chk = true;
        }
    }

    if (chk)
    {
        printf("Indirect recursion Found\n");
    }
    else
    {
        printf("Indirect recursion not found\n");
    }

    return 0;
}
