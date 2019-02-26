#include <stdio.h>

int main(int argc, char const *argv[])
{	

	double num, total;
	total=1;
	
	printf("Porfavor, indique el número del cual quiere hallar su factorial\n");

	scanf("%lf",&num);

	for (int i = 1; i <= num; ++i)
	{
		total=total*i;
	}

	printf("El factorial de %.0f es %.0f.\n",num, total);

	return 0;
}