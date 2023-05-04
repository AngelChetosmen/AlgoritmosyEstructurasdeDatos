/*
Autor: AngelChetosmen
Consultar la Licencia del Autor | Derechos Reservados EUVA B&T ©
*/
#include <stdlib.h>
#include <stdio.h>

int fun(char[]);
void tabla(int, int, int[]);
void limpio(int[]);
void imp(int[]);

int main()
{
	int a, n, b, inc;
	int hash[23];
	char placa[6];
	limpio(hash);
	printf("Este programa hace la implementacion de una tabla hash.\n");
	printf("Este es un indicador de que si 'x' vehiculo ha pasado el limite de velocidad permitido.\n");
	printf("Si pasas el limite de velocidad mas de una vez, este te indicara.\n");
	printf("Solo podra detectar y almacenar placas de 23 vehiculos.\n");
	do
	{
		printf("\n");
		printf("\n");
		printf("Las placas consta de los primeros 3 digitos (numeros) y 3 letras.\n");
		printf("Es una simlucion, por lo tanto tendra un menu con las opciones.\n");
		printf("\nMenu:\n");
		printf("1. Ingresar placas.\n");
		printf("2. Mostrar tabla del numero de velocidades excedidas.\n");
		printf("3. Salir del programa.\n");
		scanf("%d", &a);
		printf("\n");
		if (a == 1)
		{
			printf("Ingresar las placas (3 numeros y 3 letras).\n");
			scanf("%s", placa);
			n = fun(placa);
			printf("\n");
			printf("\n");
			printf("Este vehiculo excedio los limites.\n");
			printf("1. SI.\n");
			printf("2. NO.\n");
			scanf("%d", &b);
			switch (b)
			{
			case 1:
				inc = 1;
				tabla(inc, n, hash);
				break;
			case 2:
				inc = 0;
				tabla(inc, n, hash);
				break;
			default:
				printf("Opcion no valida.\n");
				break;
			}
		}
		if (a == 2)
		{
			imp(hash);
		}
	} while (a != 3);
	printf("Usted ha salido del programa.\n");
	return 0;
}

void tabla(int sino, int pos, int ta[])
{
	if (sino == 1)
	{
		ta[pos]++;
		if (ta[pos] > 1)
		{
			printf("Usted ha excedido el limite de velocidad %d veces.\n", ta[pos]);
		}
		else
		{
			printf("Aun permitido.\n");
		}
	}
	else
	{
		printf("Velocidad adecuada.\n");
	}
}

void limpio(int a[])
{
	for (int x = 0; x < 23; x++)
	{
		a[x] = 0;
	}
}

int fun(char ar[])
{
	int x;
	int o[10];
	for (int y = 0; y < 3; y++)
	{
		o[y] = ar[y] * (y + 1);
	}
	o[7] = o[0] + o[1] + o[2];
	for (int y = 3; y < 6; y++)
	{
		o[y] = ar[y] * (y + 1);
	}
	o[8] = o[3] + o[4] + o[5] + o[7];
	x = o[8] % 23;
	printf("La posicion de las placas en tabla es: %d.\n", x);
	return x;
}

void imp(int tab[])
{
	int c = 0;
	printf("Tabla de velocidades excedidas.\n");
	for (int i = 0; i < 23; i++)
	{
		if (tab[i] > 1)
		{
			printf(" %d . Ha excedido %d veces la velocidad.\n", i, tab[i]);
			c++;
		}
	}
	if (c == 0)
	{
		printf("No se han excedido el limite de velocidad.\n");
	}
}
