#include"headers.h"

int main()
{
int a[5]={22,33,44,55,66};
int *p=a;
printf("%d %d %d %d \n",*p,*(p+1),*(p+2),*p);
}
