#include"cheaders.h"

int main(int argc , char **argv)
{
	int i,a[10];
	char ch[10];
	for(i=0;i<10 ;i++)
	{
		a[i]=(rand()/getpid())%300;
	}

	for(i=0;i<10 ;i++)
	{
		printf("%d %x\t",a[i],a[i]);
	}
puts("");
	for(i=0;i<10 ;i++)
	{
		ch[i]=a[i];
	}
	for(i=0;i<10 ;i++)
	{
		printf("%d ",ch[i]);
	}

puts("");	
return 0;
}
