#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

int rules = 3;

bool chkTerminal (char T1,char terminal[3]){
	bool flag = true;
	int i = 0;
	
	for(i=0;i<rules;i++){
		if(T1==terminal[i]){
			flag = false;
		}
	}
	
	return flag;
}

char getFirst (char T1,char terminal[3],char rule[3][10]) {
	int i = 0;
	for(i = 0;i<rules;i++){
		if(T1==rule[i][0]){
			if(chkTerminal(rule[i][2],terminal)){
				return rule[i][2];
			}
			
		}
	}
}

int main(){
	
	int i,j,l = 0;
	char rule[3][10] = {"S=AB","A=a","B=b"};
	char terminal[rules];
	char first[rules];
	char follow[rules];
	
	for(i=0;i<rules;i++){
		terminal[i] = rule[i][0];
	}

	for(i=0;i<rules;i++){
		if(chkTerminal(rule[i][2],terminal)){
			first[i] = rule[i][2];
		}else{
			first[i] = getFirst(rule[i][2],terminal,rule);
		}
	}
	
	for(i=0;i<rules;i++){
		printf("First of %c is %c\n",terminal[i],first[i]);
	}
	
	printf("\n\n");
	
	follow[0] = '$';
	
	for(i=0;i<rules;i++){
		for(j=0;j<rules;j++){
			int k = 2;
			while(rule[j][k]!='\0'){
				if(rule[j][k]==terminal[i]){
					if( !chkTerminal(rule[j][k+1],terminal)){
						
						for(l=0;l<rules;l++){
							if(rule[j][k+1]==terminal[l]){
								follow[i] = first[l];
							}
						}
						
					}else if(rule[j][k+1]!='\0'){
						
						follow[i] = rule[j][k+1];
						
					}else{
						
						for(l=0;l<rules;l++){
							if(rule[j][0]==terminal[l]){
								follow[i] = follow[l];
							}
						}
						 
					}
				}
				k++;
			}	
		}
	}
	
	for(i=0;i<rules;i++){
		printf("Follow of %c is %c\n",terminal[i],follow[i]);
	}
		
	return 0;
}
