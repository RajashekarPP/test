#include"headers.h"


double pow ( double , int );

double  g(int x, int y)
{
	int sigma=33;  // ITs value will be given or we need to clculate
	sigma *= sigma;  // variance if not given
	double value=0;
	int  v=0;

	v=-(( (x*x) + (y*y) )/(2*sigma) );
	value=(1/(2*3.142 * sigma) * pow(2.71828 , v ));
	return value;
}


double pow( double e , int x)
{
	double temp=e;
	if(x>0)
	{
		for( int i=1 ; i<x ; i++)
			temp *= e;
		return temp;
	}
	else
	{	
		x=-x;
		temp=1/e;
		for( int i=1 ; i<x ; i++)
			temp *= 1/e;
		return temp;
	}
}
