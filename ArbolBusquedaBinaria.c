/*
Autor: AngelChetosmen
Consultar la Licencia del Autor | Derechos Reservados EUVA B&T ©
*/
#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <stdlib.h>
struct node
{
  int data;
  struct node *left;
  struct node *right;
};

struct node *tree;
void create_tree(struct node *);
struct node *insertElement(struct node *, int);
void preorderTraversal(struct node *);
void inorderTraversal(struct node *);
void postorderTraversal(struct node *);
int smallestElement(struct node *tree);
int largestElement(struct node *tree);
struct node *deleteElement(struct node *, int);
void mirrorImage(struct node *);
void process_node(struct node *);
int totalNodes(struct node *);
int totalExternalNodes(struct node *);
int totalInternalNodes(struct node *);
int Height(struct node *);
struct node *deleteTree(struct node *);

int main()
{
  struct node *ptr;
  int *arr2 = malloc(sizeof(struct node *));
  create_tree(tree);
  int ch, ele, val, i = 0;
loop:
  do
  {
    printf("\nElije alguna de las siguientes opciones: \n");
    printf("1. Insertar elemento \n");
    printf("2. Arbol en preorden \n");
    printf("3. Arbol en inorden \n");
    printf("4. Arbol en postorden\n");
    printf("5. Encontrar elemento mas pequeno \n");
    printf("6. Encontrar elemento mas grande \n");
    printf("7. Borrar elemento \n");
    printf("8. Total de nodos\n");
    printf("9. Total de nodos externos \n");
    printf("10. Total de nodos internos \n");
    printf("11. Altura del Arbol \n");
    printf("12. Imagen Espejo \n");
    printf("13. Eliminar Arbol\n");
    printf("14. Ordenar datos de manera ascendente \n");
    printf("15. Salir  \n");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
      printf("Ingrese el elemento que le gustaria ingresar al Arbol: \n");
      scanf("%d", &ele);
      fflush(stdin);
      tree = insertElement(tree, ele);
      printf("Se ingreso el elemento al Arbol \n");
      arr2[i] = ele;
      i++;
      goto loop;
      break;
    case 2:
      printf("La forma del Arbol en preorden es: \n");
      preorderTraversal(tree);
      break;
    case 3:
      printf("La forma del Arbol en inorden es: \n");
      inorderTraversal(tree);
      break;
    case 4:
      printf("La forma del Arbol en postorden es: \n");
      postorderTraversal(tree);
      break;
    case 5:
      printf("El elemento mas pequeno del Arbol es: %d\n", smallestElement(tree));
      break;
    case 6:
      printf("El elemento mas grande del Arbol es: %d\n", largestElement(tree));
      break;
    case 7:
      printf("Ingrese el elemento que quiere eliminar \n");
      scanf("%d", &val);
      tree = deleteElement(tree, val);
      break;
    case 8:
      printf("El numero total de nodos es: %d \n", totalNodes(tree));
      break;
    case 9:
      printf("El numero total de nodos externos es: %d \n", totalExternalNodes(tree));
      break;
    case 10:
      printf("El numero total de nodos internos es: %d \n", totalInternalNodes(tree));
      break;
    case 11:
      printf("La altura del Arbol es: %d\n", Height(tree));
      break;
    case 12:
      printf("La imagen espejo del Arbol es:\n");
      mirrorImage(tree);
      break;
    case 13:
      tree = deleteTree(tree);
      printf("El Arbol se elimino correctamente \n");
      break;
    case 14:
      printf("Arbol en forma ingresada: \n");
      for (int i = 0; i <= totalNodes(tree) - 1; i++)
      {
        printf("%d\t", arr2[i]);
      }
      printf("\n");
      printf("Dado el ABB creado, los datos en orden ascendente son: \n");
      inorderTraversal(tree);
      break;
    default:
      printf("\n");
    }
  } while (ch != 15);

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

void preorderTraversal(struct node *tree)
{
  if (tree != NULL)
  {
    printf("%d\t", tree->data);
    preorderTraversal(tree->left);
    preorderTraversal(tree->right);
  }
}

void inorderTraversal(struct node *tree)
{
  if (tree != NULL)
  {
    inorderTraversal(tree->left);
    printf("%d\t", tree->data);
    inorderTraversal(tree->right);
  }
}

void postorderTraversal(struct node *tree)
{
  if (tree != NULL)
  {
    postorderTraversal(tree->left);
    postorderTraversal(tree->right);
    printf("%d\t", tree->data);
  }
}

struct node *deleteElement(struct node *tree, int val)
{
  struct node *cur, *parent, *suc, *psuc, *ptr;
  if (tree == NULL)
  {
    printf("\n El arbol esta vacio ");
    return (tree);
  }
  parent = tree;
  cur = tree->left;
  while (cur != NULL && val != cur->data)
  {
    parent = cur;
    cur = (val < cur->data) ? cur->left : cur->right;
  }
  if (cur == NULL)
  {
    printf("\n El elemento a eliminarse no esta en el arbol");
    return (tree);
  }
  if (cur->left == NULL)
    ptr = cur->right;
  else if (cur->right == NULL)
    ptr = cur->left;
  else
  {
    psuc = cur;
    cur = cur->left;
    while (suc->left != NULL)
    {
      psuc = suc;
      suc = suc->left;
    }
    if (cur == psuc)
    {
      suc->left = cur->right;
    }
    else
    {
      suc->left = cur->left;
      psuc->left = suc->right;
      suc->right = cur->right;
    }
    ptr = suc;
  }
  if (parent->left == cur)
    parent->left = ptr;
  else
    parent->right = ptr;
  printf("El elemento se elimino correctamente\n");
  free(cur);
  return tree;
}

int totalNodes(struct node *tree)
{
  if (tree == NULL)
    return 0;
  else
    return (totalNodes(tree->left) + totalNodes(tree->right) + 1);
}

int totalExternalNodes(struct node *tree)
{
  if (tree == NULL)
    return 0;
  else if ((tree->left == NULL) && (tree->right == NULL))
    return 1;
  else
    return (totalExternalNodes(tree->left) +
            totalExternalNodes(tree->right));
}

int totalInternalNodes(struct node *tree)
{
  if ((tree == NULL) || ((tree->left == NULL) && (tree->right == NULL)))
    return 0;
  else
    return (totalInternalNodes(tree->left) + totalInternalNodes(tree->right) + 1);
}

int Height(struct node *tree)
{
  int leftheight, rightheight;
  if (tree == NULL)
    return 0;
  else
  {
    leftheight = Height(tree->left);
    rightheight = Height(tree->right);
    if (leftheight > rightheight)
      return (leftheight + 1);
    else
      return (rightheight + 1);
  }
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

int smallestElement(struct node *tree)
{
  if (tree == NULL)
  {
    printf("Tree is empty\n");
    return 0;
  }
  else
  {
    int leftMin, rightMin;
    int min = tree->data;
    if (tree->left != NULL)
    {
      leftMin = smallestElement(tree->left);
      min = (min > leftMin) ? leftMin : min;
    }
    if (tree->right != NULL)
    {
      rightMin = smallestElement(tree->right);
      min = (min > rightMin) ? rightMin : min;
    }
    return min;
  }
}
int largestElement(struct node *tree)
{
  if (tree == NULL)
  {
    printf("Tree is empty\n");
    return 0;
  }
  else
  {
    int leftMax, rightMax;
    int max = tree->data;
    if (tree->right != NULL)
    {
      leftMax = largestElement(tree->right);
      // si max es menor que leftMax guardará el valor de leftMax en max
      max = (max < leftMax) ? leftMax : max;
    }
    if (tree->left != NULL)
    {
      rightMax = largestElement(tree->left);
      // si max es menor que rightMax guardará el valor de rightMax en max
      max = (max < rightMax) ? rightMax : max;
    }
    return max;
  }
}
struct node *deleteTree(struct node *tree)
{
  if (tree != NULL)
  {
    deleteTree(tree->left);
    deleteTree(tree->right);
    tree = NULL;
  }
}
