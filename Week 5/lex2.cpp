#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

bool isKeyword(char* str)
{
	if (!strcmp(str, "if") || !strcmp(str, "else") ||
		!strcmp(str, "while") || !strcmp(str, "do") ||
		!strcmp(str, "break") ||
		!strcmp(str, "continue") || !strcmp(str, "int")
		|| !strcmp(str, "double") || !strcmp(str, "float")
		|| !strcmp(str, "return") || !strcmp(str, "char")
		|| !strcmp(str, "case") || !strcmp(str, "char")
		|| !strcmp(str, "sizeof") || !strcmp(str, "long")
		|| !strcmp(str, "short") || !strcmp(str, "typedef")
		|| !strcmp(str, "switch") || !strcmp(str, "unsigned")
		|| !strcmp(str, "void") || !strcmp(str, "static")
		|| !strcmp(str, "struct") || !strcmp(str, "goto"))
		return (true);
	return (false);
}

bool isIdentifier(char* str)
{
	int flag = 0;
	
	if(str[0]=='_'|| (str[0] >= 'a' && str[0] <= 'z') || (str[0] >= 'A' && str[0] <= 'Z')){
		
		for(int i = 1;i<strlen(str);i++){
    		if(str[i]=='_'|| (str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z' ) || (str[i] >= '0' && str[i] <= '9' )){
    		
			}else{
				return false;
			}		
		}
	}else{
		return false;
	}
    	
    return true;
}

bool isOperator(char ch)
{
	if (ch == '+' || ch == '-' || ch == '*' ||
		ch == '/' || ch == '>' || ch == '<' ||
		ch == '=')
		return (true);
	return (false);
}

void parse(char* str)
{
	if(isKeyword(str))
		printf("%s		keyword \n",str);
	else{
		if(isIdentifier(str))
			printf("%s		identifier \n",str);
		else{
			if(isOperator(str[0]))
				printf("%s		Operator \n",str);
		}
			
	}
}

int main()
{
	char str[10];
	FILE *fptr;

	fptr = fopen("./input.txt","a+");
	if(fptr == NULL){
		printf("Error");
	}
	
	while(fscanf(fptr,"%s",str)!=EOF){
		parse(str);
	}
	
	return (0);
}

