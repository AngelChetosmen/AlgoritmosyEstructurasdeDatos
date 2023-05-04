/*
Autor: AngelChetosmen
Consultar la Licencia del Autor | Derechos Reservados EUVA B&T ©
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct elem
{
	int operador;
	struct elem *mayor;
} ope;

void proce(float n);
void resultado(char[], int);
void agOpe(int);
void DisNum();
void nuevo();
int decision();
int pote(int, int);

int inc = 0;
float numi, numd;
ope *alto = NULL;

int main()
{
	int a;
	char pre[30];
	do
	{
		inc = 0;
		alto = NULL;
		int x = 0;
		printf("Este programa obtiene el resultado de una operacion de forma recursiva.\n");
		printf("Acepta expresion solo en prefija.\n");
		printf("Por favor ingrese la expresion prefija.\n");
		printf("No colocar parentesis, solo operandos y operadores de un solo digito.\n");
		printf("\n");
		scanf("%s", pre);
		fflush(stdin);
		resultado(pre, x);
		a = decision();
	} while (a < 2);
	alto = NULL;
	free(alto);
	printf("Programa finalizado.\n");
	return 0;
}

void resultado(char pre[], int i)
{
	int y;
	y = pre[i];
	if (pre[i] == '\0')
	{
		if (inc == 1)
		{
			printf("\n");
			printf("El resultado de tu expresion prefija es %.2f .\n", numi);
			printf("\n");
			nuevo();
		}
	}
	else
	{
		switch (y)
		{
		case 42: // *
			agOpe('*');
			break;

		case 43: // +
			agOpe('+');
			break;

		case 45: // -
			agOpe('-');
			break;

		case 47: // /
			agOpe('/');
			break;

		case 101: // ^
			agOpe('e');
			break;

		case 49: // 1
			inc++;
			proce(1);
			break;

		case 50: // 2
			inc++;
			proce(2);
			break;

		case 51: // 3
			inc++;
			proce(3);
			break;

		case 52: // 4
			inc++;
			proce(4);
			break;

		case 53: // 5
			inc++;
			proce(5);
			break;

		case 54: // 6
			inc++;
			proce(6);
			break;

		case 55: // 7
			inc++;
			proce(7);
			break;

		case 56: // 8
			inc++;
			proce(8);
			break;

		case 57: // 9
			inc++;
			proce(9);
			break;

		default:
			printf("Error de caracter.\n");
		}
		return resultado(pre, i + 1);
	}
}

void proce(float n)
{
	float total;
	int v;
	if (alto != NULL)
	{
		if (inc == 1)
		{
			numi = n;
		}
		else
		{
			v = alto->operador;
			switch (v)
			{
			case 42: //*
				numd = n;
				total = numi * numd;
				numi = total;
				DisNum();
				inc--;
				break;

			case 43: //+
				numd = n;
				total = numi + numd;
				numi = total;
				DisNum();
				inc--;
				break;

			case 45: //-
				numd = n;
				total = numi - numd;
				numi = total;
				DisNum();
				inc--;
				break;

			case 47: // /
				numd = n;
				total = numi / numd;
				numi = total;
				DisNum();
				inc--;
				break;

			case 101: // ^
				numd = n;
				total = pote(numi, numd);
				numi = total;
				DisNum();
				inc--;
				break;

			default:
				printf("Caracter invalido.\n");
			}
		}
	}
	else
	{
		printf("Tu expresion es incorrecta.\n");
	}
}

int decision()
{
	int v;
	printf("Desea ingresar otro dato:\n");
	printf("1. SI.\n");
	printf("2. NO.\n");
	scanf("%d", &v);
	return v;
}

int pote(int x, int a)
{
	if (a == 1)
	{
		return x;
	}
	else
	{
		x = x * pote(x, a - 1);
		return x;
	}
}

void agOpe(int oper)
{
	ope *opepun;
	opepun = (ope *)malloc(sizeof(ope));
	opepun->operador = oper;
	opepun->mayor = alto;
	alto = opepun;
}

void DisNum()
{
	if (alto != NULL)
	{
		ope *aux;
		aux = alto;
		alto = alto->mayor;
		aux = NULL;
		free(aux);
	}
}

void nuevo()
{
	ope *au = alto;
	ope *eli;
	while (au != NULL)
	{
		eli = au;
		au = au->mayor;
		eli = NULL;
		free(eli);
	}
	printf("Se ha liberado la memoria.\n");
}
