//File handling
#include<stdio.h>
#include<stdlib.h>

int main(){
	FILE *fptr;
	fptr = fopen("./p3.txt","a+");
	
	if(fptr==NULL){
		printf("Error opening the File");
		exit(1);
	}
	
	return 0;
}
