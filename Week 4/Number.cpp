#include <stdio.h>
#include <string.h>

int chkNumber (char str[10]){
	
	int flag = 0;
	int i = 0;
	int j = 0;
	
	if((str[0] >= '0' && str[0] <= '9' )){
		
		for(i = 1;i<strlen(str);i++){
    		if((str[i] >= '0' && str[i] <= '9' )){
    			
    			
			}else if(str[i]=='.'){
				
				for(j = i+1;j<strlen(str);j++){
					if((str[j] >= '0' && str[j] <= '9' )){
						
					}else{
						flag = 1;
					}
				}
				i = j;
				
			}else if(str[i]=='e'|| str[i]=='E'){
				i = i + 1;
				if(str[i]=='+'||str[i]=='-'){
					
					for(j = i+1;j<strlen(str);j++){
					if((str[j] >= '0' && str[j] <= '9' )){
						
					}else{
						flag = 1;
					}
				}
				i = j;
					
				}else{
					flag = 1;
				}
				
			}else{
				flag = 1;
			}		
		}
	}else{
		flag = 1;
		return flag;
	}
    	
    return flag;
}

int main() {
   
   
	printf("Enter the word: ");
	char str[100];
	scanf("%s",&str);

	int num = chkNumber(str);
	   if(num==0)
	      printf("%s is a Number\n",str);
	   else
	      printf("%s is not a Number\n",str);      
}
