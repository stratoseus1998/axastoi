#include <stdio.h>
#include <stdlib.h>

main(){
// srand(2650); //xrhsh srand
 int r_number=(rand() % 300) + 1;	 //random number 1-300
printf("%d \n",r_number);
int i=0;
int number;
while(i<=8){
	printf("Give a random number: \n");
	number=scanf("%d",&number);
	if(number<r_number){
		printf("Your number is greater than the random number \n");
	}else if(number>r_number){
		printf("Your number is less than the random number \n");
	
	}else{
		printf("RIGHT! \n");
		
		break;
	}
i++;
	
	
}
printf("FAILURE!");

	

}






