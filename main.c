#include <stdio.h>

void addAndPrint(int a, int b){
	int sum = a + b;
	printf("Die Summe beträgt: %d \n", sum); //Option,Shift,7
}

int main()
{
	addAndPrint(1, 7);

	int num = 100;

	while (num / 2 > 10){
		num = num / 2;
	}

	printf("%d", num);

	return 0;
}
