/*
Autor: AngelChetosmen
Consultar la Licencia del Autor | Derechos Reservados EUVA B&T ©
*/
#include <stdio.h>
#include <math.h>
// declaración de prototipo de funciones y procesos;
#define i -1

// Declaracion de estructuras y/o macrodefiniciones;
struct complejo
{
	float preal, pimaginaria, pmodular;
	float ang, sumatoria, diferencia;
	float multi, divi;
};
// Declaracion y desarrollo de la funcion principal
int main()
{
	// Uso y declaracion de variables;
	// char i;
	int op, opuno, opdos;
	struct complejo numcom;
	struct complejo numComp;
	struct complejo resul;
	// Implemenacion de la portada;
	printf("Bienvenido\n");
	printf("Programas TAD de numeros imaginarios\n");
	printf("Ingreso de datos del numero complejo:\n");
	printf("Ingrese la parte real: \n");
	scanf("%f", &numcom.preal);
	printf("Ingrese la parte imaginaria: \n");
	scanf("%f", &numcom.pimaginaria);
	// Implementacion del menu con opciones;
	printf("Por favor, seleccione numericamente la opcion que desee:\n");
	printf("1.- Suma\n");
	printf("2.- Resta\n");
	printf("3.- Multiplicacion\n");
	printf("4.- Division\n");
	printf("5.- Magnitud o modulo\n");
	printf("6.- Angulo\n");
	printf("7.- Parte real\n");
	printf("8.- Parte imaginaria\n");
	printf("9.- Salir del programa\n");
	scanf("%d", &op);

	switch (op)
	{
	case 1:
	{
		printf("¿Desea realizar la suma con dos numeros imaginarios?\n");
		printf("1.- SI\n");
		printf("2.- NO\n");
		scanf("%d", &opuno);
		// Submenu;
		switch (opuno)
		{
		case 1:
		{
			printf("Ingrese la parte real: \n");
			scanf("%f", &numComp.preal);
			printf("Ingrese la parte imaginaria: \n");
			scanf("%f", &numComp.pimaginaria);
			resul.sumatoria = ((numcom.preal + numComp.preal) + i * (numcom.pimaginaria + numComp.pimaginaria));
			printf("La sumatoria de los dos numeros complejos es: %.4f", resul.sumatoria);
			break;
		}
		case 2:
		{
			numcom.sumatoria = numcom.preal + i * numcom.pimaginaria;
			printf("La suma del numero compeljo es: %.4f", numcom.sumatoria);
			break;
		}
		default:
		{
			printf("Opcion no valida\n");
			break;
		}
		}
		break;
	}
	case 2:
	{
		printf("¿Desea realizar la resta con dos numeros imaginarios?\n");
		printf("1.- SI\n");
		printf("2.- NO\n");
		scanf("%d", &opdos);
		// Submenu;
		switch (opdos)
		{
		case 1:
		{
			printf("Ingrese la parte real: \n");
			scanf("%f", &numComp.preal);
			printf("Ingrese la parte imaginaria: \n");
			scanf("%f", &numComp.pimaginaria);
			resul.diferencia = ((numcom.preal - numComp.preal) + i * (numcom.pimaginaria - numComp.pimaginaria));
			printf("La diferencia de los dos numeros complejos es: %.4f", resul.diferencia);
			break;
		}
		case 2:
		{
			numcom.diferencia = numcom.preal - i * numcom.pimaginaria;
			printf("La suma del numero compeljo es: %.4f", numcom.diferencia);
			break;
		}
		default:
		{
			printf("Opcion no valida\n");
			break;
		}
		}
		break;
	}
	case 3:
	{
		printf("Datos del segundo numero complejo:\n");
		printf("Ingrese la parte real: \n");
		scanf("%f", &numComp.preal);
		printf("Ingrese la parte imaginaria: \n");
		scanf("%f", &numComp.pimaginaria);
		resul.multi = ((numcom.preal - numComp.preal - numcom.pimaginaria * numComp.pimaginaria) + i * (numcom.preal * numComp.pimaginaria + numcom.pimaginaria * numComp.preal));
		printf("La multiplicacion de los dos numeros complejos es: %.4f", resul.multi);
		break;
	}
	case 4:
	{
		printf("Datos del segundo numero complejo:\n");
		printf("Ingrese la parte real: \n");
		scanf("%f", &numComp.preal);
		printf("Ingrese la parte imaginaria: \n");
		scanf("%f", &numComp.pimaginaria);
		resul.divi = ((numcom.preal * numComp.preal + numcom.pimaginaria * numComp.pimaginaria) + i * (numcom.pimaginaria * numComp.preal - numcom.preal * numComp.pimaginaria)) / ((numComp.preal * numComp.preal) + (numComp.pimaginaria * numComp.pimaginaria));
		printf("La multiplicacion de los dos numeros complejos es: %.4f", resul.divi);
		break;
	}
	case 5:
	{
		numcom.pmodular = sqrt(numcom.preal * numcom.preal + numcom.pimaginaria * numcom.pimaginaria);
		printf("\nEl modulo es: %f", numcom.pmodular);
		break;
	}
	case 6:
	{
		numcom.ang = atan(numcom.pimaginaria / numcom.preal);
		numcom.ang = numcom.ang * 180;
		printf("\nEl angulo del numero complejo es: %f", numcom.ang);
		break;
	}
	case 7:
	{
		printf("\nLa parte real es: %f", numcom.preal);
		break;
	}
	case 8:
	{
		printf("\nLa parte imaginaria es: %f", numcom.pimaginaria);
		break;
	}
	case 9:
	{
		break;
	}
	default:
	{
		printf("Opcion no valida\n");
		break;
	}
	}
	printf("\nVuelva pronto\n");
	// Calculamos el modulo;
	// numcom.modulo = sqrt(numcom.preal*numcom.real+numcom.pimaginaria*numcom.pimaginaria);
	// printf("\nEl modulo es: %f", numcom.modulo);
	return 0;
}
// Desarrollo de las funciones prototipadas
