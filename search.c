#include <string.h>
#include<stdio.h>
#define LARGE 999
#define SMALL 50

void search(char key,char value[],char attr,char output[]);

void call_search(char key, char value[],char attr,char output[]){
	FILE * db= fopen("db.txt","r");
	char temp_string[LARGE+1];
	fgets(temp_string,LARGE,db);
		printf("%s",temp_string);
	int d =  ftell(db);
	fseek(db , -d , SEEK_CUR);
	char tocheck[SMALL] = "";

	for(int i=0; i < strlen(temp_string);i++){
					printf("%c",temp_string[1]);
		if(temp_string[i]=='/'){
			i++;
			if(temp_string[i]==key){
				i+=2;
				int i_temp=i;
				while(temp_string[i]!='/'){
					tocheck[i-i_temp]=temp_string[i];
					i++;
				}

			}

		}
	}

	fclose(db);

	if(strcmp(tocheck,value)==0){
		search(key,value,attr,output);
	}

}

//will be called by another function that will ensure that it only returns one attribute
void search (char key,char value[],char attr,char output[]){
	FILE * db= fopen("db.txt","r");
	char temp_string[LARGE+1];
	fgets(temp_string,LARGE,db);
	int d =  ftell(db);
	fseek(db , -d , SEEK_CUR);

	for(int i=0; i < strlen(temp_string);i++){
		if(temp_string[i]=='/'){
			i++;
			int i_temp=i;
			if(temp_string[i]==attr){
				i++;
				while(temp_string[i]!='/'){
					output[i-i_temp]=temp_string[i];
					printf("%c\n",output[i-i_temp]);
				}
			}

		}
	}

}

int main(){
	char op[SMALL] = "bio";
	call_search('i',"Krishna Sharma",'f',op);
	printf("%s\n",op);

}
