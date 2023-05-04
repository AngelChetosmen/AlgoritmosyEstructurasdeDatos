/*
Autor: AngelChetosmen
Consultar la Licencia del Autor | Derechos Reservados EUVA B&T ©
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct nod
{
	struct nod *niz;
	struct nod *nde;
	char dato;
} nodo;

int Tam(char[]);
nodo *Arbol(char[], int fin, int inicio);
void imprimir(nodo *n);
void inorden(nodo *ra);
void postorden(nodo *ra);
void preorden(nodo *ra);

int main()
{
	char in[100];
	int b;
	nodo *arb;
	printf("Este programa convierte tu expresion infija a postfija y prefija.\n");
	printf("Por favor coloque la expresion infija sin parentesis.\n");
	printf("Solo se aceptan operandos un solo digito y operadores binarios.\n");
	printf("Solo son operandos (variables) de un solo digito y operaciones binarias ' -+/*^ '.\n");
	printf("Coloque la expresion infija.\n");
	scanf("%s", in);
	fflush(stdin);
	b = Tam(in);
	printf("El tamano de tu expresion es: %d.\n", b);
	arb = Arbol(in, 0, b - 1);
	printf("Inorden: Izquierda,raiz y derecha. \n");
	inorden(arb);
	printf("\n\n");
	printf("Preorden: Raiz,izquierda y derecha. \n");
	preorden(arb);
	printf("\n\n");
	printf("Postorden: Izquierda,derecha y raiz. \n");
	postorden(arb);
	return 0;
}

int Tam(char arr[])
{
	int n = 0;
	while (arr[n] != '\0')
	{
		n++;
	}
	return n;
}

// la variable a es el final del arreglo de caracteres y b es el inicio del arreglo de caracteres.
nodo *Arbol(char arr[], int a, int b)
{
	nodo *p;
	int x, ban, pos;
	ban = 0;
	if (a == b)
	{ // Es cuando es un solo caracter, es decir, que es una hoja, que es un operando (variable).
		p = (nodo *)malloc(sizeof(nodo));
		p->dato = arr[a];
		p->niz = NULL;
		p->nde = NULL;
		return p;
	}
	for (x = a; x <= b; x++)
	{ // Se toma primero las sumas, ya que primero tomamos la suma y resta para jerarquizar los signos.
		if (arr[x] == '+' || arr[x] == '-')
		{ // Estos sigos estaran arriba del arbol, ya que son los ultimos en actuar.
			ban = 1;
			pos = x;
		}
	}
	if (ban == 0)
	{ // Si no hay suma o resta, entonces iremos por / y * ya que son de mayor jerarquia.
		for (x = 0; x <= b; x++)
		{ // Estos iran en un nivel del arbol con mayor nodos.
			if (arr[x] == '*' || arr[x] == '/' || arr[x] == 'e')
			{
				ban = 1;
				pos = x;
			}
		}
	}
	if (ban != 0)
	{ // Ya teniendo eso, dividiremos a subarbol izq y subarbol der
		p = (nodo *)malloc(sizeof(nodo));
		p->dato = arr[pos];
		p->niz = Arbol(arr, a, pos - 1);
		p->nde = Arbol(arr, pos + 1, b);
		return p;
	}
	else
	{ // En caso de que no haya ningun operando.
		printf("Tu arbol esta vacio.\n");
		return NULL;
	}
}

void imprimir(nodo *a)
{
	if (a != NULL)
	{
		printf(" %c ", a->dato);
	}
	else
	{
		printf("No hay dato en este nodo.\n");
	}
}

void inorden(nodo *ra)
{
	if (ra != NULL)
	{
		inorden(ra->niz);
		imprimir(ra);
		inorden(ra->nde);
	}
}

void preorden(nodo *ra)
{
	if (ra != NULL)
	{
		imprimir(ra);
		preorden(ra->niz);
		preorden(ra->nde);
	}
}

void postorden(nodo *ra)
{
	if (ra != NULL)
	{
		postorden(ra->niz);
		postorden(ra->nde);
		imprimir(ra);
	}
}
