
/// Implementing of the threads where two threads are created one will be printing odd sequence and other will be printing even sequence //


#include"headers.h"

pthread_t tid1,tid2;

void *f1(void *p)
{
	puts("in f1");
	printf("%s\n",(char *)p);
	sleep(1);
	for(int i=2;i<100;i+=2)
		printf("%d ",i);	
	puts("");
	while(1);
	pthread_exit(NULL);
}

void *f2(void *p)
{

	puts("in f2");
	sleep(1);
	for(int i=1;i<100;i+=2)
		printf("%d ",i);
	puts("");
	pthread_exit(NULL);
}

int main()
{
	pthread_t tid1,tid2;
	pthread_create(&tid1,NULL,f1,"raja");
	pthread_create(&tid2,NULL,f2,NULL);
//	sleep(1); //  If not present output will not be displayed as threads will not be attached
// to attach the threads use the below functions
//	pthread_join(tid2,NULL);
	pthread_join(tid1,NULL);
	return 0;
}
