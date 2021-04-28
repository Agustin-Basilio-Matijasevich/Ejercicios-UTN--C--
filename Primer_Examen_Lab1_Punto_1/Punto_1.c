//Inclusion de las librerias a utilizar
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdbool.h>

int main()
{
	//Declaracion de variables
	float  gigas, gbmb, cd;
	int repetir;
	bool bandera, bandera2;

	//Inicializacion de variables
	repetir = 0;
	cd = 0;
	gigas = 0;
	gbmb = 0;
	bandera = true;
	bandera2 = true;

	//Impresion del enunciado
	printf("Nuevo enunciado:\n");
	printf("Realizar un programa que permita calcular el numero de CDs necesarios para hacer una copia de seguridad de la informacion almacenada en un disco cuya capacidad se ingresa por teclado. Considerar que el disco duro esta lleno de informacion y que esta expresado en gigabyte. Un CD virgen tiene 700 megabytes y un gigabyte es igual a 1024 megabytes.");
	printf("\n\n");

	//Ciclo principal del sistema
	do
	{
		//Sistema
		printf("Cuantos gigabytes desea guardar\n");
		scanf_s("%f", &gigas);
		gbmb = gigas * 1024;
		cd = gbmb / 700;
		printf("La cantidad de cds que se necesitan son %.0f\n\n", cd);
		//Fin sistema

		//Menu de seleccion para volver a ejecutar el programa
		do
		{
			printf("¿Desea realizar otra operacion?\nIngrese 1 para SI. Ingrese 2 para NO.\n");
			scanf_s("%i", &repetir);

			switch (repetir)
			{
				case 1:
				{
					bandera = true;
					bandera2 = false;
					break;
				}
				case 2:
				{
					bandera = false;
					bandera2 = false;
					break;
				}
				default:
				{
					printf("Opcion invalida, por favor, reintente\n\n");
					bandera2 = true;
					break;
				}

			}
		
		} while (bandera2);

	} while (bandera);

	//Pausa del programa y finalizacion
	system("Pause");
	return 0;
}