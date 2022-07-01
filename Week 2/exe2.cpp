#include <stdio.h>
#include <stdlib.h>

int main()
{
   char c;
   
   FILE *fptr;

   fptr = fopen("./program.txt","a+");

   if(fptr == NULL)
   {
      printf("Error!");   
      exit(1);             
   }
   
   	while ((c = fgetc(fptr)) != EOF)
        {
            if(c=='\n'){
            	printf("\n");
			}else if(c == '\t'){
				printf("\n");
			}else if(c == ' '){
				printf("\n");
			}else{
				printf("%c",c);
			}
			
        }

   fclose(fptr);

   return 0;
}
