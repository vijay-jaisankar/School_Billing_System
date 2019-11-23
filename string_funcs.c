#include <string.h>
#include <stdio.h>

int to_int(char *str)
{
	int num = 0;
	int len = strlen(str);
	for(int i = 0; i<len; i++)
	{
		num = num * 10 + (str[i]-'0');
	}
	return num;
}

int check_date(char *str){
  if(strlen(str)!=10)
    return 0;

  if(str[2]!='-' || str[5]!='-')
    return 0;

  int day , month, year;
  char sub_str_1[10] , sub_str_2[10] , sub_str_3[10];

  for(int i = 0; i<2; i++){
    sub_str_2[i] = str[i];
  }

  for(int i = 3; i<5; i++){
    sub_str_2[i] = str[i];
  }

  for(int i = 6; i<10; i++){
    sub_str_3[i] = str[i];
  }
  day = to_int(sub_str_1);
  month = to_int(sub_str_2);
  year = to_int(sub_str_3);

  int day_max[12] = {31 , 29 , 31 ,30 , 31 , 30 , 31 , 31 , 30 , 31 , 30 , 31 };
  if(year%4!=0 || (year%100==0 && year%400!=0))
    day_max[1] = 28;

  if(month>12)
    return 0;
  if(day>day_max[month-1])
    return 0;

  return 1;

}
