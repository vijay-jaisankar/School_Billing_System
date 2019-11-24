#include <string.h>
#include <stdio.h>
#include<stdlib.h>
#include "util1.h"
#define NULLSTRING "NULLNULLNULL"
#define LARGE 999
#define SMALL 50
#define ARBITLARGE 99999
#define USINGINT 1
#define USINGCHAR 0


//function searches the line in the database according to the template
void domain_search(char namef[],char namel[],int * roll,int * fees, char date[],char category[] ,FILE* db){

    fscanf(db,"namef=%s namel=%s roll=%d fees=%d date=%s category=%s",namef,namel,roll,fees,date, category);

}

void domain_call_search(char key[], char value_lb,char value_ub,char namef[],char namel[],int * roll,int * fees, char date[],char category[] , int int_value_lb,int int_value_ub,int using,FILE* db){
    char val_temp[SMALL]="";
    int val_temp_int=LARGE;
    char cat_temp[SMALL];
    while(1){
       // printf("%d",feof(db));
        char BUFFER[LARGE];
        domain_search(namef,namel,roll,fees,date,cat_temp, db);
        //exits the loop if end of file is reached
        if(feof(db))
          break;
      	//copies the value of given key into val_temp or val_temp_int to later compare
        if(strcmp(key,"namef")==0){
            strcpy(val_temp,namef);
        }
        else if(strcmp(key,"namel")==0){
            strcpy(val_temp,namel);
        }
        else if(strcmp(key,"roll")==0){
            val_temp_int=*roll;
        }
        else if(strcmp(key,"fees")==0){
            val_temp_int=*fees;
        }

        //performs the domain check on the val_temp or val_temp_int and prints according to the template
        if(using){
            if(val_temp_int<=int_value_ub && val_temp_int>= int_value_lb && strcmp(cat_temp , category)==0){
                printf("%s      %s      %d      %d      %s\n",namef,namel,*roll,*fees,date );
            }
        }
        else{
            if(val_temp[0]<=value_ub && val_temp[0]>=value_lb && strcmp(cat_temp , category)==0){
                printf("%s      %s      %d      %d      %s\n",namef,namel,*roll,*fees,date );
            }
        }
        fgets(BUFFER,LARGE,db);

    }

}

//driver function, Takes care of UI and memory allocation and definition of variables
void search_domain_driver(FILE* db){
    char namef[SMALL]="";
    char namel[SMALL]="";
    int * roll=malloc(sizeof(int));
    int *fees=malloc(sizeof(int));
    char date[SMALL]="";
    char category[SMALL]="";

    char key[SMALL];
    //lower and upper bounds of value(for char value)
    char value_lb='\0';
    char value_ub='\0';
    //lower and upper bounds of int_value(for int value)
    int int_value_lb=ARBITLARGE;
    int int_value_ub=ARBITLARGE;
    int using;
    printf("Enter the category(student or staff): ");
    scanf("%s" , category);
    printf("Type in the field you want to search by(namef,namel,roll,fees)\n");
    scanf("%s",key);

    //'value' is used if the key requires char inputs
    if(strcmp(key,"fees")!=0 && strcmp(key,"roll")!=0 ){
        printf("Enter Char Values(lower bound and upper bound)\n");
        getchar();
        scanf("%c",&value_lb);
        getchar();
        scanf("%c",&value_ub);
        using=USINGCHAR;
    }
    //else 'int_value' is used
    else{
        printf("Enter Integer Value(lower bound and upper bound)\n");
        scanf("%d%d",&int_value_lb,&int_value_ub);
        using=USINGINT;
    }
    if(strcmp(category , "student")==0)
      display_stud();
    else if(strcmp(category , "staff")==0)
      display_staff();


    domain_call_search(key,value_lb,value_ub,namef,namel,roll,fees,date,category, int_value_lb,int_value_ub,using,db);
}


