#include"cheaders.h"


char buf[4000],destbuf[4000];

int main()
{
	FILE  *fp;
	int i;
	char src[10],name[20]="image";
	srand(getpid());
while(1)
{
	for(i=0 ; i<9 ;i++)
	{
		src[i]=rand()%26+65;
	}
	src[9]=0;
	strcpy(name+5,src);
	fp = fopen(name,"w");
        perror("open");
	gets(buf);
       	fwrite( buf, strlen(buf) ,1, fp);
        fclose(fp);
	puts("data written to file is :");
	fp = fopen(name,"r");
        perror("reopen");
	fread(destbuf,4000,1,fp);
	printf("%s\n",destbuf);
        fclose(fp);
	memset( &buf,0,sizeof(buf) );
	memset( &destbuf,0,sizeof(buf) );
}
}
