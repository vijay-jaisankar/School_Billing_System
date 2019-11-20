#include<stdio.h>
void add_student()//this function will add the details of one student in the database.
{
    char name[80];
    printf("Enter student's name...\n");//entering student's name
    scanf("%s",name);
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
        fprintf(fp,"/i=%s/end//r=%d//end/f=%d/end/d=%s\n",name,roll,due,date);
        fprintf(fp,"name=%s/end/roll=%d/end/fees_due=%d/end/due_date=%s\n",name,roll,due,date);//writing data into file
        fprintf(fp,"/i=%s/end//r=%d//end/f=%d/end/d=%s\n",name,roll,due,date);
        
    }
    fclose(fp);//closing and flushing the buffer
}
