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

typedef struct tCola
{
	int tamano;
	Nodo *frontal;
	Nodo *final;
} Cola;

Nodo *crearNodo(int valor)
{
	Nodo *nodo = (Nodo *)malloc(sizeof(Nodo));
	nodo->valor = valor;
	nodo->sig = NULL;
	return nodo;
}

Cola *crearColas()
{
	Cola *n = (Cola *)malloc(sizeof(Cola));
	n->tamano = 0;
	n->frontal = NULL;
	n->final = NULL;
	return n;
}

void Encolar(Cola *n, Nodo *nodo)
{
	if (n->frontal == NULL)
		n->frontal = nodo;
	else
		n->final->sig = nodo;
	n->final = nodo;
	n->tamano++;
}

int Desencolar(Cola *n)
{
	if (n->tamano)
	{
		int returnValue;
		Nodo *aux = n->frontal;
		returnValue = aux->valor;
		n->frontal = n->frontal->sig;
		free(aux);
		n->tamano--;
		return returnValue;
	}
	return -1; // Indicador de que no hay elementos
}

int primerV(Cola *n)
{
	if (n->frontal == NULL)
	{
		printf("\n La cola esta vacia \n");
		return -1;
	}
	else
		return n->frontal->valor;
}

Cola *ImprimirC(Cola *n)
{
	Nodo *ptr;
	ptr = n->frontal;
	if (ptr == NULL)
	{
		printf("\n La cola esta vacia \n");
	}
	else
	{
		printf("\n");
		while (ptr != n->final)
		{
			printf("%d\t", ptr->valor);
			ptr = ptr->sig;
		}
		printf("%d\t", ptr->valor);
	}
	return n;
}

int estaVacia(Cola *n)
{
	if (n->frontal == NULL)
		return 1;
	else
		return 0;
} // 1 indica que esta vacia, 0 que tiene elementos

void invertirC(Cola *n)
{
	Nodo *actual = n->frontal;
	Nodo *anterior = NULL;
	Nodo *siguiente = actual ? actual->sig : NULL;
	n->final = n->frontal;
	while (actual)
	{
		actual->sig = anterior;
		anterior = actual;
		actual = siguiente;
		siguiente = actual ? actual->sig : NULL;
	}
	n->frontal = anterior;
}

void unirC(Cola *n, Cola *m, Cola *o)
{
	Nodo *a = n->final;
	Nodo *b = m->final;
	Nodo *c = crearNodo(a->valor);
	Nodo *d = crearNodo(b->valor);
	while (a != NULL)
	{
		Encolar(o, c);
		a = a->sig;
	}
	while (a != NULL)
	{
		Encolar(o, d);
		b = b->sig;
	}
	a = o->final;
	while (a != NULL)
	{
		printf("\nDato: %d \n", a->valor);
		a = a->sig;
	}
}

int main()
{

	Cola *COLA = crearColas();
	Cola *COLA2 = crearColas();
	Cola *COLA3 = crearColas();
	Nodo *a = crearNodo(10);
	Nodo *b = crearNodo(20);
	Nodo *c = crearNodo(30);
	Nodo *a1 = crearNodo(90);
	Nodo *a2 = crearNodo(79);
	Nodo *a3 = crearNodo(60);
	Encolar(COLA, a);
	Encolar(COLA, b);
	Encolar(COLA, c);

	printf("\n La cola 1 es:\n");
	ImprimirC(COLA);
	printf("\n La cola 1 invertida es:\n");
	invertirC(COLA);
	ImprimirC(COLA);

	Encolar(COLA2, a1);
	Encolar(COLA2, a2);
	Encolar(COLA2, a3);
	printf("\n La cola 2 es:\n");
	ImprimirC(COLA2);
	printf("\n La cola 2 invertida es:\n");
	invertirC(COLA2);
	ImprimirC(COLA2);

	unirC(COLA2, COLA, COLA3);
	free(COLA);
	free(COLA2);

	return 0;
}
