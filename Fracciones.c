/*
Autor: AngelChetosmen
Consultar la Licencia del Autor | Derechos Reservados EUVA B&T ©
*/
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
typedef struct frac
{
	int num[2];
	int den[2];
} fr;

int sum(int, int, int, int);
int res(int, int, int, int);
int mul(int, int);
int elevado(int, int);

int main()
{
	int a, deno, ex;
	fr fra;
	int ope[5];
	do
	{
		printf("Este programa tiene el objetivo de realizar una serie de operaciones con numeros fraccionarios.\n");
		printf("Seleccione de forma numerica la operación que desea realizar.\n");
		printf("1. Suma de dos fracciones.\n");
		printf("2. Resta de dos fracciones.\n");
		printf("3. Multiplicacion de dos fracciones.\n");
		printf("4. Division de dos fracciones.\n");
		printf("5. Potencia.\n");
		printf("6. Simplificacion.\n");
		printf("7. Numerador de una fraccion.\n");
		printf("8. Denominador de una fraccion.\n");
		printf("9. Salir.\n");
		scanf("%d", &a);
		fflush(stdin);
		switch (a)
		{
		case 1:
			printf("Selecciono suma de fracciones.\n");
			printf("Se le pedira dos fracciones.\n");
			printf("Fraccion 1.\n");
			printf("Coloque el numerador.\n");
			scanf("%d", &fra.num[0]);
			printf("Coloque el denominador.\n");
			scanf("%d", &fra.den[0]);
			printf("Fraccion 2\n");
			printf("Coloque el numerador.\n");
			scanf("%d", &fra.num[1]);
			printf("Coloque el denominador.\n");
			scanf("%d", &fra.den[1]);
			deno = mul(fra.den[0], fra.den[1]);
			printf("La suma de las fracciones es: %d / %d\n", sum(fra.num[0], fra.den[0], fra.num[1], fra.den[1]), deno);
			break;
		case 2:
			printf("Selecciono resta de fracciones.\n");
			printf("Se le pedira dos fracciones.\n");
			printf("Fraccion 1.\n");
			printf("Coloque el numerador.\n");
			scanf("%d", &fra.num[0]);
			printf("Coloque el denominador.\n");
			scanf("%d", &fra.den[0]);
			printf("Fraccion 2\n");
			printf("Coloque el numerador.\n");
			scanf("%d", &fra.num[1]);
			printf("Coloque el denominador.\n");
			scanf("%d", &fra.den[1]);
			printf("La resta de las fracciones es: %d / %d\n", res(fra.num[0], fra.den[0], fra.num[1], fra.den[1]), mul(fra.den[0], fra.den[1]));
			break;
		case 3:
			printf("Selecciono multiplicacion de fracciones.\n");
			printf("Se le pedira dos fracciones.\n");
			printf("Fraccion 1.\n");
			printf("Coloque el numerador.\n");
			scanf("%d", &fra.num[0]);
			printf("Coloque el denominador.\n");
			scanf("%d", &fra.den[0]);
			printf("Fraccion 2\n");
			printf("Coloque el numerador.\n");
			scanf("%d", &fra.num[1]);
			printf("Coloque el denominador.\n");
			scanf("%d", &fra.den[1]);
			printf("La multiplicacion de las fracciones es: %d / %d\n", mul(fra.num[0], fra.num[1]), mul(fra.den[0], fra.den[1]));
			break;
		case 4:
			printf("Selecciono division de fracciones.\n");
			printf("Se le pedira dos fracciones.\n");
			printf("Fraccion 1.\n");
			printf("Coloque el numerador.\n");
			scanf("%d", &fra.num[0]);
			printf("Coloque el denominador.\n");
			scanf("%d", &fra.den[0]);
			printf("Fraccion 2\n");
			printf("Coloque el numerador.\n");
			scanf("%d", &fra.num[1]);
			printf("Coloque el denominador.\n");
			scanf("%d", &fra.den[1]);
			printf("La division de las fracciones es: %d / %d\n", mul(fra.num[0], fra.den[1]), mul(fra.den[0], fra.num[1]));
			break;
		case 5:
			printf("Selecciono potencia de una fraccion.\n");
			printf("Se le pedira una fraccion y el exponente entero.\n");
			printf("Coloque el numerador.\n");
			scanf("%d", &fra.num[0]);
			printf("Coloque el denominador.\n");
			scanf("%d", &fra.den[0]);
			printf("Coloque el exponente de la fraccion.\n");
			scanf("%d", &ex);
			printf("El resultado de la fraccion con exponente a la %d es: %d / %d\n", ex, elevado(fra.num[0], ex), elevado(fra.den[0], ex));
			break;
		case 6:
			printf("Selecciono simplificacion de una fraccion.\n");
			printf("Se le pedira una fraccion.\n");
			printf("Coloque el numerador.\n");
			scanf("%d", &fra.num[0]);
			printf("Coloque el denominador.\n");
			scanf("%d", &fra.den[0]);
			while (fra.num[0] % 2 == 0 && fra.den[0] % 2 == 0)
			{
				fra.num[0] = fra.num[0] / 2;
				fra.den[0] = fra.den[0] / 2;
			}
			while (fra.num[0] % 3 == 0 && fra.den[0] % 3 == 0)
			{
				fra.num[0] = fra.num[0] / 3;
				fra.den[0] = fra.den[0] / 3;
			}
			while (fra.num[0] % 5 == 0 && fra.den[0] % 5 == 0)
			{
				fra.num[0] = fra.num[0] / 5;
				fra.den[0] = fra.den[0] / 5;
			}
			while (fra.num[0] % 7 == 0 && fra.den[0] % 7 == 0)
			{
				fra.num[0] = fra.num[0] / 7;
				fra.den[0] = fra.den[0] / 7;
			}
			while (fra.num[0] % 11 == 0 && fra.den[0] % 11 == 0)
			{
				fra.num[0] = fra.num[0] / 11;
				fra.den[0] = fra.den[0] / 11;
			}
			printf("La fraccion simplificada es: %d / %d\n", fra.num[0], fra.den[0]);
			break;
		case 7:
			printf("Selecciono numerador de una fraccion.\n");
			printf("Se le pedira una fraccion\n");
			printf("Coloque el numerador.\n");
			scanf("%d", &fra.num[0]);
			printf("Coloque el denominador.\n");
			scanf("%d", &fra.den[0]);
			printf("El numerador de la fraccion es: %d\n", fra.num[0]);
			break;
		case 8:
			printf("Selecciono denominador de una fraccion.\n");
			printf("Se le pedira una fraccion\n");
			printf("Coloque el numerador.\n");
			scanf("%d", &fra.num[0]);
			printf("Coloque el denominador.\n");
			scanf("%d", &fra.den[0]);
			printf("El denominador de la fraccion es: %d\n", fra.den[0]);
			break;
		default:
			printf("Usted ha salido del programa.\n");
		}
		printf("\n");
		printf("\n");
		printf("\n");
		fra.den[0] = 0;
		fra.den[1] = 0;
		fra.num[0] = 0;
		fra.den[0] = 0;
	} while (a < 9);
	return 0;
}

int sum(int a, int b, int c, int d)
{
	int dat[4], re;
	dat[0] = a * d;
	dat[1] = b * c;
	re = dat[0] + dat[1];
	return re;
}

int mul(int b, int d)
{
	int res;
	res = b * d;
	return res;
}

int res(int a, int b, int c, int d)
{
	int r[4], re;
	r[0] = a * d;
	r[1] = b * c;
	re = r[0] - r[1];
	return re;
}

int elevado(int x, int y)
{
	int z;
	z = pow(x, y);
	return z;
}
