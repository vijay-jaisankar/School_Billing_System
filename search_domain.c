#include <string.h>
#include <stdio.h>
#include<stdlib.h>
#include "util1.h"
#include "string_funcs.h"
#include <ctype.h>
#define NULLSTRIG "NULLNULLNULL"
#define LARGE 999
#define SMALL 50
#define ARBITLARGE 99999
#define USINGINT 1
#define USINGCHAR 0



void domain_search(char namef[],char namel[],int * roll,int * fees, char date[],char category[] ,FILE* db){

    fscanf(db,"namef=%s namel=%s roll=%d fees=%d date=%s category=%s",namef,namel,roll,fees,date, category);

}

void domain_call_search(char key[], char value_lb,char value_ub,char namef[],char namel[],int * roll,int * fees, char date[],char category[] , int int_value_lb,int int_value_ub,char date_lb[] , char date_ub[] ,int using,FILE* db){
    char val_temp[SMALL]="";
    int val_temp_int=LARGE;
    char cat_temp[SMALL];
    while(1){
       // printf("%d",feof(db));
        char BUFFER[LARGE];
        domain_search(namef,namel,roll,fees,date,cat_temp, db);

        if(feof(db))
          break;
        if(strcmp(key,"namef")==0){
            strcpy(val_temp,namef);
        }
        else if(strcmp(key,"namel")==0){
            strcpy(val_temp,namel);
        }
        else if(strcmp(key,"roll")==0){
            val_temp_int=*roll;
        }
        else if(strcmp(key,"fees/salary")==0){
            val_temp_int=*fees;
        }

        else if(strcmp(key , "date")==0){
            strcpy(val_temp , date);
        }
        if(using){
            if(val_temp_int<=int_value_ub && val_temp_int>= int_value_lb && strcmp(cat_temp , category)==0){
                printf("%s      %s      %d      %d      %s\n",namef,namel,*roll,*fees,date );
            }
        }
        else{
            if(val_temp[0]<=value_ub && val_temp[0]>=value_lb && strcmp(cat_temp , category)==0 && strcmp(key , "date")!=0){
                printf("%s      %s      %d      %d      %s\n",namef,namel,*roll,*fees,date );
            }
            if(strcmp(key , "date")==0){
              if(pending_or_not(date , date_lb) && pending_or_not(date_ub ,date) && strcmp(cat_temp , category)==0){
                printf("%s      %s      %d      %d      %s\n",namef,namel,*roll,*fees,date );
              }
            }
        }
        fgets(BUFFER,LARGE,db);

    }

}

void search_domain_driver(FILE* db){
    char namef[SMALL]="";
    char namel[SMALL]="";
    int * roll=malloc(sizeof(int));
    int *fees=malloc(sizeof(int));
    char date[SMALL]="";
    char category[SMALL]="";

    char key[SMALL];
    char value_lb='\0';
    char value_ub='\0';
    int int_value_lb=ARBITLARGE;
    int int_value_ub=ARBITLARGE;
    char dat_lb[SMALL] = "";
    char dat_ub[SMALL] = "";
    int using;
    printf("Enter the category(student or staff): ");
    scanf("%s" , category);
    lower_case(category);
    if(strcmp(category , "student")!=0 && strcmp(category , "staff")!=0){
      printf("Invalid category");
      return ;
    }
    printf("Type in the field you want to search by(namef,namel,roll,fees/salary)\n");
    scanf("%s",key);
    lower_case(key);

    if(strcmp(key,"namef")==0 || strcmp(key,"namel")==0){
        printf("Enter Char Values(lower bound and upper bound)\n");
        getchar();
        scanf("%c",&value_lb);
        value_lb = toupper(value_lb);
        getchar();
        scanf("%c",&value_ub);
        value_ub = toupper(value_ub);
        using=USINGCHAR;
    }
    else if(strcmp(key , "roll")==0 || strcmp(key , "fees/salary")==0){
        printf("Enter Integer Value(lower bound and upper bound)\n");
        scanf("%d%d",&int_value_lb,&int_value_ub);
        using=USINGINT;
    }
    else if(strcmp(key , "date")==0){
      printf("Enter the lower bound in DD-MM-YYYY format : ");
      scanf("%s" , dat_lb);
      if(!check_date(dat_lb)){
        printf("Invalid date!");
        return ;
      }
      printf("Enter the upper bound in DD-MM-YYYY format : ");
      scanf("%s" , dat_ub);
        if(!check_date(dat_ub)){
        printf("Invalid date!");
        return ;
      }

      if(pending_or_not(dat_lb , dat_ub)){
        printf("Invalid upper and lower bound values");
      }
    }
    else{
      printf("Invalid option!!");
    }
    if(strcmp(category , "student")==0)
      display_stud();
    else if(strcmp(category , "staff")==0)
      display_staff();
    //printf("nameF        nameL       Roll   Fees      DueDate\n\n");


    domain_call_search(key,value_lb,value_ub,namef,namel,roll,fees,date,category, int_value_lb,int_value_ub,dat_lb , dat_ub , using,db);
}

// int main(void){
//     FILE* db=fopen("db.txt","r");
//     search_domain_driver(db);
//     return 0;
// }
