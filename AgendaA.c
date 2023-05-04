/*
Autor: AngelChetosmen
Consultar la Licencia del Autor | Derechos Reservados EUVA B&T ©
*/
#include <stdio.h>

struct contacto
{
	char id[20];
	char nombre[30];
	char apa[30];
	char ama[30];
	char dom[100];
	char rfc[15];
	char movil[22];
	char fijo[22];
	char mail[30];
	char fb[30];
	char tw[25];
};

int compara(char no[], struct contacto *pt);
int Tam(char caracter[]);
void modificar(int, struct contacto *pr);
void eliminar(struct contacto *pe);

int main()
{
	int x = 0, n = 0, val = 0, val1 = 0, v = 0;
	int sel = 0, des;
	struct contacto per[100];
	struct contacto *ptr, *pt;
	char este[30];
	char modi[30], eli[30];

	printf("Este programa es una Agenda Academica Digital.\n");
	printf("Tiene solo una capacidad maxima de almacenar 100 alumnos.\n");
	printf("Cada alumno se le solicitaran los siguientes datos.\n");
	printf("Boleta, nombre, apellido paterno, apellido materno, domicilio, grupo, telefono movil, telefono fijo, e-mail, facebook y twitter.\n");
	do
	{
		printf("\n");
		printf("\n");
		printf("\n");
		printf("Seleccione la opcion que desea realizar.\n");
		printf("Elija de forma numerica la opcion deseada.\n");
		printf("Seleccione:\n");
		printf("1.Nuevo alumno.\n");
		printf("2.Buscar alumno.\n");
		printf("3.Modificar datos del alumno.\n");
		printf("4.Eliminar alumno.\n");
		printf("5.Salir del programa.\n");
		printf("\n");
		printf("\n");
		printf("\n");
		scanf("%d", &x);
		switch (x)
		{
		case 1:
			printf("Por favor, ingrese los siguientes datos.\n");
			printf("Ingrese su boleta.\n");
			scanf("%s", per[n].id);
			fflush(stdin);
			printf("Ingrese su nombre.\n");
			scanf("%[^\n]", per[n].nombre);
			fflush(stdin);
			printf("Ingrese el apellido paterno.\n");
			scanf("%[^\n]", per[n].apa);
			fflush(stdin);
			printf("Ingrese el apellido materno.\n");
			scanf("%[^\n]", per[n].ama);
			fflush(stdin);
			printf("Ingrese su domicilio.\n");
			scanf("%[^\n]", per[n].dom);
			fflush(stdin);
			printf("Ingrese su grupo.\n");
			scanf("%s", per[n].rfc);
			fflush(stdin);
			printf("Ingrese su numero movil.\n");
			scanf("%[^\n]", per[n].movil);
			fflush(stdin);
			printf("Ingrese su numero fijo.\n");
			scanf("%[^\n]", per[n].fijo);
			fflush(stdin);
			printf("Ingrese su correo electronico (e-mail).\n");
			scanf("%s", per[n].mail);
			fflush(stdin);
			printf("Ingrese su usuario de Facebook.\n");
			scanf("%[^\n]", per[n].fb);
			fflush(stdin);
			printf("Ingrese su usuario de Twitter.\n");
			scanf("%s", per[n].tw);
			fflush(stdin);
			n++;
			x = 0;
			break;

		case 2:
			printf("Por favor ingrese el nombre del alumno a buscar.\n");
			scanf("%s", este);
			fflush(stdin);
			val = compara(este, per) - 1;
			printf("El alumno %s tiene como datos:\n", per[val].nombre);
			printf("\n");
			printf("El nombre es: %s\n", per[val].nombre);
			printf("Boleta: %s\n", per[val].id);
			printf("Apellido paterno: %s\n", per[val].apa);
			printf("Apellido materno: %s\n", per[val].ama);
			printf("Su domicilio es: %s\n", per[val].dom);
			printf("El grupo es: %s\n", per[val].rfc);
			printf("Su numero movil es: %s\n", per[val].movil);
			printf("Su numero fijo es: %s\n", per[val].fijo);
			printf("El correo electronico (e-mail) es: %s\n", per[val].mail);
			printf("Usuario de Facebook es: %s\n", per[val].fb);
			printf("Usuario de Twitter es: %s\n", per[val].tw);
			x = 0;
			break;

		case 3:
			printf("Por favor, ingrese el nombre completo del alumno a modificar.\n");
			printf("Ingrese el nombre respetando mayúsculas y minúsculas (si es el caso, tambien los espacios).\n");
			scanf("%s", modi);
			fflush(stdin);
			val1 = compara(modi, per) - 1;
			printf("Los datos del alumno llamado ' %s ' son:\n", per[val1].nombre);
			printf("\n");
			printf("Boleta: %s\n", per[val1].id);
			printf("Apellido paterno: %s\n", per[val1].apa);
			printf("Apellido materno: %s\n", per[val1].ama);
			printf("Su domicilio es: %s\n", per[val1].dom);
			printf("El grupo es: %s\n", per[val1].rfc);
			printf("Su numero movil es: %s\n", per[val1].movil);
			printf("Su numero fijo es: %s\n", per[val1].fijo);
			printf("El correo electronico (e-mail) es: %s\n", per[val1].mail);
			printf("Usuario de Facebook es: %s\n", per[val1].fb);
			printf("Usuario de Twitter es: %s\n", per[val1].tw);
			printf("\n");
			printf("\n");
			printf("¿Que desea modificar de los datos del alumno %s ?\n", per[val1].nombre);
			printf("Elige la opcion de forma númerica.\n");
			printf("1. Boleta\n");
			printf("2. Nombre\n");
			printf("3. Apellido paterno\n");
			printf("4. Apellido materno\n");
			printf("5. Domicilio\n");
			printf("6. Grupo\n");
			printf("7. Numero de telefono movil\n");
			printf("8. Numero de telefono fijo\n");
			printf("9. Correo electronico\n");
			printf("10. Usuario de facebook\n");
			printf("11. Usuario de twitter\n");
			printf("\n");
			printf("\n");
			scanf("%d", &sel);
			modificar(sel, &per[val1]);
			printf("Usted modifico la opcion numero %d, por lo que la nueva modificacion del alumno es\n", sel);
			printf("Los datos completos del contacto modificado son:\n");
			printf("Boleta: %s\n", per[val1].id);
			printf("Nombre: %s\n", per[val1].nombre);
			printf("Apellido paterno: %s\n", per[val1].apa);
			printf("Apellido materno: %s\n", per[val1].ama);
			printf("Su domicilio es: %s\n", per[val1].dom);
			printf("El grupo es: %s\n", per[val1].rfc);
			printf("Su numero movil es: %s\n", per[val1].movil);
			printf("Su numero fijo es: %s\n", per[val1].fijo);
			printf("El correo electronico (e-mail) es: %s\n", per[val1].mail);
			printf("Usuario de Facebook es: %s\n", per[val1].fb);
			printf("Usuario de Twitter es: %s\n", per[val1].tw);
			break;
		case 4:
			printf("Por favor, coloque el nombre del alumno a eliminar.\n");
			scanf("%s", eli);
			fflush(stdin);
			v = compara(eli, per) - 1;
			printf("Los datos del alumno llamado ' %s ' son:\n", per[v].nombre);
			printf("\n");
			printf("El nombre es: %s\n", per[v].nombre);
			printf("Boleta: %s\n", per[v].id);
			printf("Apellido paterno: %s\n", per[v].apa);
			printf("Apellido materno: %s\n", per[v].ama);
			printf("Su domicilio es: %s\n", per[v].dom);
			printf("El grupo es: %s\n", per[v].rfc);
			printf("Su numero movil es: %s\n", per[v].movil);
			printf("Su numero fijo es: %s\n", per[v].fijo);
			printf("El correo electronico (e-mail) es: %s\n", per[v].mail);
			printf("Usuario de Facebook es: %s\n", per[v].fb);
			printf("Usuario de Twitter es: %s\n", per[v].tw);
			printf("\n");
			printf("\n");
			printf("¿Esta seguro de eliminar el alumno?\n");
			printf("De forma numerica seleccione.\n");
			printf(" 1. SI deseo eliminarlo.\n");
			printf(" 2. NO deseo eliminarlo.\n");
			scanf("%d", &des);
			if (des == 1)
			{
				eliminar(&per[v]);
				printf("Se ha eliminado todos los datos del alumno de forma exitosa");
			}

			else
			{
				printf("No se ha eliminado ningun alumno del sistema.");
			}

			break;
		default:
			printf("Te haz salido del programa.\n");
		}
		printf("\n");
		printf("\n");
		printf("\n");
	} while (x != 5);
	return 0;
}
// ptr esta apuntando a la direccion de memoria del arreglo[0].
int compara(char nom[], struct contacto *ptr)
{
	int i = 0, acu = 0, b, a = 0, c = 0;
	int peso = 0;
	peso = Tam(nom);
	// printf("El peso del nombre introducido es: %d\n",peso);
	while (c < 1)
	{
		if (acu == peso)
		{
			c = 1;
		}
		else
		{
			if (a < 100)
			{
				acu = 0;
				i = 0;
				// Evaluamos uno por uno en el arreglo.
				while (i < peso)
				{
					if (nom[i] == ptr->nombre[i])
					{
						i++;
						acu++;
					}
					else
					{
						i++;
					}
				}
				a++;
				ptr++;
			}
			else
			{
				printf("\n");
				printf("\n");
				printf("---------------------------------------\n");
				printf("\n");
				printf("EL NOMBRE INGRESADO NO ES VALIDO.\n");
				printf("POR FAVOR INTENTE DE NUEVO, RESPETANDO ACENTOS, ESPACIOS, MAYUSCULAS Y MINUSCULAS.\n");
				printf("\n");
				printf("---------------------------------------\n");
				printf("\n");
				printf("\n");
				c = 1;
				a = 0;
			}
		}
	}
	return a;
}

int Tam(char no[])
{
	int b = 0, sin = 0;
	while (no[b] != '\0')
	{
		b++;
		sin++;
	}
	return sin;
}

void modificar(int a, struct contacto *puntero)
{
	switch (a)
	{
	case 1:
		printf("Ingrese la nueva boleta.\n");
		scanf("%s", puntero->id);
		fflush(stdin);
		break;
	case 2:
		printf("Ingrese el nuevo nombre.\n");
		scanf("%s", puntero->nombre);
		fflush(stdin);
		break;
	case 3:
		printf("Ingrese el nuevo apellido paterno.\n");
		scanf("%s", puntero->apa);
		fflush(stdin);
		break;
	case 4:
		printf("Ingrese el nuevo apellido materno.\n");
		scanf("%s", puntero->ama);
		fflush(stdin);
		break;
	case 5:
		printf("Ingrese el nuevo domicilio.\n");
		scanf("%s", puntero->dom);
		fflush(stdin);
		break;
	case 6:
		printf("Ingrese el nuevo grupo.\n");
		scanf("%s", puntero->rfc);
		fflush(stdin);
		break;
	case 7:
		printf("Ingrese el nuevo numero movil.\n");
		scanf("%s", puntero->movil);
		fflush(stdin);
		break;
	case 8:
		printf("Ingrese el nuevo numero fijo.\n");
		scanf("%s", puntero->fijo);
		fflush(stdin);
		break;
	case 9:
		printf("Ingrese el nuevo correo electronico (e-mail).\n");
		scanf("%s", puntero->mail);
		fflush(stdin);
		break;
	case 10:
		printf("Ingrese el nuevo usuario de facebook.\n");
		scanf("%s", puntero->fb);
		fflush(stdin);
		break;
	case 11:
		printf("Ingrese el nuevo usuario de twitter.\n");
		scanf("%s", puntero->tw);
		fflush(stdin);
		break;
	default:
		printf("No existe este elemento.\n");
	}
}

void eliminar(struct contacto *punt)
{
	punt->id[20] = ' ';
	punt->nombre[30] = ' ';
	punt->apa[30] = ' ';
	punt->ama[30] = ' ';
	punt->dom[100] = ' ';
	punt->rfc[15] = ' ';
	punt->movil[22] = ' ';
	punt->fijo[22] = ' ';
	punt->mail[30] = ' ';
	punt->fb[30] = ' ';
	punt->tw[25] = ' ';
}
