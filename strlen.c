#include"headers.h"

int main()
{
char s[]="a";
int i=0;
while(s[i++]);
printf("i= %d  strlen= %d \n",i-1,strlen(s));

}
