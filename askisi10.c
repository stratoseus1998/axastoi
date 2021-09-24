#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
void swap(int n1,int n2){
int p1=n1;
n1=n2;
n2=p1;
printf("Teliki Timi n1 = %d, n2 = %d ", n1, n2);	
	
	
}
main(){
int n1;
int n2;
srand(2650);
n1=(rand() % 1000) + 1;
n2=(rand() % 1000) + 1;	

printf("Arxiki Timi n1 = %d , n2 = %d \n",n1,n2);
swap(n1,n2);	
	
	
}
