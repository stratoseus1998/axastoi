#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
main(){

int array[9];
int i;
srand(2650);

for(i=0;i<=9;i++){
	
	array[i]=(rand() % 100) + 1;
	
}



int s=0;
for(i=0;i<=9;i++){
	s=s+array[i];
	
	
}
double mesi_timi=s/10;

printf("H mesh timh einai : %.1f \n",mesi_timi);


int max=array[0];
int min=array[0];
for(i=1;i<=9;i++){
	if(array[i]>max){
		max=array[i];
	
		
	}
	
	
}
	printf("To megalytero stoixeio vrethike sth thesh : %d \n" ,i);
for(i=1;i<=9;i++){
	if(array[i]<min){
		min=array[i];
	
	
	}
	
	
}
	printf("To mikrotero stoixeio vrethike sth thesh : %d " ,i);

}
