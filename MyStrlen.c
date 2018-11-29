#include"cheaders.h"

int main(int argc , char **argv)
{
	char str[30]="RajaSara";
	int le;
//	puts("enter a string");
//	fgets(str,30,stdin);
	for(le=0;str[le];le++);
	printf("Length is %d\n",le);
	return 0;
}
