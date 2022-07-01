/*

//Stack Implementation

#include <stdio.h>
#include <stdlib.h>
#define size 5

int arr[size];
int index = -1;
int top = size;

bool isEmpty(){
	if(index == -1){
		return true;
	}else{
		return false;
	}	
}

bool isFull(){
	if(index == size-1){
		return true;
	}else{
		return false;
	}
}

void push(int val){
	if(isFull()){
		return;
	}	
	
	index++;
	arr[index] = val;
	
	return;
}

int pop(){	
	int val = arr[index];
	index--;
	return val;
}

int topV(){
	return arr[index];
}

int main(){
	
	int choice = 1;
	
	while(choice != 0){
		printf("1 for isEmpty \n2 for isFull \n3 for pop \n4 for push \n5 for top \nEnter: ");
		scanf("%d",&choice);
				
		if(choice == 1){
			
			if(isEmpty()){
				printf("Stack is Empty\n");
			}else{
				printf("Stack is not Empty\n");
			}
			
		}else if(choice == 2){
			
			if(isFull()){
				printf("Stack is Full\n");
			}else{
				printf("Stack is not Full\n");
			}
			
		}else if(choice == 3){
			
			if(!isEmpty()){
				printf("Pop: %d\n",pop());	
			}else{
				printf("Stack is empty\n");
			}
			
		}else if(choice == 4){
			
			int inp;
			printf("Enter input: ");
			scanf("%d",&inp);
			if(!isFull()){
				push(inp);
			}else{
				printf("Stack is Full\n");
			}
			
		}else if(choice == 5){
			
			if(!isEmpty()){
				printf("Top value: %d\n",topV());	
			}else{
				printf("Stack is Empty\n");
			}	
			
		}
	}
	
	
	return 0;
}
*/

//POSTFIX TO INFINIX
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>  
#define SIZE 100

char stack[SIZE];
int index = -1;
char postFix[SIZE];


void push(int val){
	if(index == SIZE-1){
		printf("Stack is Full\n");
		return;
	}	
	
	index++;
	stack[index] = val;
	
	return;
}

int pop(){	
	int val = stack[index];
	index--;
	return val;
}

int topValue(){
	return stack[index];
}

bool isOperator(char ch)
{
	if(ch == '^' || ch == '/' || ch == '*' || ch == '+' || ch =='-')
		return true;	
	else
		return false;

}

int precedence(char symbol)
{
	if(symbol == '^')
	{
		return(3);
	}
	else if(symbol == '*' || symbol == '/')
	{
		return(2);
	}
	else if(symbol == '+' || symbol == '-')          
	{
		return(1);
	}
	else
	{
		return(0);
	}
}

void toPostFix(char in[SIZE]){
	int i,j = 0;
	char p;
	
	
	strcat(in,")");
	push('(');
	
	while(in[i] != '\0'){	
		if(in[i]=='('){
			push(in[i]);
		}else if(isalpha(in[i]) || isdigit(in[i])){
			postFix[j] = in[i];
			j++;
		}else if( isOperator(in[i]) ){
			
			p=pop();
			while(isOperator(p) && precedence(p)>= precedence(in[i]))
			{
				postFix[j] = p;                 
				j++;
				p = pop();                       
			}
			push(p);
			
			push(in[i]);
			
		}else if(in[i]==')'){
			p = pop();                   
			while(p != '(')               
			{
				postFix[j] = p;
				j++;
				p = pop();
			}
		}else{
			printf("Invalid Expression\n");  
			exit(0);
		}
		
		i++;
	}
	
	if(index>0)
	{
		printf("Invalid Expression\n");  
		exit(0);
	}
	
}

int main(){

	char infinix[SIZE];
	int i = 0;
	
	printf("Infix expression : ");
	scanf("%s",&infinix);

	toPostFix(infinix);
	
	printf("Postfix Expression: %s",postFix);
	
	
	return 0;
}
