#include<stdio.h>

int fun(int count)
{
	printf("%d\n", count);
	if(count < 3) {
		fun(fun(fun(++count)));
	}
	return count;
}

int main()
{
	fun(1);
	return 0;
}
