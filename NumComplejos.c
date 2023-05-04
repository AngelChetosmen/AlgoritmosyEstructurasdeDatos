/*
Autor: AngelChetosmen
Consultar la Licencia del Autor | Derechos Reservados EUVA B&T ©
*/
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>

typedef struct im
{
	float re;
	float im;
} nu;

// Numero complejo TAD
// Numero que tiene dos partes, una real o imaginaria
// Imaginaria la indicamos con una "i".
// Numeros tipo float.
// Coeficiente de parte real y coeficiente de parte imaginaria.
float suma(float, float);
float resta(float, float);
float mult(float, float);
float magnitud(float, float);
float angulo(float, float);

int main()
{
	int a;
	nu num0, num1;
	float d1[2], d2[2];
	float m1[2], m2[2];
	float sum[4], cam;
	float cua[2], de;
	do
	{
		printf("Este programa lo que realiza es la operacion de numeros complejos.\n");
		printf("Por favor, seleccione de forma numerica la opcion deseada.\n");
		printf("1.Suma de dos numeros complejos.\n");
		printf("2.Resta de dos numeros complejos.\n");
		printf("3.Multiplicacion de dos numeros complejos.\n");
		printf("4.Division de dos numeros complejos.\n");
		printf("5.Magnitud de un numero complejo.\n");
		printf("6.Angulo de un numero complejo.\n");
		printf("7.Real de un numero complejo.\n");
		printf("8.Imaginario de un numero complejo.\n");
		printf("9. Salir del programa.\n");
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			printf("Selecciono la operacion suma.\n");
			printf("Por favor, coloque de forma ordenada los dos numeros complejos\n");
			printf("Coloque el primer numero complejo.\n");
			printf("Numero real.\n");
			scanf("%f", &num0.re);
			printf("Numero imaginario.\n");
			scanf("%f", &num0.im);
			printf("Coloque el segundo numero complejo.\n");
			printf("Numero real.\n");
			scanf("%f", &num1.re);
			printf("Numero imaginario.\n");
			scanf("%f", &num1.im);
			printf("La suma de numeros complejos es: %.2f + ( %.2f )i.\n", suma(num0.re, num1.re), suma(num0.im, num1.im));
			break;
		case 2:
			printf("Selecciono la operacion resta.\n");
			printf("Por favor, coloque de forma ordenada los dos numeros complejos\n");
			printf("Coloque el primer numero complejo.\n");
			printf("Numero real.\n");
			scanf("%f", &num0.re);
			printf("Numero imaginario.\n");
			scanf("%f", &num0.im);
			printf("Coloque el segundo numero complejo.\n");
			printf("Numero real.\n");
			scanf("%f", &num1.re);
			printf("Numero imaginario.\n");
			scanf("%f", &num1.im);
			printf("La resta de los numeros complejos es: %.2f + ( %.2f )i.\n", resta(num0.re, num1.re), resta(num0.im, num1.im));
			break;
		case 3:
			printf("Selecciono la operacion multiplicacion.\n");
			printf("Por favor, coloque de forma ordenada los dos numeros complejos\n");
			printf("Coloque el primer numero complejo.\n");
			printf("Numero real.\n");
			scanf("%f", &num0.re);
			printf("Numero imaginario.\n");
			scanf("%f", &num0.im);
			printf("Coloque el segundo numero complejo.\n");
			printf("Numero real.\n");
			scanf("%f", &num1.re);
			printf("Numero imaginario.\n");
			scanf("%f", &num1.im);
			m1[0] = mult(num0.re, num1.re);
			m1[1] = mult(num0.im, num1.im);
			m2[0] = mult(num0.re, num1.im);
			m2[1] = mult(num0.im, num1.re);
			m1[1] = -m1[1];
			sum[0] = m1[0] + m1[1];
			sum[1] = m2[0] + m2[1];
			printf("La multiplicacion de los numeros complejos es: %.2f + ( %.2f ) i\n", sum[0], sum[1]);
			break;
		case 4:
			printf("Selecciono la operacion division.\n");
			printf("Por favor, coloque de forma ordenada los dos numeros complejos.\n");
			printf("Coloque el primer numero complejo.\n");
			printf("Se le pedira el numero complejo como numerador.\n");
			printf("Numero real.\n");
			scanf("%f", &num0.re);
			printf("Numero imaginario.\n");
			scanf("%f", &num0.im);
			printf("Coloque el segundo numero complejo.\n");
			printf("Se le pedira el numero complejo como denominador.\n");
			printf("Numero real.\n");
			scanf("%f", &num1.re);
			printf("Numero imaginario.\n");
			scanf("%f", &num1.im);
			cam = -(num1.im);
			m1[0] = mult(num0.re, num1.re);
			m1[1] = mult(num0.im, cam);
			m2[0] = mult(num0.re, cam);
			m2[1] = mult(num0.im, num1.re);
			m1[1] = -m1[1];
			sum[0] = m1[0] + m1[1];
			sum[1] = m2[0] + m2[1];

			cua[0] = num1.re * num1.re;
			cua[1] = num1.im * num1.im;
			de = cua[1] + cua[0];
			printf("El resultado de la division es: %.2f / %.2f  +  ( %.2f / %.2f )i\n", sum[0], de, sum[1], de);
			break;
		case 5:
			printf("Selecciono obtener la magnitud de un numero complejo.\n");
			printf("Por favor, coloque de forma ordenada el numero complejo.\n");
			printf("Coloque el numero complejo.\n");
			printf("Numero real.\n");
			scanf("%f", &num0.re);
			printf("Numero imaginario.\n");
			scanf("%f", &num0.im);
			printf("La magnitud del numero complejo es: %.4f\n", magnitud(num0.re, num0.im));

			break;
		case 6:
			printf("Selecciono obtener la angulo de un numero complejo.\n");
			printf("Por favor, coloque de forma ordenada el numero complejo.\n");
			printf("Coloque el numero complejo.\n");
			printf("Numero real.\n");
			scanf("%f", &num0.re);
			printf("Numero imaginario.\n");
			scanf("%f", &num0.im);
			printf("El angulo del numero complejo es: %.4f\n", angulo(num0.re, num0.im));

			break;
		case 7:
			printf("Selecciono obtener numero real de un numero complejo.\n");
			printf("Por favor, coloque de forma ordenada el numero complejo.\n");
			printf("Coloque el numero complejo.\n");
			printf("Numero real.\n");
			scanf("%f", &num0.re);
			printf("Numero imaginario.\n");
			scanf("%f", &num0.im);
			printf("El numero real de tu numero complejo es: %.2f\n", num0.re);

			break;
		case 8:
			printf("Selecciono obtener numero imaginario de un numero complejo.\n");
			printf("Por favor, coloque de forma ordenada el numero complejo.\n");
			printf("Coloque el numero complejo.\n");
			printf("Numero real.\n");
			scanf("%f", &num0.re);
			printf("Numero imaginario.\n");
			scanf("%f", &num0.im);
			printf("El numero imaginario de tu numero complejo es: %.2f\n", num0.im);

			break;
		default:
			printf("Usted ha salido del programa.\n");
		}
		printf("\n");
		printf("\n");
		printf("\n");
		d1[0] = 0;
		d1[1] = 0;
		d2[0] = 0;
		d2[1] = 0;
	} while (a < 9);
	return 0;
}

float suma(float x, float y)
{
	float r;
	r = x + y;
	return r;
}

float resta(float a, float b)
{
	float d;
	d = a - b;
	return d;
}

float mult(float c, float d)
{
	float re;
	re = c * d;
	return re;
}

float magnitud(float x, float y)
{
	float ope, suma;
	x = x * x;
	y = y * y;
	suma = x + y;
	ope = sqrt(suma);
	return ope;
}

float angulo(float x, float y)
{
	float ang, div, con, ope;
	// Para obtener el ángulo fue a traves de la tangente del triángulo rectángulo de forma que: ángulo=tan^-1(y/x).
	div = y / x;
	ang = atan(div);
	// Este es para convertir de radianes a grados.
	con = ang * 57.2958;
	// Este da a conocer en que cuadrante del plano cartesiano pertenece el punto para obtener por lo tanto, un ángulo positivo.
	if (x < 0)
	{
		if (y < 0)
		{
			// Aqui se restará 270 debido a que pertenece al cuadrante 3 del plano cartesiano (-,-).
			ope = 270 - con;
		}
		else
		{
			// Aqui se restará 180 debido a que esta en el cuadrante 2 del plano cartesiano (-,+).
			ope = 180 + con;
		}
	}
	else
	{
		if (y < 0)
		{
			// Aqui se restará 360 debido a que esta en el cuadrante 4 del plano cartesiano (+,-).
			ope = 360 + con;
		}
		else
		{
			// Aqui no hay necesidad de restar debido a que pertenece al cuadrante 1 del plano cartesiano (+,+).
			ope = con;
		}
	}
	return ope;
}
