/*
Autor: AngelChetosmen
Consultar la Licencia del Autor | Derechos Reservados EUVA B&T ©
*/
#include <stdio.h>

/*  Actividad: Programar la solución para las torres de Hanoi. Ingresar
 * el numero de discos desde el teclado. ¿Cuantos discos soporta su
 * computadora?;¿cuanto tiempo tarda?*/

// Declaracion de macrodefiniciones y cabeceras de archivos;
// Declaracion de estructuras, variables globales procesos y funciones;
// Procesos y funciones;
void hanoi(char desde, char hacia, char otro, int n);
// Estructuras y variables globales;
// Desarrollo del contenido de estas variables;
// Otras declaraciones;
// Prototipo y desarrollo de la funcion principal;
int main()
{
	// Declaracionde variables locales;
	int n;
	//'
	printf("Programa de solucion para las torres de Hanoi:\n");
	printf("Ingrese el numero de discos deseados\n");
	scanf("%d", &n);
	printf("La resolucion de la torre de Hanoi es de la siguiente manera\n");
	// Llamada de la funcion recursiva Hanoi;
	hanoi('A', 'B', 'C', n);
	printf("La Torre ha sido resuelta\n");
	return 0;
}
// Desarrollo de los procesos y funciones prototipadas;
void hanoi(char desde, char hacia, char otro, int n)
{
	if (n > 0)
	{
		hanoi(desde, otro, hacia, n - 1);
		printf("%c -> %c\n", desde, hacia);
		hanoi(otro, hacia, desde, n - 1);
	}
}
