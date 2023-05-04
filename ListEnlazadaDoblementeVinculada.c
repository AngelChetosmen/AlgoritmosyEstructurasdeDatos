/*
Autor: AngelChetosmen
Consultar la Licencia del Autor | Derechos Reservados EUVA B&T ©
*/
#include <stdio.h>
#include <stdlib.h>

struct linked_list
{
    int number;
    struct linked_list *next;
    struct linked_list *previous;
};

typedef struct linked_list node;
node *head = NULL, *tail = NULL;

void insert_at_head(int number);
void insert_at_tail(int number);
void insert_at_middle(int number, int position);
void delete_head();
void delete_tail();
void delete_middle(int posision);
void print_forward_order();
void print_reverse_order();
void print_list();
int getListLength();

int main()
{
    int opcionMenu, a, d, e, f, g;
    do
    {
        printf("\n Lista circular doblemente vinculada \n");
        printf("1. Insertar al inicio\n");
        printf("2. Insertar al final  \n");
        printf("3. Insertar en posicion dada \n");
        printf("4. Eliminar al inicio\n");
        printf("5. Eliminar al final  \n");
        printf("6. Eliminar en posicion dada \n");
        printf("7. Desplegar desde el primero al ultimo \n");
        printf("8. Desplegar desde el ultimo al primero \n");
        printf("9. Salir\n");
        printf("\n\n Escoja una Opcion: ");
        scanf("%d", &opcionMenu);
        fflush(stdin);
        switch (opcionMenu)
        {
        case 1:
            printf("\n\n Insertar al inicio de la lista: \n\n");
            printf("Ingresa numero: \n");
            scanf("%d", &a);
            fflush(stdin);
            insert_at_head(a);
            print_list();
            break;
        case 2:
            printf("\n\n Insertar al final de la lista: \n\n");
            printf("Ingresa numero: \n");
            scanf("%d", &d);
            fflush(stdin);
            insert_at_tail(d);
            print_list();
            break;
        case 3:
            printf("\nInsertar en posicion de la lista: \n\n");
            printf("Ingresa numero: \n");
            scanf("%d", &e);
            fflush(stdin);
            printf("Ingresa posicion: \n");
            scanf("%d", &f);
            fflush(stdin);
            insert_at_middle(e, f);
            print_list();
            break;
        case 4:
            printf("\n\n Eliminar al inicio de la lista: \n\n");
            delete_head();
            print_list();
            break;
        case 5:
            printf("\n\n Eliminar al final de la lista: \n\n");
            delete_tail();
            print_list();
            break;
        case 6:
            printf("\n\n Eliminar en posicion dada de la lista: \n\n");
            printf("Ingresa posicion: \n");
            scanf("%d", &g);
            fflush(stdin);
            delete_middle(g);
            print_list();
            break;
        case 7:
            print_forward_order();
            break;
        case 8:
            print_reverse_order();
            break;
        default:
            printf("\n\n Ha salido del programa \n\n");
        }
    } while (opcionMenu != 9);
    return 0;
}

// Insert a node at front of a circular doubly linked list
void insert_at_head(int number)
{
    node *newNode = (node *)malloc(sizeof(node));

    newNode->number = number;
    newNode->next = newNode;
    newNode->previous = newNode;

    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        newNode->next = head;
        newNode->previous = tail;
        head->previous = newNode;
        tail->next = newNode;
        head = newNode;
    }
}

// Insert a node at tail of a circular doubly linked list
void insert_at_tail(int number)
{
    node *newNode = (node *)malloc(sizeof(node));

    newNode->number = number;
    newNode->next = newNode;
    newNode->previous = newNode;

    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        newNode->next = head;
        newNode->previous = tail;
        tail = newNode;
        head->previous = tail;
    }
}

// Insert a node at middle of a circular doubly linked list
void insert_at_middle(int number, int position)
{
    if (position == 1)
    {
        insert_at_head(number);
        return;
    }
    else if (position > 1 && head != NULL)
    {
        node *current = head;
        node *temp = (node *)malloc(sizeof(node));
        int count = 0;

        do
        {
            count++;
            temp = current;
            current = current->next;
        } while (current->next != head && count < position - 1);

        if (count == position - 1)
        {
            if (temp == tail)
                insert_at_tail(number);
            else
            {
                node *newNode = (node *)malloc(sizeof(node));
                newNode->number = number;

                temp->next = newNode;
                newNode->next = current;
                newNode->previous = temp;
                current->previous = newNode;
            }
            return;
        }
    }

    printf("Position does not exist!\n");
}

// Delete HEAD node of a circular doubly linked list
void delete_head()
{
    if (head == NULL)
        return;

    node *temp = head;

    tail->next = head->next;
    head = head->next;
    head->previous = tail;

    free(temp);
}

// Delete TAIL node of a circular doubly linked list
void delete_tail()
{
    if (head == NULL)
        return;

    node *temp = head;
    node *current = head;

    while (current->next != head)
    {
        temp = current;
        current = current->next;
    }
    // now, `current` node is the TAIL. `temp` is the previous node of TAIL.
    // `current->next` is HEAD

    temp->next = head; // also can write temp->next = current->next;
    tail = temp;
    head->previous = tail;
    free(current);
}

// Delete a node middle in the circular doubly linked list
void delete_middle(int position)
{
    if (head == NULL)
        return;

    if (position == 1)
    {
        delete_head();
        return;
    }

    node *current = head;
    node *temp;
    int count = 0;

    do
    {
        count++;
        temp = current;
        current = current->next;
    } while (current->next != head && count < position - 1);

    if (count == position - 1)
    {
        if (current == tail)
        {
            delete_tail();
            return;
        }

        temp->next = current->next;
        current->next->previous = temp;
        free(current);
        return;
    }

    printf("La posicion (%d) no existe!\n", position);
}

// Print the list in FORWARD order and REVERSE order
void print_list()
{
    printf("Impresion de lista de primero a ultimo:\n");
    print_forward_order();

    printf("Impresion de lista de ultimo a primero:\n");
    print_reverse_order();
}

// Print FORWARD ORDER all node's data of a circular doubly linked list
void print_forward_order()
{
    if (head == NULL)
        return;

    node *current = head;

    do
    {
        printf("%d ", current->number);
        current = current->next;
    } while (current != head);

    printf("\nTamano de la lista: %d\n\n", getListLength());
}

// Print REVERSE ORDER all node's data of a circular doubly linked list
void print_reverse_order()
{
    if (head == NULL)
        return; // also can check `tail==NULL`. both are same

    node *current = tail;

    do
    {
        printf("%d ", current->number);
        current = current->previous;
    } while (current != tail);

    printf("\nTamano de la lista: %d\n\n", getListLength());
    puts("\n");
}

// Determine the number of nodes in circular doubly linked list
int getListLength()
{
    if (head == NULL)
        return 0;

    int count = 0;
    node *current = head;

    do
    {
        count++;
        current = current->next;
    } while (current != head);

    return count;
}
