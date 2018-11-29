#include"cheaders.h"

int main()
{
	char a[10]="123456789",b[10]={0};
	int  a1[10]={1,2,3,4,5,6},b1[10];
	swab(a,b, strlen(a));
	swab(a1,b1,24);
	printf("%s %s\n",a,b);
	for(int i=0;i<6;i++)
		printf("%d %d \n",a1[i],b1[i]);

}
