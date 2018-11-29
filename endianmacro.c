#include"headers.h"

int main()
{
#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
	puts("little endian ");

#else
	puts("big endian ");
#endif
}
