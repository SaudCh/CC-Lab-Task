#include <stdio.h>
int main()
{

    int arr[10]={1,2,3,4,5,6,7,8,9,10};
	int arr2[12]={4,5,6,7,8,9,10,11,12,13,14,15};
	
	//union array
	int u[100];
	//union counter
	int uc = 0;
	//intersection array
	int in[100];
	//intersection counter
	int ic = 0;
	
	bool unique = true;
	
	//intersection
    for (int i = 0; i < 10; ++i){
    	
    	for(int j=0;j<12;j++){
    		
    		if(arr[i]==arr2[j]){
    			unique = false;
			}
			
		}
		
		if(!unique){
			u[uc]=arr[i];
			uc++;
		}
		
		unique = true;
		
	}
	
	//intersection
	for(int k = 0; k < 10; k++){
		in[ic]=arr[k];
		ic++;
	}
		
	
    for (int i = 0; i < 12; ++i){
    	
    	for(int j = 0; j < 10; j++){
    		
    		if(arr2[i]==arr[j]){
    			unique = false;
			}
			
		}
		
		if(unique){
			in[ic]=arr2[i];
			ic++;
		}
		
		unique = true;
		
	}
        
    
    printf("Intersection: ");
	for(int i=0;i<uc;i++)
		printf("%d \t",u[i]);
		
	printf("\nUnion: ");
    for(int i=0;i<ic;i++)
		printf("%d \t",in[i]);
        
    return 0;

}

