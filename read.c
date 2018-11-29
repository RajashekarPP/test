#include"cheaders.h"

int main()
{
	int fd;
	char buf[100] ,dest[20];
	fd = open("text",O_RDONLY);
//	while(1)
	read(fd , buf , 20 );

	snprintf(dest , 10 ,buf);
	printf("%s\n",dest);
	return 0;
}

