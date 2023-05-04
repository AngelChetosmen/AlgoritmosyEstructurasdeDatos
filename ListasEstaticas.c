/*
Autor: AngelChetosmen
Consultar la Licencia del Autor | Derechos Reservados EUVA B&T ©
*/
#include <stdio.h>
#include <stdlib.h>

#define TM 5

void InserInicio(int p[], int, int);
void InserPos(int p[], int, int, int);
void InserFin(int p[], int, int);

int EliInicio(int p[], int);
int EliPos(int p[], int, int);
int EliFin(int p[], int);

int BuscaNum(int p[], int);
int BuscPos(int p[], int);

int sumNumsIni(int x[], int y[], int fin1, int fin2);
int sumNumsFin(int x[], int y[], int fin1, int fin2);
int resNumsIni(int x[], int y[], int fin1, int fin2);
int resNumsFin(int x[], int y[], int fin1, int fin2);
int multNumsFin(int x[], int y[], int fin1, int fin2);
int multNumsIni(int x[], int y[], int fin1, int fin2);
int divNumsIni(int x[], int y[], int fin1, int fin2);
int divNumsFin(int x[], int y[], int fin1, int fin2);

void Crear(int p[]);
void display(int p[], int);

int main()
{
  int a, lista1[TM], lista2[TM];
  int b1, c1, fin1, d, d1, e1, f1, g1, h1, i1;
  int b2, c2, fin2, d2, e2, f2, g2, h2, i2;
  int sum, res1, mult, div1, div2;
  int s1, s2, s3, s4, r1, r2, r3, r4, m1, m2, m3, m4, z1, z2, z3, z4, x, y;
  int op;
  fin1 = -1;
  fin2 = -1;
  do
  {
    printf("\n");
    printf("\n");
    printf("                       Operaciones entre listas estaticas             \n");
    printf("Seleccione de forma numerica la opcion que desea realizar con las listas\n");
    printf("En caso de que sea la primera vez, escoga la opcion de CREAR LISTAS NUEVAS\n");
    printf("\n");
    printf("\n");
    printf("1. Crear listas nuevas.\n");
    printf("2. Insertar elemento a listas\n");
    printf("3. Eliminar elemento a listas \n");
    printf("4. Busqueda a traves del valor a buscar en listas. \n");
    printf("5. Busqueda por medio del numero de posicion del elemento en listas \n");
    printf("6. Sumar elementos \n");
    printf("7. Restar elementos \n");
    printf("8. Multiplicar elementos \n");
    printf("9. Dividir elementos \n");
    printf("10. Ver listas \n");
    printf("11. Salir del programa.\n");
    scanf("%d", &a);
    switch (a)
    {

    case 1:
      fin1 = -1;
      fin2 = -1;
      Crear(lista1);
      printf("La lista 1 se creo con exito\n");
      fin1++; // Aqui ahora vale 0, esta en la posicion 0 del arreglo.
      printf("Coloque el primer numero como dato que desea agregar a la lista 1 \n");
      scanf("%d", &c1);
      lista1[fin1] = c1;
      display(lista1, fin1);
      Crear(lista2);
      printf("La lista 2 se creo con exito\n");
      fin2++; // Aqui ahora vale 0, esta en la posicion 0 del arreglo.
      printf("Coloque el primer numero como dato que desea agregar a la lista 2 \n");
      scanf("%d", &c2);
      lista2[fin2] = c2;
      display(lista2, fin2);
      break;

    case 2:
      if (fin1 == TM - 1 || fin2 == TM - 1)
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
        printf("Coloque el elemento de tipo entero a agregar a la lista 1\n");
        scanf("%d", &c1);
        printf("\n");
        printf("\n");
        printf("Elija de forma numerica, como desea agregar el elemento\n");
        printf("1. Inicio de la lista\n");
        printf("2. Final de la lista\n");
        printf("3. Posicion especifica\n");
        printf("\n");
        printf("\n");
        scanf("%d", &d1);
        switch (d1)
        {
        case 1:
          InserInicio(lista1, c1, fin1);
          fin1++;
          display(lista1, fin1);
          break;
        case 2:
          InserFin(lista1, c1, fin1);
          fin1++;
          display(lista1, fin1);
          break;
        case 3:
          printf("Por favor, coloque la posicion deseada\n");
          display(lista1, fin1);
          scanf("%d", &e1);
          InserPos(lista1, e1, fin1, c1);
          fin1++;
          display(lista1, fin1);
          break;
        default:
          printf("Esa opcion es incorrecta, intente de nuevo\n");
        }
        printf("\n");
        printf("\n");
        printf("Coloque el elemento de tipo entero a agregar a la lista 2\n");
        scanf("%d", &c2);
        printf("\n");
        printf("\n");
        printf("Elija de forma numerica, como desea agregar el elemento\n");
        printf("1. Inicio de la lista\n");
        printf("2. Final de la lista\n");
        printf("3. Posicion especifica\n");
        printf("\n");
        printf("\n");
        scanf("%d", &d2);
        switch (d2)
        {
        case 1:
          InserInicio(lista2, c2, fin2);
          fin2++;
          display(lista2, fin2);
          break;
        case 2:
          InserFin(lista2, c2, fin2);
          fin2++;
          display(lista2, fin2);
          break;
        case 3:
          printf("Por favor, coloque la posicion deseada\n");
          display(lista2, fin2);
          scanf("%d", &e2);
          InserPos(lista2, e2, fin2, c2);
          fin2++;
          display(lista2, fin2);
          break;
        default:
          printf("Esa opcion es incorrecta, intente de nuevo\n");
        }
      }

      break;

    case 3:
      if (fin1 == -1 || fin2 == -1)
      {
        printf("\n");
        printf("Tus listas estan vacias\n");
        printf("\n");
        break;
      }
      else
      {
        printf("\n");
        printf("\n");
        printf("Elija de forma numerica, como desea eliminar el elemento en la lista 1\n");
        printf("1. Inicio de la lista 1\n");
        printf("2. Final de la lista 1\n");
        printf("3. Posicion especifica de lista 1\n");
        printf("\n");
        printf("\n");
        scanf("%d", &d1);
        switch (d1)
        {
        case 1:
          f1 = EliInicio(lista1, fin1);
          printf("El elemento eliminado es: %d .\n", f1);
          fin1--;
          display(lista1, fin1);
          break;
        case 2:
          f1 = EliFin(lista1, fin1);
          printf("El elemento eliminado es: %d .\n", f1);
          fin1--;
          display(lista1, fin1);
          break;
        case 3:
          printf("Por favor, coloque la posicion deseada\n");
          display(lista1, fin1);
          scanf("%d", &e1);
          f1 = EliPos(lista1, e1, fin1);
          fin1--;
          display(lista1, fin1);
          break;
        default:
          printf("Esa opcion es incorrecta intente de nuevo\n");
        }
        printf("\n");
        printf("\n");
        printf("Elija de forma numerica, como desea eliminar el elemento de la lista 2n\n");
        printf("1. Inicio de la lista 2\n");
        printf("2. Final de la lista 2\n");
        printf("3. Posicion especifica de la lista 2\n");
        printf("\n");
        printf("\n");
        scanf("%d", &d2);
        switch (d2)
        {
        case 1:
          f2 = EliInicio(lista2, fin2);
          printf("El elemento eliminado es: %d .\n", f2);
          fin2--;
          display(lista2, fin2);
          break;
        case 2:
          f2 = EliFin(lista2, fin2);
          printf("El elemento eliminado es: %d .\n", f2);
          fin2--;
          display(lista2, fin2);
          break;
        case 3:
          printf("Por favor, coloque la posicion deseada\n");
          display(lista2, fin2);
          scanf("%d", &e2);
          f2 = EliPos(lista2, e2, fin2);
          printf("El elemento eliminado es: %d .\n", f2);
          fin2--;
          display(lista2, fin2);
          break;
        default:
          printf("Esa opcion es incorrecta intente de nuevo\n");
        }
      }

      break;
    case 4:
      if (fin1 == -1 || fin2 == -1)
      {
        printf("Tus listas no tienen elementos\n");
        break;
      }
      else
      {
        printf("Por favor coloque el valor que desea buscar de la lista 1:\n");
        scanf("%d", &g1);
        printf("\n");
        printf("\n");
        f1 = BuscaNum(lista1, g1);
        printf("El valor %d se encuentra en la posicion %d de la lista 1\n", g1, f1 + 1);
        printf("\n");
        printf("\n");
        display(lista1, fin1);
        printf("Por favor coloque el valor que desea buscar de la lista 2:\n");
        scanf("%d", &g2);
        printf("\n");
        printf("\n");
        f2 = BuscaNum(lista2, g2);
        printf("El valor %d se encuentra en la posicion %d de la lista 2", g2, f2 + 1);
        printf("\n");
        printf("\n");
        display(lista2, fin2);
        break;
      }
    case 5:
      if (fin1 == -1 || fin2 == -1)
      {
        printf("Tu lista no tiene elementos\n");
        break;
      }
      else
      {
        printf("Por favor coloque la posicion donde desea buscar en la lista 1:\n");
        scanf("%d", &i1);
        h1 = BuscPos(lista1, i1);
        printf("\n");
        printf("\n");
        printf("En la posicion %d se encuentra el elemento: %d .\n", i1, h1);
        printf("\n");
        printf("\n");
        display(lista1, fin1);
        printf("Por favor coloque la posicion donde desea buscar en la lista 2:\n");
        scanf("%d", &i2);
        h2 = BuscPos(lista2, i2);
        printf("\n");
        printf("\n");
        printf("En la posicion %d se encuentra el elemento: %d .\n", i2, h2);
        printf("\n");
        printf("\n");
        display(lista2, fin2);
        break;
      }
      break;
    case 6:
      printf("\n\nSuma de enteros\n");
      if (fin1 == TM - 1 || fin2 == TM - 1)
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
        printf("Elija de forma numerica, como desea sumar elementos\n");
        printf("1. Primeros dos de la lista\n");
        printf("2. Ultimos dos de la lista\n");
        printf("3. Indicar la posicion de ambos numeros \n");
        printf("\n");
        printf("\n");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
          s1 = sumNumsIni(lista1, lista2, fin1, fin2);
          printf("Lista 1: \n");
          display(lista1, fin1);
          printf("Lista 2: \n");
          display(lista2, fin2);
          printf("La suma de los dos primeros numeros \n      de las listas es: %d\n", s1);
          break;
        case 2:
          s2 = sumNumsFin(lista1, lista2, fin1, fin2);
          printf("Lista 1: \n");
          display(lista1, fin1);
          printf("Lista 2: \n");
          display(lista2, fin2);
          printf("La suma de los dos ultimos numeros \n      de las listas es: %d\n", s2);
          break;
        case 3:
          printf("Por favor, coloque la posicion deseada del elemento de la lista 1\n");
          display(lista1, fin1);
          scanf("%d", &x);
          s3 = BuscPos(lista1, x);
          printf("Por favor, coloque la posicion deseada del elemento de la lista 2\n");
          display(lista2, fin2);
          scanf("%d", &y);
          s4 = BuscPos(lista2, y);
          sum = s3 + s4;
          printf("La suma de los dos numeros indicados es: %d+%d =%d\n", s3, s4, sum);
          break;
        default:
          printf("Esa opcion es incorrecta, intente de nuevo\n");
        }
      }
      break;
    case 7:
      printf("\n\nResta de enteros\n");
      if (fin1 == TM - 1 || fin2 == TM - 1)
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
        printf("Elija de forma numerica, como desea restar elementos\n");
        printf("1. Primeros dos de la lista\n");
        printf("2. Ultimos dos de la lista\n");
        printf("3. Indicar la posicion de ambos numeros \n");
        printf("\n");
        printf("\n");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
          r1 = resNumsIni(lista1, lista2, fin1, fin2);
          printf("Lista 1: \n");
          display(lista1, fin1);
          printf("Lista 2: \n");
          display(lista2, fin2);
          printf("La resta de los dos primeros numeros \n      de las listas es: %d\n", r1);
          break;
        case 2:
          r2 = resNumsFin(lista1, lista2, fin1, fin2);
          printf("Lista 1: \n");
          display(lista1, fin1);
          printf("Lista 2: \n");
          display(lista2, fin2);
          printf("La resta de los dos ultimos numeros \n      de las listas es: %d\n", r2);
          break;
        case 3:
          printf("Por favor, coloque la posicion deseada del elemento de la lista 1\n");
          display(lista1, fin1);
          scanf("%d", &x);
          r3 = BuscPos(lista1, x);
          printf("Por favor, coloque la posicion deseada del elemento de la lista 2\n");
          display(lista2, fin2);
          scanf("%d", &y);
          r4 = BuscPos(lista2, y);
          res1 = r3 - r4;
          printf("La resta de los dos numeros indicados es: %d-%d = %d \n", r3, r4, res1);
          break;
        default:
          printf("Esa opcion es incorrecta, intente de nuevo\n");
        }
      }
      break;
    case 8:
      printf("\n\nMultiplicacion de enteros\n");
      if (fin1 == TM - 1 || fin2 == TM - 1)
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
        printf("Elija de forma numerica, como desea multiplicar elementos\n");
        printf("1. Primeros dos de la lista\n");
        printf("2. Ultimos dos de la lista\n");
        printf("3. Indicar la posicion de ambos numeros \n");
        printf("\n");
        printf("\n");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
          m1 = multNumsIni(lista1, lista2, fin1, fin2);
          printf("Lista 1: \n");
          display(lista1, fin1);
          printf("Lista 2: \n");
          display(lista2, fin2);
          printf("La multiplicacion de los dos primeros numeros \n      de las listas es: %d\n", m1);
          break;
        case 2:
          m2 = multNumsFin(lista1, lista2, fin1, fin2);
          printf("Lista 1: \n");
          display(lista1, fin1);
          printf("Lista 2: \n");
          display(lista2, fin2);
          printf("La resta de los dos ultimos numeros \n      de las listas es: %d\n", m2);
          break;
        case 3:
          printf("Por favor, coloque la posicion deseada del elemento de la lista 1\n");
          display(lista1, fin1);
          scanf("%d", &x);
          m3 = BuscPos(lista1, x);
          printf("Por favor, coloque la posicion deseada del elemento de la lista 2\n");
          display(lista2, fin2);
          scanf("%d", &y);
          m4 = BuscPos(lista2, y);
          mult = m3 * m4;
          printf("La multiplicaion de los dos numeros indicados es: %d * %d = %d\n", m3, m4, mult);

          break;
        default:
          printf("Esa opcion es incorrecta, intente de nuevo\n");
        }
      }

      break;
    case 9:
      printf("\n\nDivision de enteros\n");
      if (fin1 == TM - 1 || fin2 == TM - 1)
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
        printf("Elija de forma numerica, como desea dividir elementos\n");
        printf("1. Primeros dos de la lista\n");
        printf("2. Ultimos dos de la lista\n");
        printf("3. Indicar la posicion de ambos numeros \n");
        printf("\n");
        printf("\n");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
          z1 = divNumsIni(lista1, lista2, fin1, fin2);
          printf("Lista 1: \n");
          display(lista1, fin1);
          printf("Lista 2: \n");
          display(lista2, fin2);
          printf("La division de los dos primeros numeros \n      de las listas es: %d\n", z1);
          break;
        case 2:
          z2 = divNumsFin(lista1, lista2, fin1, fin2);
          printf("Lista 1: \n");
          display(lista1, fin1);
          printf("Lista 2: \n");
          display(lista2, fin2);
          printf("La division de los dos ultimos numeros \n      de las listas es: %d\n", z2);
          break;
        case 3:
          printf("Por favor, coloque la posicion deseada del elemento de la lista 1\n");
          display(lista1, fin1);
          scanf("%d", &x);
          z3 = BuscPos(lista1, x);
          printf("Por favor, coloque la posicion deseada del elemento de la lista 2\n");
          display(lista2, fin2);
          scanf("%d", &y);
          z4 = BuscPos(lista2, y);
          div1 = z3 / z4;
          div2 = z4 / z3;
          printf("La division de los dos numeros indicados es: %d/%d = %d\n", z3, z4, div1);
          printf("O tambien: %d/%d = %d\n", z4, z3, div2);

          break;

        default:
          printf("Esa opcion es incorrecta, intente de nuevo\n");
        }
      }
      break;
    case 10:
      printf("Lista 1: \n");
      display(lista1, fin1);
      printf("Lista 2: \n");
      display(lista2, fin2);
      break;
    }

    printf("\n");
  } while (a < 11);
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
{              // p es la posicion, f el final, a es el elemento
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
}

int sumNumsIni(int x[], int y[], int fin1, int fin2)
{
  int a, b, sum;
  fin1 = 1;
  fin2 = 1;
  a = BuscPos(x, fin1);
  b = BuscPos(y, fin2);
  sum = a + b;
  return sum;
}
int sumNumsFin(int x[], int y[], int fin1, int fin2)
{
  int a, b, sum;
  fin1 = fin1 + 1;
  fin2 = fin2 + 1;
  a = BuscPos(x, fin1);
  b = BuscPos(y, fin2);
  sum = a + b;
  return sum;
}
int resNumsIni(int x[], int y[], int fin1, int fin2)
{
  int a, b, res;
  fin1 = 1;
  fin2 = 1;
  a = BuscPos(x, fin1);
  b = BuscPos(y, fin2);
  res = a - b;
  return res;
}
int resNumsFin(int x[], int y[], int fin1, int fin2)
{
  int a, b, res;
  fin1 = fin1 + 1;
  fin2 = fin2 + 1;
  a = BuscPos(x, fin1);
  b = BuscPos(y, fin2);
  res = a - b;
  return res;
}
int multNumsIni(int x[], int y[], int fin1, int fin2)
{
  int a, b, mult;
  fin1 = 1;
  fin2 = 1;
  a = BuscPos(x, fin1);
  b = BuscPos(y, fin2);
  mult = a * b;
  return mult;
}
int multNumsFin(int x[], int y[], int fin1, int fin2)
{
  int a, b, mult;
  fin1 = fin1 + 1;
  fin2 = fin2 + 1;
  a = BuscPos(x, fin1);
  b = BuscPos(y, fin2);
  mult = a * b;
  return mult;
}
int divNumsIni(int x[], int y[], int fin1, int fin2)
{
  int a, b, div;
  fin1 = 1;
  fin2 = 1;
  a = BuscPos(x, fin1);
  b = BuscPos(y, fin2);
  div = a / b;
  return div;
}
int divNumsFin(int x[], int y[], int fin1, int fin2)
{
  int a, b, div;
  fin1 = fin1 + 1;
  fin2 = fin2 + 1;
  a = BuscPos(x, fin1);
  b = BuscPos(y, fin2);
  div = a / b;
  return div;
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
