/*
Autor: AngelChetosmen
Consultar la Licencia del Autor | Derechos Reservados EUVA B&T ©
*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
// #include <windows.h>
#include <time.h>
// #include<conio.h>
/*Ejercicio: Hacer un programa que simule el proceso de inscripción de
 * alumnos a una escuela. Independientemente de la hora de llegada de
 * los alumnos, en el turno siguiente se atiende al alumno con mayor
 * promedio que esté presente. El tiempo de atención por alumno es de 3
 * minutos y la frecuencia de llegada de alumnos es de un alumno por
 * minuto. La escuela tiene 60 alumnos. El programa debe imprimir un
 * mensaje cuando se termina de atender a un alumno indicando quien es
 * el siguiente. Los alumnos se registran cuando llegan y su
 * identificación se hace con un nombre y un apellido. */

typedef struct node
{
	char data;

	// Lower values indicate higher priority
	int priority;

	struct node *next;

} Node;

// Function to Create A New Node
Node *newNode(char d, int p)
{
	Node *temp = (Node *)malloc(sizeof(Node));
	temp->data = d;
	temp->priority = p;
	temp->next = NULL;

	return temp;
}

// Return the value at head
char peek(Node **head)
{
	return (*head)->data;
}

// Removes the element with the
// highest priority form the list
void pop(Node **head)
{
	Node *temp = *head;
	(*head) = (*head)->next;
	free(temp);
}

// Function to push according to priority
void push(Node **head, char d, int p)
{
	Node *start = (*head);

	// Create new Node
	Node *temp = newNode(d, p);

	// Special Case: The head of list has lesser
	// priority than new node. So insert new
	// node before head node and change head node.
	if ((*head)->priority > p)
	{

		// Insert New Node before head
		temp->next = *head;
		(*head) = temp;
	}
	else
	{

		// Traverse the list and find a
		// position to insert new node
		while (start->next != NULL &&
			   start->next->priority < p)
		{
			start = start->next;
		}

		// Either at the ends of the list
		// or at required position
		temp->next = start->next;
		start->next = temp;
	}
}

// Function to check is list is empty
int isEmpty(Node **head)
{
	return (*head) == NULL;
}
void waitFor(unsigned int secs)
{
	unsigned int retTime = time(0) + secs; // Get finishing time.
	while (time(0) < retTime)
		; // Loop until it arrives.
}

// Driver code
int main()
{
	int z, o, p, op, sal, hrs, mins, segs1, segs2;
	char x[60], y[60];
	char carre[20], grupo[20], numBol[50];
	time_t seconds;
	struct tm *timeStruct;
	seconds = time(NULL);
	timeStruct = localtime(&seconds);
	Node *cola = newNode(x, p);
	segs1 = timeStruct->tm_sec;
	segs2 = timeStruct->tm_sec + 5;

	do
	{
		/*(hora no importa 1. Alumno con mayor promedio presente. 2. Tiempo 3 minxalumn. 3. Cada min llega uno.
		4. 60 alumnos. 5. Se registran cuando llegan, identificandose con nombre.)*/
		printf("\nProceso de incripcion \n");
		printf("\n\n Elija alguna de las siguientes opciones: \n");
		printf("1. Registro de alumnos \n");
		printf("2. Area de inscripcion \n");
		printf("3. Salir \n");
		scanf("%d", &o);
		switch (o)
		{
		case 1:
			do
			{
				printf("\n\nBienvenido al area de registro a su inscripcion : \n");
				printf("Si usted es el ultimo estudiante en la fila, salir\n\escribiendo un numero 2 y luego la tecla enter en el proceso: \n");
				printf("de lo contrario, escriba cualquier otra tecla:\n\n");
				waitFor(10);

				printf("Ingrese su nombre: \n");
				scanf("%s", x);
				printf("Ingrese su apellido: \n");
				scanf("%s", y);
				// fflush(stdin);
				printf("Ingrese su promedio con numeros enteros \n");
				scanf("%d", &p);
				// fflush(stdin);
				push(&cola, x, p);
				printf("Es usted el ultimo en la fila? \n");
				printf("1.No . 2.- Si\n");
				scanf("%d", &op);
				// fflush(stdin);
			} while (op != 2);

			break;
		case 2:
			sal = 0;
			do
			{
				printf("\n\nPor tener una calificacion mayor, se le ha atendido a usted primero \n");
				printf("Tiene un maximo de 3 minutos para registrar los datos que se le soliciten \n");
				printf("\nColoque el nombre de su carrera: \n");
				scanf("%s", carre);
				// fflush(stdin);
				printf("\nColoque su grupo: \n");
				scanf("%s", grupo);
				// fflush(stdin);
				printf("\nColoque su numero de boleta: \n");
				scanf("%s", numBol);
				// fflush(stdin);
				printf("\nGracias por ingresar los datos, ya puede retirarse ingresando el numero 2\n");
				scanf("%d", &sal);
			} while (timeStruct->tm_sec != segs2);

			break;
		default:
			printf("\nVuelva pronto");
			break;
		}

	} while (o != 3);

	return 0;
}
