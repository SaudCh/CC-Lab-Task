#include<stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student{
	char name[50];
	char regdNo[50];
	float cgpa;
} student;

void addStudent(student s1){
	FILE *fptr;
	fptr = fopen("./student.txt","a+");
	
	printf("Enter the Name: ");
	scanf("%s",s1.name);
	printf("Enter the Registration: ");
	scanf("%s",s1.regdNo);
	printf("Enter the CGPA: ");	
	fflush(stdin);
	scanf("%f",&s1.cgpa);
		
	fwrite (&s1, sizeof(student), 1, fptr);
	
	if(fwrite != 0)
        printf("contents to file written successfully !\n");
    else
        printf("error writing file !\n");
        
    fclose(fptr);
}

void viewStudent(student s2){
	FILE *fptr;
	fptr = fopen("./student.txt","a+");
		
	while(fread (&s2, sizeof(student), 1, fptr)){
		printf("\n**********Student Info**********\n");
		printf("Name: %s\n",s2.name);
		printf("Registration: %s\n",s2.regdNo);
		printf("CGPA: %f\n",s2.cgpa);	
	}
	
    fclose(fptr);
}

int noOfRecords(){
	student s1;
	FILE *fp;
	fp = fopen("./student.txt","r");
	fseek(fp,0,SEEK_END);
	int n = ftell(fp)/sizeof(student);
	fclose(fp);
	return n;
}

void deleteStudent(){
	FILE *fp;
	fp = fopen("./student.txt","r");
	int n = noOfRecords();
	
	student s1,st[n];
	int count = 0;
	
	while(fread (&s1, sizeof(student), 1, fp)){
		if(strcmp("078",s1.regdNo)==0){
			printf("\n**********Student Info**********\n");
			printf("Name: %s\n",s1.name);
			printf("Registration: %s\n",s1.regdNo);
			printf("CGPA: %f\n",s1.cgpa);
		}else{
			st[count] = s1;
			count++;
		}	
	}
	
	fclose(fp);
	
//	for(int i = 0;i<count;i++){
//		printf("%s",st[i].name);
//	}
	
	FILE *fptr;
	fptr = fopen("./student.txt","w");
		
	fwrite (&s1, sizeof(student), count, fptr);
	
	fclose(fptr);
}

int main(){
	student s1,s2;
   
   
    int choice=1;
	
   while(choice){
   		printf("\nPress \n1 for create \n2 for view \n3 for update \n4 for delete \nEnter your Choice: ");
   		scanf("%d",&choice);
   		
		if(choice == 1){
			addStudent(s1);
		}else if(choice == 2){
			viewStudent(s2);	
		}else if(choice == 4){
			deleteStudent();
		}
   }
   
   
	return 0;
}
