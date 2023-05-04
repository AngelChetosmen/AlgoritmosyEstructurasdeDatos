/*
Autor: AngelChetosmen
Consultar la Licencia del Autor | Derechos Reservados EUVA B&T ©
*/
#include <stdio.h>
#include <stdlib.h>

struct nodo
{
    float dato;
    struct nodo *sig;
};

struct nodo *tope = NULL;

void display();
void push(float);
void pop();
void seek();

int main()
{
    float n;
    int o;
    do
    {
        printf("\n\nMenu\n");
        printf("1. Agregar numero \n");
        printf("2. Sacar numero \n");
        printf("3. Ver pila\n");
        printf("4. Ver ultimo numero agregado\n");
        printf("5. Salir \n");
        printf("Elija alguna opcion de las anteriores: \n");
        scanf("%d", &o);
        switch (o)
        {
        case 1:
            printf("\nIngrese un numero entero: ");
            scanf("%f", &n);
            push(n);
            printf("Se agrego correctamente el numero %.2f \n", n);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            seek();
            break;
        }
    } while (o != 5);
}

void push(float num)
{
    struct nodo *ptr = malloc(sizeof(struct nodo));
    ptr->dato = num;
    ptr->sig = tope;
    tope = ptr;
}

void display()
{
    struct nodo *aux;
    aux = tope;
    while (aux != NULL)
    {

        {
            printf("\n%.2f", aux->dato);
            aux = aux->sig;
        }
    }
}
void seek()
{
    struct nodo *aux;
    aux = tope;
    printf("\n%.2f", aux->dato);
}

void pop()
{
    if (tope == NULL)
    {
        printf("\n\nPila vacia ");
    }
    else
    {
        struct nodo *aux;
        aux = tope;
        tope = tope->sig;
        printf("\n\nEl numero %.2f se saco de la pila", aux->dato);
        free(aux);
    }
}
