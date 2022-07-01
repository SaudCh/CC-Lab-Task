#include <stdio.h>
#include <stdlib.h>

int main()
{
   char c;
   bool chk=true;
   
   FILE *fptr;
   FILE *fpt;

   fptr = fopen("./program.txt","a+");
   fpt = fopen("./text.txt","a+");

   if(fptr == NULL)
   {
      printf("Error!");   
      exit(1);             
   }
   
   	while ((c = fgetc(fptr)) != EOF)
        {
            if(c=='/'){
            	c = fgetc(fptr);
            	if(c=='/'){
            		c = fgetc(fptr);
            		while(c!='\n'){
            			c = fgetc(fptr);
					}
				}else if(c =='*'){
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
			}else{
				if(c=='\n'){
	            	
				}else if(c == '\t'){
					
				}else if(c == ' '){
					
				}else{
					printf("%c",c);
					putc(c, fpt);
				}
			}
			
					
        }

   fclose(fptr);

   return 0;
}
