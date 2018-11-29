#include"cheaders.h"

void * mymalloc(size_t);
void  myfree(void *);

char a[1000];  // used as heap area 
static void *base , *upper;

typedef struct block
{
	struct block *next;
	unsigned size;
}HEADER;

static HEADER *head = NULL;

int main()
{
	char *p , *q ,*r;
	head = malloc(sizeof(HEADER));
	if(!head)
	{
		puts("memory allocation failed");
		return -1;
	}

	head->size = sizeof(a);
	head->next = NULL;
	base = upper = a;	
	printf("base addres = %p \n",base);
	p = (char *)mymalloc(100);
	printf("base addres p  = %p \n",p);
	q = (char *)mymalloc(300);
	printf("base addres q  = %p \n",q);
	r = (char *)mymalloc(800);
	printf("base addres = %p \n",r);

	if(p)
		puts("memory allocation sucess for p");

	if(q)
		puts("memory allocation sucess for q");

	if(r)
		puts("memory allocation sucess for r");

	myfree(p);
	myfree(q);
	myfree(r);

//	r = mymalloc(800);

	if(r)
		puts("memory allocation sucess for r");

//	free(r);	

	return 0;
}

void * mymalloc(size_t size)
{

	HEADER *new , *temp;
	temp = head;
	void *ptr;
	if( size <= head->size)
	{
		if(!(head->next))
		{
			new = (HEADER *)base;
			head->next = new ;
			new->next = head;
			new->size = size + sizeof(HEADER);
			ptr = base + sizeof(HEADER);  // allocation of memory for first malloc calling 
			upper = base + size + sizeof(HEADER);
			return ptr;
		} 

		while(temp->next != head)
		{
			if((temp - temp->next - 2*sizeof(HEADER)) >= size)
			{
				base = temp+temp->size;	// the two statements below can be combined and wriiten
				new = base;
				ptr = base;
				new->size = size+sizeof(HEADER);
				new->next = temp->next;
				temp->next = new;
				return ptr;
			}
			temp = temp->next;
		}

		if( ( head+sizeof(a) - temp+temp->size) >= size + sizeof(HEADER) )  //Last byte address - last block/node end address
		{
			ptr = new = temp+temp->size;
			new->size = size+sizeof(HEADER);
			new->next = head;
			temp->next = new;
			return ptr;
		}

		return NULL;
	}
	else
	{
		return NULL;
	}
}

void myfree(void *p)
{
	puts("NOtHING DONE SO FAR");
}
