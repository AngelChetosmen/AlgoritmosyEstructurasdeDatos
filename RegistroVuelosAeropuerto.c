/*
Autor: AngelChetosmen
Consultar la Licencia del Autor | Derechos Reservados EUVA B&T ©
*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <Windows.h>

struct aerolinea
{
	char horasalida[6];
	char nombre[15];
	char destinacion[15];
	int asiento;
	char email[15];
	struct aerolinea *following;
} *begin, *stream, *dummy;
// struct aerolinea *dummy;

void main()
{
	void reserve(int x), cancel(), display(), savefile();
	int op;
	begin = stream = NULL;
	int num = 1;
	do
	{

		printf("\nRegistro de vuelos de aeropuerto\n");
		printf("\n\n\n\t\t Porfavor seleccione de forma numerica la operacion que desea realizar:");
		printf("\n\n\t\t 1. Reservar vuelo");
		printf("\n\n\t\t 2. Cancelar reservacion");
		printf("\n\n\t\t 3. Mostrar todas las reservaciones");
		printf("\n\n\t\t 4. Salir");
		printf("\n\n\t\t Por favor coloque el numero de la opcion que desea hacer:");

		scanf("%d", &op);
		fflush(stdin);
		system("cls");
		switch (op)
		{
		case 1:
			reserve(num);
			num++;
			break;
		case 2:
			cancel();
			break;
		case 3:
			display();
			break;
		case 4:
		{
			savefile();
			break;
		}
		default:
			printf("\n\n\t Opcion invalida!");
			printf("\n\n\t Por favor, Selecciona del: 1-4");
		}
		getch();
	} while (op != 4);
}
// ************************GOOD LUCK MUFTI*****************************
void details()
{
	printf("\n\t Ingrese su hora de salida (todo junto):");
	gets(stream->horasalida);
	fflush(stdin); // reads a line from stdin and stores it into the string pointed
	printf("\n\t Ingrese su Nombre:");
	gets(stream->nombre);
	fflush(stdin);
	printf("\n\t Ingrese su Correo Electronico:");
	gets(stream->email);
	fflush(stdin);
	printf("\n\t Ingrese su Destino : ");
	gets(stream->destinacion);
	fflush(stdin);
}

void details();

void reserve(int x)
{
	stream = begin;
	if (begin == NULL)
	{
		// primer usuario
		begin = stream = (struct aerolinea *)malloc(sizeof(struct aerolinea));
		details();
		stream->following = NULL;
		printf("\n\t Se aparto su lugar correctamente");
		printf("\n\t Su numero de asiento es: Asiento A-%d", x);
		stream->asiento = x;
		return;
	}
	else if (x > 15)
	{
		printf("\n\t\t Seat Full.");
		return;
	}
	else
	{
		// next user
		while (stream->following)
			stream = stream->following;
		stream->following = (struct aerolinea *)malloc(sizeof(struct aerolinea));
		stream = stream->following;
		details();
		stream->following = NULL;
		printf("\n\t Se aparto su lugar correctamente!");
		printf("\n\t Su numero de asiento es: Asiento A-%d", x);
		stream->asiento = x;
		return;
	}
}
// ************************GOOD LUCK MUFTI********************************

void savefile()
{
	FILE *fpointer = fopen("mufti records", "w");
	if (!fpointer)
	{
		printf("\n Error al abrir el archivo");
		return;
		Sleep(800);
	}
	stream = begin;
	while (stream)
	{
		fprintf(fpointer, "%-6s", stream->horasalida);
		fprintf(fpointer, "%-15s", stream->nombre);
		fprintf(fpointer, "%-15s", stream->email);
		fprintf(fpointer, "%-15s", stream->destinacion);
		fprintf(fpointer, "\n");
		stream = stream->following;
	}
	printf("\n\n\t Los datos se han guardado ");
	fclose(fpointer);
}

void display()
{
	stream = begin;
	while (stream)
	{
		printf("\n\n Hora de salida : %-6s", stream->horasalida);
		printf("\n         Nombre : %-15s", stream->nombre);
		printf("\n      Correo Electronico : %-15s", stream->email);
		printf("\n      Numero de Asiento: A-%d", stream->asiento);
		printf("\n     Destino:%-15s", stream->destinacion);
		printf("\n\n++*=====================================================*++");
		stream = stream->following;
	}
}
//*****************************GOOD LUCK MUFTI*************************************

void cancel()
{
	stream = begin;
	system("cls");
	char horasalida[6];
	printf("\n\n Ingrese la hora de salida, para eliminar:");
	gets(horasalida);
	fflush(stdin);
	if (strcmp(begin->horasalida, horasalida) == 0)
	{
		dummy = begin;
		begin = begin->following;
		free(dummy);
		printf(" El vuelo se ha cancelado");
		Sleep(800);
		return;
	}

	while (stream->following)
	{
		if (strcmp(stream->following->horasalida, horasalida) == 0)
		{
			dummy = stream->following;
			stream->following = stream->following->following;
			free(dummy);
			printf("Ha sido eliminado ");
			getch();
			Sleep(800);
			return;
		}
		stream = stream->following;
	}
	printf("El numero del vuelo de reserva es incorrecto, vuelva a intentar");
}
