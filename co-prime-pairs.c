
//perfectly co-primes are not found first

#include"cheaders.h"

int checkprime(int);


#if 0
int main()
{
	int N ,i ,ele=1 ,j;
	int *a=NULL;
	printf("enter the product of co prime no\n");
	scanf("%d",&N);
	for(i=2 ; i<=N; i++)
	{
		if(checkprime(i))
		{ 
			a=realloc(a , ele*sizeof(int));
			//printf("no of elements = %d\n",sizeof(a)/4);
			a[ele-1]=i;
			ele++;
		//	printf("ele %d\n",ele);
		//	printf("%d\n",a[ele-2] );
		}
	}

#if 0
	puts("all prime no");
	for(i=0 ; i< ele-1  ; i++)
	{
		printf("%d\n",a[i]);
	}
#endif

	for(i=0 ; i< ele-1 ; i++)
	{
		int temp=a[i];
		printf("%d\n",a[i]);
		for(j=2 ; j <=N/2; j++)
		{
			if(j%a[i]==0) continue;
			if(temp * j == N)
			{
				printf("%d %d\n",temp,j);
			}
		}
	}

	return 0;
}



int checkprime(int i)
{	
	//printf(" testing prime %d\n",i);
	int j ;
	if(i==2) return 1;
	if(i==3) return 1;
	if(i%2 ==0) return 0;
	for(j=3 ; j <i/2; j+=2)
	{
		if(i % j==0) return  0;
	}
	return 1;
}


#endif





int main()
{





}
