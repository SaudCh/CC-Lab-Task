#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int rules = 3;

bool chkTerminal (char T1,char terminal[3]){
	bool flag = true;
	
	for(int i=0;i<rules;i++){
		if(T1==terminal[i]){
			flag = false;
		}
	}
	
	return flag;
	
}

char getFirst (char T1,char terminal[3],char rule[3][10]) {
	for(int i = 0;i<rules;i++){
		if(T1==rule[i][0]){
			if(chkTerminal(rule[i][2],terminal)){
				return rule[i][2];
			}
			
		}
	}
}

int main(){

	char rule[rules][10] = {"S=AB","A=a","B=b"};
	char terminal[rules];
	char first[rules];
	
	for(int i=0;i<rules;i++){
		terminal[i] = rule[i][0];
	}

	for(int i=0;i<rules;i++){
		if(chkTerminal(rule[i][2],terminal)){
			first[i] = rule[i][2];
		}else{
			first[i] = getFirst(rule[i][2],terminal,rule);
		}
	}
	
	for(int i=0;i<rules;i++){
		printf("First of %c is %c\n",terminal[i],first[i]);
	}
		
	return 0;
}
