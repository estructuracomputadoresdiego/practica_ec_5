#include <stdio.h>

int main(int argc, char *argv[])
{
		
	int segundos, minutos, horas, dias, resto;

	dias=minutos=horas=resto=0;

	printf("Dime que cantidad de segundos quieres que convierta\n");

	scanf("%d", &segundos);

	dias=segundos/(3600*24);
	resto=segundos%(3600*24);
	horas=resto/3600;
	resto=segundos%3600;
	minutos=resto/60;
	segundos=segundos%60;

	printf("\n\n%d segundos equivalen a %d días %d horas %d minutos y %d segundos. \n", segundos, dias, horas, minutos, segundos);

	return 0;
}