#include <stdio.h>
#include <stdlib.h>

int main()
{
   char c;
   int ch=0;
   int tab=0;
   int enter=0;
   int sp =0;
   
   FILE *fptr;

   fptr = fopen("./program.txt","a+");

   if(fptr == NULL)
   {
      printf("Error!");   
      exit(1);             
   }
   
   	while ((c = fgetc(fptr)) != EOF)
        {
            printf("%c", c);
            if(c=='\n'){
            	enter++;
			}else if(c == '\t'){
				tab++;
			}else if(c == ' '){
				sp++;
			}else{
				ch++;
			}
			
        }

	printf("\nThe number of character is %d",ch);
	printf("\nThe number of Lines is %d",enter+1);
	printf("\nThe number of tab is %d",tab);
	printf("\nThe number of space is %d",sp);
   fclose(fptr);

   return 0;
}
