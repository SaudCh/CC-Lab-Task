#include <stdio.h>
#include <string.h>

static char str[100];
int i = 0;

void chkE();
int chkED();
int chkT();
int chkF();
int chkTD();

void chkE( ){
	if(chkT()){
		if(chkED()){
			printf("Valid String");	
		}else{
			printf("Invalid String");
		}
	}else{
		printf("Invalid String");
	}
}

int chkED(){
	if(str[i]=='+'){
		i++;
		if(chkT()){
			return chkED();	
		}else{
			return 0;
		}
		
	}else if(str[i] == '-'){
		i++;
		if(chkT()){
			return chkED();	
		}else{
			return 0;
		}
	}if((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z' ) || (str[i] >= '0' && str[i] <= '9' )){
		return 0;
	}
	
	return 1;
}

int chkT(){
	if(chkF()){
		return chkTD();	
	}else{
		return 0;
	}
	
	return 0;
}

int chkTD(){
	if(str[i]=='*'){
		i++;
		if(chkF()){
			return chkTD();
		}else{
			return 0;
		}
		
	}else if(str[i] == '/'){
		i++;
		if(chkF()){
			return chkTD();	
		}else{
			return 0;
		}
		
	}
	
	return 1;
}

int chkF(){
	if((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z' ) || (str[i] >= '0' && str[i] <= '9' )){
		i++;
	}else{
		printf("Id or num expected\n");
		return 0;
	}
	
	return 1;
}

int main() {
	
	int flag=0;
	
	printf("Enter the string: ");
	scanf("%s",&str);
		
	chkE();

}
