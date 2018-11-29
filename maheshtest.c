#include"headers.h"



/* if mathematical problem given is of thie type 

sum[n]=y[n]+x[n-1];


*/




int *claculatesum( int *y , int *x , int n )
{
static int  sum[n];
int i;
	for(i=0;i<n;i++)
	{
		sum[i]=y[i]+x[i-1];
					
	}

return sum;
}
