#include <stdio.h>
#include "search.h"
#include <stdlib.h>
int check_uniq(FILE *fp , int *roll_no){ //Accepting file pointer and roll no as parameters
  char namef[1000] , namel[1000] , date[20], category[30] ,BUFFER[1000];
  int *roll , *fees;
  roll = (int *)malloc(sizeof(int));
  fees = (int *)malloc(sizeof(int));
  while(1){
    search(namef,namel,roll,fees,date,category ,fp); //Searching a particular row of a database using search function declared in search.h
    if(feof(fp)) //When cursor reaches end of File
      break;

    if(*roll==*roll_no) //If roll number is not unique
      return 0;

    fgets(BUFFER , 1000 , fp); //To get to next Line
  }return 1;
}

void display_stud()
{
	printf("\nnameF        nameL       Roll   Fees      DueDate\n");
}

void display_staff()
{
	printf("\nnameF        nameL       Staff ID   Salary      DueDate\n");
}

void display()
{
	        printf("\nPLEASE AN CHOOSE AN ACTION FROM THE FOLLOWING LIST OF OPTIONS\n");
                printf("|----------------WELCOME TO THIS SCHOOL BILLING SOFTWARE----------|\n");
		            printf("|	                                                          |\n");
                printf("|         1. ADD A RECORD                                         |\n");
                printf("|         2. DELETE A RECORD                                      |\n");
                printf("|         3. SEARCH A RECORD                                      |\n");
		            printf("|         4. DOMAIN BASED SEARCHING(search for a range of records)|\n");
		            printf("|         5. EXIT THE SOFTWARE                                    |\n");
                printf("|_________________________________________________________________|\n");

}
