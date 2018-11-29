#include"cheaders.h"
void recursive_reverse(char *);

static int i,j;

int main()
{
	char a[100];
	puts("enter the string to be reversed");
	scanf("%s",a);
	printf("entered string is : %s\n",a);	
	j=strlen(a)-1;
	recursive_reverse(a);
	printf("string after reversing is : %s\n",a);
	return 0;
}

void recursive_reverse(char *p)
{
	char temp;
	if(i<j)
	{
		temp=p[i];
		p[i]=p[j];
		p[j]=temp;
		i++,j--;
		recursive_reverse(p);
	}
	return;

}
