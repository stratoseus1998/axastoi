#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

main(){
	
int array[9];

int i;
for(i=0;i<=9;i++){

	//srand(2650); 
	array[i]=(rand() % 10) + 1;
	
	
}
for(i=0;i<=9;i++){
	
printf("%d \n",array[i]);
	
	
}
for(i=0;i<=9;i++){
	if(array[i]>0&&array[i]<=4){
		printf("Grade : %d ",array[i]);
		printf("Aneprakhs \n");
	}else if(array[i]>=5&&array[i]<=6){
		printf("Grade : %d ",array[i]);
		printf("Good \n");
	}else if(array[i]>=7&&array[i]<=8){
		printf("Grade : %d ",array[i]);
		printf("Very Good \n");
		
	}else if(array[i]>=9&&array[i]<=10){
		printf("Grade : %d ",array[i]);
		printf("Excellent \n");
	}
	//array[i]>9&&array[i]<=10
	
	
	
}		


	
	
	
}
