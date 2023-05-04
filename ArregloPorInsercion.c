/*
Autor: AngelChetosmen
Consultar la Licencia del Autor | Derechos Reservados EUVA B&T ©
*/
#include <stdlib.h>
#include <stdio.h>

void mostrar(int x[]);
void com(int x[]);

int main()
{
	int ar[11];
	printf("Este programa ordena un arreglo.\n");
	printf("Tipo de ordenamiento INSERCION.\n");
	printf("El arreglo es de 10 numeros enteros.\n");
	printf("Su ordenamiento es ascendente.\n");
	for (int i = 1; i < 11; i++)
	{
		printf("Ingrese el numero de la posicion %d.\n", i);
		scanf("%d", &ar[i]);
	}
	mostrar(ar);
	com(ar);
	mostrar(ar);
	return 0;
}

void com(int a[])
{
	int aux, u, w;
	int ca[5];
	for (u = 2; u < 11; u++)
	{
		w = u;
		while (w > 1 && a[u] < a[w - 1])
		{
			w--;
		}
		aux = a[u];
		for (int z = u; z > w; z--)
		{
			ca[0] = a[z];
			a[z] = a[z - 1];
		}
		a[w] = aux;
	}
}

void mostrar(int a[])
{
	printf("Tu arreglo esta ordenado de la siguiente manera:\n");
	printf("\n");
	for (int y = 1; y < 11; y++)
	{
		printf("%d. %d\n", y, a[y]);
	}
}
