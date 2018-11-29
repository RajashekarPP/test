#include"cheaders.h"

void * mymalloc(size_t);
void  myfree(void *);

char a[10000];  // used as heap area 

static unsigned int count = 0;
static void *base , *last;

int bytesfree;

typedef struct block
{
	struct block *next;
	unsigned long int size;
}HEADER;

//static HEADER *head = NULL;

HEADER *head = (HEADER *)&a;
int main()
{
	char *p , *q , *r ;
//	head = malloc(sizeof(HEADER));
//	HEADER *head = &a;
	head->next = NULL;
	head->size = 0;
	
	bytesfree = sizeof(a);

	if(!head)
	{
		puts("memory allocation failed");
		return -1;
	}

printf("size of structure is = %lu \n", sizeof(HEADER));
//	head->size = sizeof(a);
//	head->next = NULL;
	base  = a;	
	last = a+sizeof(a);
	printf("base addres = %lu \n",(long unsigned )a);
	printf("last address = %lu \n",(long unsigned )last);
	p = (char *)mymalloc(84);
	printf("base addres p  = %lu \n",(long unsigned )p);
	q = (char *)mymalloc(184);
	printf("base addres q  = %lu \n",(long unsigned )q);
	r = (char *)mymalloc(284);
	printf("base addres r = %lu \n",(long unsigned )r);

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
	HEADER *new=NULL , *temp=NULL;
	temp = head;
	void *ptr;

	printf("bytes free = %d \n",bytesfree);
	if( size <= bytesfree)
	{
		if(!(temp->next))  // this means that it is the first node
		{
			puts("Only once");
			head->next = a+size+sizeof(HEADER);
			//printf("head->next = %lu \n",head->next);
			head->size = size;
			new = (HEADER *)head->next;
			new->next = NULL;
			new->size = 0;
			bytesfree = bytesfree-( size+sizeof(HEADER));
			//printf("head->next = %lu and head->next->size =  %ld \n",head->next , head->next->size);
			ptr = base + sizeof(HEADER);  // allocation of memory for first malloc calling 

			//printf("temp->next = %lu\ntemp = %lu \n header size = %lu\n temp-size=%lu\n",temp->next , temp , sizeof(HEADER) ,temp->size );
			//puts("");
			//puts("**** returning in first if block *****");
			//printf("ptr = %lu \n",ptr);
			count++;
			return ptr;
		} 

if(count == 1)
{
	if( ((HEADER *)last - temp - sizeof(HEADER) - temp->size )  >= (size + sizeof(HEADER)) )  //Last byte address - last block/node end address
		{	
			unsigned long int  assign;
			puts("***** second case *****");
			assign = (unsigned long)temp;
			assign += (unsigned long)temp->size;
			assign += 16;
//			printf("temp = %lu temp->size = %lu sizeH = %lu\n",temp,temp->size,sizeof(HEADER) );
//			printf("new = %lu \n",new);
			new = (HEADER *)assign;
//			printf("new = %lu \n",new);
			new->size = 0;
			new->next = NULL;
			temp->next = new;
			bytesfree = bytesfree - sizeof(HEADER) - size ;
//			printf("new = %lu \n",new);
			new = (HEADER *)assign +16;
//			printf("new = %lu \n",new);	
			ptr = (void *)new;
			puts("checking whether data is saved properly in node r not");
			printf("head->size = %lu head-s-s = %lu\n",head->size,head->next->size);
			puts("########## returning from last if block ########");
			count++;
			return ptr;
		}
}

//printf("temp -> next = %lu \n", temp->next);
//printf("bytes free = %d \n",bytesfree);

int i;
		for(i=1 ;i<count ;i++)
		{
			printf("This case has to be entered for third case only \n");
			//printf("temp->next = %lu\ntemp = %lu \n header size = %lu\n temp-size=%lu\n",temp->next , temp , sizeof(HEADER) ,temp->size );
			//puts("");
			int lvalue =0 ,rvalue = temp->size;
			lvalue = (int )temp->next;
			lvalue -= (int)temp;
			lvalue -= 16;
			printf("lvalue = %d rvalue = %d\n" ,lvalue,rvalue);
			if(lvalue == rvalue)
			{
				puts("%%%%%%%%%% skipping cases %%%%%%%%%%%%%%%%");
				printf(" temp - size = %lu ",temp->size); 
				temp = temp->next;
				printf(" temp - size = %lu ",temp->size); 
//				puts("*********** if **************");
		//	printf("temp->next = %lu\ntemp = %lu \n header size = %lu\n temp-size=%lu\n",temp->next , temp , sizeof(HEADER) ,temp->size );
				continue;
				puts("********* use less statement ***********");
			}
	//		temp = temp->next;
			//printf(" temp->next = %lu \n",temp->next);
	//		printf("temp->next = %lu\ntemp = %lu \n header size = %lu\n temp-size=%lu\n",temp->next , temp , sizeof(HEADER) ,temp->size );
	//		puts("");
//	#if 1
			else
			{
				puts("*********** else **************");
			//printf("temp->next = %lu\ntemp = %lu \n header size = %lu\n temp-size=%lu\n",temp->next , temp , sizeof(HEADER) ,temp->size );
			//printf("temp->next = %lu\ntemp = %lu \n header size = %lu\n temp-size=%lu\n",temp->next , temp , sizeof(HEADER) ,temp->size );
			//	printf(" *** %ld %ld \n" , (temp->next - temp -sizeof(HEADER)-temp->size ), (size + sizeof(HEADER) ) );
				if(((temp->next - temp -sizeof(HEADER))-temp->size) > (size + sizeof(HEADER) ) )
				{
					puts("loop not to be used");
					new = temp + sizeof(HEADER) + temp->size;
					new->next = temp->next;
					new->size = size;
					temp->next = new;
					bytesfree = bytesfree - (size +sizeof(HEADER) );
					ptr = new + sizeof(HEADER);
					puts("**** returning in else block *****");
					count++;
					return ptr;
				}
			temp = temp->next;
			}
//	#endif

		}
//		printf("temp = %ld \n",temp);
//		temp = temp->next;

//		printf("***last =  %ld temp  = %ld ***\n",(HEADER *)last , temp  );
//		printf(" size = %ld \n",size);
		//printf("temp = %ld \n",temp);
	long int lvalue=0,rvalue=0;

if( ((HEADER *)last - temp - sizeof(HEADER) - temp->size )  >= (size + sizeof(HEADER)) )  //Last byte address - last block/node end address
		{	
			unsigned long int  assign;
			puts("***** last loop  case *****");
			assign = temp;
			assign += temp->size;
			assign += 16;
//			printf("temp = %lu temp->size = %lu sizeH = %lu\n",temp,temp->size,sizeof(HEADER) );
			printf("assign= %lu \n",(long unsigned)new);
			new = (HEADER *)assign;
//			printf("new = %lu \n",new);
			new->size = 0;
			new->next = NULL;
			temp->next = new;
			bytesfree = bytesfree - sizeof(HEADER) - size ;
//			printf("new = %lu \n",new);
			new = assign +16;
			printf("new = %lu \n",(long unsigned )new);	
			ptr = new;
			puts("########## returning from last if block ########");
			count++;
			return ptr;
		}




//	printf(" %ld *  %ld *  %ld * %ld *  %ld *\n",(HEADER *)last , temp ,sizeof(HEADER),temp->size, size  ); 	

//	lvalue = (HEADER *)last - temp - sizeof(HEADER) - temp->size ;
//	rvalue = size + sizeof(HEADER);  //Last byte address - last block/node end address
	
//	printf("lvalue = %ld rvalue = %ld \n",lvalue , rvalue);


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
