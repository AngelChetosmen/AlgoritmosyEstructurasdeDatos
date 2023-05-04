// Ordenamiento Burbuja
/*
Autor: AngelChetosmen
Consultar la Licencia del Autor | Derechos Reservados EUVA B&T ©
*/
#include <stdio.h>
#include <stdlib.h>
#define TAM 11

int main()
{
  int a[TAM] = {32, 27, 22, 11, 13, 1, 99, 70, 45, 21};
  int i, temp, x, j, tam, *arr, o;
  arr = (int *)malloc(sizeof(int));
  printf("Los datos en el orden original son: \n");
  for (i = 0; i < TAM - 1; i++)
    printf("%d ", a[i]);
  printf("\n");

  for (i = 0; i < TAM - 1; i++)
  {
    for (j = 0; j < TAM - 1 - i; j++)
      if (a[j] > a[j + 1])
      {
        temp = a[j];
        a[j] = a[j + 1];
        a[j + 1] = temp;
      }
    x++;
  }

  printf("Los datos en orden creciente son: \n");
  for (i = 1; i <= TAM - 1; i++)
    printf("%d ", a[i]);
  printf("\n");

  printf("\nDesea ingresar numeros a un arreglo nuevo? \n");
  printf("(si=1/no=ingrese cualquier otra tecla)\n");
  scanf("%d", &o);
  if (o == 1)
  {
    printf("Ingrese el numero de elementos del arreglo: \n");
    scanf("%d", &tam);

    printf("Ingrese los %d elementos \n", tam);
    for (i = 0; i < tam; i++)
    {
      scanf("%d", &arr[i]);
    }
    printf("Antes de acomodar los numeros: \n");
    for (i = 0; i < tam; i++)
    {
      printf("%d ", arr[i]);
    }
    printf("\n");

    for (i = 0; i < tam - 1; i++)
    {
      for (j = 0; j < tam - 1 - i; j++)
      {
        if (arr[j] >= arr[j + 1])
        {
          temp = arr[j];
          arr[j] = arr[j + 1];
          arr[j + 1] = temp;
        }
      }
    }
    x++;

    printf("Despues de acomodar los numeros: \n");
    for (i = 0; i < tam; i++)
    {
      printf("%d ", arr[i]);
    }
  }
  return 0;
}
