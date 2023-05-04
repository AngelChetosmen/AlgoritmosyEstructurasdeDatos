/*
Autor: AngelChetosmen
Consultar la Licencia del Autor | Derechos Reservados EUVA B&T ©
*/
#include <stdio.h>

// Declaracion de prototipo de funciones
void suma();
void resta();
void multiplicacionuno();
void multiplicaciondos();
void divisionuno();
void divisiondos();
void potencia();
void simplificacion();
void solicitud();
// Declaracion y desarrollo de la funcion principal
int main()
{
	int x1, y1, x2, y2;
	// int a;

	int a;
	int b, c, d, e, f, g, h, i, j;
	// void k;

	printf("Bienvenido\n");
	printf("Programa de fracciones\n");
	printf("Por favor seleccione numericamente la opcion que desea:\n");
	// Implementacion del menu con opciones
	printf("1.- Suma\n");
	printf("2.- Resta\n");
	printf("3.- Multiplicacion\n");
	printf("4.- Division\n");
	printf("5.- Potencia\n");
	printf("6.- Simplificacion\n");
	printf("7.- Numerador\n");
	printf("8.- Denominador\n");
	printf("9.- Salir del programa\n");
	// Solicitud del valor a escoger de manera numerica
	scanf("%d", &a);
	// Creacion de la programacion del menu
	switch (a)
	{
	case 1:
	{
		// b = y1*y2;
		// c = ((x1*y2)+(y1*x2));
		printf("Ingrese los valores:\n");
		printf("Primera fraccion:\n");
		printf("\nValor del numerador\n");
		scanf("%d", &x1);
		printf("\nValor del denominador\n");
		scanf("%d", &y1);
		printf("Segunda fraccion");
		printf("\nValor del numerador:\n");
		scanf("%d", &x2);
		printf("\nValor del denominador:\n");
		scanf("%d", &y2);
		printf("La suma es: (%d/%d) + (%d/%d)\n", x1, y1, x2, y2);
		// printf("\b");
		break;
	}
	case 2:
	{
		printf("Ingrese los valores:\n");
		printf("Primera fraccion:\n");
		printf("Valor del numerador\n");
		scanf("%d", &x1);
		printf("\nValor del denominador\n");
		scanf("%d", &y1);
		printf("\nSegunda fraccion\n");
		printf("Valor del numerador:\n");
		scanf("%d", &x2);
		printf("\nValor del denominador:\n");
		scanf("%d", &y2);
		printf("\nLa resta es: (%d/%d) - (%d/%d)\n", x1, y1, x2, y2);
		break;
	}
	case 3:
	{
		// multiplicacionuno();
		// multiplicaciondos();
		printf("Ingrese los valores de los numeradores y denominadores\n:");
		printf("Valor del numerador x1 1:\n");
		scanf("%d\n", &x1);
		printf("Valor de donominador y2 2:\n");
		scanf("%d\n", &y2);
		printf("Ingrese los valores de los denominadores\n:");
		printf("\nValor del denomiandor 1:\n");
		scanf("%d", &y1);
		printf("\nValor del donominador 2:\n");
		scanf("%d", &y2);
		printf("La multiplicacion es: (%d/%d)*(%d/%d)\n", x1, y1, x2, y2);
		break;
	}
	case 4:
	{
		// Llamado de funciones por copia;
		divisionuno();
		divisiondos();
		printf("La division es: (%d/%d)/(%d/%d)", x1, y1, x2, y2);
		break;
	}
	case 5:
	{
		// Llamado de las funciones correspondientes;
		// potencia();
		printf("Ingrese los datos de la base en fraccion:\n");
		printf("Valor del numerador base:\n");
		scanf("%d", &x1);
		printf("\nValor del denominador base:\n ");
		scanf("%d", &y1);
		printf("\nValor del exponente:\n");
		scanf("%d", &x2);

		printf("La potencia es: (%d/%d)^(%d)\n", x1, y1, x2);
		break;
	}
	case 6:
	{
		// Llamado de funciones;
		// divisionuno();
		// divisiondos();
		printf("Ingrese los valores de los numeradores y denominadores:\n");
		printf("Valor del numerador x1 1:\n");
		scanf("%d", &x1);
		printf("\nValor de donominador y1 1:\n");
		scanf("%d", &y1);
		printf("Ingrese los valores de los numeradores y denominadores:\n");
		printf("\nValor del numerador x2 2:\n");
		scanf("%d", &x2);
		printf("\nValor de donominador y2 2:\n");
		scanf("%d", &y2);
		printf("La division es: (%d/%d)/(%d/%d)= (%d)*(%d)/(%d)*(%d)\n", x1, y1, x2, y2, x1, y2, y1, x2);
		break;
	}
	case 7:
	{
		// solicitud();
		printf("Ingrese los valores:\n");
		printf("Primera fraccion:\n");
		printf("Valor del numerador\n");
		scanf("%d", &x1);
		printf("Valor del denominador\n");
		scanf("%d", &y1);
		printf("El numerador es: %d\n", x1);
		break;
	}
	case 8:
	{
		// solicitud();
		printf("Ingrese los valores:\n");
		printf("Primera fraccion:\n");
		printf("Valor del numerador\n");
		scanf("%d", &x1);
		printf("Valor del denominador\n");
		scanf("%d", &y1);
		printf("El denominador es: %d\n", y1);
		break;
	}
	case 9:
		// printf("");
		break;
	default:
		printf("Opcion no valida\n");
		break;
	}

	printf("Vuelva pronto :)\n");
	return 0;
}
// Desarrollo de la funciones de prototipo;
void suma()
{
	// Declaracion de variables locales
	int x1, y1, x2, y2;
	int sumauno = x1 / y1;
	int sumados = x2 / y2;
	int resultadosuma = sumauno + sumados;
	// Solicitud de datos
	/*
	printf("Ingrese los valores:\n");
	printf("Primera fraccion:\n");
	printf("Valor del numerador\n");
	scanf("%d\n", &x1);
	printf("Valor del denominador\n");
	scanf("%d\n\n", &y1);
	printf("Segunda fraccion");
	printf("Valor del numerador:\n");
	scanf("%d\n",&x2);
	printf("Valor del denominador:\n");
	scanf("%d\n\n",&y2);
	*/
	printf("Ingrese los valores:\n");
	printf("Primera fraccion:\n");
	printf("\nValor del numerador\n");
	scanf("%d", &x1);
	printf("\nValor del denominador\n");
	scanf("%d", &y1);
	printf("Segunda fraccion");
	printf("\nValor del numerador:\n");
	scanf("%d", &x2);
	printf("\nValor del denominador:\n");
	scanf("%d", &y2);
	printf("La suma es: (%d/%d) + (%d/%d) = %d/%d = %d\n", x1, y1, x2, y2, sumauno, sumados, resultadosuma);
	// Retorno de valores;
	// return resultadosuma;
}
void resta()
{
	// Declracion de variable locales;
	int x1, y1, x2, y2;
	int restauno = x1 / y1;
	int restados = x2 / y2;
	int resultadoresta = restauno - restados;
	// Solicitud de datos;
	printf("Ingrese los valores:\n");
	printf("Primera fraccion:\n");
	printf("Valor del numerador\n");
	scanf("%d\n", &x1);
	printf("Valor del denominador\n");
	scanf("%d\n\n", &y1);
	printf("Segunda fraccion");
	printf("Valor del numerador:\n");
	scanf("%d\n", &x2);
	printf("Valor del denominador:\n");
	scanf("%d\n\n", &y2);
	// Retorno de valores;
	// return resultadoresta;
}
void multiplicacionuno()
{
	// Declaracion de variables locales;
	int x1, y1, x2, y2;
	int multiuno = x1 * x2;
	// Solicitamos valores correspondientes;
	printf("Ingrese los valores de los numeradores\n:");
	printf("\nValor del numerador 1\n:");
	scanf("%d", &x1);
	printf("\nValor de numerador 2\n:");
	scanf("%d", &x2);
	// Retorno de valores;
	// return multiuno;
}
void multiplicaciondos()
{
	// Declaracion de variables locales;
	int x1, y1, x2, y2;
	int multidos = y1 * y2;
	// Solicitamos valores correspondientes;
	printf("Ingrese los valores de los denominadores\n:");
	printf("\nValor del denomiandor 1:\n");
	scanf("%d", &y1);
	printf("\nValor del donominador 2:\n");
	scanf("%d", &y2);
	// Retornamos valores;
	// return multidos;
}
void divisionuno()
{
	// Declaracion de variabñes locales;
	int x1, y1, x2, y2;
	int diviuno = x1 * y2;
	// Solicitamos valores correspondientes;
	printf("Ingrese los valores de los numeradores y denominadores\n:");
	printf("Valor del numerador x1 1:\n");
	scanf("%d\n", &x1);
	printf("Valor de donominador y2 2:\n");
	scanf("%d\n", &y2);
	// Retornamos valores;
	// return diviuno;
}
void divisiondos()
{
	// Declaracion de variabñes locales;
	int x1, y1, x2, y2;
	int dividos = y1 * x2;
	// Solicitamos valores correspondientes;
	printf("Ingrese los valores de los numeradores y denominadores\n:");
	printf("Valor del numerador x2 1:\n");
	scanf("%d\n", &x2);
	printf("Valor de donominador y1 2:\n");
	scanf("%d\n", &y1);
	// Retornamos valores;
	// return dividos;
}
void potencia()
{
	// Declartacion de las variables locales;
	int x1, y1, x2, y2;
	// int base = x1/y1;
	// int poten = base ^ x2;
	// Solicitud de los datos correspondientes;
	printf("Ingrese los datos de la base en fraccion:\n");
	printf("Valor del numerador base:\n");
	scanf("%d", &x1);
	printf("\nValor del denominador base:\n ");
	scanf("%d", &y1);
	printf("\nValor del exponente:\n");
	scanf("%d", &x2);
	// Retornamos valores;
	// return poten;
}
void simplificacion()
{
	int x1, y1, x2, y2;
	int fraccion = x1 / y1;
	// Llamado de procesos;
	solicitud();
	// Condicionales;
	if (fraccion != 0)
	{
		printf("La fraccion tiene simplificacion: %d\n", fraccion);
	}
	if (fraccion == 0)
	{
		printf("La fraccion no tiene simplificacion: %d/%d\n", x1, y1);
	}
	// return fraccion;
}
void solicitud()
{
	int x1, y1, x2, y2;
	// Solicitamos valores correspondientes;
	printf("Ingrese los valores:\n");
	printf("Primera fraccion:\n");
	printf("Valor del numerador\n");
	scanf("%d", &x1);
	printf("Valor del denominador\n");
	scanf("%d", &y1);
}
