#include <string.h>
#include <stdio.h>
#include <ctype.h>
//Function to convert String to integer
int to_int(char *str)
{
	int num = 0;
	int len = strlen(str); //Length of string
	for(int i = 0; i<len; i++)
	{
		num = num * 10 + (str[i]-'0');
	}
	return num; //Returns the number
}

//Function to check validity of date
int check_date(char *str){
  if(strlen(str)!=10) //Since date is in DD-MM-YYYY format length of string should be 10
    return 0;

  if(str[2]!='-' || str[5]!='-') //the separator should be a hiffen as per the format
    return 0;

  int day = 0 , month = 0, year = 0; //Variables to store the values of day year and month respectively
  char sub_str_1[4] = "" , sub_str_2[4] = "" , sub_str_3[8] = ""; //Sub strings containing the values of day , month .year respectively

  for(int i = 0; i<2; i++){
    sub_str_1[i] = str[i];
  }

  for(int i = 3; i<5; i++){
    sub_str_2[i-3] = str[i];
  }

  for(int i = 6; i<10; i++){
    sub_str_3[i-6] = str[i];
  }

	//Conversion of substrings into integers
  day = to_int(sub_str_1);
  month = to_int(sub_str_2);
  year = to_int(sub_str_3);

  int day_max[12] = {31 , 29 , 31 ,30 , 31 , 30 , 31 , 31 , 30 , 31 , 30 , 31 }; //Array containing the maximum number of days in each month

	//Condition to check leap year
  if(year%4!=0 || (year%100==0 && year%400!=0))
    day_max[1] = 28;

	//Condition to check month
  if(month>12)
    return 0;

	//Condition to check day
  if(day>day_max[month-1])
    return 0;

  return 1;
}

//Function to convert all letters of the string to lowercase
char *lower_case(char *str){
		int len = strlen(str);
		for(int i = 0; i<len; i++){
			str[i] = tolower(str[i]); //Using tolower function of ctype.h file
		}
		return str;
}

//Function to check whether due date has passed
int pending_or_not(char *str1, char *str2){

	int day_1 = 0 , year_1 = 0 , month_1 = 0, day_2 = 0 , month_2 = 0 , year_2 = 0; //Varibles to store day , year and month respt. according to the first parameter
	char sub_str_1[4] = "" , sub_str_2[4] = "" , sub_str_3[8] = ""; //Substrings for the same

	for(int i = 0; i<2; i++){
		sub_str_1[i] = str1[i];
	}

	for(int i = 3; i<5; i++){
		sub_str_2[i-3] = str1[i];
	}

	for(int i = 6; i<10; i++){
		sub_str_3[i-6] = str1[i];
	}

	//Conversion of substrings into integers
	day_1 = to_int(sub_str_1);
	month_1 = to_int(sub_str_2);
	year_1 = to_int(sub_str_3);

	for(int i = 0; i<2; i++){
		sub_str_1[i] = str2[i];
	}

	for(int i = 3; i<5; i++){
		sub_str_2[i-3] = str2[i];
	}

	for(int i = 6; i<10; i++){
		sub_str_3[i-6] = str2[i];
	}

	//Converion of substrings into integers
	day_2 = to_int(sub_str_1);
	month_2 = to_int(sub_str_2);
	year_2 = to_int(sub_str_3);

	//Condtions to check whether date_1(str1) is earlier than date_2(str2) or not
	if(year_1<year_2)
		return 0;
	else if(year_1>year_2)
		return 1;

	if(month_1<month_2)
		return 0;
	else if(month_1>month_2)
		return 1;

	if(day_1<day_2)
		return 0;
	else if(day_2<day_1)
		return 1;

	return 1;
}
