#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include<stdio.h>  //Error corregido faltaba #
#include<stdlib.h>
#include<string.h>
#define a "arch.dat"  //Direccion del archivo cambiada en favor de su localizacion

struct registro
{
	int cliente;
	char nombre[20];
	float saldo;
};

int main()
{
	FILE* arch;
	struct registro reg;
	char seguir;
	int retornoscan;  //Error corregido faltaba variable donde retornen los scanf
	int retornowrite;  //Error corregido faltaba variable donde retorne el fwrite

	if ((fopen(a, "w+b")) == NULL)
	{
		printf("No se pudo abrir el archivo");
		return 1;  //Error corregido faltaba un retorno abrupto para finalizar la ejecucion del programa en caso de error
	}
	else
	{
		arch = fopen(a, "w+b");  //Error corregido faltaba la instruccion de apertura y se añade lectura
	}

	do
	{
		printf("\nIngrese numero de cliente: ");
		retornoscan = scanf(" %i", &reg.cliente);
		if (retornoscan == EOF)  //Error corregido faltaban los controles de ingreso de datos por pantalla
		{
			printf("Error al leer la entrada por pantalla");
			return 2;
		}
		printf("\nIngrese el nombre: ");
		retornoscan = scanf(" %s", &reg.nombre);
		if (retornoscan == EOF)
		{
			printf("Error al leer la entrada por pantalla");
			return 2;
		}
		printf("\nIngrese el saldo: ");
		retornoscan = scanf(" %f", &reg.saldo);
		if (retornoscan == EOF)
		{
			printf("Error al leer la entrada por pantalla");
			return 2;
		}

		retornowrite = fwrite(&reg, sizeof(reg), 1, arch);
		if (retornowrite < 1)  //Error corregido faltaba control de escritura en archivo
		{
			printf("Error al escribir en el archivo");
		}

		printf("\nDesea terminar s/n: ");  //Error corregido se movio el salto de linea al printf
		retornoscan = scanf(" %c", &seguir);
		if (retornoscan == EOF)
		{
			printf("Error al leer la entrada por pantalla");
			return 2;
		}
	} while (seguir == 'n');
	
	//Agregado al programa punto ii

	rewind(arch);  //Reinicio del puntero del archivo
	
	printf("\nLectura del archivo\n\n");

	while (!feof(arch))  //Control fin de archivo
	{
		fread(&reg, sizeof(reg), 1, arch);  //Lectura
		if (!feof(arch))  //Control fin archivo
		{
			printf("Nro.Cliente: %i  Nombre: %s  Saldo: %f\n", reg.cliente, reg.nombre, reg.saldo);  //Impresion
		}
	}

	printf("\n");

	//Fin agregado al programa

	if (fclose(arch) == -1)  //Error corregido faltaba control de cerrado de archivo
	{
		printf("Error al cerrar el archivo\n");
	}
	else
	{
		fclose(arch);
	}


	system("Pause");
	return 0;  //Error corregido faltaba return 0
}