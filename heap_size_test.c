#include"cheaders.h"

int main()
{
#if 1
	char *p=NULL;
	size_t oneMB=1024*1024*30;
	size_t allocated = 0;
	do
	{
		#if 0
		if(p)
		{
			//printf("tested size is %ld\n",allocated/1024);
			free(p);
		}
		#endif
		allocated += oneMB;
	//	usleep(10);
	printf("tested size is %ld GB\n",allocated/(1024*1024*1024));
		p=(char *)malloc(allocated);
	//	printf("%lu ",p);
	}while(p);

	printf("tested size is %ld GB\n",allocated/(1024*1024*1024));
#endif

//char a[8][1000000];
puts("end");
	return 0;
}
