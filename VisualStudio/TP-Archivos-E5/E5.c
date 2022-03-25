#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define ruta "lista.bin"

struct alumno
{
	char DNI[20];
	char apellido[30];
	char nombre[30];
	float nota;
};

void nuevo_registro();
void añadir_alumno();
void leer_registro();

int main()
{
	int opcion, retornoscanf;

	do
	{
		printf("***Bienvenido al sistema de control de alumnos***\n\n");

		printf("Ingrese 1 para modificar el registro\nIngrese 2 para leer el registro\nIngrese 3 para salir\n\nIngrese su opcion: ");
		retornoscanf = scanf(" %i", &opcion);
		printf("\n");

		if (retornoscanf == EOF)
		{
			exit(EXIT_FAILURE);
		}

		if (opcion == 1)
		{
			printf("Ingrese 1 para borrar el registro y comenzar uno nuevo\nIngrese 2 para agregar un alumno\n\nIngrese su opcion: ");
			retornoscanf = scanf(" %i", &opcion);
			printf("\n");

			if (retornoscanf == EOF)
			{
				exit(EXIT_FAILURE);
			}

			if (opcion == 1)
			{
				nuevo_registro();
			}
			else if (opcion == 2)
			{
				añadir_alumno();
			}

		}
		else if (opcion == 2)
		{
			leer_registro();
		}
		else
		{
			break;
		}

	} while (true);

	system("Pause");
	return 0;
}

void nuevo_registro()
{
	FILE* arch;

	remove(ruta);
	arch = fopen(ruta, "wb");
	if (arch == NULL)
	{
		printf("Error al crear el archivo\n\n");
		exit(1);
	}
	fclose(arch);
	printf("Registro creado correctamente\n\n");
}

void añadir_alumno()
{
	FILE* arch;
	struct alumno al;
	int retornoscanf, retornofwrite;

	arch = fopen(ruta, "ab");
	if (arch == NULL)
	{
		printf("Error al abrir el archivo\n\n");
		exit(2);
	}

	printf("Ingrese DNI del Alumno: ");
	retornoscanf = scanf(" %s", &al.DNI);
	if (retornoscanf == EOF)
	{
		exit(EXIT_FAILURE);
	}
	printf("Ingrese Nombre del Alumno: ");
	retornoscanf = scanf(" %s", &al.nombre);
	if (retornoscanf == EOF)
	{
		exit(EXIT_FAILURE);
	}
	printf("Ingrese Apellido del Alumno: ");
	retornoscanf = scanf(" %s", &al.apellido);
	if (retornoscanf == EOF)
	{
		exit(EXIT_FAILURE);
	}
	printf("Ingrese la Nota del Alumno: ");
	retornoscanf = scanf(" %f", &al.nota);
	if (retornoscanf == EOF)
	{
		exit(EXIT_FAILURE);
	}

	retornofwrite = fwrite(&al, sizeof(al), 1, arch);
	if (retornofwrite < 1)
	{
		printf("Error al escribir el registro");
		exit(1);
	}

	printf("\n\n");

	fclose(arch);

}

void leer_registro()
{
	FILE* arch;
	struct alumno al, almas, almenos;
	int retornoprint, cantal = 0, cantala = 0, cantalr = 0;
	float sumnotas = 0;

	almas.nota = 0;
	almenos.nota = 1000;

	arch = fopen(ruta, "rb");
	if (arch == NULL)
	{
		printf("Error al abrir el archivo\n\n");
		exit(2);
	}

	while (true)
	{
		fread(&al, sizeof(al), 1, arch);
		if (feof(arch))
		{
			break;
		}

		cantal++;
		if (al.nota > almas.nota)
		{
			almas = al;
		}
		if (al.nota < almenos.nota)
		{
			almenos = al;
		}
		sumnotas += al.nota;
		if (al.nota >= 6)
		{
			cantala++;
		}
		if (al.nota < 6)
		{
			cantalr++;
		}

		retornoprint = printf("DNI: %s  Apellido: %s  Nombre: %s  Nota: %f\n", al.DNI, al.apellido, al.nombre, al.nota);

		for (int i = 0; i < retornoprint; i++)
		{
			printf("-");
		}

		printf("\n\n");

	}

	float aux1 = cantala * 100;
	float aux2 = cantalr * 100;
	char porc = '%';

	printf("Total de Alumnos: %i\n", cantal);
	printf("Alumno con la nota mas alta=> DNI: %s  Apellido: %s  Nombre: %s  Nota: %f\n", almas.DNI, almas.apellido, almas.nombre, almas.nota);
	printf("Alumno con la nota mas baja=> DNI: %s  Apellido: %s  Nombre: %s  Nota: %f\n", almenos.DNI, almenos.apellido, almenos.nombre, almenos.nota);
	printf("Promedio general de los alumnos: %f\n", sumnotas / cantal);
	printf("Cantidad de alumnos con nota mayor o igual a 6: %i\n", cantala);
	printf("Cantidad de alumnos con nota menor a 6: %i\n", cantalr);
	printf("Porcentaje de alumnos con nota mayor o igual a 6: %c%f\n", porc, aux1 / cantal);
	printf("Porcentaje de alumnos con nota menor a 6: %c%f\n", porc, aux2 / cantal);

	printf("\n\n");

	fclose(arch);

}