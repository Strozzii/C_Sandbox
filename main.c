#include <stdio.h>

void ulam(int a0);

int main()
{
	ulam(7);
}

void ulam(int a0)
{
	if (a0 == 1)
	{
		printf("%d\n", 1);
	}
	else if (a0 % 2 == 1)
	{
		printf("%d\n", a0);
		ulam(3 * a0 + 1);
	}
	else if (a0 % 2 == 0)
	{
		printf("%d\n", a0);
		ulam(a0 / 2);
	}
}