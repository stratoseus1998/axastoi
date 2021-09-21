/********************************************************************************************
�� ��� ���� ��������� �������� ���������� ���� ���� �������� ������� ��� ��������� 					*
����� �������� ��� �������� ������������ ��� �.�.���������� ���� �� ���������� ���� 				*
2020-21.																																										*
�������� �� ��������������� ���� ��� �������� ����� �������� ������ ����.										*
������ ����������, ������� �������-������, ����� ������� ��������, ����� ����������,				*
���������� ������� �������,  �������, �����������, �����, �������, ���������� �������				*
�������� ��� ��������.																																			*
������-������ ��� �������� ����� :																													*
�� ����� �� ������� ��� �������, �������� ����������� ��� ����������� ��������� ������������*
��� ���������� �������� ��� ������ �������� ��� ������ �� ������� � ������ ��������.				*				
�� ��� ��� ������ �� ������������ ��������� ��������� ������.																*
�� �������� ��� �� ��������� � �������� �� ���� ��� ��� ���������� ��� �� ��������������.		*
�� ��������� ��� �������� ����� ������ ������ �� �� ������ C.																*
�� ������� �� ������ ���������� �� ���� ��� �������� ����������� ���.												*
*********************************************************************************************/
#include <stdio.h>
#include <string.h>

typedef struct stud // �������� � ����� ��� ����� �� �� �������� ��� ��������
{
	unsigned short aem;
	char lname[26];
	char fname[24];
} STUD;

typedef struct studgrade // �������� � ���� ��� ����������� ��� ����������� �� ��� ����������
{
	STUD  rec;
	float grade;
} STUDGRADE;

enum FileName {InputFile, Ex1_9999b, Ex2_9999b, Exam1_9999, Exam2_9999};

int ReadStudent(STUD *, int );
float grade(void);
void GrDistr(int GrDst[], float);
void OutPut (int IDFL, int GrDst[], int, float);


FILE *IDfile[5];

int main()
{
/************************************************************************************************************************
��� ��������� ��� ����� ���� ������������ � ���������� ��������� ��� ������ ���������� ����������� (enum). ���� 
������� ��� �� ���������� ���� ����� ��� ���������� ���� ���� ������� ���� ��� ��� ������ ������� �������� �������
�� ������������ �� ����� �������.
InputFile 			: � ������������� ��� �� ������ ������ ������� ���������.
Ex1_9999b 			: � ������������� ��� �� ��������� ��������� ������� ������ ��������� ��� ������ �����������.
Ex2_9999b				: � ������������� ��� �� ��������� ��������� ������ ��������� ��� �������� �����������.
Exam1_9999			: � ������������� ��� �� ������ ������ �������� ������������ ��� ������ �����������.
Exam2_9999			: � ������������� ��� �� ������ ������ �������� ������������ ��� ��������� �����������.
FileIndex				: ����������� ����� ���������� ��� ��� ������������ ��� ���������� �������.
i 							:��������������� �� ����������� ������ ��� ���� ����� ����������
Case						:��������������� ��� �� ���������� ��� ����� ��� ���������� � rand()	
StudentPopul 		: �� ������ ��� �������� �� �������� �����������.
Grade						: ���������� ��������� ��� ��� ���������� ������.
GradeDistr[5]		:������������ �� ���� ���� � ������� ��� �������� �� �� ���������� ��� ����������
NoMaxGrade			: � ������� ��� ������� �� ��� ��������� ����������.
IDrecord[20]		: ������� �� ��� �������� ��� ����� ��� ��������� ����������. ���������� ��� ��� �� ����� ������������ ��� 20.
sum=0.0					: ������������ �� �������� ��� ������ �� ���� ���������
max=0.0					: ������������ � �������� ������ ��� ���������
AEM=9999				: ������� �� ��� ���� ��� ���.
Appear=60				: ������� � ����� ���������� ��� ������� ��� �������� ��� ������������ ���� ���������
StudentDistrA=5		: ������� ��� �������� �� ������� ��� �������� ���� ��������� 8,5-10
StudentDistrB=20	: ������� ����������� ���������� �+� ����������, ������ ����� ��� ����� ��� 6,5 ��� �����
StudentDistrC=40	: ������� ����������� ���������� �+�+� ����������, ������ ����� ��� ����� ��� 5 ��� �����
StudentDistrD=70	: ������� ����������� ���������� �+�+�+� ����������, ������ ����� ��� ����� ��� 3 ��� �����
StudentDistrF=100	: ������� ����������� ���������� �+�+�+�+� ����������, ���� ������ ����� ��� ����� ��� 0 ��� �����
************************************************************************************************************************/
enum FileName FileIndex;
int i=0, Case, StudentPopul=0, icount=0, AemMax=0, GradeDistr[]={0, 0, 0, 0, 0}, NoMaxGrade=0, IDrecord[20]={0};
float Grade, sum=0.0, max=0.0;
const unsigned int AEM=9999, Appear=60;
// ������� ���������� ��� ��������������� ��� ����� ��� ���������.
STUD rec;
STUDGRADE recgrd;
unsigned short int aem;


	IDfile[InputFile]=fopen("InputFile", "rb");
	IDfile[Ex1_9999b]=fopen("Ex1-9999b", "wb+");
	IDfile[Ex2_9999b]=fopen("Ex2-9999b", "wb+");
	IDfile[Exam1_9999]=fopen("Exam1-9999", "w");


   srand(AEM); //����������� �� ����� ��� ������� �� �� ���� ��� ���


   while(!feof(IDfile[InputFile]))
   {
		fread(&rec, sizeof(rec), 1, IDfile[InputFile]);
		if(feof(IDfile[InputFile])) break;
		recgrd.grade=-1.;
		recgrd.rec=rec;
		Case=rand()%101;
		
	if(Case>Appear) 
	{
		fwrite(&recgrd, sizeof(recgrd), 1, IDfile[Ex1_9999b]);
		fwrite(&recgrd, sizeof(recgrd), 1, IDfile[Ex2_9999b]);	
	}
	else
	{
		StudentPopul++;				//������������ ��� ������ �������� ��� ���������� ���� ���������

		//���������� ��� ������ ���������� �� ���� �� �������� ���������� �������� ������.
		Grade=grade();
		recgrd.grade=Grade;
		recgrd.rec=rec;		
		
		sum+=Grade;	//�������� ��������� ����� ��� ������� ���� sum, ����������� �� ���� ��� ���� ���.
		
		if(Grade>max) 	max=Grade; 	// �������� ���� max �� ������� ���� ��� ���� �������� ����� ����

		fwrite(&recgrd, sizeof(recgrd), 1, IDfile[Ex1_9999b]);
		GrDistr(GradeDistr, Grade);
		if(Grade<5.0) 
		{
    recgrd.grade=-1.0;
		fwrite(&recgrd, sizeof(recgrd), 1, IDfile[Ex2_9999b]);
		}
//		if(Grade<5.0) fprintf(IDfile[Exam2_9999],"%-4u %-26s %-24s\n", recgrd.rec.aem, recgrd.rec.lname, recgrd.rec.fname);
		
	}
   } 
   
   		fclose(IDfile[InputFile]);
   		rewind(IDfile[Ex1_9999b]);
   		i=0;
   		while(!feof(IDfile[Ex1_9999b]))
   		{
   			fread(&recgrd, sizeof(recgrd), 1, IDfile[Ex1_9999b]);
   			if(feof(IDfile[Ex1_9999b])) break;
			NoMaxGrade++;
   			if(recgrd.grade<0) fprintf(IDfile[Exam1_9999],"%-4u %-26s %-24s\n", recgrd.rec.aem, recgrd.rec.lname, recgrd.rec.fname);
   			else 
			   {
			   fprintf(IDfile[Exam1_9999],"%-4u %-26s %-24s %-4.1f\n", recgrd.rec.aem, recgrd.rec.lname, recgrd.rec.fname, recgrd.grade);
			   if(recgrd.grade > max-0.05)
			   {
			    i++;	   
			    IDrecord[i]=NoMaxGrade;
			    IDrecord[0]++;
				}		
			   }	
		} 

	OutPut (Exam1_9999, GradeDistr, StudentPopul, sum);
		
	for(i=1; i<=IDrecord[0]; i++)
	{
		fseek(IDfile[Ex1_9999b], (IDrecord[i]-1)*sizeof(recgrd), 0);
		fread(&recgrd, sizeof(rec), 1, IDfile[Ex1_9999b]);
		fprintf(IDfile[Exam1_9999], "%-4u %-26s %-24s %4.1f\n", recgrd.rec.aem, recgrd.rec.lname, recgrd.rec.fname, max);	
	};
	
	fclose(IDfile[Ex1_9999b]);
	fclose(IDfile[Exam1_9999]);
	remove("Ex1-9999b"); //��������� �� ��������� ��������� ������ ��� ������ �����������.

//--------------------------------------------------------------------------
	
	rewind(IDfile[Ex2_9999b]);
	IDfile[Exam2_9999]=fopen("Exam2-9999", "w");
	
	StudentPopul=0;
	NoMaxGrade=0;
	IDrecord[0]=0;
	sum=0.;
	max=0.;
	for(i=0;i<5;i++) GradeDistr[i]=0;
		
	   while(!feof(IDfile[Ex2_9999b]))
   {
		fread(&recgrd, sizeof(recgrd), 1, IDfile[Ex2_9999b]);
		if(feof(IDfile[Ex2_9999b])) break;
		
		Case=rand()%101;
		
		if(Case>Appear)  continue;

		StudentPopul++;				//������������ ��� ������ �������� ��� ���������� ���� ���������
		Grade=grade(); //���������� ��� ������ ���������� �� ���� �� �������� ���������� �������� ������.

		recgrd.grade =Grade;	
		// ���� ������ �� �������������� ��� ���������� ��� -1.0 ���� ��� ������ �����
		// ��� ���� �� ��� fseek ���������� ���� ���� ��� �������������� �������� ��� ������
		fseek(IDfile[Ex2_9999b], (ftell(IDfile[Ex2_9999b])-sizeof(recgrd)), 0);
		// ��� ���� ������ ���� ���� ���� �� ��� ������� �� ���������� �� ����������.
		fwrite(&recgrd, sizeof(recgrd), 1, IDfile[Ex2_9999b]);
		// ���� ���������� ���� ��� �������� ��� ������� �� ��� ������������ ����������.
		fseek(IDfile[Ex2_9999b], (ftell(IDfile[Ex2_9999b])-sizeof(recgrd)), 0);
    fread(&recgrd, sizeof(recgrd), 1, IDfile[Ex2_9999b]);
    
		sum+=Grade; 								//�������� ��������� ����� ��� ������� ���� sum, ����������� �� ���� ��� ���� ���.
		if(Grade>max) 	max=Grade; 	// �������� ���� max �� ������� ���� ��� ���� �������� ����� ����
		GrDistr(GradeDistr, Grade);
   } 
   
   		rewind(IDfile[Ex2_9999b]);

   		i=0;
   		while(!feof(IDfile[Ex2_9999b]))
   		{
   			fread(&recgrd, sizeof(recgrd), 1, IDfile[Ex2_9999b]);
		    if(feof(IDfile[Ex2_9999b])) break;
			  NoMaxGrade++;
  			if(recgrd.grade < 0.) fprintf(IDfile[Exam2_9999],"%-4u %-26s %-24s\n", recgrd.rec.aem, recgrd.rec.lname, recgrd.rec.fname);
   			else fprintf(IDfile[Exam2_9999],"%-4u %-26s %-24s %-4.1f\n", recgrd.rec.aem, recgrd.rec.lname, recgrd.rec.fname, recgrd.grade);
   			
			if(recgrd.grade > max-0.05)
			{
			    i++;	   
			    IDrecord[i]=NoMaxGrade;
			    IDrecord[0]++;
			}		
		} 
       OutPut (Exam2_9999, GradeDistr, StudentPopul, sum);
		
	for(i=1; i<=IDrecord[0]; i++)
	{
		fseek(IDfile[Ex2_9999b], (IDrecord[i]-1)*sizeof(recgrd), 0);
		fread(&recgrd, sizeof(recgrd), 1, IDfile[Ex2_9999b]);
		fprintf(IDfile[Exam2_9999], "%-4u %-26s %-24s %-4.1f\n", recgrd.rec.aem, recgrd.rec.lname, recgrd.rec.fname, max);	
	};
	
	fclose(IDfile[Ex2_9999b]);
	remove("Ex2-9999b");    //��������� �� ��������� ��������� ������ ��� ������������� �����������.
	fclose(IDfile[Exam2_9999]);
		
  return;
  
}

int ReadStudent(STUD *par1, int i)
{
  int elm;
	if(elm = fread(par1, sizeof(*par1), 1, IDfile[i])) return elm;
	return 0;
}

float grade(void)
{
	float Grade;
	int Case;
	// ����������� ��������. ������� �� ������� ���������� ��� ��������� �����������.
	const unsigned int StudentDistrA=5, StudentDistrB=20, StudentDistrC=40, StudentDistrD=70, StudentDistrF=100;
	
	Case=rand()%101;
	if(Case<=StudentDistrA) Grade=8.5+(Case%16)/10.;
	if(Case>StudentDistrA && Case<=StudentDistrB) Grade=6.5+(Case%20)/10.;
	if(Case>StudentDistrB && Case<=StudentDistrC) Grade=5.0+(Case%15)/10.;
	if(Case>StudentDistrC && Case<=StudentDistrD) Grade=3.0+(Case%20)/10.;
	if(Case>StudentDistrD && Case<=StudentDistrF) Grade=(Case%30)/10.;
	
	return Grade;
}

void GrDistr(int GrDst[5], float points)
{
	if(points>=8.5)GrDst[0]++;
	if(points>=6.5 && points<8.5)GrDst[1]++;
	if(points>=5.0 && points<6.5)GrDst[2]++;
	if(points>=3.0 && points<5.0)GrDst[3]++;
	if(points<3.0 && points>=0.0)GrDst[4]++;
}

void OutPut (int IDFL, int GrDst[], int STNo, float GrSum)
{
	    
	   fprintf(IDfile[IDFL], "\n_____________________________________");
	   fprintf(IDfile[IDFL], "\n\nO mesos oros tis vathmologias ton %d foititon pou exetastikan: %3.1f", STNo, GrSum/STNo);
	   fprintf(IDfile[IDFL], "\nI katanomi tis vathmologias einai :");
	   fprintf(IDfile[IDFL], "\n_____________________________________\n");
	   fprintf(IDfile[IDFL], "\n\t8.5-10.0 = %3d", GrDst[0]);
	   fprintf(IDfile[IDFL], "\n\t6.5-8.4 = %3d", GrDst[1]);
	   fprintf(IDfile[IDFL], "\n\t5.0-6.4 = %3d", GrDst[2]);
	   fprintf(IDfile[IDFL], "\n\t3.0-4.9 = %3d", GrDst[3]);
	   fprintf(IDfile[IDFL], "\n\t0.0-2.9 = %3d\n", GrDst[4]);
	   fprintf(IDfile[IDFL], "\nO megistos vathmos anikei:\n");
}
