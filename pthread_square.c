#include"cheaders.h"

pthread_t tid;
int a;

void *square(void *p)
{
	a*=a;
	printf("sqaure is %d\n",a);
}

int main()
{
	puts("enter the value to find square");
	scanf("%d",&a);
	pthread_create(&tid,NULL,square,NULL);
	pthread_join(tid,NULL);
	return 0;
}
