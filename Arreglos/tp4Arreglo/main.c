#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
/**Hacer una función que reciba como parámetro un arreglo, la cantidad de elementos (válidos) cargados en él y una Pila.
 La función debe copiar los elementos del arreglo en la pila. */

int mostrarValidos(int arreglo[], int dimension);
void cargarPila(int arreglo[],int validos,int dimension, Pila* pila);

int main()
{
    Pila pila;
    inicpila(&pila);

    int arreglo[10];
    int dimension = 10;
    int sum=0;
    int validos= mostrarValidos(arreglo, dimension);
    printf("validos: %i \n", validos);


    cargarPila(arreglo,validos, dimension,&pila);



    return 0;
}
int mostrarValidos(int arreglo[], int dimension)
 {
     char op = 's';
    int i= 0;
    while (op == 's' && i < dimension){
        printf("Ingrese un numero\n");
        scanf("%i", &arreglo[i]);
        i++;
        printf("Desea continuar? s/n\n");
        fflush(stdin);
        scanf("%c", &op);
    }
    return i;
 }
void cargarPila(int arreglo[],int validos,int dimension, Pila* pila){



for (int i = 0; i< validos; i++){

   apilar(pila,arreglo[i]);
    }

mostrar(pila);

}
