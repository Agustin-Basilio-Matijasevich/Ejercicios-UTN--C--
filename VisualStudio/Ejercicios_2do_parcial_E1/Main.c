#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

void inicializar_array(int array[MAX]);  //Se le pasa direccion de array y lo inicializa con "0"
bool insertar_valor(int array[MAX], int posicion, int valor);  //Se le pasa direccion de array, posicion donde insertar y valor a insertar, la funcion inserta el valor o devuelve un false como error si el array esta lleno
void eliminar_valor(int array[MAX], int posicion);  //Se le pasa direccion de array y una posicion, la funcion elimina el valor de la posicion poniendo "0"
int buscar_valor(int array[MAX], int valor);  //Se le pasa direccion de array y un valor a buscar, la funcion busca el valor y devuelve -1 si no existe el valor o el indice donde esta si existe
void ordenar_array(int array[MAX], int tipo);  //Se le pasa direccion de array y un 1 para ordenar de menor a mayor o un 2 para ordenar de mayor a menor, la funcion ordena el array segun el parametro
void mostrar_array(int array[MAX]);  //Se le pasa una copia de un array y lo imprime en pantalla

int main()
{
	bool control = true;
	int array[MAX];
	int menu = 0;

	inicializar_array(array);

	do
	{
		printf("Bienvenido, el arreglo es de 10 posiciones, iniciando en 0 y terminando en 9\n\n");

		printf("Por favor, seleccione una opcion:\nIngrese 1 para insertar un elemento. Ingrese 2 para eliminar un elemento.\nIngrese 3 para buscar un elemento. Ingrese 4 para ordenar el array. Ingrese 5 para salir.\n\n");

		scanf_s(" %i", &menu);

		switch (menu)
		{
			case 1:  //Insertar
			{
				int valor, posicion;
				bool resultado;

				printf("Indique el valor a insertar: ");
				scanf_s(" %i", &valor);
				printf("Indique la posicion donde quiere insertar el elemento: ");
				scanf_s(" %i", &posicion);

				resultado = insertar_valor(array, posicion, valor);

				if (resultado == true)
				{
					printf("Valor insertado correctamente.\n\n");
				}
				else
				{
					printf("El arreglo esta lleno, intente eliminar un elemento.\n\n");
				}

				break;
			}

			case 2:  //Eliminar
			{
				int indice;

				printf("Ingrese el indice que desea eliminar: ");
				scanf_s(" %i", &indice);

				eliminar_valor(array, indice);

				printf("\nValor eliminado del indice selecciondo\n\n");

				break;
			}

			case 3:  //Buscar
			{
				int valor, indice;

				printf("Ingrese un valor a buscar: ");
				scanf_s(" %i", &valor);

				indice = buscar_valor(array, valor);

				if (indice == -1)
				{
					printf("\n\nEl valor no se encuentra en el array\n\n");
				}
				else
				{
					printf("El valor %i se encuentra en la posicion %i\n\n", valor, indice);
				}

				break;
			}

			case 4:  //Ordenar
			{
				int tipo;

				printf("Si desea ordenar el array de forma ascendente ingrese 1.\nSi desea ordenar el array de forma descendente ingrese 2.\n");
				scanf_s(" %i", &tipo);

				printf("Array antes de ordenar:\n\n");
				mostrar_array(array);

				ordenar_array(array, tipo);

				printf("Array despues de ordenar:\n\n");
				mostrar_array(array);

				if (tipo < 1 || tipo > 2)
				{
					printf("Opcion invalida\n\n");
				}
				else
				{
					printf("Array ordenado correctamente\n\n");
				}

				break;
			}

			case 5:  //Salir
			{
				printf("\n\nFIN\n\n");
				control = false;

				break;
			}

			default:
			{
				printf("\n\nFatal ERROR\n\n");
				control = false;

				break;
			}

		}

	} while (control);

	system("pause");

}

void inicializar_array(int array[MAX])
{
	for (int i = 0; i < MAX; i++)
	{
		array[i] = 0;  //Valor "0" sera equivalente a "lugar vacio" en este programa
	}
}

bool insertar_valor(int array[MAX], int posicion, int valor)
{
	for (int i = 0; i <= MAX; i++)  //Verifica que haya lugar para insertar
	{
		if (i > MAX-1)
		{
			return false;
		}
		else if (array[i] == 0)
		{
			break;
		}
	}

	if (array[posicion] == 0)
	{
		array[posicion] = valor;
		return true;
	}
	else
	{
		for (int i = posicion; i < MAX; i++)
		{
			if (array[i] == 0)
			{
				for (int j = i; j >= posicion; j--)
				{
					if (j == posicion)
					{
						array[j] = valor;
						return true;
					}
					else
					{
						int swap;

						swap = array[j - 1];
						array[j - 1] = 0;
						array[j] = swap;

					}

				}

			}

		}

		for (int i = posicion; i >= 0; i--)
		{
			if (array[i] == 0)
			{
				for (int j = i; j <= posicion; j++)
				{
					if (j == posicion)
					{
						array[j] = valor;
						return true;
					}
					else
					{
						int swap;

						swap = array[j + 1];
						array[j + 1] = 0;
						array[j] = swap;
					}
				}

			}

		}

	}

	return false;
}

void eliminar_valor(int array[MAX], int posicion)
{
	array[posicion] = 0;
}

int buscar_valor(int array[MAX], int valor)
{
	for (int i = 0; i < MAX; i++)
	{
		if (array[i] == valor)
		{
			return i;
		}
	}
	return -1;
}

void ordenar_array(int array[MAX], int tipo)
{
	int swap;

	if (tipo == 1)
	{
		for (int i = 0; i < MAX - 1; i++)
		{
			for (int j = 0; j < MAX - i - 1; j++)
			{
				if (array[j] > array[j + 1])
				{
					swap = array[j];
					array[j] = array[j + 1];
					array[j + 1] = swap;
				}
			}
		}
	}
	else if (tipo == 2)
	{
		for (int i = 0; i < MAX - 1; i++)
		{
			for (int j = 0; j < MAX - i - 1; j++)
			{
				if (array[j] < array[j + 1])
				{
					swap = array[j];
					array[j] = array[j + 1];
					array[j + 1] = swap;
				}
			}
		}
	}
}

void mostrar_array(int array[MAX])
{
	printf("{ ");

	for (int i = 0; i < MAX; i++)
	{
		if (i == MAX - 1)
		{
			printf("%i", array[i]);
		}
		else
		{
			printf("%i", array[i]);
			printf(", ");
		}
		
	}

	printf("}\n\n");
}