#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

main(){
 int array[10][6];	
 int i;
 int j;
 
 srand(2650);
 for(i=0;i<10;i++){
 	
 	for(j=0;j<6;j++){
 		array[i][j]=(rand() % 100) + 50;
 		
	 }
 	
 }
 int srow=0;
 int scol=0;
  for(i=0;i<10;i++){
  
 	scol=scol+array[i][j];
 	for(j=0;j<6;j++){
 		srow=srow+array[i][j];
 		
		 printf("array[%d] [%d] = %d  \n  \n",i,j,array[i][j]);
		 printf("sum_grammhs:%d  sum sthlhs:%d  ",srow,scol);
 	
 		
 		
	 }
 	
 }

 
 
	
	
	
}
