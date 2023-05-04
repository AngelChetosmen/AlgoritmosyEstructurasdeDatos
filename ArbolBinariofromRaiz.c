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
int Contar_Nodos(Nodo *arbol);
int get_Niveles(Nodo *arbol);
void Preorden(Nodo *arbol);
void PostOrden(Nodo *arbol);
void Orden(Nodo *arbol);
int sumatoria(Nodo *arbol);
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
			printf("\n El numero de nodos es: %d ", Contar_Nodos(arbol));
			break;
		case 5:
			printf("\n El numero de niveles del arbol es %d \n", get_Niveles(arbol));
			break;
		case 6:
			Preorden(arbol);
			printf("\n");
			break;
		case 7:
			PostOrden(arbol);
			printf("\n");
			break;
		case 8:
			Orden(arbol);
			printf("\n");
			break;
		case 9:
			printf("\n La sumatoria es: %d", sumatoria(arbol));
			break;
		case 10:
			printf("\n Digite el valor del nodo que desea eliminar: \t");
			scanf("%d", &valor3);
			eliminar_nodo(arbol, valor3);
			break;
		case 11:
			break;
		default:
			printf("\n Ingrese una opcion valida");
		}
	} while (opc != 11);
	return 0;
}
//------------------------------------------------------------------------------------------------------------------------------
void Opciones()
{
	printf("\n 1. Agregar valor al arbol");
	printf("\n 2. Ver valor mayor del arbol \n 3. Ver valor menor del arbol \n 4. Saber el numero de nodos del arbol \n 5. Saber el numero de niveles del arbol \n 6. Ver Preorden \n 7. Ver Postorden \n 8. Ver Orden \n 9. Sumar todos los valores del arbol \n 10. Eliminar un nodo \n 11. Salir \n");
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

int Contar_Nodos(Nodo *aux)
{
	if (aux != NULL)
	{
		int izq = Contar_Nodos(aux->izquierdo);
		int der = Contar_Nodos(aux->derecho);
		int medio = 1;
		return izq + der + medio;
	}

	return 0;
}
int get_Niveles(Nodo *aux)
{
	if (aux != NULL)
	{
		int niveles = 0;
		int izq = get_Niveles(aux->izquierdo) + 1;
		int der = get_Niveles(aux->derecho) + 1;
		if (izq > der)
		{
			niveles = izq;
			return niveles;
		}
		niveles = der;
		return niveles;
	}
	return -1;
}

void Preorden(Nodo *aux)
{
	if (aux == NULL)
	{
		return;
	}
	else
	{
		printf("%d-", aux->valor);
		Preorden(aux->izquierdo);
		Preorden(aux->derecho);
	}
}

void PostOrden(Nodo *aux)
{
	if (aux == NULL)
	{
		return;
	}
	else
	{

		PostOrden(aux->izquierdo);
		PostOrden(aux->derecho);
		printf("%d-", aux->valor);
	}
}

void Orden(Nodo *aux)
{
	if (aux == NULL)
	{
		return;
	}
	else
	{
		Orden(aux->izquierdo);
		printf("%d-", aux->valor);
		Orden(aux->derecho);
	}
}

int sumatoria(Nodo *aux)
{
	if (aux != NULL)
	{
		int centro = aux->valor;
		int izq = sumatoria(aux->izquierdo);
		int der = sumatoria(aux->derecho);
		return izq + centro + der;
	}
	return 0;
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
