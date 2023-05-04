/*
Autor: AngelChetosmen
Consultar la Licencia del Autor | Derechos Reservados EUVA B&T ©
*/
#include <stdio.h>
#include <string.h>
/*Ejercicio D: Para buscar un elemento en un arreglo usando búsqueda
 * binaria, cada elemento del arreglo contiene la siguiente información:
 *  nombre, apellido paterno, apellido materno, boleta y promedio; la
 * búsqueda se puede hacer tomando como llave la boleta o el apellido
 * paterno.*/
typedef struct Entidad
{
	char Boleta[10];
	char Nombre[60];
	char ApellidoPat[40];
	char ApellidoMat[40];
	char Grupo[5];
	char Materia[50];
	float Calificacion;
	// Entidad.Matricula[0]='z';
} Alumnos;
// void Promedios(Alumnos * puntero);
void Alta(Alumnos *puntero);
void Listar(Alumnos *puntero);
void Busqueda(Alumnos *puntero);
void Modificar(Alumnos *puntero);
int main()
{
	int opcion = 9;
	Alumnos Registro_2020[60];
	Alumnos *puntero;
	Alumnos *lt;
	lt = &Registro_2020[0];
	puntero = &Registro_2020[0];
	puntero->Boleta[0] = 'z';

	while (opcion != 0)
	{
		printf("Instituto Politecnico Nacional\n");
		printf("Equipo Tiburones Blancos|Grupo: 2CM4\n");
		printf("Programa para Busqueda Binaria de Elemntos para Alumnos\n");
		printf("---------MENU----------\n");
		printf("[1] Alta Alumnos\n");
		printf("[2] Busqueda Alumnos\n");
		printf("[3] Listar Alumnos\n");
		printf("[4] Modificar Dato\n");
		printf("[0] Salir del programa\n");
		scanf("%d", &opcion);

		switch (opcion)
		{

		case 1:
		{
			while (lt->Boleta[0] != 'z')
			{
				lt = lt + 1;
			}

			Alta(lt);
		}
		break;

		case 2:
		{
			Busqueda(puntero);
		}
		break;

		case 3:
		{
			Listar(puntero);
		}
		break;

		case 4:
		{
			Modificar(puntero);
		}
		break;

		case 0:
		{
			// No se realizan ejecuciones o instrucciones;
		}
		break;

		default:
		{
			printf("Opcion no valida\n");
		}
		}
	};
	return 0;
}

void Alta(Alumnos *puntero)
{
	int opcion = 9;

	while (opcion != 0)
	{
		printf("1--------Desea Agregar alummos oprime 1 sino oprima 0--------\n");
		scanf("%d", &opcion);

		if (opcion == 1)
		{
			printf("captura la Boleta\n");
			getchar();
			gets(puntero->Boleta);
			printf("Captura el Nombre\n");
			gets(puntero->Nombre);
			printf("Captura Apellido Paterno\n");
			gets(puntero->ApellidoPat);
			printf("Captura Apellido Materno\n");
			gets(puntero->ApellidoMat);
			printf("Captura el Grupo\n");
			gets(puntero->Grupo);
			printf("Captura la Materia\n");
			gets(puntero->Materia);
			printf("Captura la Calificacion la Materia\n");
			scanf("%f", &puntero->Calificacion);
			puntero = puntero + 1;
			puntero->Boleta[0] = 'z';
		}
	};
}

void Listar(Alumnos *puntero)
{
	char Boleta[10];
	int val;
	while (puntero->Boleta[0] != 'z')
	{

		// if(val==0){
		printf("------------------------\n");
		printf("Boleta: %s\n", puntero->Boleta);
		printf("Nombre: %s \n", puntero->Nombre);
		printf("Apellido Paterno: %s\n", puntero->ApellidoPat);
		printf("Apellido Materrno: %s\n", puntero->ApellidoMat);
		printf("Grupo: %s \n", puntero->Grupo);
		printf("Materia: %s \n", puntero->Materia);
		printf("Calificacion (Promedio): %f \n", puntero->Calificacion);
		printf("------------------------\n");
		//}
		puntero = puntero + 1;
	};
}

void Busqueda(Alumnos *puntero)
{

	char Boleta[10];
	int val;
	printf("Captura la Boleta que deseas buscar \n");
	getchar();
	gets(Boleta);

	while (puntero->Boleta[0] != 'z')
	{

		val = strcmp(puntero->Boleta, Boleta);
		if (val == 0)
		{

			printf("Boleta %s\n", puntero->Boleta);
			printf("Nombre %s \n", puntero->Nombre);
			printf("Apellido Paterno %s\n", puntero->ApellidoPat);
			printf("Apellido Materno %s\n", puntero->ApellidoMat);
			printf("grupo %s \n", puntero->Grupo);
			printf("materia %s \n", puntero->Materia);
			printf("calificacion %f \n", puntero->Calificacion);
		}
		puntero = puntero + 1;
	};
}

void Modificar(Alumnos *puntero)
{

	char Boleta[10];
	int val;
	printf("Captura la matricula que deseas modificar \n");
	getchar();
	gets(Boleta);

	while (puntero->Boleta[0] != 'z')
	{

		val = strcmp(puntero->Boleta, Boleta);
		if (val == 0)
		{

			printf("captura el nombre\n");
			gets(puntero->Nombre);
			printf("captura apellido paterno\n");
			gets(puntero->ApellidoPat);
			printf("captura apellido materno\n");
			gets(puntero->ApellidoMat);
			printf("Captura el Grupo\n");
			gets(puntero->Grupo);
			printf("Captura la Materia\n");
			gets(puntero->Materia);
			printf("Captura la Calificacion la Materia (Promedio)\n");
			scanf("%f", &puntero->Calificacion);
		}
		puntero = puntero + 1;
	};
}
