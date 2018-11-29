#include"cheaders.h"

int main(int argc, char **argv)
{
	char src[30]="rajasara",rev[30],temp;
	int i,j;
	scanf("%s",src);
	printf("source string : %s\n",src);
	for(i=0 ;src[i] ;++i);
j=i-1;
	for(i=0;src[i];i++,j--)
	{
		rev[j]=src[i];
	}
	rev[i]=0;
	for(j=i-1,i=0; i<j; i++,j--)
	{
		temp=src[i];
		src[i]=src[j];
		src[j]=temp;
	}
puts(src);
puts(rev);
	return 0;
}
