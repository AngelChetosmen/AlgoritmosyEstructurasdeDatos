/*
Autor: AngelChetosmen
Consultar la Licencia del Autor | Derechos Reservados EUVA B&T ©
*/
#include <stdio.h>
#include <stdlib.h>

#define Tamax 20
// typedef int td;

typedef struct es
{
	int arre[Tamax];
	int tope;
} pila;

void VaciaP(pila *x);
int Ver(pila *x);
int ComVacia(pila *x);
int ComLlena(pila *x);
void push(pila *x, int o);
int Pop(pila *z);

int main()
{
	pila n;
	pila *pun = &n;
	int a, e = 0;
	int b = 0, c, d;
	printf("Este programa es una pila estatica de enteros.\n");
	printf("Tiene un maximo la pila hasta de 20 numeros enteros.\n");
	pun->tope = -1;
	do
	{
		printf("Elija la opcion de forma numerica, lo que desee realizar.\n");
		printf("1. Agregar un numero.\n");
		printf("2. Borrar el ultimo numero que esta en la pila y mostrar.\n");
		printf("3. Ver el ultimo elemento agregado a la pila.\n");
		printf("4. Pila esta vacia.\n");
		printf("5. Pila esta llena.\n");
		printf("6. Inicializar pila.\n");
		printf("7. Salir del programa\n");
		scanf("%d", &a);
		fflush(stdin);
		switch (a)
		{
		case 1:
			printf("Por favor, introduzca el entero que desee meter a la pila.\n");
			fflush(stdin);
			scanf("%d", &b);
			push(pun, b);
			break;
		case 2:
			c = Pop(pun);
			printf("Se elimino el elemento que estaba hasta arriba de la pila: %d.\n", c);
			break;
		case 3:
			d = Ver(pun);
			printf("El numero de hasta arriba de la pila es: %d", d);
			break;
		case 4:
			e = ComVacia(pun);
			if (e == 1)
			{
				printf("La pila esta vacia.\n");
			}
			else
			{
				printf("La pila NO esta vacia.\n");
			}
			break;
		case 5:
			e = ComLlena(pun);
			if (e == 1)
			{
				printf("La pila esta llena.\n");
			}
			else
			{
				printf("La pila NO esta llena.\n");
			}
			break;
		case 6:
			VaciaP(pun);
			break;
		default:
			printf("Te haz salido del programa.\n");
		}
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
	} while (a < 7);
	return 0;
}

void VaciaP(pila *p)
{
	int t = -1;
	p->tope = t;
	printf("La pila esta vacia, inicia con %d.\n", p->tope);
}

void push(pila *p1, int y)
{
	int to;
	to = p1->tope;
	if (to != Tamax - 1)
	{
		p1->tope = p1->tope + 1;
		p1->arre[p1->tope] = y;
		printf("El numero %d se agrego a la pila.\n", p1->arre[p1->tope]);
	}
	else
	{
		printf("No se pueden agregar mas elementos, tu pila esta llena.\n");
	}
}

int ComLlena(pila *p2)
{
	int g = 0;
	if (p2->tope == 20)
	{
		// printf("La pila esta llena\n");
		return g;
	}
	else
	{
		// printf("La pila NO esta llena\n");
		printf("El tope esta en: %d\n", p2->tope);
		return g;
	}
}

int Pop(pila *p3)
{
	int v;
	if (p3->tope == -1)
	{
		printf("No hay ningun elemento por eliminar, esta vacia la pila, por lo que retornara 0.\n");
		return 0;
	}
	else
	{
		v = p3->arre[p3->tope];
		p3->tope--;
		return v;
	}
}

int ComVacia(pila *p7)
{
	if (p7->tope == -1)
	{
		// printf("La pila esta vacia\n");
		return 1;
	}
	else
	{
		// printf("La pila NO esta vacia\n");
		return 0;
	}
}

int Ver(pila *p4)
{
	int e;
	e = p4->arre[p4->tope];
	return e;
}
