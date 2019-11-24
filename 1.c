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
	if(argc==2){  //Test Case for invalid number of command-line arguments handled here
		//Infinite loop to display the menu
		while(1)
		{
			display(); //Function defined in util1.c and declared in util1.h to display the menu of options
			printf("Enter an option : ");
			char option[100];
			int op = 0;
			scanf("%s" ,  option);
			//Code to handle cases where user enters invalid options
			if(strlen(option)>1)
				printf("Invalid input !!!");
			else if(strlen(option)==1)
				op = option[0]-'0';

			//Switch Case Block for executing various functions
			switch(op)
			{
				case 1:{ //For Adding new records to the filename specified as command-line argument
				  char category[100];
				  printf("Enter the category(student or staff) : ");
				  scanf("%s" , category);


					if(strcmp(category , "student")==0 || strcmp(category , "staff")==0) //condition to check whether users do not enter invalid category
					{
						printf("Enter roll no. : ");
						char roll[10];
						int roll_no , flip = 0;
						scanf("%s" , roll);
						//To check whether user does not enter invalid roll no
						for(int i = 0; i<strlen(roll);i++)
						{
							if(roll[i]<'0' || roll[i]>'9') //Incase invalid character is entered
							{
								flip++;
								break;
							}
						}
						if(flip==0){ //Conditon for checking validity
							roll_no = to_int(roll); //calling function to convert string to integer (function in defined externally)

							FILE *fp = fopen(argv[1] , "r"); //argv[1] or the second command line argument contains the name of the text file
							if(check_uniq(fp , roll_no)) //calling function to check whether roll number entered is unique
							{
								fclose(fp);
								FILE *fp = fopen(argv[1] , "a");
								add_student(fp , roll_no, category); //calling the function defined to add student in file
								fclose(fp); //Closing the file
							}else{
								printf("Invalid roll no!!!");
							}
						}
						else{
							printf("Invalid roll no!!");
						}
					}
					else
					{
						printf("Invalid category entry");
					}
				}
				break;

				//Deletion of Records
				case 2:
				{
					printf("Delete by name(choose 1) or roll no(choose 2) : ");
					char temp[100];
					int op = 0 , flip = 0;
					scanf("%s" , temp);
					//To check the validity of the option entered by the user
					for(int i = 0; i<strlen(temp); i++){
						if(temp[i]<'0' || temp[i]>'9'){
							flip++;
							break;
						}
					}
					op = to_int(temp); //Conversion of string to integer
					if(op==1 && (!flip))
					{
						//Deletion by name
						char fname[100] , lname[100];
						printf("Enter first name : ");
						scanf("%s" , fname);
						printf("Enter last name : ");
						scanf("%s" , lname);
						delete_by_name(fname , lname , argv[1]); //Calling the function for deletion of a record by name
					}else if(op==2 && (!flip)){
						//Deletion by roll number
						int roll;
						printf("Enter roll number : ");
						scanf("%d" , &roll);
						delete_by_roll(roll , argv[1]);  //Calling the function for deletion of a record by roll number
					}
					else{
						printf("Invalid input");
					}
				}
				break;

				//Searching records
				case 3:
				{
					FILE *fp_3 = fopen(argv[1] , "r"); //declaration of File pointer
					search_driver(fp_3); //Calling function to search a particular record
					fclose(fp_3);
				}
				break;

				//Searching a range of records(Domain based searching)
				case 4:
				{
					FILE *fp_4 = fopen(argv[1] , "r");
					search_domain_driver(fp_4); //Calling function for the same
					fclose(fp_4);
				}
				break;
				//Exiting the software
				case 5:
				printf("Exiting...\n");
				break;

				//Incase user enters invalid option
				default:
				printf("\nENTER VALID OPTION\n");
				break;
			}
			if(op==5) //For exiting the interface
				break;
		}
	}
		else{
			printf("Invalid number of arguments !!!\n");
		}
	return 0;

}
