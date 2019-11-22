#include <stdio.h>
#include "search.h"
#include<stdlib.h>
#define LARGE 1000
//Function to check uniqueness of roll number
int check_uniq(FILE *fp , int *roll_no){ //Accepting file pointer and roll no as parameters
  char namef[LARGE] , namel[LARGE] , date[20], BUFFER[LARGE];
  #include<stdio.h>
  int *roll , *fees;
  roll = (int *)malloc(sizeof(int));
  fees = (int *)malloc(sizeof(int));
  while(1){
    search(namef,namel,roll,fees,date,fp); //Searching a particular row of a database using search function declared in search.h
    if(feof(fp)) //When cursor reaches end of File
      break;

    if(*roll==*roll_no) //If roll number is not unique
      return 0;

    fgets(BUFFER , LARGE , fp); //To get to next Line
  }return 1;
}
void add_student(FILE *fp , int roll)//this function will add the details of one student in the database and accepts file pointer as parameter
{
    char fname[80],lname[80],category[20];
    scanf("%s",date);
    strcpy(category , "student");
    printf("Enter %s's first name...\n" ,  category);//entering student's first name
    scanf("%s",fname);
    printf("Enter %s's last name...\n" , category);//entering student's last name
    scanf("%s",lname);
    int due;
    printf("Enter due amount...\n");//entering due amount
    scanf("%d",&due);
    char date[20];
    printf("Enter the due date in DD-MM-YYYY format...\n");//entering the due date
    if(fp==NULL)
    {
        printf("Error opening File! Please try again...\n");//integrity check

    }
    else
    {
        fprintf(fp,"namef=%s namel=%s roll=%d fees=%d date=%s\n",fname,lname,roll,due,date);//writing data into file


    }
    //closing and flushing the buffer
}
