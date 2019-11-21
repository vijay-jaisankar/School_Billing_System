#include <string.h>
#include <stdio.h>
#include<stdlib.h>
#define small 20
#define large 100

typedef struct student{
	char namef[small];
	char namel[small];
	int roll;
	int fees;
	char date[small];

}student;



void delete(char namef[large],char namel[large])
{
	struct student s[large];
	FILE *db;
	db = fopen("db.txt","r");
	int i = 0;
	while(!feof(db))
	{
		fscanf(db,"namef=%s namel=%s roll=%d fees=%d date=%s\n",s[i].namef,s[i].namel,&s[i].roll,&s[i].fees,s[i].date);

	}
	FILE *db1;
	db1 = fopen("db.txt","w");
	for(int j=0;j<1;j++)
	{
		if((strcmp(s[j].namef,namef)==0) && (strcmp(s[j].namel,namel)==0))
		{
			continue;
		}
		else
		{
			fprintf(db1,"namef=%s namel=%s roll=%d fees=%d date=%s\n",s[j].namef,s[j].namel,s[j].roll,s[j].fees,s[j].date);
		}
	}
}
int main()
{
	delete("Krishna","Sharma");
	return 0;
}
