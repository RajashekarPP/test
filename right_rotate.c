#include"cheaders.h"

#define rightrot(a,b) a=a>>b

int main()
{
	int a= 0xfc,no_of_bits=2;
	rightrot(a,no_of_bits);
	puts("after rotating");
	printf("%x\n",a);
	return 0;
}
