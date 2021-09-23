#include <stdio.h>

void f_to_c( float celsius ){
	
	double fahrenheit;
	
	 fahrenheit = (9/5 * celsius   )+ 32  ;
	
	    printf("%.2f celsius = %.2f fahrenheit", celsius, fahrenheit);

}

int main()
{
    float celsius;

  
    printf("Enter temperature in celsius: ");
    celsius=scanf("%f", &celsius);

    
  f_to_c (celsius);

  

    return 0;
}
