
#include <string.h>
#include <stdio.h>
#include<stdlib.h>
#define NULLSTRING "NULLNULLNULL"
#define LARGE 999
#define SMALL 50
#define ARBITLARGE 99999999
#include "util1.h"

//This Function searches for the requried line in the database in the order of the formatted string
void search(char namef[],char namel[],int * roll,int * fees, char date[],char category[] ,FILE* db){

    fscanf(db,"namef=%s namel=%s roll=%d fees=%d date=%s category=%s",namef,namel,roll,fees,date , category);

}

//This Function calls the search function to compare the keys with their values and get required information for student or staff
void call_search(char key[], char value[],char namef[],char namel[],int * roll,int * fees, char date[],char category[] , int int_value,FILE* db){
    char val_temp[SMALL];
    int val_temp_int;
    char cat[SMALL];
    while(1){
       //printf("%d",feof(db));
        char BUFFER[LARGE];
        
        //Calling the search function for the required student or staff member to be searched
        search(namef,namel,roll,fees,date,cat,db);
        
        //Exits the loop if end of file is reached
        if(feof(db))
          break;

        fgets(BUFFER,LARGE,db);

        //Copying the value of the corresponding key into a temporary string or temporary integer so as to compare later
        if(strcmp(key,"namef")==0){
            strcpy(val_temp,namef);
        }
        else if(strcmp(key,"namel")==0){
            strcpy(val_temp,namel);
        }
        else if(strcmp(key,"roll")==0){
            val_temp_int=*roll;
        }
        else if(strcmp(key,"date")==0){
            strcpy(val_temp,date);
        }
        else if(strcmp(key,"fees")==0){
            val_temp_int=*fees;
        }

        //Comparing the value to that of the temporary value and printing required information 
        if(strcmp(val_temp,value)==0 || val_temp_int==int_value && strcmp(category ,cat )==0){
            printf("%s      %s      %d      %d      %s\n",namef,namel,*roll,*fees,date );
        }
    }

}

//Driver Function in which variables are defined and also User Interface is taken care of
void search_driver(FILE* db){
    char namef[SMALL]="";
    char namel[SMALL]="";
    int * roll=malloc(sizeof(int));
    int *fees=malloc(sizeof(int));
    char date[SMALL]="";

    char key[SMALL]= "";
    char value[SMALL]=NULLSTRING;
    int int_value=ARBITLARGE;
    printf("Enter the category(students/staff) : ");
    char category[100];
    scanf("%s" , category);
    printf("Type in the field you want to search by(namef,namel,roll/salary,date)\n");
    scanf("%s",key);
    if(strcmp(key,"fees")!=0 && strcmp(key,"roll")!=0 ){
        printf("Enter String Value\n");
        scanf("%s",value);
    }
    else{
        printf("Enter Integer Value\n");
        scanf("%d",&int_value);
    }
    
  //Checking the category of person and calling functions accordingly
  if(strcmp(category , "student")==0){
    display_stud();
    call_search(key,value,namef,namel,roll,fees,date,category,int_value,db);
   }
  else if(strcmp(category , "staff")==0){
    display_staff();
    call_search(key,value,namef,namel,roll,fees,date,category,int_value,db);
  }
}
