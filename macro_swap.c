#include"cheaders.h"

#define FLOAT
#define INTEGER

#ifdef INTEGER
#define swap(t,x,y) t temp;\
		temp=x;\
		x=y;\
		y=temp
#endif

int main()
{
#ifdef INTEGER
	int i1=10,i2=20;
	puts("Before swapping");
	printf("i1 = %d i2 = %d\n",i1,i2);
	swap(int,i1,i2);
	puts("After swapping");
	printf("i1 = %d i2 = %d\n",i1,i2);
#endif

#ifdef FLOAT
#define swap(t,x,y) t temp1;\
                temp1=x;\
                x=y;\
                y=temp1
#endif

#ifdef FLOAT
	float f1=11.11,f2=22.22;
	printf("f1 = %f f2 = %f\n",f1,f2);
	swap(float,f1,f2);
	puts("After swapping");
	printf("f1 = %f f2 = %f\n",f1,f2);
#endif
	return 0;
}
