#include <stdio.h>
#include <string.h>

//remove Comments
void removeComments(FILE *fptr,char str[10]){
	char c;
	bool chk = true;
	
		if(strcmp(str,"//")==0){
			c = fgetc(fptr);
        		while(c!='\n'){
        			c = fgetc(fptr);
				}
		}
		
		if(strcmp(str,"/*")==0){
			c = fgetc(fptr);
    		while(chk){
    			if(c=='*'){
    				c = fgetc(fptr);
    				if(c=='/'){
    					chk = false;
					}
				}else{
					c = fgetc(fptr);
				}
		}
		}
}

//check keywords
int chkkeyword (char str[10]){
	char keyword[32][10]={
      "auto","double","int","struct","break","else","long",
      "switch","case","enum","register","typedef","char",
      "extern","return","union","const","float","short",
      "unsigned","continue","for","signed","void","default",
      "goto","sizeof","voltile","do","if","static","while"
   } ;
   
   
   int flag=0;
   for(int i = 0; i < 32; i++) {
      if(strcmp(str,keyword[i])==0) {
         flag=1;
      }
   }
   
   return flag;
}

//check identifier
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

//check special character and operator
int chkspchr (char str[10]){
	
	//0-5 special character
	//6-24 operators
	char keyword[25][5]={
      "(",")","{","}",";",","
      "=","+","-","*","/","%",
      "+=","/=","*=","-=","==","!=",
      "<","<=",">=",">","&&","||","&"
   } ;
   
	for(int i = 0;i<25;i++){
		if(strcmp(str,keyword[i])==0){
			if(i<=5)
				printf("Special Character   %s \n",str);
			else
				printf("Operater            %s \n",str);
			
		}
	}
		
}

int main() {
	char str[10];
	FILE *fptr;

	fptr = fopen("./input.txt","a+");
	if(fptr == NULL){
		printf("Error opening file");
	}
	
	while(fscanf(fptr,"%s",str)!=EOF){	
	
		removeComments(fptr,str);	
			
		if(chkkeyword(str)==1)
		    printf("keyword             %s\n",str);
		else{
		    if(chkIdentifier(str)==0)
			    printf("Identifier          %s \n",str);
			else
			   	chkspchr(str);
		}
	}
}
