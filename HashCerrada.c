/*
Autor: AngelChetosmen
Consultar la Licencia del Autor | Derechos Reservados EUVA B&T ©
*/
#include <stdio.h>
#include <limits.h>

// funcion para insertar elementos
void insert(int arr[], int fn, int tam)
{
        int elemento, pos, n = 0;

        printf("Ingrese llave a insertar a la tabla\n");
        scanf("%d", &elemento);

        pos = elemento % fn;

        while (arr[pos] != INT_MIN)
        { // INT_MIN and INT_MAX son funciones de header limits.h para saber si la posición está vacía y si lo está, saldrá del while para insertar un elemento
                if (arr[pos] == INT_MAX)
                        break;
                pos = (pos + 1) % fn;
                n++;
                if (n == tam)
                        break; // Si la tabla está llena, saldría del bucle
        }

        if (n == tam)
                printf("La tabla hash esta llena de elementos\nNo se puede insertar el elemento\n\n");
        else
                arr[pos] = elemento; // Se inserta el elemento en la posición deseada si hay un espacio
}

// funcion para eliminar
void delete(int arr[], int fn, int tam)
{
        int elemento, n = 0, pos;

        printf("Ingrese el elemento a eliminar\n");
        scanf("%d", &elemento);

        pos = elemento % fn;

        while (n++ != tam)
        {
                if (arr[pos] == INT_MIN)
                {
                        printf("No se encontro en la tabla\n");
                        break;
                }
                else if (arr[pos] == elemento)
                {
                        arr[pos] = INT_MAX;
                        printf("Elemento eliminado\n\n");
                        break;
                }
                else
                {
                        pos = (pos + 1) % fn;
                }
        }
        if (--n == tam)
                printf("Elemento no encontrado en la tabla hash\n");
}

void search(int arr[], int fn, int tam)
{
        int elemento, pos, n = 0;

        printf("Elemento a buscar\n");
        scanf("%d", &elemento);

        pos = elemento % fn;

        while (n++ != tam)
        {
                if (arr[pos] == elemento)
                {
                        printf("Se encontro en la posicion %d\n", pos);
                        break;
                }
                else if (arr[pos] == INT_MAX || arr[pos] != INT_MIN)
                        pos = (pos + 1) % fn;
        }
        if (--n == tam)
                printf("No se encontro el elemento en la tabla\n");
}

void display(int arr[], int tam)
{
        int i;

        printf("Posiciones\tElementos\n");

        for (i = 0; i < tam; i++)
        {
                if (arr[i] == INT_MAX)
                        printf("%d\t\t%d\n", i, 0);
                else if (arr[i] != INT_MIN)
                        printf("%d\t\t%d\n", i, arr[i]);
                else
                        printf("%d\t\t%d\n", i, 0);
        }
}

int main()
{
        int tam, fn, i, choice;
        char n = 164;
        printf("Ingresa el tama%co de la tabla hash\n", n);
        scanf("%d", &tam);

        int arr[tam];

        printf("Ingresa el valor para la funcion de dispersion (h(k)=kmod#)\n");
        printf("Es decir, para la formula anterior ingrese el #)");
        printf(" (Para tablas hash abiertas, se recomendaria que fuera numero primo) \n");
        scanf("%d", &fn);

        for (i = 0; i < tam; i++)
                arr[i] = INT_MIN; // se asigna el valor INT_MIN para indicar que está vacía

        do
        {
                printf("Ingrese alguna de las opciones siguientes: \n");
                printf("1. Insertar elemento\n");
                printf("2. Eliminar elemento\n");
                printf("3. Imprimir tabla\n");
                printf("4. Buscar elemento\n");
                printf("5. Salir\n");
                scanf("%d", &choice);

                switch (choice)
                {
                case 1:
                        insert(arr, fn, tam);
                        printf("La tabla va quedando asi: \n");
                        display(arr, tam);
                        break;
                case 2:
                        delete (arr, fn, tam);
                        printf("La tabla va quedando asi: \n");
                        display(arr, tam);
                        break;
                case 3:
                        display(arr, tam);
                        break;
                case 4:
                        search(arr, fn, tam);
                        break;
                }
        } while (choice != 5);

        return 0;
}
