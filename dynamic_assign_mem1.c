
#include"cheaders.h"

typedef struct node
{
	struct node *next;
	unsigned long int size;
}NODE;

char ch1[200];

int main()
{
	char *ch;
	NODE *head , *b , *c;


	head=ch1;
	head->next = NULL;
	head->size = 34;

	printf("%lu %lu\n",ch ,head);
	
	ch = head;
	ch +=50;
	b= ch;
	b->next= NULL;
	b->size = 34;
	head->next = b;
	
	ch = b;
	ch += 50;
	c= ch;
	c->next = NULL;
	b->next = c;
	c->size = 34;

	printf("head = %lu  head-n = %lu head-n-n = %lu	\n head-s = %lu head-s-s = %lu head-s-s-s = %lu \n",
			head , head->next ,head->next->next ,head->size, head->next->size , head->next->next->size);

	return 0;
}
