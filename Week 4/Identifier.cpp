#include <stdio.h>
#include <string.h>

int chkkeyword (char str[10]){
	char keyword[32][10]={
      "auto","double","int","struct","break","else","long",
      "switch","case","enum","register","typedef","char",
      "extern","return","union","const","float","short",
      "unsigned","continue","for","signed","void","default",
      "goto","sizeof","voltile","do","if","static","while"
   } ;
   
   
   int flag=0,i;
   for(i = 0; i < 32; i++) {
      if(strcmp(str,keyword[i])==0) {
         flag=1;
      }
   }
   
   return flag;
}

int chkIdentifier (char str[10]){
	
	int flag = 0;
	
	if(str[0]=='_'|| (str[0] >= 'a' && str[0] <= 'z') || (str[0] >= 'A' && str[0] <= 'Z')){
		
		for(int i = 1;i<strlen(str);i++){
    		if(str[i]=='_'|| (str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z' ) || (str[i] >= '0' && str[i] <= '9' )){
    			
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
	char str[10];
	scanf("%s",&str);
	
	int flag = chkkeyword(str);
	   if(flag==1)
	      printf("%s is a keyword\n",str);
	   else
	      chkIdentifier(str);

	int ind = chkIdentifier(str);
	   if(ind==0)
	      printf("%s is a Identifier\n",str);
	   else
	      printf("%s is not Identifier\n",str);      
}
