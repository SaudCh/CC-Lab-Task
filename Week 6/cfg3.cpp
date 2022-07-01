#include <stdio.h>
#include <string.h>

int main() {
	
	char str[100];
	int len;
	int flag=0;
	
	printf("Enter the string: ");
	scanf("%s",&str);
	
	len = strlen(str);
	int j = len-1;
	
	if(len>=1){
		
		if(len%2==0){
			for(int i = 0;i<len;i++){
				if(str[i]!=str[j]){
					flag = 1;
				}
				j--;
			}
	}else{
		flag = 1;
	}
					
	}else{
		printf("Enter a String");
	}
	    
	if(flag == 0 ){
		printf("Valid String");
	}else{
		printf("Invalid String");
	}
}
