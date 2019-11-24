#include <string.h>
#include <stdio.h>
#include<stdlib.h>
#define small 200
#define large 1000
#define BUFFER malloc(large)

typedef struct student{
	char namef[small];
	char namel[small];
	int roll;
	int fees;
	char date[small];
	char category[small];

}student;//we create a structure called student which houses all the details about the students



void delete_by_name(char namef[large],char namel[large] , char *str)
{
	struct student s[large];//we create an array of variables of struct student type i.e students
	FILE *db;//a file pointer db is declared, which opens file parameter in read mode
	db = fopen(str,"r");
	int i = 0;
	while(!feof(db))//in this loop, we store the details of the students from the file into the array of students we created.
	{
		fscanf(db,"namef=%s namel=%s roll=%d fees=%d date=%s category=%s\n",s[i].namef,s[i].namel,&s[i].roll,&s[i].fees,s[i].date, s[i].category);
		i++;
	}
	FILE *db1;
	db1 = fopen(str,"w");//a file pointer db1 is declared, which opens file parameter in write mode(i.e erases the contents)
	for(int j=0;j<i;j++)
	{
		if((strcmp(s[j].namef,namef)==0) && (strcmp(s[j].namel,namel)==0))//if both first name and last name of the student matches with that in the array we created, we "delete" his/her records.
		{
			continue;//exclude printing the details of the student whose records are to be deleted...
		}
		else
		{
			fprintf(db1,"namef=%s namel=%s roll=%d fees=%d date=%s category=%s\n",s[j].namef,s[j].namel,s[j].roll,s[j].fees,s[j].date,s[j].category);
		}//print the other students' records
	}
	printf("DELETION DONE SUCCESSFULLY !!! :)");
}


void delete_by_roll(int roll , char *str)
{
	struct student s[large];
	FILE *db;
	db = fopen(str,"r");
	int i = 0;
	while(!feof(db))//similar procedure as before, create two file pointers and in the read-only one, create an array of students
	{
		fscanf(db,"namef=%s namel=%s roll=%d fees=%d date=%s category=%s\n",s[i].namef,s[i].namel,&s[i].roll,&s[i].fees,s[i].date,s[i].category);
		//fgets(BUFFER,large,db);
		i++;
	}
	FILE *db1;
	db1 = fopen(str,"w");
	for(int j=0;j<i;j++)
	{
		if( s[j].roll == roll)//if roll number of student to be deleted is matching with any element in the array, we change the database so as to display all other records
		{
			continue;
		}
		else
		{
			fprintf(db1,"namef=%s namel=%s roll=%d fees=%d date=%s category=%s\n",s[j].namef,s[j].namel,s[j].roll,s[j].fees,s[j].date,s[j].category);
		}
	}
	printf("DELETION DONE SUCCESSFULLY !!! :)");
}

