#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#define rules 4


char rule[rules][10] = {"E=EA|A","A=AT|aa","T=a","E=b"};
char terminal[rules];
char alpha[rules][10];
char beta[rules][10];

void getAlpha(int ind){
	int j = 3;
	bool betaChk = true;
	int a= 0;
	int b = 0;
	
	while(rule[ind][j]!= '\0'){
		
		if(rule[ind][j]=='|')
			betaChk = false;
		
		if(rule[ind][j] !='|'){
			if(betaChk){
				alpha[ind][a] = rule[ind][j];
				a++;
			}else{
				beta[ind][b] = rule[ind][j];
				b++;
			}
		}
		
		j++;
	}
}


int main(){
	int i = 0;
	int num = 0;
	
	for(i = 0;i<rules;i++){
		if(rule[i][0]==rule[i][2]){
			num++;
			getAlpha(i);
		}
	}
	
	for(i = 0;i<num;i++){
		printf("%c = %s%c' \n",rule[i][0],beta[i],rule[i][0]);
		printf("%c' = %s%c' | episilon \n",rule[i][0],alpha[i],rule[i][0]);
	}
	
	return 0;
}
