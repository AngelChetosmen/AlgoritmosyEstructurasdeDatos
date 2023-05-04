/*
Autor: AngelChetosmen
Consultar la Licencia del Autor | Derechos Reservados EUVA B&T ©
*/
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct nodo
{
	struct nodo *padre;
	struct nodo *izquierdo;
	struct nodo *derecho;
	int valor;
} Nodo;

struct nodo *crear_nodo(Nodo *padre, int valor);
void agregar_valor(Nodo *arbol, int valor);
void eliminar_nodo(Nodo *arbol, int valor);
void eliminar(Nodo *nodoaeliminar);
Nodo *minimo(Nodo *arbol);
void reemplazar(Nodo *arbol, Nodo *nuevo);
void destruir(Nodo *arbol);
void Ver_Mayor(Nodo *arbol);
void ver_menor(Nodo *arbol);
void Opciones();

//---------------------------------------------------main----------------------------------------------------------------------
int main()
{
	int opc, opc2;
	int valor, valor2, valor3;
	printf("\n---------------------Arbol Binario------------------\n");
	printf("Ingrese el valor que quiera de raiz: \t");
	scanf("%d", &valor);
	Nodo *arbol;
	arbol = crear_nodo(NULL, valor);
	do
	{
		Opciones();
		printf("\n Ingrese alguna opcion: \t");
		scanf("%d", &opc);
		printf("\n");
		switch (opc)
		{
		case 1:
			do
			{
				printf("\n 1. Ingresar valor. \n 2. Salir");
				printf("\n Ingrese alguna opcion: \t");
				scanf("%d", &opc2);
				switch (opc2)
				{
				case 1:
					printf("\n Ingrese el valor: \t");
					scanf("%d", &valor2);
					agregar_valor(arbol, valor2);
					break;
				case 2:
					break;
				default:
					printf("\n Ingrese una opcion valida");
				}
			} while (opc2 != 2);
			break;
		case 2:
			printf("\n");
			Ver_Mayor(arbol);
			break;
		case 3:
			printf("\n");
			ver_menor(arbol);
			break;

		case 4:
			printf("\n Digite el valor del nodo que desea eliminar: \t");
			scanf("%d", &valor3);
			eliminar_nodo(arbol, valor3);
			break;
		case 5:
			break;
		default:
			printf("\n Ingrese una opcion valida");
		}
	} while (opc != 5);
	return 0;
}
//------------------------------------------------------------------------------------------------------------------------------
void Opciones()
{
	printf("\n 1. Agregar valor al arbol");
	printf("\n 2. Ver valor mayor del arbol \n 3. Ver valor menor del arbol \n 4. Eliminar un nodo \n 5. Salir \n");
}

Nodo *crear_nodo(Nodo *padre, int valor)
{
	Nodo *n = calloc(sizeof(Nodo), 1);
	n->padre = padre;
	n->valor = valor;
	return n;
}

void agregar_valor(Nodo *arbol, int valor)
{
	Nodo *temp, *pivote;
	int derecho = 0;
	if (arbol)
	{
		temp = arbol;
		while (temp != NULL)
		{
			pivote = temp;
			if (valor > temp->valor)
			{
				temp = temp->derecho;
				derecho = 1;
			}
			else
			{
				temp = temp->izquierdo;
				derecho = 0;
			}
		}
		temp = crear_nodo(pivote, valor);
		if (derecho)
		{
			printf("Insertando %i el lado derecho de %i\n", valor, pivote->valor);
			pivote->derecho = temp;
		}
		else
		{
			printf("Insertando %i el lado izquierdo de %i\n", valor, pivote->valor);
			pivote->izquierdo = temp;
		}
	}
	else
	{
		printf("EL arbol no esta inicializado");
	}
}

void Ver_Mayor(Nodo *aux)
{

	int mayor = aux->valor;

	if (aux != NULL)
	{

		while (aux->derecho != NULL)
		{

			aux = aux->derecho;

			mayor = aux->valor;
		}
	}
	printf("El mayor es: %d \n", mayor);
}

void ver_menor(Nodo *aux)
{
	int menor = aux->valor;
	if (aux != NULL)
	{
		while (aux->izquierdo != NULL)
		{
			aux = aux->izquierdo;
			menor = aux->valor;
		}
	}
	printf("El menor es: %d \n", menor);
}

void eliminar_nodo(Nodo *aux, int valor)
{
	if (aux == NULL)
	{
		return;
	}
	else if (valor < aux->valor)
	{
		eliminar_nodo(aux->izquierdo, valor);
	}
	else if (valor > aux->valor)
	{
		eliminar_nodo(aux->derecho, valor);
	}
	else
	{
		eliminar(aux);
	}
}
Nodo *minimo(Nodo *aux)
{
	if (aux == NULL)
	{
		return NULL;
	}
	if (aux->izquierdo)
	{
		return minimo(aux->izquierdo);
	}
	else
	{
		return aux;
	}
}
void reemplazar(Nodo *aux, Nodo *nuevo)
{
	if (aux->padre)
	{
		if (aux->valor = aux->padre->izquierdo->valor)
		{
			aux->padre->izquierdo = nuevo;
		}
		else if (aux->valor = aux->padre->derecho->valor)
		{
			aux->padre->derecho = nuevo;
		}
	}
	if (nuevo)
	{
		nuevo->padre = aux->padre;
	}
}

void destruir(Nodo *aux)
{
	aux->izquierdo = NULL;
	aux->derecho = NULL;
	free(aux);
}
void eliminar(Nodo *aux)
{
	if (aux->izquierdo && aux->derecho)
	{
		Nodo *menor = minimo(aux->derecho);
		aux->valor = menor->valor;
		eliminar(menor);
	}
	else if (aux->izquierdo)
	{
		reemplazar(aux, aux->izquierdo);
		destruir(aux);
	}
	else if (aux->derecho)
	{
		reemplazar(aux, aux->derecho);
		destruir(aux);
	}
	else
	{
		reemplazar(aux, NULL);
		destruir(aux);
	}
}
