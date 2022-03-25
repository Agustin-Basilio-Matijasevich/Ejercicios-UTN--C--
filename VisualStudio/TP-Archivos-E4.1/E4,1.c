#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
	FILE* arch;
	char texto[20], caracter;
	int controlI, controlA;

	for (int i = 0; i < 20; i++)  //Inicializacion del array de cracteres con valor nulo
	{
		texto[i] = 00;
	}

	//Generacion del archivo con nombres

	if (fopen("archivo.txt", "w") == NULL)  //Control de apertura de archivo
	{
		printf("Error al abrir archivo\n");
		return 1;
	}
	else
	{
		arch = fopen("archivo.txt", "w");  //Generacion y apertura de archivo
	}

	for (int i = 0; i < 5; i++)  //Carga de los nombres
	{
		printf("Ingrese un nombre (MAX 20 caracteres)\n");
		controlI = scanf(" %s", &texto);

		if (controlI == EOF)
		{
			printf("Error al leer la entrada por pantalla\n");
		}

		controlA = fwrite(texto, sizeof(char), strlen(texto), arch);

		if (controlA < strlen(texto))
		{
			printf("Error al escribir en el archivo\n");
		}

		fprintf(arch, ".");

		for (int i = 0; i < 20; i++)  //Limpieza del array de caracteres
		{
			texto[i] = 00;
		}
	}

	if (fclose(arch) == -1)  //Control de cerrado del archivo
	{
		printf("Error al cerrar el archivo\n");
	}
	else
	{
		fclose(arch);  //Cerrado del archivo
	}

	//Lectura del archivo con nombres

	if (fopen("archivo.txt", "r") == NULL)  //Control de apertura de archivo
	{
		printf("Error al abrir archivo\n");
		return 1;
	}
	else
	{
		arch = fopen("archivo.txt", "r");  //Apertura de archivo
	}

	printf("Lectura de los nombres uno debajo del otro\n\n");

	while (!feof(arch))  //Lectura e impresion del archivo
	{
		fread(&caracter, sizeof(char), 1, arch);

		if (caracter == '.')
		{
			printf("\n");
		}
		else
		{
			printf("%c", caracter);
		}
	}

	if (fclose(arch) == -1)  //Control de cerrado del archivo
	{
		printf("Error al cerrar el archivo\n");
	}
	else
	{
		fclose(arch);  //Cerrado del archivo
	}
	
	system("Pause");
	return 0;
}