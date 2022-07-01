#include<string.h>
#include<string.h>
#include<stdio.h>


//s3--> s1 c s2
//s1 --> a s1 b | null
//s2 --> d s2 | null

void chkS3();
void chkS1();
void chkS2();

char str[100];
int count;

int main(){
	
	scanf("%s",&str);
	
	chkS3();
	
	
	if(strlen(str)==count){
		printf("Valid String");
	}else{
		printf("Invalid String");
	}
	
	return 0;
}

void chkS3(){
	chkS1();
	if(str[count]=='c'){
		count++;
		chkS2();
	}
}
void chkS1(){
	if(str[count]=='a'){
		count++;
		chkS1();
		if(str[count]=='b'){
			count++;
		}
	}
	
	return;
}
void chkS2(){
	if(str[count]=='d'){
		count++;
		chkS2();
	}
	return;
}

