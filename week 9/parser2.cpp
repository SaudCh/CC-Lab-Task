#include<stdio.h>
#include<string.h>
int count = 0;

int E(char str[]);
int EPrime(char str[]);
int T(char str[]);
int TPrime(char str[]);
int F(char str[]);
int identifier(char var[]);
int number(char num[20]);

int main()
{
    char str[20];
    printf("Enter a String: ");
    scanf("%s",&str);
    E(str);
    int len = strlen(str);
    if (count == len){
        printf("Your string is valid!");
    }
    else{
        printf("Your string is not valid!");
    }
}

int E(char str[])
{
    T(str);
    EPrime(str);

}

int EPrime(char str[])
{
    if (str[count]=='+' || str[count]=='-')
    {
        count++;
        T(str);
        EPrime(str);
    }
    else if(str[count]=='@')
    {

    }
}

int T(char str[])
{
    F(str);
    TPrime(str);

}

int TPrime(char str[])
{
     if (str[count]=='*' || str[count]=='/')
    {
        count++;
        F(str);
        TPrime(str);
    }
    else if(str[count]=='@')
    {

    }
}

int F(char str[])
{
    return (identifier(str) || number(str));
}

int identifier(char var[])
{
    int flag = 0;
    if ((var[count]>=65 && var[count]<=90) || (var[count]>=97 && var[count]<=122))
    {
        flag = 1;
        count++;
    }
    return flag;
}

int number(char num[20])
{
    int flag;
    if (num[count]>='0' && num[count]<='9')
    {
        flag = 1;
        count++;
    }
    return flag;
}
