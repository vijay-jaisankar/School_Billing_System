
#include <string.h>
#include <stdio.h>
#include<stdlib.h>
#define NULLSTRING "NULLNULLNULL"
#define LARGE 999
#define SMALL 50
#define ARBITLARGE 99999999



void search(char namef[],char namel[],int * roll,int * fees, char date[],FILE* db){

    fscanf(db,"namef=%s namel=%s roll=%d fees=%d date=%s",namef,namel,roll,fees,date);

}

void call_search(char key[], char value[],char namef[],char namel[],int * roll,int * fees, char date[],int int_value,FILE* db){
    char val_temp[SMALL];
    int val_temp_int;
    while(1){
       //printf("%d",feof(db));
        char BUFFER[LARGE];
        search(namef,namel,roll,fees,date,db);
        if(feof(db))
          break;

        fgets(BUFFER,LARGE,db);

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

        if(strcmp(val_temp,value)==0 || val_temp_int==int_value){
            printf("%s      %s      %d      %d      %s\n",namef,namel,*roll,*fees,date );
        }
    }

}

void search_driver(FILE* db){
    char namef[SMALL]="";
    char namel[SMALL]="";
    int * roll=malloc(sizeof(int));
    int *fees=malloc(sizeof(int));
    char date[SMALL]="";

    char key[SMALL]= "";
    char value[SMALL]=NULLSTRING;
    int int_value=ARBITLARGE;

    printf("Type in the field you want to search by(namef,namel,roll,fees,date)\n");
    scanf("%s",key);

    if(strcmp(key,"fees")!=0 && strcmp(key,"roll")!=0 ){
        printf("Enter String Value\n");
        scanf("%s",value);
    }
    else{
        printf("Enter Integer Value\n");
        scanf("%d",&int_value);
    }
    printf("nameF        nameL       Roll   Fees      DueDate\n");

    call_search(key,value,namef,namel,roll,fees,date,int_value,db);
}

 //int main(void){
  //  FILE* db=fopen("db.txt","r");
    /// search_driver(db);
    //return 0;
 //}
