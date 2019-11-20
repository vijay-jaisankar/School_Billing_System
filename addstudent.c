#include<stdio.h>
void add_student()//this function will add the details of one student in the database.
{
    char fname[80],lname[80];
    printf("Enter student's first name...\n");//entering student's first name
    scanf("%s",fname);
    printf("Enter student's last name...\n");//entering student's last name
    scanf("%s",lname);
    int roll;
    printf("Enter roll number...\n");//entering student's roll number
    scanf("%d",&roll);
    int due;
    printf("Enter due amount...\n");//entering due amount
    scanf("%d",&due);
    char date[11];
    printf("Enter the due date in DD-MM-YYYY format...\n");//entering the due date
    scanf("%s",date);
    FILE* fp;//declaring a file pointer
    fp=fopen("database1.txt","a");//we use append mode as we don't want the previous contents to be deleted.
    if(fp==NULL)
    {
        printf("Error opening File! Please try again...\n");//integrity check
        
    }
    else
    {
        fprintf(fp,"namef=%s namel=%s roll=%d fees=%d date=%s\n",fname,lname,roll,due,date);//writing data into file
        
        
    }
    fclose(fp);//closing and flushing the buffer
}
