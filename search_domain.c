#include <string.h>
#include <stdio.h>
#include<stdlib.h>
#define NULLSTRING "NULLNULLNULL"
#define LARGE 999
#define SMALL 50
#define ARBITLARGE 99999
#define USINGINT 1
#define USINGCHAR 0



void domain_search(char namef[],char namel[],int * roll,int * fees, char date[],FILE* db){

    fscanf(db,"namef=%s namel=%s roll=%d fees=%d date=%s",namef,namel,roll,fees,date);

}

void domain_call_search(char key[], char value_lb,char value_ub,char namef[],char namel[],int * roll,int * fees, char date[],int int_value_lb,int int_value_ub,int using,FILE* db){
    char val_temp[SMALL]="";
    int val_temp_int=LARGE;
    while(1){
       // printf("%d",feof(db));
        char BUFFER[LARGE];
        domain_search(namef,namel,roll,fees,date,db);

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
        else if(strcmp(key,"fees")==0){
            val_temp_int=*fees;
        }

        if(using){
            if(val_temp_int<=int_value_ub && val_temp_int>= int_value_lb){
                printf("%s      %s      %d      %d      %s\n",namef,namel,*roll,*fees,date );
            }
        }
        else{
            if(val_temp[0]<=value_ub && val_temp[0]>=value_lb){
                printf("%s      %s      %d      %d      %s\n",namef,namel,*roll,*fees,date );
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

    char key[SMALL];
    char value_lb='\0';
    char value_ub='\0';
    int int_value_lb=ARBITLARGE;
    int int_value_ub=ARBITLARGE;
    int using;

    printf("Type in the field you want to search by(namef,namel,roll,fees)\n");
    scanf("%s",key);

    if(strcmp(key,"fees")!=0 && strcmp(key,"roll")!=0 ){
        printf("Enter Char Values(lower bound and upper bound)\n");
        getchar();
        scanf("%c",&value_lb);
        getchar();
        scanf("%c",&value_ub);
        using=USINGCHAR;
    }
    else{
        printf("Enter Integer Value(lower bound and upper bound)\n");
        scanf("%d%d",&int_value_lb,&int_value_ub);
        using=USINGINT;
    }
    printf("nameF        nameL       Roll   Fees      DueDate\n\n");


    domain_call_search(key,value_lb,value_ub,namef,namel,roll,fees,date,int_value_lb,int_value_ub,using,db);
}

// int main(void){
//     FILE* db=fopen("db.txt","r");
//     search_domain_driver(db);
//     return 0;
// }
