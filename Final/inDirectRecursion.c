#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define max 50

int numRules = 0;
char rules[50][10] = {"E->E+T|a ", "T->T*F|Fc", "F->Ft|Cf", "C->F*C|D", "D->D/F|/F"};
char terminals[50];

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
            if (rule[i][3] == t1)
            {
                chk = true;
                printf("%s\n", rule[i]);
                break;
            }
            else if (chkTerminal(rule[i][3]))
            {
                chk = chkIndirectRecursion(t1, rule[i][3], i, rule);
                if (chk)
                    break;
            }
        }
    }

    return chk;
}

int main()
{
    int i = 0, j = 0, k = 0;
    bool chk = false;
    char newRules[50][10];

    while (rules[i][0] != '\0')
    {
        terminals[i] = rules[i][0];
        strcpy(newRules[numRules], rules[i]);

        while (rules[i][j] != '\0')
        {
            if (rules[i][j] == '|')
            {
                numRules++;
                newRules[numRules][0] = rules[i][0];
                newRules[numRules][1] = '-';
                newRules[numRules][2] = '>';
                k = 3;

                chk = true;
            }

            if (chk && rules[i][j] != '|')
            {
                newRules[numRules][k] = rules[i][j];

                k++;
            }
            j++;
        }

        k = 0;
        j = 0;
        chk = false;
        numRules++;
        i++;
    }

    printf("Rules with Indirect Recursion: \n");
    for (i = 0; i < numRules; i++)
    {
        if (chkTerminal(newRules[i][3]) && newRules[i][0] != newRules[i][3])
        {
            if (chkIndirectRecursion(newRules[i][0], newRules[i][3], i, newRules))
            {
                chk = true;
                printf("%s \n", newRules[i]);
            }
        }
    }

    if(!chk){
        printf("No Indirect Recursion Found\n");
    }

    return 0;
}
