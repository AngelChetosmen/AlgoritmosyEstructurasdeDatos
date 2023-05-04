/*
Autor: AngelChetosmen
Consultar la Licencia del Autor | Derechos Reservados EUVA B&T ©
*/
#include <stdio.h>
#include <conio.h>
#include <malloc.h>
struct node
{
  int data;
  struct node *left;
  struct node *right;
};

struct node *tree;
void create_tree(struct node *);
struct node *insertElement(struct node *, int);
void mirrorImage(struct node *);
void process_node(struct node *);

int main()
{
  struct node *ptr;
  create_tree(tree);
  int ch, ele, val;
  do
  {
    printf("\nElije alguna de las siguientes opciones: \n");
    printf("1. Insertar elemento \n");
    printf("2. Imagen espejo  \n");
    printf("3. Salir  \n");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
      printf("Ingrese los elementos que le gustaria ingresar al Arbol: \n");
      scanf("%d", &ele);
      fflush(stdin);
      tree = insertElement(tree, ele);
      printf("Se ingreso el elemento al Arbol \n");
      break;
    case 2:
      printf("La imagen espejo del Arbol es:\n");
      mirrorImage(tree);
      break;
    default:
      printf("\n");
    }
  } while (ch != 3);

  return 0;
}

void create_tree(struct node *tree)
{
  tree = NULL;
}
struct node *insertElement(struct node *tree, int val)
{
  struct node *ptr, *nodeptr, *parentptr;
  ptr = (struct node *)malloc(sizeof(struct node));
  ptr->data = val;
  ptr->left = NULL;
  ptr->right = NULL;
  if (tree == NULL)
  {
    tree = ptr;
    tree->left = NULL;
    tree->right = NULL;
  }
  else
  {
    parentptr = NULL;
    nodeptr = tree;
    while (nodeptr != NULL)
    {
      parentptr = nodeptr;
      if (val < nodeptr->data)
        nodeptr = nodeptr->left;
      else
        nodeptr = nodeptr->right;
    }
    if (val < parentptr->data)
      parentptr->left = ptr;
    else
      parentptr->right = ptr;
  }
  return tree;
}
void mirrorImage(struct node *tree)
{
  if (tree)
  {
    mirrorImage(tree->right);
    printf("%d\t", tree->data);
    mirrorImage(tree->left);
  }
  return;
}
