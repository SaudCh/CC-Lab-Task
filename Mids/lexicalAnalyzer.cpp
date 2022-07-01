#include<stdio.h>
#include<stdlib.h>
#include<string.h>

bool isSpCh(char a){
	bool flag = false;
	if( a =='!' || a =='@' || a =='#' || a =='%' || a =='^' || a =='*' )
		flag = true;
		
	return flag;
}

bool isNum(char a){
	bool flag = false;
	if( (a >='0' && a <='9') )
		flag = true;
		
	return flag;
}

bool isAlpha(char a){
	bool flag = false;
	if( (a >='A' && a <='Z') || (a >='a' && a <='z') )
		flag = true;
		
	return flag;
}

bool chkVaribales (char str[10]){
	bool flag = true;
	int len = strlen(str);
	int i = 0;
	if( isNum(str[i]) ){
		
		i++;
		
		if( isAlpha(str[i]) ){
			i++;
			
			for(int j = i; j<str[j]==len-2;j++){
				if(isAlpha(str[j]) || isSpCh(str[j]) ){
					
				}else{
					flag = false;
				}
			}
			
			if(isNum(str[len-1])){
				
			}else{
				flag = false;	
			}
			
		}else
			flag = false;
		
	}else{
		flag = false;
	}
	
	
}

bool chkDigit (char str[10]){
	bool flag = true;
	int len = strlen(str);
	int i = 0,j,k;
	
	if( str[i] == '+' || str[i] == '-' ){
		i++;
		for(j = i; j< len;j++){
			if(isNum(str[j])){
				
			}else if(str[j]=='.' && j>=2 && len>3 ){
				for(k=j+1;k<len;k++){
					if(isNum(str[k])){
					}else{
						flag = false;
					}
				}
				j = k;
			}else{
				flag = false;
			}
		}
		
	}else{
		flag = false;
	}
	
	return flag;
}

bool chkSpCh (char str[10]){
	bool flag = false;
	
	char oper[6][10]= {
	"<",">","=","<=",">=","!="
	};
		
	for(int i = 0;i<6;i++){
		if(strcmp(oper[i],str)==0){
			flag = true;
		}
	}
	
	return flag;
}


int main(){
	
	FILE *fptr;
	char str[40];
	
	fptr = fopen("./mids.txt","r");
	
	if(fptr==NULL){
		printf("Error Opening File");
		exit(1);
	}
	
	while( (fscanf(fptr,"%s",str) ) != EOF ){
		if(chkVaribales(str)){
			printf("Varibale: %s \n",str);
		}else if(chkDigit(str)){
			printf("Digit: %s \n",str);
		}else if(chkSpCh(str)){
			printf("Operators: %s \n",str);
		}
	}
	
	
	return 0;
}
