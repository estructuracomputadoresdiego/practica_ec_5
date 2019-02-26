#include <stdio.h>

int main(int argc, char const *argv[])
{
	int m,n,total;

	n=m=total=0;

	do{

		printf("Dame dos números, el primero debe ser mayor que el segundo\n");
		printf("Primer número:\n");
		scanf("%d",&m);
		printf("Segundo numero:\n");
		scanf("%d",&n);

	}while(n>m);

	for (int i = n; i <= m; ++i)
	{
		total=total+i;
	}

	printf("El resultado es:%d\n",total);

	return 0;
}