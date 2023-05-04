/*
Autor: AngelChetosmen
Consultar la Licencia del Autor | Derechos Reservados EUVA B&T ©
*/
#include <stdio.h>
#include <stdlib.h>

void q_sort(int a[], int inicio, int final);

int main()
{
	int i, ta;
	int a[] = {1, 67, 99, 43, 12, 3};
	ta = sizeof(a) / sizeof(int);
	for (i = 0; i < ta; ++i)
		printf("%d ", a[i]);
	printf("\n");

	q_sort(a, 0, 5);
	for (i = 0; i < ta; ++i)
		printf("%d ", a[i]);
	printf("\n");

	return 0;
}

void q_sort(int a[], int inicio, int final)
{
	int piv, der, izq, med;
	if (inicio < final)
	{
		piv = a[inicio];
		izq = inicio;

		der = final;
		while (izq < der)
		{
			while (der > izq && a[der] > piv)
				der--;
			if (der > izq)
			{
				a[izq] = a[der];
				izq++;
			}
			while (izq < der && a[izq] < piv)
				izq++;
			if (izq < der)
			{
				a[der] = a[izq];
				der--;
			}
		}
		a[der] = piv;
		med = der;

		q_sort(a, inicio, med - 1);
		q_sort(a, med + 1, final);
	}
}
