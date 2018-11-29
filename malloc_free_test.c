#include"cheaders.h"


int main()
{
	char *p ,*q ,*r,*s;
	p=malloc(1000);
	q=malloc(30);
	r=malloc(50);
	printf("%lu %lu %lu\n",p,q,r);
	free(p);
	p=malloc(10);
	s=malloc(10);
//	s=malloc(300);
//	printf("%lu %lu  %lu %lu\n",p ,s,q,r);
	printf("%lu %lu %lu %lu\n",p,s,q,r);
	return 0;

}
