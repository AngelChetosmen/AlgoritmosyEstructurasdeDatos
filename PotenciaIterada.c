/*
Autor: AngelChetosmen
Consultar la Licencia del Autor | Derechos Reservados EUVA B&T ©
*/
#include <stdio.h>
#include <stdlib.h>

int pote(int, int);

int main()
{
	int x, a, r;
	printf("Este programa saca potencia de un numero 'a' elevado a un numero 'b'.\n");
	printf("Los dos son de tipo entero.\n");
	printf("Por favor, ingrese el numero.\n");
	scanf("%d", &x);
	printf("Ingrese la potencia.\n");
	scanf("%d", &a);
	r = pote(x, a);
	printf("El resultado de %d ^ ( %d ) es:  %d.\n", x, a, r);
	return 0;
}

int pote(int x, int a)
{
	if (a == 1)
	{
		return x;
	}
	else
	{
		x = x * pote(x, a - 1);
		return x;
	}
}
