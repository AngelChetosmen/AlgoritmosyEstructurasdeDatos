/*
Autor: AngelChetosmen
Consultar la Licencia del Autor | Derechos Reservados EUVA B&T ©
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct tNodo
{
	int valor;
	struct tNodo *sig;
} Nodo;

typedef struct tColaPrioridad
{
	struct Nodo *frente;
} Cola;

Cola *crearCola()
{
	Cola *n = (Cola *)malloc(sizeof(Cola));
	n->frente = NULL;
	return n;
}

Nodo *crearNodo(int valor)
{
	Nodo *nodo = (Nodo *)malloc(sizeof(Nodo));
	nodo->valor = valor;
	nodo->sig = NULL;
	return nodo;
}

void EncolarCD(Cola *n, int x)
{
	if (n->frente == NULL)
	{
		n->frente = crearNodo(x);
		return;
	}

	Nodo *actual = n->frente;
	while (actual != NULL)
	{
		if (actual->valor <= x)
		{
			Nodo *m = crearNodo(actual->valor);
			m->sig = actual->sig;
			actual->sig = m;
			actual->valor = x;
			break;
		}

		if (actual->sig == NULL)
		{
			Nodo *m = crearNodo(x);
			actual->sig = m;
			return;
		}
		actual = actual->sig;
	}
}

void EncolarCA(Cola *n, int x)
{
	if (n->frente == NULL)
	{
		n->frente = crearNodo(x);
		return;
	}

	Nodo *actual = n->frente;
	while (actual != NULL)
	{
		if (actual->valor >= x)
		{
			Nodo *m = crearNodo(actual->valor);
			m->sig = actual->sig;
			actual->sig = m;
			actual->valor = x;
			break;
		}

		if (actual->sig == NULL)
		{
			Nodo *m = crearNodo(x);
			actual->sig = m;
			return;
		}
		actual = actual->sig;
	}
}

int DesencolarCP(Cola *n)
{
	Nodo *z = n->frente;
	int x = z->valor;
	Nodo *aux = z;
	n->frente = z->sig;
	free(aux);
	return x;
}

void ImprimirCP(Cola *n)
{
	Nodo *actual = n->frente;
	printf("\nLISTA:\n");
	while (actual != NULL)
	{
		printf("%d\t", actual->valor);
		actual = actual->sig;
	}
}

int EstaVacia(Cola *n)
{
	if (n->frente == NULL)
		return 1;
	else
		return 0;
} // regresa 1 si es vacia y 0 si contiene elementos

int mostrar(Cola *n)
{
	Nodo *z = n->frente;
	if (z == NULL)
	{
		printf("\n La cola esta vacia");
		return -1;
	}
	else
		return z->valor;
}

int main()
{
	Cola *COLA = crearCola();
	Cola *COLA2 = crearCola();
	EncolarCD(COLA, 10);
	EncolarCD(COLA, 90);
	EncolarCD(COLA, 18);
	ImprimirCP(COLA);
	printf("\n El valor maximo es: %d", mostrar(COLA));
	DesencolarCP(COLA);
	ImprimirCP(COLA);
	printf("\n El valor maximo es: %d", mostrar(COLA));
	printf("\n %d", EstaVacia(COLA));
	EncolarCA(COLA2, 99);
	EncolarCA(COLA2, 9);
	EncolarCA(COLA2, 1);
	ImprimirCP(COLA2);
	printf("\n El valor minimo es: %d", mostrar(COLA2));
	printf("\n %d", EstaVacia(COLA2));
	free(COLA);
	free(COLA2);
}
