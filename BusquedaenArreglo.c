/*
Autor: AngelChetosmen
Consultar la Licencia del Autor | Derechos Reservados EUVA B&T ©
*/
#include <stdio.h>
#include <string.h>
#define MAX_SIZE 150

int main()
{
    char str[MAX_SIZE];
    char word[MAX_SIZE];
    int i, j, found;
    int strLen, wordLen;

    printf("Ingrese la primer cadena: ");
    gets(str);
    printf("Ingrese la palabra a buscar: ");
    gets(word);

    strLen = strlen(str);
    wordLen = strlen(word);

    for (i = 0; i < strLen; i++)
    {

        found = 1;
        for (j = 0; j < wordLen; j++)
        {
            if (str[i + j] != word[j])
            {
                found = 0;
                break;
            }
        }
        if (found == 1)
        {
            printf("'%s' se encontro en la posicion:", word);
            printf("%d \n", i);
        }
    }

    return 0;
}
