#include <stdio.h>
#include <stdlib.h>
#include <math.h>
main(){
 
 int num;
 printf("Give your AFM \n");
 num=scanf("%d",&num);
 int array[8];
 int i=0;
 		array[i] = num % 10;
        array[i+1] = ( num / 10 ) % 10;
        array[i+2] = ( num / 100 ) % 10;
        array[i+3] = ( num / 1000 ) % 10;
        array[i+4] = ( num / 10000 ) % 10;
        array[i+5] = ( num / 100000 ) % 10;
        array[i+6] = ( num / 1000000 ) % 10;
        array[i+7] = ( num / 10000000 ) % 10;
        array[i+8] = ( num / 100000000 ) % 10;
 int j;
 //for(j=0;j<=8;j++){
 //	printf("%d",array[j-1]);
 	
 //}	
 printf("%d",array[8]);
	
	
}
