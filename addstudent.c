#include<stdio.h>
void add_student()
{
    char name[80];
    printf("Enter student's name...\n");
    scanf("%s",name);
    int roll;
    printf("Enter roll number...\n");
    scanf("%d",&roll);
    int due;
    printf("Enter due amount...\n");
    scanf("%d",&due);
    char date[11];
    printf("Enter the due date in DD-MM-YYYY format...\n");
    scanf("%s",date);
    FILE* fp;
    fp=fopen("database1.txt","a");
    if(fp==NULL)
    {
        printf("Error opening File! Please try again...\n");
        
    }
    else
    {
        fprintf(fp,"/i=%s/end//r=%d//end/f=%d/end/d=%s\n",name,roll,due,date);
        fprintf(fp,"name=%s/end/roll=%d/end/fees_due=%d/end/due_date=%s\n",name,roll,due,date);
        fprintf(fp,"/i=%s/end//r=%d//end/f=%d/end/d=%s\n",name,roll,due,date);
        
    }
    fclose(fp);
}
