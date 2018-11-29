#include"cheaders.h"

int main(int argc , char **argv)
{
	char str[40]="RajaSara",copy[40];
	int i;
	for(i=0 ; str[i] ;i++)
	{
		copy[i]=str[i];
	}
copy[i]=0; //making the last character to null
printf("original string is :%s\n",str);
printf("copied string is :%s\n",copy);
}
