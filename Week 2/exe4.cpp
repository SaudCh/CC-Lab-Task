#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
   char c;
   char ch[100];
   int length;
   int c1=0;
   int count =0;
   
   FILE *fptr;

   fptr = fopen("./program.txt","a+");
   
   printf("Enter the word: ");
   scanf("%s",&ch);
   
   if(fptr == NULL)
   {
      printf("Error!");   
      exit(1);             
   }

	length = strlen(ch);
	
	while((c = fgetc(fptr)) != EOF){
		for(int i=0;i<=length;i++){

			if(c==ch[i]){
				c1++;
			}else{
				break;
			}
			c = fgetc(fptr);
		}
		if(c1==length){
				count++;
			}
			c1 =0;
	}
   
   printf("%d",count);

   fclose(fptr);

   return 0;
}
