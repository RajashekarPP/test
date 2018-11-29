#include"cheaders.h"
void *thread_child(void*);
void *thread_main(void*);

pthread_t tid_main,tid_child;

void *thread_main(void *p)
{
	puts("1");
	pthread_create(&tid_child,NULL,thread_child,NULL);
	//sleep(1);
	puts("3");
	//pthread_exit(NULL);
	return;
}

void *thread_child(void *p)
{
	puts("2");
	sleep(3);
	puts("5");
	return;
}



int main(int argc , char **argv)
{
	pthread_create(&tid_main,NULL,thread_main,NULL);		
//	pthread_join(tid_main,NULL);//this waits untill the thread specified by it is terminated	
	puts("4");
	//sleep(3);
	puts("6");
	return 0;
}
