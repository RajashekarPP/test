#include"cheaders.h"

int main()
{
	char i,a[50];
	puts("enter the string : string end is ! symbol");
	scanf("%[^!]s",a);
	for(i=0 ; a[i]; i++)
		if(9==a[i] || 10==a[i])
			if(9==a[i])
				printf("\\t");
			else printf("\\n");
		else
			printf("%c",a[i]);
	return 0;
}
