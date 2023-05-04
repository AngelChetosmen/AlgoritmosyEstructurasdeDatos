/*
Autor: AngelChetosmen
Consultar la Licencia del Autor | Derechos Reservados EUVA B&T ©
*/
#include <stdio.h>
#include <stdlib.h>

#define Tamax 100
typedef char td;

typedef struct es
{
	td arre[Tamax];
	int tope;
} pila;

void VaciaP(pila *x);
int ComVacia(pila *x);
int ComLlena(pila *x);
void push(pila *x, char o);
td Pop(pila *z);
int Num(char[]);
void Eva(pila *x, int n, char[]);

int main()
{
	pila n;
	pila *pun = &n;
	int a = 0, b = 0, c = 0, d = 0;
	char ex[Tamax];
	printf("\n");
	printf("\n");
	printf("Comprueba si los parentesis de la operacion colocada es correcta.\n");
	do
	{
		printf("\n");
		printf("Desea comprobar si su expresion es correcta:\n");
		printf(" 1. SI\n");
		printf(" 2. NO\n");
		scanf("%d", &d);
		if (d == 1)
		{
			VaciaP(pun);
			printf("\n");
			printf("Coloca la operacion.\n");
			scanf("%s", ex);
			fflush(stdin);
			b = Num(ex);
			printf("\n");
			printf("Tu expresion es de: %d\n", b);
			Eva(pun, b, ex);
		}
		else
		{
			printf("\n");
			printf("Se cerro el programa.\n");
			printf("\n");
		}
		a = 0;
		b = 0;
		c = 0;
	} while (d != 2);
	return 0;
}

void Eva(pila *p, int n, char ex[])
{
	int m, r, z;
	td s, w;
	for (int q = 0; q < n; q++)
	{
		if (ex[q] == '(' || ex[q] == '[' || ex[q] == '{')
		{
			m = ComLlena(p);
			if (m == 0)
			{
				push(p, ex[q]);
			}
			else
			{
				printf("La pila esta llena.\n");
			}
		}
		else
		{
			if (ex[q] == ')' || ex[q] == ']' || ex[q] == '}')
			{
				r = ComVacia(p);
				if (r == 0)
				{
					s = Pop(p);
				}
				else
				{
					printf("\n");
					printf("Ya no hay elementos '(' , '{' , '[' por comparar.\n");
					printf("Tu expresion tiene un error en el tipo de parentesis, donde sale sobrando: %c \n", ex[q]);
					printf("\n");
				}
			}
		}
	}
	z = ComVacia(p);
	if (z == 0)
	{
		while (z == 0)
		{
			w = Pop(p);
			printf("\n");
			printf("Existe un error donde los parentesis de tipo %c no coinciden\n", w);
			z = ComVacia(p);
		}
	}
	else
	{
		printf("\n");
		printf("Los parentesis de tu expresion son correctos.\n");
		printf("\n");
	}
}

int Num(char arr[])
{
	int n = 0;
	while (arr[n] != '\0')
	{
		n++;
	}
	return n;
}

void VaciaP(pila *p)
{
	int t = -1;
	p->tope = t;
}

void push(pila *p1, char y)
{
	int to;
	to = p1->tope;
	if (to != Tamax - 1)
	{
		p1->tope = p1->tope + 1;
		p1->arre[p1->tope] = y;
		// printf("El parentesis que se agrego a la pila es %c .\n",p1->arre[p1->tope]);
	}
	else
	{
		printf("No se pueden agregar mas elementos, tu pila esta llena.\n");
	}
}

int ComLlena(pila *p2)
{
	if (p2->tope == 20)
	{
		// printf("La pila esta llena\n");
		return 1;
	}
	else
	{
		// printf("La pila NO esta llena\n");
		// printf("El tope esta en: %d\n",p2->tope);
		return 0;
	}
}

td Pop(pila *p3)
{
	td v;
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
