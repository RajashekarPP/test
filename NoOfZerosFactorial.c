
#include"cheaders.h"

int main()
{
	int n , i, zeros=0, NoOfFives=0, NoOfTwos=0;
	printf("enter the integer to find zeros of its factorial\n");
	scanf("%d",&n);
	for(i=n ; i>0 ;i--)
	{	
		int temp = i;
		while(temp%5==0)
		{
			NoOfFives++;
			temp/=5;
		}
#if 0
		temp=i;
		while(temp%2==0)
		{
			NoOfTwos++;
			temp/=2;
		}
#endif

	}
		printf("NO of tailing zeros is %d\n",NoOfFives);
}
