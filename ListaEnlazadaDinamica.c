/*
Autor: AngelChetosmen
Consultar la Licencia del Autor | Derechos Reservados EUVA B&T ©
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct lista
{
	int dato;
	struct lista *sig;
} elem;

typedef struct id
{
	elem *inicio;
	elem *fin;
	int tam;
} lista;

void inicializo(lista *x);

int InsLisVacia(lista *x, int d);

int InsInicio(lista *l, int d);
int InsFinal(lista *l, int d);
int InsPos(lista *x, int d, int pos);

int ElimInicio(lista *x);
int ElimPos(lista *x, int pos);
int ElimFinal(lista *x);

int menu(lista *a, int *b);
void muestra(lista *c);
void destruir(lista *d);
int BusNum(lista *x, int a);
int BusPos(lista *x, int a);

int main()
{
	int a, b, c, d, e, f, g;
	int el[6];
	int bu[3];
	lista n;
	lista *lis = &n;
	printf("\n");
	printf("\n");
	printf("Este programa realiza una lista linealmente enlazada de manera dinamica.\n");
	printf("SELECCIONE 1. INICIALIZAR LISTA.\n");

	inicializo(lis);
	do
	{
		printf("\n");
		printf("\n");
		printf("Seleccione de forma numerica la operacion que desea realizar:\n");
		printf("\n");
		printf("1. Inicializar la lista (En caso de que sea la primera ejecucion o desee crear una nueva lista).\n");
		printf("\n");
		printf("2. Agregar un elemento a la lista.\n");
		printf("3. Eliminar un elemento a la lista.\n");
		printf("\n");
		printf("4. Buscar un elemento.\n");
		printf("5. Mostrar lista.\n");
		printf("6. Salir del programa.\n");
		scanf("%d", &a);
		printf("\n");
		switch (a)
		{
		case 1:
			printf("Usted ha inicializado una pila.\n");
			inicializo(lis);
			printf("Coloque el primer elemento de la lista.\n");
			printf("\n");
			scanf("%d", &f);
			g = InsLisVacia(lis, f);
			if (g == 0)
			{
				printf("Error en la memoria.\n");
				break;
			}
			else
			{
				printf("Se agrego de manera exitosa.\n");
				muestra(lis);
			}
			break;
		case 2:
			printf("\n");
			printf("\n");
			muestra(lis);
			printf("\n");
			printf("Seleccione de forma numerica la forma de agregar el elemento.\n");
			printf("1. Inicio de la lista.\n");
			printf("2. Posicion especifica.\n");
			printf("3. Final de la lista.\n");
			printf("\n");
			scanf("%d", &c);
			switch (c)
			{
			case 1:
				printf("\n");
				muestra(lis);
				printf("Por favor, coloque el elemento a agregar.\n");
				printf("\n");
				scanf("%d", &b);
				d = InsInicio(lis, b);
				if (d == 0)
				{
					printf("Error en la asignacion de memoria.\n");
					break;
				}
				else
				{
					printf("Se agrego a la lista exitosamente.\n");
					muestra(lis);
					break;
				}
			case 2:
				printf("\n");
				printf("\n");
				printf("Por favor, coloque el elemento a agregar.\n");
				printf("\n");
				scanf("%d", &b);
				muestra(lis);
				printf("Coloque en que posicion de la lista desea agregarlo.\n");
				printf("\n");
				scanf("%d", &e);
				d = InsPos(lis, b, e);
				if (d == 0)
				{
					printf("Error.\n");
					break;
				}
				else
				{
					muestra(lis);
					printf("Se agrego a la lista el valor: %d en la posicion - %d - de manera exitosa.\n", b, e);
					printf("\n");
					break;
				}

			case 3:
				printf("\n");
				muestra(lis);
				printf("Por favor, coloque el elemento a agregar.\n");
				printf("\n");
				scanf("%d", &b);
				d = InsFinal(lis, b);
				if (d == 0)
				{
					break;
				}
				else
				{
					printf("Se agrego exitosamente a la lista.\n");
					muestra(lis);
					break;
				}
			default:
				printf("Selecciono una opcion no existente, vuelta a intentarlo.\n");
			}
			break;
		case 3:
			printf("\n");
			muestra(lis);
			printf("Seleccione de forma numerica la forma de eliminar el elemento.\n");
			printf("1. Inicio de la lista.\n");
			printf("2. Posicion especifica.\n");
			printf("3. Final de la lista.\n");
			scanf("%d", &c);
			printf("\n");
			switch (c)
			{
			case 1:
				el[0] = ElimInicio(lis);
				if (el[0] == -1)
				{
					break;
				}
				else
				{
					printf("\n");
					printf("\n");
					muestra(lis);
					break;
				}
			case 2:
				printf("\n");
				printf("\n");
				muestra(lis);
				printf("Por favor, coloque la posicion donde se encuentra el elemento a eliminar.\n");
				printf("\n");
				scanf("%d", &el[2]);
				el[1] = ElimPos(lis, el[2]);
				if (el[1] == 0)
				{
					break;
				}
				else
				{
					printf("\n");
					muestra(lis);
					break;
				}
			case 3:
				printf("\n");
				el[3] = ElimFinal(lis);
				if (el[3] == 0)
				{
					break;
				}
				else
				{
					printf("\n");
					muestra(lis);
					break;
				}
			default:
				printf("La opcion es incorrecta.\n");
			}
			break;
		case 4:
			printf("\n");
			printf("\n");
			printf("Por medio del valor del elemento.\n");
			printf("Proporcionara la posicion en donde se encuentra dicho valor a buscar en la lista.\n");
			printf("Por favor, coloque el valor del elemento entero.\n");
			printf("\n");
			scanf("%d", &bu[0]);
			bu[1] = BusNum(lis, bu[0]);
			if (bu[1] == 0)
			{
				break;
			}
			else
			{
				muestra(lis);
				break;
			}
		case 5:
			if (lis->tam == 0)
			{
				printf("No hay elementos en la lista.\n");
				break;
			}
			else
			{
				muestra(lis);
				break;
			}
		default:
			printf("\n");
			printf("\n");
			printf("Usted ha salido del programa.\n");
		}
	} while (a < 6);
	lis = NULL;
	free(lis);
	return 0;
}

int ElimFinal(lista *n)
{
	int i, numero;
	elem *el;
	elem *aux;
	if (n->tam == 0)
	{
		printf("No hay elementos en tu lista.\n");
		return 0;
	}
	if (n->tam == 1)
	{
		printf("Seleccione de nuevo eliminar pero al principio de la lista.\n");
		return 0;
	}
	else
	{
		numero = n->tam;
		el = n->fin;
		aux = n->inicio;
		numero = numero - 1;
		for (i = 1; i != numero; i++)
		{
			aux = aux->sig;
		}
		n->fin = aux;
		n->fin->sig = NULL;
		printf("El valor del ultimo elemento de la posicion %d ya eliminado es: %d", n->tam, el->dato);
		el = NULL;
		free(el);
		n->tam--;
		return 1;
	}
}

int BusNum(lista *x, int num)
{
	if (x->tam == 0)
	{
		printf("No hay elementos en la lista.\n");
		return 0;
	}
	else
	{
		int a = 1;
		elem *aux, *f;
		int ele;
		aux = x->inicio;
		f = x->fin;
		while (aux != NULL && aux->dato != num)
		{
			a++;
			aux = aux->sig;
		}
		if (aux == NULL)
		{
			printf("El elemento a buscar no existe en esta lista.\n");
			return 0;
		}
		else
		{
			printf("\n");
			printf("\n");
			printf("La posicion del elemento %d es: - %d - .\n", num, a);
		}
		return 1;
	}
}

int ElimPos(lista *x, int po)
{
	int i;
	elem *act;
	elem *elm;
	elem *aux;
	if (po > x->tam || po < 1)
	{
		printf("\n");
		printf("\n");
		printf("La posicion ingresada es invalida, no se encuentra en la lista.\n");
		return 0;
	}
	if (po == x->tam || po == 1)
	{
		printf("\n");
		printf("\n");
		printf("Usted esta deseando eliminar un elemento del inicio o final.\n");
		printf("Para ello, tenemos opciones para eliminar al inicio o final, intentelo de nuevo.\n");
		return 0;
	}
	else
	{
		act = x->inicio;
		for (i = 1; i < po - 1; i++)
		{
			act = act->sig;
		}
		elm = act->sig;
		act->sig = act->sig->sig;
		if (act->sig == NULL)
		{
			x->fin = act;
		}
		printf("\n");
		printf("\n");
		printf("El elemento eliminado en la posicion %d es: %d \n", po, elm->dato);
		elm = NULL;
		free(elm);
		x->tam--;
		return 1;
	}
}

int ElimInicio(lista *x)
{
	int b;
	elem *el;
	elem *aux;
	if (x->tam == 0)
	{
		printf("No hay datos en la lista existentes.\n");
		return -1;
	}
	else
	{
		b = x->inicio->dato;
		el = x->inicio;
		aux = x->inicio;
		aux = aux->sig;
		x->inicio = aux;
		printf("El primer elemento de la lista que tenia como elemento: %d fue eliminado.\n", b);
		if (x->tam == 1)
		{
			x->fin = NULL;
			return 1;
		}
		else
		{
			el = NULL;
			free(el);
			return 1;
		}
	}
}

int InsLisVacia(lista *l, int a)
{
	elem *nue;
	nue = (elem *)malloc(sizeof(elem));
	if (nue == NULL)
	{
		return 0;
	}
	else
	{
		nue->dato = a;
		nue->sig = NULL;
		l->inicio = nue;
		l->fin = nue;
		l->tam++;
		return 1;
	}
}

int InsFinal(lista *n, int d)
{
	elem *nue;
	elem *aux;
	int i, t;
	t = n->tam;
	printf("t es %d\n", t);
	nue = (elem *)malloc(sizeof(elem));
	if (nue == NULL)
	{
		printf("Error en la asignacion de la memoria.\n");
		return 0;
	}
	else
	{
		nue->dato = d;
		aux = n->fin;
		aux->sig = nue;
		nue->sig = NULL;
		n->fin = nue;
		n->tam++;
		return 1;
	}
}

int InsPos(lista *n, int d, int po)
{
	elem *aux;
	elem *nue;
	int i, j, k;
	j = po - 1;
	if (n->tam < 2)
	{
		printf("Solo tienes un elemento, no se puede seleccionar una posicion, agrega mas elementos.\n");
		return 0;
	}
	else
	{
		if (po < 1 || po >= n->tam)
		{
			printf("La posicion que desea colocar pasa del tamaño de la lista actual.\n");
			return 0;
		}
		else
		{
			nue = (elem *)malloc(sizeof(elem));
			if (nue == NULL)
			{
				printf("Error en la asignacion de memoria.\n");
				return 0;
			}
			else
			{
				aux = n->inicio;
				for (i = 1; i < po - 1; i++)
				{
					aux = aux->sig;
				}
				if (aux->sig == NULL)
				{
					return 0;
				}
				else
				{
					nue->dato = d;
					nue->sig = aux->sig;
					aux->sig = nue;
					n->tam++;
					nue = NULL;
					free(nue);
					return 1;
				}
			}
		}
	}
}

void inicializo(lista *l)
{
	l->inicio = NULL;
	l->fin = NULL;
	l->tam = 0;
}

int InsInicio(lista *n, int x)
{
	elem *nuel;
	nuel = (elem *)malloc(sizeof(elem));
	if (nuel == NULL)
	{
		printf("Error en la memoria\n");
		return 0;
	}
	else
	{
		nuel->dato = x;		   // Agrego el dato al nuevo elemento donde estara en el inicio.
		nuel->sig = n->inicio; // El apuntador sig del elemento nuevo apuntara donde era el primer elemento, que ahora es el segundo.
		n->inicio = nuel;	   // Ahora inicio apunta al nuevo primer elemento.
		n->tam++;			   // Incremento el numero de elementos que tengo en la lista (+1).
		nuel = NULL;
		free(nuel);
		return 1;
	}
}

void muestra(lista *x)
{
	int a = 1;
	elem *aux, *f;
	aux = x->inicio;
	f = x->fin;
	printf("\n");
	printf("Tu lista es:\n");
	while (aux != NULL)
	{
		printf(" %d - %d \n", a, aux->dato);
		a++;
		aux = aux->sig;
	}
	printf("\n");
}
