#include <stdio.h>
#include <string.h>

int main() {
	
	char str[100];
	int len;
	int flag=0;
	
	printf("Enter the string: ");
	scanf("%s",&str);
	
	len = strlen(str);
	
	
	if(len>=1){
		for(int i = 0;i<len;i++){
			if(str[i]!='a'&&i<len/3)
				flag = 1;
			
			if(str[i]!='b'&&i>=len/3)
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
