#include <stdio.h>
#include <string.h>

int chkSD(char str[100]){
	int len = strlen(str);
	int j = len - 2;
	int flag = 1;
	
	for(int i=1;i<strlen(str)/2;i++){
		if(str[i]=='a'&&str[j]=='b'){
			
		}else{
			flag = 1;
		}
		j--;	
	}
	
	j = len;
	for(int i=0;i<strlen(str);i++){
		if(i==j){
			flag = 0;
		}
		j--;
	}
	
	return flag;
}

int chkS(char str[100]){
	int len;
	len = strlen(str);
	int j = len-1;
	
	if(str[0]=='a'&&str[j]=='b'){
		chkSD(str);
	}else{
		return 1;
	}
}

int main() {
	
	char str[100];
	int flag=0;
	
	printf("Enter the string: ");
	scanf("%s",&str);
	
	
	flag = chkS(str);
	    
	if(flag == 0 ){
		printf("Valid String");
	}else{
		printf("Invalid String");
	}
}
