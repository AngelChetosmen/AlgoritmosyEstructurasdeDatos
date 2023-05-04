/*
Autor: AngelChetosmen
Consultar la Licencia del Autor | Derechos Reservados EUVA B&T ©
*/
#include <stdio.h>
#include <ctype.h>

char pila[50];
int tope = -1;

void push(char x)
{
  pila[++tope] = x;
}

char pop()
{
  if (tope == -1)
    return -1;
  else
    return pila[tope--];
}

int prioridad(char x)
{
  if (x == '(')
    return 0;
  if (x == '+' || x == '-')
    return 1;
  if (x == '*' || x == '/')
    return 2;
  return 0;
}

int main()
{

  char exp[50];
  char *e, x; // e es el puntero a stack
inicio:
  printf("Bienvenido al programa de conversion de notacion infija a postfija\n");
  printf("Escriba la expresion en notacion infija: \n");
  scanf("%s", exp);
  printf("\n");
  e = exp;

  while (*e != '\0')
  {
    if (isalnum(*e)) // funcion para ver si es alfanumérico, lo imprime
      printf("%c", *e);
    else if (*e == '(') // si encuentra parentesis abierto, lo manda al stack
      push(*e);
    else if (*e == ')') // si hay parentesis cerrado, siga sacando del stack
    {
      while ((x = pop()) != '(')
        printf("%c", x);
    }
    else
    {
      while (prioridad(pila[tope]) >= prioridad(*e))
        printf("%c", pop());
      push(*e); // va metiendo a la pila dependiendo la prioridad
    }
    e++; // apunta al siguiente caracter
  }
  while (tope != -1)
  {
    printf("%c", pop());
  }
  printf("\n\nDesea ingresar otra expresion?\n");
  printf("1. Si \n 2. No \n");
  int op;
  scanf("%d", &op);
  switch (op)
  {
  case 1:
    goto inicio;
    break;

  case 2:
    goto final;
    break;

  default:
    printf("Error \n");
  }
final:
  return 0;
}
