#include <stdio.h>
#include <string.h>

/*Ejercicio hecho puramente como un reto personal el cual consiste en una modificacion del ejercicio del
 factorial, pero con el añadido de la posibilidad de guardar y sobreescribir los resultados en un archivo txt externo*/

int main(int argc, char const *argv[])
{	
	FILE *fichero;

	char archivo_volcado[100]="factorial.txt";
	double num, total;
	total=1;
	char respuesta_al_almacenado;
	
	printf("Por favor, indique el número del cual quiere hallar su factorial\n");

	scanf("%lf",&num);

	for (int i = 1; i <= num; ++i)
	{
		total=total*i;
	}

	printf("\nEl factorial de %.0f es %.0f.\n",num, total);

	//Aqui empieza la selección para el volcado de datos en el txt

	reset_selection_1:

	fflush(stdin);

	printf("\n¿Quieres guardar el factorial en un documento?\nSi[S/s]\nNo[N/n]\n\n");

	scanf("%s",&respuesta_al_almacenado);

	switch(respuesta_al_almacenado){

		case 'S':
		case 's':

				fichero = fopen(archivo_volcado, "rt");
			
				if(fichero == NULL){	
					printf("Se ha creado un archivo con el nombre fichero.txt en el cual se van a almacenar los factoriales y sus resultados\n");
					fichero = fopen(archivo_volcado, "at");
					fprintf(fichero, " El factorial de %.0f es %.0f \n",num,total );
					fclose(fichero);

				}



				else{
					reset_selection_2:
					printf("\nYa tienes mas factoriales almacenados en el archivo fichero.txt, ¿Que quieres hacer?\n  [1]Escribir el resultado a continuacion del anterior\n  [2]Sobreescribir el archivo anterior\n\n");
					int escribir_sobreescribir;
					scanf("%d",&escribir_sobreescribir);
					switch(escribir_sobreescribir){
						case 1:
							fichero = fopen(archivo_volcado, "at");
							fprintf(fichero, " El factorial de %.0f es %.0f \n",num,total );
							fclose(fichero);
							printf("\nHe añadido el factorial de %.0f y su resultado al archivo\n",num );
						break;

						case 2:
							fclose(fichero);
							fichero = fopen(archivo_volcado, "w");
							fprintf(fichero, " El factorial de %.0f es %.0f \n",num,total );
							fclose(fichero);
							printf("\nHe sobreescrito el contenido del archivo por el factorial de %.0f  \n",num );
						break;

						default:
						goto reset_selection_2;

					}

				}

			break;

		case 'N':
		case 'n':
			
			break;

		default:
			printf("\nPor favor, indique 'Si' con S/s o 'No' con N/n\n");
			goto reset_selection_1;

	}

	

	return 0;
}