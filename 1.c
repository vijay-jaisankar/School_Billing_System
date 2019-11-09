#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "util1.h"
int main(int argc , char **argv)
{
	while(1)
	{
		display();
		printf("Enter an option : ");
		int op;
		scanf("%d" , &op);
		switch(op)
		{
			case 1:
			printf("ADD\n");
			break;
			case 2:
			printf("SUB\n");
			break;
			case 3:
			printf("Ser\n");
			break;
			case 4:
			printf("exit\n");
			break;
			default:
			printf("\nENTER VALID OPTION\n");
			break;
		}
		if(op==4)
			break;
	}

	return 0;		

}

		
