/*
Autor: AngelChetosmen
Consultar la Licencia del Autor | Derechos Reservados EUVA B&T ©
*/
#include <stdio.h>
#include <stdlib.h>

struct Cola
{
	int arreglo[5];
	int *ptrS;
	int *ptrM;
};

int menu();
void meter(struct Cola *ptrCola, int dato);
int sacar(struct Cola *ptrCola, int dato);
int colaLlena(struct Cola *ptrCola);
int colaVacia(struct Cola *ptrCola);
void resetear(struct Cola *ptrCola);
void mostrar(struct Cola *ptrCola);

int main()
{
	struct Cola cola, *miPtrCola;
	int miDato;
	printf("Este programa tiene la funcion de realizar una cola estatica circular.\n");
	printf("Solo tiene la capacidad de almacenar 5 elementos.\n");
	miPtrCola = &cola;
	miPtrCola->ptrM = miPtrCola->arreglo;
	miPtrCola->ptrS = miPtrCola->arreglo;

	for (;;)
	{
		switch (menu())
		{
		case 1:
			if (colaLlena(miPtrCola) == 1)
			{
				printf("\n");
				printf("La cola esta LLENA.\n");
				printf("\n");
			}
			else
			{
				printf("Introduce un numero entero:\n");
				scanf("%d", &miDato);
				meter(miPtrCola, miDato);
			}
			break;
		case 2:
			if (colaVacia(miPtrCola) == 1)
			{
				printf("\n");
				printf("La cola esta VACIA.\n");
				printf("\n");
				break;
			}
			else
			{
				printf("El dato sacado de la cola es: %d\n", sacar(miPtrCola, miDato));
				break;
			}
		case 3:
			mostrar(miPtrCola);
			break;
		case 4:
			resetear(miPtrCola);
			break;
		case 5:
			exit(0);
			break;
		default:
			printf("Ingresa un numero valido.\n");
		}
	}

	return 0;
}

void meter(struct Cola *ptrCola, int dato)
{
	*ptrCola->ptrM = dato;
	if (ptrCola->ptrM == &ptrCola->arreglo[5])
	{
		ptrCola->ptrM = ptrCola->arreglo;
	}
	else
	{
		ptrCola->ptrM++;
	}
}

int sacar(struct Cola *ptrCola, int dato)
{
	dato = *ptrCola->ptrS;
	if (ptrCola->ptrS == &ptrCola->arreglo[5])
	{
		ptrCola->ptrS = ptrCola->arreglo;
	}
	else
	{
		ptrCola->ptrS++;
	}
	return dato;
}

int colaLlena(struct Cola *ptrCola)
{
	if (ptrCola->ptrM == ptrCola->ptrS - 1 || (ptrCola->ptrM == &ptrCola->arreglo[5] && ptrCola->ptrS == ptrCola->arreglo))
	{
		return 1;
	}
	else if (ptrCola->ptrM == ptrCola->ptrS && ptrCola->ptrM == ptrCola->arreglo)
	{
		return 0;
	}
}

int colaVacia(struct Cola *ptrCola)
{
	if (ptrCola->ptrM == ptrCola->ptrS)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void resetear(struct Cola *ptrCola)
{
	ptrCola->ptrM = ptrCola->arreglo;
	ptrCola->ptrS = ptrCola->arreglo;
}

void mostrar(struct Cola *ptrCola)
{
	int *pos;

	pos = ptrCola->ptrS;
	for (ptrCola->ptrS = ptrCola->arreglo; ptrCola->ptrS < &ptrCola->arreglo[5]; ptrCola->ptrS++)
	{
		printf("%d ", *ptrCola->ptrS);
	}
	ptrCola->ptrS = pos;
}

int menu()
{
	int c = 0;
	printf("\n");
	printf("\n");
	printf("\nSeleccione de forma numerica la operacion deseada.\n");
	printf("1. Introducir un dato.\n");
	printf("2. Saca un dato.\n");
	printf("3. Mostrar datos en la cola.\n");
	printf("4. Reinicia cola (eliminacion de todo el contenido).\n");
	printf("5. Finalizar programa.\n");
	scanf("%d", &c);
	printf("\n");

	return c;
}
