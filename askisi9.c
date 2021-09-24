#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


int add(int n1,int n2){
 int result;
result=n1+n2;
return result;
 
 
	
}

int sub(int n1,int n2){
	int res;
	res=n1-n2;
	int result=abs(res);
	return result;
	
}
int mul(int n1,int n2){
	int result;
	result=n1*n2;

	return result;
}

double div1(int n1,int n2){
	double result;
	result=n1/n2;
	return result;
	
}

int main(){

int i;
int random;
int answer;
double answer1;
srand(2650);
int result;
int n1;
int n2;
int n1_mull;
int n2_mull;
int n1_div;
int n2_div;
int m;
double result1;
for(i=0;i<10;i++){

random=(rand() % 4) + 0;

switch(random){
	
	case 0:
		n1=(rand() % 1000) + 100;
		n2=(rand() % 1000) + 100;
		printf("Dwse apanthsh gia %d + %d =  \n ",n1,n2);
		result=add(n1,n2);
		answer=scanf("%d",answer);
		if(result==answer){
			printf("RIGHT \n ");
			
		}else if(result!=answer){
			printf("ERROR \n ");
		}
	
		break;
	
	case 1:
			n1=(rand() % 1000) + 100;
			n2=(rand() % 1000) + 100;
			printf("Dwse apanthsh gia %d - %d =  \n ",n1,n2);
			result=sub(n1,n2);
			answer=scanf("%d",answer);
			if(result==answer){
			printf("RIGHT \n ");
			
		}else if(result!=answer){
			printf("ERROR \n ");
		}
		break;
		
	case 2:
		n1_mull=(rand() % 30) + 1;
		n2_mull=(rand() % 30) + 1;
		printf("Dwse apanthsh gia %d * %d =  \n ",n1_mull,n2_mull);
			result=mul(n1_mull,n2_mull);
			answer=scanf("%d",answer);
			if(result==answer){
			printf("RIGHT \n ");
			
		}else if(result!=answer){
			printf("ERROR \n ");
		}
		break;
	case 3:
		n2_div=(rand() % 20) + 1;
		m=(rand() % 20) + 1;
		n1_div=n2_div*m;
		printf("Dwse apanthsh gia %d / %d =  \n ",n1_div,n2_div);
		result1=div1(n1_div,n2_div);
		answer1=scanf("%lf",answer1);
		if(result1==answer1){
			printf("RIGHT \n ");
			
		}else if(result1!=answer1){
			printf("ERROR \n ");
		}
		break;
		
	default:
		 printf("END \n");
		 break;
		
	}

/*	if(random==0){
		printf("Dwse apanthsh gia %d + %d =  \n ",n1,n2);
		result=add(n1,n2);
		scanf("%d",answer);
		if(result==answer){
			printf("RIGHT \n ");
			
		}else if(result!=answer){
			printf("ERROR \n ");
		}
	
		
	}else if(random==1){
		printf("Dwse apanthsh gia %d - %d =  \n ",n1,n2);
			result=sub(n1,n2);
			scanf("%d",answer);
			if(result==answer){
			printf("RIGHT \n ");
			
		}else if(result!=answer){
			printf("ERROR \n ");
		}
		
	}else if(random==2){
		n1_mull=(rand() % 30) + 1;
		n2_mull=(rand() % 30) + 1;
		printf("Dwse apanthsh gia %d * %d =  \n ",n1_mull,n2_mull);
			result=mul(n1_mull,n2_mull);
			scanf("%d",answer);
			if(result==answer){
			printf("RIGHT \n ");
			
		}else if(result!=answer){
			printf("ERROR \n ");
		}
	}else if(random==3){
			n2_div=(rand() % 20) + 1;
		m=(rand() % 20) + 1;
		n1_div=n2_div*m;
		printf("Dwse apanthsh gia %d / %d =  \n ",n1_div,n2_div);
		result1=div1(n1_div,n2_div);
		scanf("%lf",answer1);
		if(result1==answer1){
			printf("RIGHT \n ");
			
		}else if(result1!=answer1){
			printf("ERROR \n ");
		}
		
	} */	
	
	
}
return 0;
 	
	
	
	
}
