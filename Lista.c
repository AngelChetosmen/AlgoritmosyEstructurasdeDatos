/*
Autor: AngelChetosmen
Consultar la Licencia del Autor | Derechos Reservados EUVA B&T ©
*/
#include <stdio.h>
#include <stdlib.h>

#define TM 10

void InserInicio(int p[], int, int);
void InserPos(int p[], int, int, int);
void InserFin(int p[], int, int);

int EliInicio(int p[], int);
int EliPos(int p[], int, int);
int EliFin(int p[], int);

int BuscaNum(int p[], int);
int BuscPos(int p[], int);

void Crear(int p[]);
void display(int p[], int);

int main()
{
	int a, lista[TM];
	int b, c, fin, d, e, f, g, h, i;
	fin = -1;
	printf("Esta es una lista lineal de forma estatica de solo enteros.\n");
	printf("Esta lista puede almacenar hasta 10 elementos.\n");
	do
	{
		printf("\n");
		printf("Seleccione de forma numerica la opcion que desea realizar en una lista\n");
		printf("En caso de que sea la primera vez, escoga la opcion de CREAR LISTA NUEVA\n");
		printf("\n");
		printf("\n");
		printf("1. Crear lista nueva.\n");
		printf("2. Insertar elemento.\n");
		printf("3. Eliminar elemento.\n");
		printf("4. Busqueda a traves del valor a buscar.\n");
		printf("5. Busqueda por medio del numero de posicion del elemento.\n");
		printf("6. Salir del programa.\n");
		scanf("%d", &a);
		switch (a)
		{

		case 1:
			fin = -1;
			Crear(lista);
			printf("La lista se creo con exito\n");
			fin++; // Aqui ahora vale 0, esta en la posicion 0 del arreglo.
			printf("Coloque el primer numero como dato que desea agregar a la lista\n");
			scanf("%d", &c);
			lista[fin] = c;
			display(lista, fin);
			break;

		case 2:
			if (fin == TM - 1)
			{
				printf("\n");
				printf("\n");
				printf("Tu lista esta llena\n");
				printf("\n");
				printf("\n");
				break;
			}
			else
			{
				printf("\n");
				printf("\n");
				printf("Coloque el elemento de tipo entero a agregar a la lista\n");
				scanf("%d", &c);
				printf("\n");
				printf("\n");
				printf("Elija de forma numerica, como desea agregar el elemento\n");
				printf("1. Inicio de la lista\n");
				printf("2. Final de la lista\n");
				printf("3. Posicion especifica\n");
				printf("\n");
				display(lista, fin);
				printf("\n");
				scanf("%d", &d);
				switch (d)
				{
				case 1:
					InserInicio(lista, c, fin);
					fin++;
					display(lista, fin);
					break;
				case 2:
					InserFin(lista, c, fin);
					fin++;
					display(lista, fin);
					break;
				case 3:
					printf("Por favor, coloque la posicion deseada\n");
					display(lista, fin);
					scanf("%d", &e);
					InserPos(lista, e, fin, c);
					fin++;
					display(lista, fin);
					break;
				default:
					printf("Esa opcion es incorrecta, intente de nuevo\n");
				}
			}
			break;

		case 3:
			if (fin == -1)
			{
				printf("\n");
				printf("\n");
				printf("Tu lista esta vacia\n");
				printf("\n");
				printf("\n");
				break;
			}
			else
			{
				printf("\n");
				printf("\n");
				printf("Elija de forma numerica, como desea eliminar el elemento\n");
				printf("1. Inicio de la lista\n");
				printf("2. Final de la lista\n");
				printf("3. Posicion especifica\n");
				printf("\n");
				display(lista, fin);
				printf("\n");
				scanf("%d", &d);
				switch (d)
				{
				case 1:
					f = EliInicio(lista, fin);
					printf("El elemento eliminado es: %d .\n", f);
					fin--;
					display(lista, fin);
					break;
				case 2:
					f = EliFin(lista, fin);
					printf("El elemento eliminado es: %d .\n", f);
					fin--;
					display(lista, fin);
					break;
				case 3:
					printf("Por favor, coloque la posicion deseada\n");
					display(lista, fin);
					scanf("%d", &e);
					f = EliPos(lista, e, fin);
					printf("El elemento eliminado es: %d .\n", f);
					fin--;
					display(lista, fin);
					break;
				default:
					printf("Esa opcion es incorrecta intente de nuevo\n");
				}
			}

			break;
		case 4:
			if (fin == -1)
			{
				printf("Tu lista no tiene elementos\n");
				break;
			}
			else
			{
				printf("Por favor coloque el valor que desea buscar:\n");
				scanf("%d", &g);
				printf("\n");
				printf("\n");
				f = BuscaNum(lista, g);
				display(lista, fin);
				printf("\n");
				printf("El valor %d se encuentra en la posicion %d de la lista\n", g, f + 1);
				break;
			}
		case 5:
			if (fin == -1)
			{
				printf("Tu lista no tiene elementos\n");
				break;
			}
			else
			{
				printf("Por favor coloque la posicion donde desea buscar:\n");
				scanf("%d", &i);
				h = BuscPos(lista, i);
				printf("\n");
				printf("\n");
				display(lista, fin);
				printf("\n");
				printf("En la posicion %d se encuentra el elemento: %d .\n", i, h);
				break;
			}
			break;
		default:
			printf("Salio del programa.\n");
		}
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
	} while (a < 6);
	return 0;
}

void Crear(int x[])
{
	for (int y = 0; y < TM; y++)
	{
		x[y] = 0;
	}
}

void InserInicio(int x[], int a, int f)
{
	if (f == TM - 1)
	{
		printf("La lista esta llena.\n");
	}
	else
	{
		for (int e = f; e > -1; e--)
		{
			x[e + 1] = x[e];
		}
	}
	x[0] = a;
}

void InserFin(int x[], int d, int f)
{
	if (f == TM - 1)
	{
		printf("La lista esta llena.\n");
	}
	else
	{
		f++;
		x[f] = d;
	}
}

void InserPos(int x[], int p, int f, int a)
{				 // p es la posicion, f el final, a es el elemento
	int q, r, s; // f va de 0 a 9.
	if (f == TM - 1)
	{
		printf("La lista esta llena\n");
	}
	else
	{
		p--;
		s = f + 1; // Ahora s va de 1 a 10.
		r = p - 1; // Posicion antes de la elegida de 1 a 10.
		for (int b = s; b > r; b--)
		{
			x[b + 1] = x[b];
		}
	}
	x[p] = a;
}

void display(int x[], int fin)
{

	printf("Tu lista es:\n");
	for (int u = 0; u < fin + 1; u++)
	{
		printf(" %d . - %d - \n", u + 1, x[u]);
	}
}

int EliInicio(int x[], int d)
{
	int a;
	a = x[0];
	for (int y = 1; y < d + 1; y++)
	{
		x[y - 1] = x[y];
	}
	x[d] = 0;
	return a;
}

int EliFin(int x[], int fn)
{
	int a;
	a = x[fn];
	x[fn] = 0;
	return a;
}

int EliPos(int x[], int p, int f)
{
	int a, r;
	a = x[p - 1];
	r = p; // Incremento a p de 0 a 10.
	for (int y = r; y < f + 1; y++)
	{
		x[y - 1] = x[y];
	}
	x[f] = 0;
	return a;
}

int BuscaNum(int x[], int f)
{
	int a = 0;
	while (f != x[a])
	{
		a++;
	}
	return a;
}

int BuscPos(int x[], int g)
{
	int b;
	b = x[g - 1];
	return b;
}
