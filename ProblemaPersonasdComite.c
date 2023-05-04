/*
Autor: AngelChetosmen
Consultar la Licencia del Autor | Derechos Reservados EUVA B&T ©
*/
#include <stdio.h>
int fact(int);
int main()
{
  int n, k;
  printf("Ingresa cantidad de personas a elegir (n): ");
  scanf("%d", &n);
  printf("\n");
  printf("Ingresa cantidad de personas por comite (k): ");
  scanf("%d", &k);
  if (n >= k)
  {
    int res;
    res = (fact(n) / (fact(k) * fact(n - k)));
    printf("Habra %d posibles comites de %d personas cada uno\n", res, k);
  }
  else
  {
    printf("Debe haber mas personas para acompletar los comites\n");
  }
  return 0;
}
int fact(int n)
{
  if (n == 0)
  {
    return 1;
  }
  else
  {
    int i, a = 1;
    for (i = n; i > 0; i--)
      a = a * i;
    return a;
  }
}
