#include <string.h>
#include <stdio.h>

int to_int(char *str)//this function changes a string to an integer
{
	int num = 0;
	int len = strlen(str);
	for(int i = 0; i<len; i++)
	{
		num = num * 10 + (str[i]-'0');//place value is taken into account and the number is incremented in that position by str[i]-'0'
	}
	return num;
}

int check_date(char *str){
  if(strlen(str)!=10)//DD-MM-YYYY has 10 characters, so if a date is given as a string with length different than 10, it is incompatible.
    return 0;

  if(str[2]!='-' || str[5]!='-')//as the date format is [0][1]-[3][4]-[6][7][8][9]; so str[2] and str[5] must be '-'
    return 0;

  int day = 0 , month = 0, year = 0;
  char sub_str_1[4] = "" , sub_str_2[4] = "" , sub_str_3[8] = "";

  for(int i = 0; i<2; i++){
    sub_str_1[i] = str[i];
  }

  for(int i = 3; i<5; i++){
    sub_str_2[i-3] = str[i];
  }

  for(int i = 6; i<10; i++){
    sub_str_3[i-6] = str[i];
  }

  day = to_int(sub_str_1);//creating an integer day formed by passing sub_str_1 to to_int()
  month = to_int(sub_str_2);//creating an integer month formed by passing sub_str_2 to to_int()
  year = to_int(sub_str_3);//creating an integer year formed by passing sub_str_3 to to_int()

  int day_max[12] = {31 , 29 , 31 ,30 , 31 , 30 , 31 , 31 , 30 , 31 , 30 , 31 };
  if(year%4!=0 || (year%100==0 && year%400!=0))//if year is not a leap year, feb has 28 days.
    day_max[1] = 28;

  if(month>12)//integrity check
    return 0;
  if(day>day_max[month-1])//integrity check
    return 0;

  return 1;//if and only if all our cases pass, function check_date() returns 1

}
