/*
Autor: AngelChetosmen
Consultar la Licencia del Autor | Derechos Reservados EUVA B&T ©
*/
#include <stdio.h>
#include <stdlib.h>

struct hash *hashT = NULL;
int Fn = 0;

struct node
{
  int llave;
  struct node *next;
};

struct hash
{
  struct node *head;
  int count;
};

struct node *crearNodo(int llave)
{
  struct node *newnode;
  newnode = (struct node *)malloc(sizeof(struct node));
  newnode->llave = llave;
  newnode->next = NULL;
  return newnode;
}

void insertar(int llave)
{
  int pos = llave % Fn;
  struct node *newnode = crearNodo(llave);
  if (!hashT[pos].head)
  {
    hashT[pos].head = newnode;
    hashT[pos].count = 1;
    return;
  }
  newnode->next = (hashT[pos].head); // se añade nuevo nodo a la lista
  hashT[pos].head = newnode;         // se actualiza el inicio de la lista
  hashT[pos].count++;
  return;
}

void eliminar(int llave)
{
  int pos = llave % Fn, flag = 0;
  struct node *temp, *nodo;
  nodo = hashT[pos].head;
  if (!nodo)
  {
    printf("No esta en la tabla hash!!\n");
    return;
  }
  temp = nodo;
  while (nodo != NULL)
  {
    // se elimina el nodo con llave  dada
    if (nodo->llave == llave)
    {
      flag = 1;
      if (nodo == hashT[pos].head)
        hashT[pos].head = nodo->next;
      else
        temp->next = nodo->next;
      hashT[pos].count--;
      free(nodo);
      break;
    }
    temp = nodo;
    nodo = nodo->next;
  }
  if (flag)
    printf("\n");
  else
    printf("\n");
  return;
}

void buscar(int llave)
{
  int pos = llave % Fn, flag = 0;
  struct node *nodo;
  nodo = hashT[pos].head;
  if (!nodo)
  {
    printf("El elemento no esta disponible en la tabla hash\n");
    return;
  }
  while (nodo != NULL)
  {
    if (nodo->llave == llave)
    {
      printf("La llave %d si esta en la tabla hash\n", nodo->llave);
      flag = 1;
      break;
    }
    nodo = nodo->next;
  }
  if (!flag)
    printf("El elemento buscado no esta en la tabla hash\n");
  return;
}

void display()
{
  struct node *nodo;
  int i;
  printf("\nPosiciones\tElemento(s)\n");
  for (i = 0; i < Fn; i++)
  {
    if (hashT[i].count == 0)
      continue;
    nodo = hashT[i].head;
    if (!nodo)
      continue;
    printf("%d", i);
    while (nodo != NULL)
    {
      printf("\t\t%d\n", nodo->llave);
      nodo = nodo->next;
    }
  }
  return;
}

int main()
{
  int n, ch, llave;
  printf("Ingresa el numero de elementos de la tabla:");
  scanf("%d", &n);
  Fn = n;
  hashT = (struct hash *)calloc(n, sizeof(struct hash)); // se crea la tabla hash con la cantidad de elementos que el usuario diga
  while (1)
  {
    printf("\n1. Insertar elemento\n");
    printf("2. Eliminar elemento\n");
    printf("3. Buscar elemento\n");
    printf("4. Imprimir tabla\n");
    printf("5. Salir\n");
    printf("Elije alguna de las opciones anteriores:\n");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
      printf("Ingresa el valor de la llave: \n");
      scanf("%d", &llave);
      insertar(llave);
      printf("La llave %d se ha agregado a la tabla hash\n", llave);
      display();
      break;

    case 2:
      printf("Ingresa la llave a eliminar: \n");
      scanf("%d", &llave);
      eliminar(llave);
      printf("La llave %d se ha eliminado de la tabla hash\n", llave);
      display();
      break;

    case 3:
      printf("Ingresa la llave buscada:\n");
      scanf("%d", &llave);
      buscar(llave);
      break;
    case 4:
      display();
      break;
    case 5:
      exit(0);
    default:
      printf("Elije alguna opcion de las anteriores\n");
      break;
    }
  }
  return 0;
}
