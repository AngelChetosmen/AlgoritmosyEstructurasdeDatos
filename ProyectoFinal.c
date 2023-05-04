/*
Autor: AngelChetosmen
Consultar la Licencia del Autor | Derechos Reservados EUVA B&T ©
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Declaracion de cabeceras y de macrodefiniciones;
//   Declaracion de tipos de estructuras;
typedef struct lista
{
	int dato;
	struct lista *sig;
} elem;

typedef struct id
{
	elem *inicio;
	elem *fin;
	int tam;
} lista;

typedef struct
{
	float precio;
	int cantidad;
	char nombre[15];
} producto;
// Declaracion de procesos y funciones;
void menu(lista *x, int i);
void menu_cancelar(lista *x);
void factura(int p[], int x);
int funcday();
void leerProds();
void com(int a[], int x);

int InsLisVacia(lista *x, int d);
int InsInicio(lista *l, int d);
int InsPos(lista *x, int d, int pos);
int InsFinal(lista *l, int d);	// Inserta el producto del consumidor.
int ElimInicio(lista *x);		// Elimina
int ElimPos(lista *x, int pos); // Elimina el producto del consumidor en una posicion de la lista.
int ElimFinal(lista *x);		// Elimina el producto del final de la lista del consumidor.
void inicializo(lista *x);		// Inicializa la lista.
void muestra(lista *c);			// Mostrara la lista de compras del consumidor.
void Lisarr(lista *n, int r[]); // Aqui pasare de una lista dinamica a un arreglo dinamico.
int OpcEli(lista *l, int n);	// Aqui agregaremos una funcion para resumir, donde seran las opciones para eliminar en la lista (inicio,posicion o final)

producto w[100];
// Declaracion y desarrollo de la funcion principal
int main()
{
	int nue, taar, *pun;
	int m = 0, num, i, j, yn, opc = 0;
	lista n;
	lista *lis = &n;
	float precio[101] = {0, 35.5, 7.3, 17, 11.6, 29.9, 41, 49.9, 65, 25.5, 28, 37, 25, 24.6, 14, 121, 29, 22.5, 335, 494, 269, 570, 195, 34.5, 34.8, 67.5, 77, 29.45, 22.5, 12.6, 8.25, 63, 8, 8, 23, 23, 96, 60, 37, 90, 49, 47.8, 28.5, 33.5, 57.5, 76, 63, 121, 199, 243, 17, 37.7, 5.6, 43, 36.5, 35, 44, 32.7, 39.9, 64.5, 74, 49.9, 77, 121, 49.9, 22999, 10999, 13999, 49999, 22477.06, 8490.01, 3990.01, 7990, 48690, 13999, 1599, 1579, 189, 149, 125, 129, 66.5, 60, 21.5, 95, 53.5, 429, 207, 58.5, 398, 699, 1149, 149, 1199, 199, 4490, 3390, 106, 116, 128, 128};
	char nombre[][101] = {"", "Takis Fuego", "Natilla Danette", "CocaCola", "Sopa Maruchan", "Cheetos Flamin", "Sabritas adobadas", "Tostitos Sabritas", "Papas Ruffles", "Agua mineral Peñafiel", "Refresco Squirt", "Pan blanco Bimbo", "Tostadas de maíz Salmas", "Tostadas Milpa Real", "Refresco Delaware", "Aromatizante ambiental", "Gomitas Sour Punch", "Galletas Kinder Bueno", "Tequila Jose Cuervo", "Tequila 1800", "Tequila Gran Centenario", "Whisky Johnnie Walker", "Ron Bacardí", "Danonino de fresa", "Yakults", "Huevo blanco San Juan", "Huevo blanco Bachoco", "Chorizo con pavo", "Tomates molidos", "Granos de elote", "Chiles chipotles", "Mayonesa McCormick", "Sopa de fideo", "Spaguetti", "Pasta Barilla penne", "Pasta Tortiglioni", "Queso parmesano", "Salsa de tomate Campbell's", "Servilletas Suavel", "Servilletas Kleenex", "Servilletas Regio", "Servilletas Pétalo", "Cucharas desechables", "Charolas desechables", "Vasos desechables", "Kosako azul", "Clamato", "Jumex de Piña", "Vodka Smirnoff", "Vodka Absolut", "Panditas clásicos ", "Bubulubu", "Boing mango", "Pan dulce Nito", "Pingüinos Marinela", "Galletas saladas Ritz", "Barras Nature Valley", "Marinela Barritas piña", "Desodorante Old Spice", "Colgate Luminous White", "Listerine Pro-Encias", "Cepillo Colgate Max White", "Jabón Dove original", "Antitranspirante Rexona", "Cepillo dental Oral B", "MacBook Air Apple", "Laptop Lenovo Ideapad 3", "Laptop Asus", " Laptop Huawei Mate Book X", "Microsoft Surface Laptop", "Xbox Series  S", "Xbox One S Reacondicionada", "PlayStation 4", "Nintendo Switch", "PlayStation 5", "Control Inalámbrico PS5", "Control Inalámbrico Xbox S", "Boxer Hombre", "Playera Hombre", "Tin Wilson", "Ropa interior Depend", "Toallas femeninas Always", "Espuma modeladora", "Almohadillas de algodón", "Loción desmaquillante", "Gel para cabello", "Alimento para Perro", "Alimento para Gato", "Shampoo Ricitos", "Biberones Avent", "Peluche Baby Yoda", "Pista de Hot Wheels", "Figura Capitán América", "Volver al Futuro Lego", "Rompecabezas Gioconda", "Bicicleta Benotto", "Triciclo apache", "Chocolate Turin", "Chocolate Ferrero Rocher", "Chocolate relleno de tequila", "Chocolate relleno de whiskey"};

	for (i = 0; i < 100; i++)
	{
		w[i].cantidad = 0;
		w[i].precio = precio[i];
		strcpy(w[i].nombre, nombre[i]);
	}
	nue = 1; // Este valor indica cuando apenas va a inicializar las compras en su carrito.
	do
	{
		printf("\n\n");
		printf("Tiendita de Tiburones Blancos\n\n");
		printf("Seleccione de forma numerica la opcion deseada:\n");
		printf("\n------Menu------\n\n");
		printf("1. Ver productos.\n\n");
		printf("2. Agregar producto al carrito.\n");
		printf("3. Eliminar producto del carrito.\n\n");
		printf("4. Imprimir ticket.\n");
		printf("5. Mi carrito.\n");
		printf("6. Salir del programa.\n");
		scanf("%d", &opc);
		switch (opc)
		{
		case 1:
			// SE AGREGA LO DE VER LOS 100 PRODUCTOS DEL TXT
			leerProds();
			break;
		case 2:
			printf("Ha seleccionado agregar un producto al carrito.\n");
			if (nue == 1)
			{
				nue = 1;
				inicializo(lis);
				menu(lis, nue);
				nue = 2;
			}
			else
			{
				nue = 2;
				menu(lis, nue);
			}
			break;
		case 3:
			printf("Ha seleccionado eliminar un producto del carrito.\n");
			menu_cancelar(lis);
			break;
		case 4:
			system("cls");
			printf("Ha seleccionado imprimir el ticket.\n");
			taar = lis->tam;
			taar++;
			pun = (int *)malloc(taar * sizeof(int));
			Lisarr(lis, pun);
			factura(pun, taar);
			opc = 6;
			break;
		case 5:
			printf("Es la lista de su carrito actual:");
			if (lis->tam == 0)
			{
				printf("No hay elementos en la lista.\n");
				break;
			}
			else
			{
				muestra(lis);
				break;
			}
			break;
		default:
			printf("Usted ha salido del programa.\n");
		}
	} while (opc != 6);
	pun = NULL;
	free(pun);
	lis = NULL;
	free(lis);
	return 0;
}
// Desarrollo de los procesos y las funciones declaradas;
void menu(lista *lis, int y)
{
	system("cls");
	int m = 0, opc = 0, i, num, x, g, h;
	// En esta linea se agrega la lista de los 100 productos, es decir, la funcion de txt al programa.
	leerProds();
	printf("Seleccione de forma numerica el producto que desea agregar.\n");
	scanf("%d", &opc);
	if (y == 1)
	{							   // ESTE CUMPLE CUANDO ES LA PRIMERA VEZ AGREGANDO UN PRODUCTO A LA LISTA.
		g = InsLisVacia(lis, opc); // AQUI SE CREA UNA NUEVA LISTA.
		if (g == 0)
		{
			printf("Error en la memoria.\n");
		}
		else
		{
			printf("Se agrego de manera exitosa.\n");
			muestra(lis);
		}
	}
	else
	{ // EN CASO DE QUE YA ESTE LA LISTA YA HECHA, SOLO SE AGREGA PRODUCTOS
		h = InsFinal(lis, opc);
		if (h == 1)
		{
			printf("Se agrego exitosamente a la lista.\n");
			muestra(lis); // Aqui mostrara la lista de productos que AGREGO EL CLIENTE.
		}
	}
	i = opc;
	printf("Cantidad a agregar de este producto:");
	scanf("%d", &x);
	w[i].cantidad = w[i].cantidad + x;
	printf("\n******%d %s agregados al carrito \n\n", x, w[i].nombre);
	system("cls");
}

void menu_cancelar(lista *l)
{
	int ins[3];
	int i, opc, eli, j, k;
	system("cls");
	// AQUI MOSTRAR LA LISTA QUE TIENE HASTA AHORA EL CLIENTE.
	muestra(l);
	printf("Seleccione de forma numerica la forma de eliminar el elemento.\n");
	printf("1. Inicio de la lista.\n");
	printf("2. Posicion especifica.\n");
	printf("3. Final de la lista.\n");
	scanf("%d", &j);
	i = OpcEli(l, j);
	if (w[i].cantidad > 0)
	{
		w[i].cantidad = 0;
		printf("Ahora tienes: %d %s en el carrito.\n", w[i].cantidad, w[i].nombre);
	}
	else
	{
		printf("Tiene %d %s en el carrito.\n", w[i].cantidad, w[i].nombre);
	}
}

int OpcEli(lista *l, int n)
{
	int el[6], pos;
	switch (n)
	{
	case 1:
		el[0] = ElimInicio(l); // EL0 ME DA LA POSICION DEL PRODUCTO EN EL ORDEN DE LOS 100 PRODUCTOS.
		pos = el[0] - 1;
		if (el[0] == 0)
		{
			break;
		}
		else
		{
			printf("\n");
			printf("\n");
			muestra(l);
			break;
		}
	case 2:
		printf("\n");
		printf("\n");
		muestra(l);
		printf("Por favor, coloque la posicion donde se encuentra el elemento a eliminar.\n");
		printf("\n");
		scanf("%d", &el[2]);
		el[1] = ElimPos(l, el[2]);
		pos = el[1] - 1;
		if (el[1] == 0)
		{
			break;
		}
		else
		{
			printf("\n");
			muestra(l);
			break;
		}
	case 3:
		printf("\n");
		el[3] = ElimFinal(l);
		pos = l->tam - 1;
		if (el[3] == 0)
		{
			break;
		}
		else
		{
			printf("\n");
			muestra(l);
			break;
		}
	default:
		printf("La opcion es incorrecta.\n");
	}
	return pos;
}

void factura(int arr[], int v)
{
	int i, j, a, z, p;
	float iva, tot, aux, monto, cam;
	FILE *f;
	// system("cls");
	z = v;
	float pago[z];

	printf("\t\t\t\tMi carrito\n\n");
	printf("\t\t\tTiendita de tiburones blancos\n\n");
	printf("\tProductos:\t\tCantidad:\t\tPrecio:\n");
	for (i = 1; i < v; i++)
	{
		// printf("Cantidad del producto numero %d es: %d",arr[i],w[arr[i]].cantidad);
		if (w[arr[i]].cantidad > 0)
		{
			pago[i] = w[arr[i]].precio * w[arr[i]].cantidad;
			printf("\n %s: \t\t\t %d \t %c %.2f", w[arr[i]].nombre, w[arr[i]].cantidad, 36, pago[i]);
		}
	}

	for (int o = 1; o < v; o++)
	{
		tot = tot + pago[o];
	}
	printf("\n");
	printf("\nEl precio total neto es: %.2f pesos mexicanos.\n", tot);
	iva = tot * 0.16;
	tot = tot + iva;
	printf("IVA       16 porciento     %.2f pesos mexicanos.\n", iva);
	printf("\nEl precio total a pagar es: %.2f pesos mexicanos.\n", tot);
	printf("\n");
	printf("Por favor indique la cantidad con la que pagara.\n");
	scanf("%f", &monto);
	cam = monto - tot;
	if (cam < 0)
	{
		printf("No agrego el monto suficiente.\n");
		printf("Se requieren %.3f pesos mexicanos mas...\n", cam * (-1.0));
	}
	else
	{
		printf("Cambio contado:  %.3f  pesos mexicanos MXN.\n", cam);
	}

	f = fopen("Ticket.txt", "w");
	if (f == NULL)
	{
		printf("\nError de apertura del archivo. \n\n");
		exit(1);
	}
	fprintf(f, "\t\t\tTiendita de tiburones blancos\n\n");
	fprintf(f, "\tProductos:\t\tCantidad:\t\tPrecio:\n");
	for (i = 1; i < v; i++)
	{
		if (w[arr[i]].cantidad > 0)
		{
			fprintf(f, "\t %s \t\t %d \t\t %c %.2f\n", w[arr[i]].nombre, w[arr[i]].cantidad, 36, pago[i]);
		}
	}
	tot = 0;
	for (int o = 1; o < v; o++)
	{
		tot = tot + pago[o];
	}
	fprintf(f, " \n");
	fprintf(f, "\n\t\t\tTotal Neto: \t\t$%.2f\n", tot);
	fprintf(f, "\t\t\tIva:\t16%c\t\t$%.2f\n", 37, iva);
	iva = tot * 0.16;
	tot = tot + iva;
	fprintf(f, "\n\t\t\tTOTAL: \t\t\t$%.2f", tot);
	fprintf(f, "\n\t\t\tPago contado: \t\t$%.2f", monto);
	fprintf(f, "\n\t\t\tCambio contado: \t$%.2f", cam);
	fprintf(f, " \n");
	fprintf(f, "\t\t\t\tGRACIAS POR SU COMPRA\n");
	fprintf(f, "\t\t\t\tVUELVA PRONTO\n");
	fclose(f);
	printf("\nSe ha impreso su ticket como 'Ticket.txt' \n");
	printf("Gracias por su compra, vuelta pronto.\n");
}

void leerProds()
{
	FILE *archivo;
	char caracter;

	archivo = fopen("catalogoproductosresumido.txt", "r");
	if (archivo == NULL)
	{
		printf("\nError de apertura del archivo. \n\n");
	}

	else
	{
		printf("\nEl contenido del catalogo es: \n");
		while ((caracter = fgetc(archivo)) != EOF)
		{
			printf("%c", caracter);
		}
	}
	fclose(archivo);
}

int ElimFinal(lista *n)
{
	int i, numero, pe;
	elem *el;
	elem *aux;
	if (n->tam == 0)
	{
		printf("No hay elementos en tu lista.\n");
		return 0;
	}
	if (n->tam == 1)
	{
		printf("Seleccione de nuevo eliminar pero al principio de la lista.\n");
		return 0;
	}
	else
	{
		numero = n->tam;
		el = n->fin;
		aux = n->inicio;
		numero = numero - 1;
		for (i = 1; i != numero; i++)
		{
			aux = aux->sig;
		}
		n->fin = aux;
		n->fin->sig = NULL;
		printf("El valor del ultimo elemento de la posicion %d ya eliminado es: %d", n->tam, el->dato);
		pe = el->dato;
		el = NULL;
		free(el);
		n->tam--;
		return pe;
	}
}

int ElimPos(lista *x, int po)
{
	int i, pe;
	elem *act;
	elem *elm;
	elem *aux;
	if (po > x->tam || po < 1)
	{
		printf("\n");
		printf("\n");
		printf("La posicion ingresada es invalida, no se encuentra en la lista.\n");
		return 0;
	}
	if (po == x->tam || po == 1)
	{
		printf("\n");
		printf("\n");
		printf("Usted esta deseando eliminar un elemento del inicio o final.\n");
		printf("Para ello, tenemos opciones para eliminar al inicio o final, intentelo de nuevo.\n");
		return 0;
	}
	else
	{
		act = x->inicio;
		for (i = 1; i < po - 1; i++)
		{
			act = act->sig;
		}
		elm = act->sig;
		act->sig = act->sig->sig;
		if (act->sig == NULL)
		{
			x->fin = act;
		}
		printf("\n");
		printf("\n");
		printf("El elemento eliminado en la posicion %d es: %d \n", po, elm->dato);
		pe = elm->dato;
		elm = NULL;
		free(elm);
		x->tam--;
		return pe;
	}
}

int ElimInicio(lista *x)
{
	int b;
	elem *el;
	elem *aux;
	if (x->tam == 0)
	{
		printf("No hay datos en la lista existentes.\n");
		return 0;
	}
	else
	{
		b = x->inicio->dato;
		el = x->inicio;
		aux = x->inicio;
		aux = aux->sig;
		x->inicio = aux;
		printf("El primer elemento de la lista que tenia como elemento: %d fue eliminado.\n", b);
		if (x->tam == 1)
		{
			x->fin = NULL;
			x->tam--;
			return b;
		}
		else
		{
			x->tam--;
			el = NULL;
			free(el);
			return b;
		}
	}
}

int InsLisVacia(lista *l, int a)
{
	elem *nue;
	nue = (elem *)malloc(sizeof(elem));
	if (nue == NULL)
	{
		return 0;
	}
	else
	{
		nue->dato = a;
		nue->sig = NULL;
		l->inicio = nue;
		l->fin = nue;
		l->tam++;
		return 1;
	}
}

int InsFinal(lista *n, int d)
{
	elem *nue;
	elem *aux;
	int i, t;
	t = n->tam;
	printf("t es %d\n", t);
	nue = (elem *)malloc(sizeof(elem));
	if (nue == NULL)
	{
		printf("Error en la asignacion de la memoria.\n");
		return 0;
	}
	else
	{
		nue->dato = d;
		aux = n->fin;
		aux->sig = nue;
		nue->sig = NULL;
		n->fin = nue;
		n->tam++;
		return 1;
	}
}

void inicializo(lista *l)
{
	l->inicio = NULL;
	l->fin = NULL;
	l->tam = 0;
}

void muestra(lista *x)
{
	int a = 1;
	elem *aux, *f;
	aux = x->inicio;
	f = x->fin;
	printf("\n");
	printf("Tu lista de compras es:\n");
	printf("---------------------\n");
	while (aux != NULL)
	{
		printf(" #   ID:   Producto:       Precio:  Cantidad:\n");
		printf(" %d - %d - %s - %.2f -   %d\n", a, aux->dato, w[aux->dato].nombre, w[aux->dato].precio, w[aux->dato].cantidad);
		printf("\n");
		a++;
		aux = aux->sig;
	}
	printf("---------------------\n");
}

void Lisarr(lista *x, int r[])
{
	int a = 1, b = 0;
	int c;
	elem *aux, *f;
	c = x->tam;
	aux = x->inicio;
	f = x->fin;
	printf("\n");
	printf("Tu lista es:\n");
	while (aux != NULL)
	{
		printf(" %d - %d \n", a, aux->dato);
		r[a] = aux->dato;
		a++;
		aux = aux->sig;
	}
	printf("\n");
	com(r, a);
	printf("Tu arreglo dinamico de lista a arreglo es:\n");
	for (int y = 1; y < (c + 1); y++)
	{
		printf("\n %d tiene numero %d\n", y, r[y]);
	}
}

void com(int a[], int x)
{
	int aux, u, w;
	int ca[5];
	for (u = 2; u < x; u++)
	{
		w = u;
		while (w > 1 && a[u] < a[w - 1])
		{
			w--;
		}
		aux = a[u];
		for (int z = u; z > w; z--)
		{
			ca[0] = a[z];
			a[z] = a[z - 1];
		}
		a[w] = aux;
	}
}
