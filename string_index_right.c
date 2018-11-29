#include"cheaders.h"

int main()
{	
	int index=0;
	char str[100],substring[20],*ptr=NULL;
	puts("enter the main string");
	scanf("%[^\n]s",str);
getchar();
	puts("enter the substring");
	scanf("%[^\n]s",substring);
	ptr=str;
	printf("%s\n%s\n",ptr,substring);
	while(ptr=strstr(ptr,substring))
	{
		index=ptr-str;
		ptr+=strlen(substring);
	}
	if(0==index)
	printf("string not found");
	else
	printf("string found at %d\n",index);
	return 0;
}
