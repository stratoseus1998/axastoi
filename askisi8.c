#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int Fibo(int n) {
   if(n == 0){
      return 0;
   } else if(n == 1) {
      return 1;
   } else {
      return (Fibo(n-1) + Fibo(n-2));
   }
}
main(){
int n=10;
int i;
printf("Fibbonacci of %d: \n" , n);


 for(i = 0;i<n;i++) {
      printf("%d ",Fibo(i));            
   }

	
	
	
}
