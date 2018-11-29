#include<stdio.h>
#include<stdlib.h>

int main()
{
	int ch;
	printf("In main\n");
	while(1)
	{
		puts("enter int");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1 :exit(0);
			default : puts("nothing");
		}






	}

puts("exiting from main");
return 0;

}
