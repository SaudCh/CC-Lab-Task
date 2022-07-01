#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char str[30];
int counter = 0;

void chkS();
void chkX();
void chkY();

int main(){
	
	printf("Enter the String: ");
	scanf("%s",str);	
	
	chkS();
	
	if(counter==strlen(str)){
		printf("Valid String");
	}else{
		printf("Invalid String");
	}
	
	return 0;
}

void S(){
	if(str[counter] == 'a'){
		counter++;
		if(strlen(str)>1){
			X();
			if(str[counter] == 'a')
				counter++;
		}else
			return;
		
	}else if(str[counter] == 'b'){
		counter++;
		if(strlen(str)>1){
			chkY();
			if(str[counter] == 'b'){
				counter++;
			}
		}else
			return;
	}
}
void chkX(){
	if(str[counter]=='b'){
		counter++;
		chkX();
	}
	
	return;
}
void chkY(){
	if(str[counter]=='a'){
		counter++;
		chkY();
	}
	
	return;
}
