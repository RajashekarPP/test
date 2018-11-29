#include"headers.h"

void isr(int n)
{
	printf("caught signal  %d\n",n);
	return;
}

main()
{
	signal(2,isr);
	puts("in main function ");
	if(fork())
	{
		pause();
		puts("exiting from  parent ");

	}
	else

	{
		sleep(1);
		puts("exiting from  child ");
	}
	exit(0);
}
