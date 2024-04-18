#include <stdio.h>
#include <stdlib.h>

/**Se cuenta con un arreglo de n�meros enteros que ya fue cargado, se pide hacer una funci�n que copie los datos de todos
los valores del arreglo anterior que sean pares en otro arreglo del tama�o justo.
Usar malloc dentro de la funci�n y retornar el arreglo o usar dos par�metros de tipo arreglo y crear el arreglo din�mico antes de la invocaci�n.
Desarrolle las funciones que considere necesarias,por ejemplo, una funci�n que cuente la cantidad de elementos pares y otra para el traspaso de los elementos.*/


int encontrarPares(int arreglo[],int pares[],int validos);
int* arrDinamico(int tam);
void pasarPares(int* dinamico,int pares[],int tam);

int main()
{
    int arreglo[10] = {1,2,3,4,5,6,7,8,9,10};
    int pares[10] = {0};
    int validos = 10;

    int tam = encontrarPares(arreglo,pares,validos);

    int* dinamico = arrDinamico(tam);
    pasarPares(dinamico, pares, tam);

    for(int i = 0; i<tam; i++)
    {
        printf("%i\n",dinamico[i]);

    }

    return 0;
}

int encontrarPares(int arreglo[],int pares[],int validos)
{
    int i = 0;
    int j = 0;
    while(i<validos)
    {
        if(i%2 == 1)
        {
            pares[j]= arreglo[i];
            j++;
        }
        i++;
    }
    return j;
}

int* arrDinamico(int tam)
{
    int* dinamico = malloc(sizeof(int)*tam);
    return dinamico;
}

void pasarPares(int* dinamico,int pares[],int tam)
{
int i = 0;
    while(i<tam ){

        dinamico[i] = pares[i];
    i++;
    }
}
