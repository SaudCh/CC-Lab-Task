#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char alpha[50][10];
char beta[50][10];
int numRules = 0; // total number of rules
int num = 0;      // total number of recursive rules

void getAlpha(int ind, char rule[][10])
{
    int j = 3;
    bool betaChk = true;
    int a = 0;
    int b = 0;

    while (rule[ind][j] != '\0')
    {

        if (rule[ind][j] == '|')
            betaChk = false;

        if (rule[ind][j] != '|')
        {
            if (betaChk)
            {
                alpha[ind][a] = rule[ind][j];
                a++;
            }
            else
            {
                beta[ind][b] = rule[ind][j];
                b++;
            }
        }

        j++;
    }
}

int main()
{
    int i = 0;

    printf("Enter the number of rules: ");
    scanf("%d", &numRules);

    char input[numRules][10];

    for (i = 0; i < numRules; i++)
    {
        printf("Rule %d: ", i + 1);
        scanf("%s", input[i]);
    }

    for (i = 0; i < numRules; i++)
    {
        if (input[i][0] == input[i][2])
        {
            num++;
            getAlpha(i, input);
        }
    }

    for (i = 0; i < num; i++)
    {
        printf("%c = %s%c' \n", input[i][0], beta[i], input[i][0]);
        printf("%c' = %s%c' | episilon \n", input[i][0], alpha[i], input[i][0]);
    }

    return 0;
}
