#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "util1.h"
#include "search_domain.h"
#include "search.h"
#include "addstudent.h"
#include "delete.h"
#include "string_funcs.h"

int main(int argc , char **argv)
{
	while(1)
	{
		display();
		printf("Enter an option : ");
		char option[100];
		int op = 0;
		scanf("%s" ,  option);
		if(strlen(option)>1)
			printf("Invalid input !!!");
		else if(strlen(option)==1)
			op = option[0]-'0';
		switch(op)
		{
			case 1:{
			  char category[100];
			  printf("Enter the category(student or staff) : ");
			  scanf("%s" , category);
				if(strcmp(category , "student")==0 || strcmp(category , "staff")==0)
				{
					printf("Enter roll no. : ");
					char roll[10];
					int roll_no , flip = 0;
					scanf("%s" , roll);
					for(int i = 0; i<strlen(roll);i++)
					{
						if(roll[i]<'0' || roll[i]>'9')
						{
							flip++;
							break;
						}
					}
					if(flip==0){
						roll_no = to_int(roll);
						FILE *fp = fopen(argv[1] , "r");
						if(check_uniq(fp , roll_no))
						{
							fclose(fp);
							FILE *fp = fopen(argv[1] , "a");
							add_student(fp , roll_no, category);
							fclose(fp);
						}else{
							printf("Invalid roll no!!!");
						}
					}
					else{
						printf("Invalid roll no");
					}
				}
				else
				{
					printf("Invalid category entry");
				}
			}
			break;

			case 2:
			{
				//FILE *fp_2 = fopen(argv[1] , "w");
				printf("Delete by name(choose 1) or roll no(choose 2) : ");
				int op;
				scanf("%d" , &op);
				if(op==1)
				{
					char fname[100] , lname[100];
					printf("Enter first name : ");
					scanf("%s" , fname);
					printf("Enter last name : ");
					scanf("%s" , lname);
					delete_by_name(fname , lname , argv[1]);
				}else if(op==2){
					int roll;
					printf("Enter roll number : ");
					scanf("%d" , &roll);
					delete_by_roll(roll , argv[1]);
				}
				else{
					printf("Invalid input");
				}
			}
			break;
			case 3:
			{
				FILE *fp_3 = fopen(argv[1] , "r"); //declaration
				search_driver(fp_3);
				fclose(fp_3);
			}
			break;
			case 4:
			{
				FILE *fp_4 = fopen(argv[1] , "r");
				search_domain_driver(fp_4);
				fclose(fp_4);
			}
			break;
			case 5:
			printf("Exiting...\n");
			break;
			default:
			printf("\nENTER VALID OPTION\n");
			break;
		}
		if(op==5)
			break;
	}
	return 0;

}
