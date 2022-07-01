#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int numRules = 5;
char rules[5][10] = {"E->E+T|a ", "T->T*F|Fc", "F->Ft|Cf", "C->F*C|D", "D->D/F|/F"};

void getAlphaBeta(int ind)
{
    char alpha[10];
    char beta[10];
    bool chk = false;
    int j = 4, a = 0, b = 0;

    while (rules[ind][j] != '\0')
    {

        if (rules[ind][j] == '|')
            chk = true;

        if (rules[ind][j] != '|')
        {
            if (!chk)
            {
                alpha[a] = rules[ind][j];
                a++;
            }
            else
            {
                beta[b] = rules[ind][j];
                b++;
            }
        }

        j++;
    }

    printf("%c = %s%c' \n", rules[ind][0], beta, rules[ind][0]);
    printf("%c' = %s%c' | episilon \n", rules[ind][0], alpha, rules[ind][0]);
}

int main()
{
    int i = 0, j = 0, k = 0;
    bool chk = false;

    for (i = 0; i < numRules; i++)
    {
        if (rules[i][0] == rules[i][3])
        {
            getAlphaBeta(i);
        }
    }

    return 0;
}
