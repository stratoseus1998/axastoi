#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//krousmata

typedef struct {
	int num;
	float avg;
	int day;
	int month;
	int year;
	
}date;

int main(int argc, char *argv[]) {
	
	int i;
	date d[10];
	int doM[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	d[0].day = 0;
	d[0].month = 3;
	d[0].year = 2019;
	int maxcases = 0;
	int maxavg = 0;
	int maxcasesd;
	int maxavgd;
	
	for(i=0;i<10;i++){
		
		//random krousmata	
		srand(2650);
		d[i].num = rand();
		
		//avg apo 7h mera kai meta
		if(i<6){
			d[i].avg=0;
		}
		else
		d[i].avg = (d[i].num + d[i - 1].num + d[i - 2].num + d[i - 3].num + d[i - 4].num + d[i - 5].num + d[i - 6].num)/7;
		
		d[i].day = d[i].day + 1;
		
		//check disekto etos
		if (( d[i].month == 2 ) && (d[i].day == 29)){
        
        	if(d[i].year % 400 == 0 || (d[i].year % 100 != 0 && d[i].year % 4 == 0)){
            doM[1] = 29;
        	}
    	
		}
		if(d[i].day > doM[d[i].month - 1]){
			d[i].day=1;
			d[i].month++;
			if(d[i].month > 12){
				d[i].month = 1;
				d[i].year++;
			}
		}
		
		//ypologismos megistwn
		if(maxcases < d[i].num){
			maxcases = d[i].num;
			maxcasesd = i;
		}	
		
		if(maxavg < d[i].avg){
			maxavg = d[i].avg;
			maxavgd = i;
		}
		
		printf("d[%d] date:%d/%d/%d, cases:%d, 7dayAVG:%f\n",i,d[i].day,d[i].month,d[i].year,d[i].num,d[i].avg);
	
	}
	
	printf("The day with the most cases is: %d/%d/%d, Total cases:%d \n",d[maxcasesd].day,d[maxcasesd].month,d[maxcasesd].year,d[maxcasesd].num);
	printf("The day with the biggest 7dayAVG is: %d/%d/%d, 7dayAVG:%d \n",d[maxavgd].day,d[maxavgd].month,d[maxavgd].year,d[maxavgd].avg);
	
	return 0;
}
