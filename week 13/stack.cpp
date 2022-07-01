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
