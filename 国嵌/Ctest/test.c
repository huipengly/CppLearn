#include <stdio.h>

void test(int &a)
{
	a += 10;
}

int main()
{
	int b = 1;
	test(b);
	printf("%d\n", b);
	return 0;
}
