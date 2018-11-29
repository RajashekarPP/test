#include"cheaders.h"

void *MyMalloc(unsigned int);
void Myfree(void *);

typedef struct node 
{
	struct node *next;
	unsigned long int size;
}NODE;

static char a[1000] ;
static char  *last=NULL;

static unsigned long int  headersize ,bytesfree , bytesallocated , cnt=0 ;

NODE *head = (NODE *) a;
int main()
{
	char *p,*q,*r,*s,*t,*u;
	headersize =  sizeof(NODE);
	bytesfree = sizeof(a);
	last = a+sizeof(a);
//	printf("size of header = %lu \n",headersize);
	printf("starting address of DMA = %lu\n",(long unsigned )a);

	head->next = NULL;
	head->size = 0;
	p=MyMalloc(84);
	printf("p = %lu \n",(unsigned long)p);
	q=MyMalloc(84);
	printf("q = %lu\n",(unsigned long )q);
	r=MyMalloc(84);
	printf("r = %lu\n",(unsigned long )r );
	s=MyMalloc(84);
	printf("s = %lu\n",(unsigned long )s );
	t=MyMalloc(84);
	printf("t = %lu\n",(unsigned long )t );
	printf("p = %lu q= %lu r = %lu s = %lu t = %lu\n",(unsigned long)p,(unsigned long )q ,(unsigned long )r,(unsigned long )s, (unsigned long)t );
	printf("cnt = %lu \n",cnt);

int i;
printf("** cnt = %d\n",cnt);
	NODE *dup;
	dup = head;
	for(i=1 ; i<=cnt ;i++)
	{
		printf(" NODE %d = %lu \n",i,(unsigned long)dup );
		dup = dup->next;
	}
	Myfree(q);
	q = NULL;
	Myfree(s);
	s = NULL;
	printf("head = %lu \n",(unsigned long )head);

printf("** cnt = %d\n",cnt);
	dup = head;
	for(i=1 ; i<=cnt ;i++)
	{
		printf(" NODE %d = %lu \n",i,(unsigned long)dup );
		dup = dup->next;
	}

//	printf("cnt = %lu \n",cnt);
	q = MyMalloc(84);
printf("** cnt = %d\n",cnt);
	dup = head;
	for(i=1 ; i<=cnt ;i++)
	{
		printf(" NODE %d = %lu \n",i,(unsigned long)dup );
		dup = dup->next;
	}
//	printf("p = %lu q= %lu r = %lu s = %lu t = %lu\n",(unsigned long)p,(unsigned long )q ,(unsigned long )r,(unsigned long )s, (unsigned long)t );
//	printf("cnt = %lu \n",cnt);

	return 0;
}


void * MyMalloc(unsigned int size)
{
	char *ptr= NULL;
if(bytesfree > size+headersize )
{
// Inserting first NODE
	if(cnt == 0 )
	{
		ptr= (char *)head;
		head->size= size;
		head->next = NULL;
		ptr = ptr + headersize;
		cnt++;
		bytesfree -= (headersize+size) ;
		return ptr;
	}
// Inserting second Node 
	if(cnt ==1 )
	{
		ptr = (char *)head + headersize + head->size;
		//printf("ptr = %lu \n", ( unsigned long )ptr);
		if(last-ptr >= size + headersize)
		{
			head->next = (NODE *)ptr;
			head->next->next=NULL;
			head->next->size = size;
			bytesfree -= (headersize+size) ;
			ptr += headersize;
			cnt++;
			return ptr;
		}
		return NULL;
	}
	
	int i;
	NODE *temp=NULL;
	temp = head;

	for(i=1;i<cnt;i++)
	{
		ptr =  (char*)temp;
		//printf(" difference = %ld \n", ((long int)temp->next - (long int)temp - (long int)temp->size)- (long int )headersize );
		if( (long int)temp->next - (long int)temp - (long int)temp->size >= (long int)size)
		{
			puts("*************************");
			NODE *new = NULL;
			ptr +=  headersize;
			ptr  += temp->size; 
			new = (NODE *)ptr;
			new->next = temp->next;
			new->size = size;
			temp->next = new;
			ptr +=  headersize;
			return ptr;		
		}
		temp = temp->next;
	}

ptr = (char *)temp;
ptr += temp->size ;
ptr +=  headersize;

// Inesrting node at last 
	if( last - ptr  - headersize  >= size )
	{
		NODE *new = NULL;
		new= (NODE *)ptr;
		new->next = NULL;
		new->size = size;
		temp->next = new;
		cnt++;
		bytesfree -= (headersize+size) ;
		//puts("third alloc");
		ptr += headersize;
		return ptr;
	}
//Allocating of discontinous blocks of memory to avoid fragmentation
//virtual address mapping is required

	return NULL;
}

return NULL;
}

void Myfree(void *p)
{
	char *ptr;
	ptr = (char *)p;
	ptr -= headersize;
	NODE *temp0,*temp1,*temp2;
	temp1 = (NODE *)ptr;
	printf("NODE to b deleted is %lu \n",(unsigned long) temp1);
	temp0=head;

	if(temp1 == head)
	{
		puts("freeing FIRST node");
		head = head->next;
		cnt--;
		return;
	}
	while(temp0 != temp1)
	{
		temp2 = temp0;
		temp0 = temp0->next;
	} 
	temp0 = temp2;
	printf("prev NODE = %lu NODE to delete = %lu \n",(unsigned long)temp0, (unsigned long)temp1);
	
	if(temp1->next == NULL)
	{
		puts("freeing last NODE");
		temp0->next = NULL;
		temp0->size = 0;
		cnt--;
		return;
	}
puts("freeing middle node");
	temp0->next = temp1->next;
	cnt--;
	return;
}
