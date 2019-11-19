void add_student()
{
    char name[80];
    printf("Enter student's name...\n");
    scanf("%s",name);
    char roll[15];
    printf("Enter roll number...\n");
    scanf("%s",roll);
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
        return;
    }
    else
    {
        fprintf(fp,"/i=%s/end//r=%s//end/f=%d/end/d=%s\n",name,roll,due,date);
        fprintf(fp,"name=%s/end/roll=%s/end/fees_due=%d/end/due_date=%s\n",name,roll,due,date);
        fprintf(fp,"/i=%s/end//r=%s//end/f=%d/end/d=%s\n",name,roll,due,date);
        return;
    }
}
