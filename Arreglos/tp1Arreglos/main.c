#include <stdio.h>
#include <stdlib.h>
/**1.Hacer una función que reciba como parámetro un arreglo de números enteros
y permita que el usuario ingrese valores al mismo por teclado.
La función debe retornar la cantidad de elementos cargados en el arreglo (o pueden utilizar como puntero válidos).**/


int cargarArreglo(int arreglo[], int dimension);

int main()
{
    int arreglo[10];
    int dimension = 10;
    int validos= cargarArreglo(arreglo, dimension);
    printf("validos: %i", validos);
    return 0;
}

int cargarArreglo(int arreglo[], int dimension){
    char op = 's';
    int i= 0;
    while (op == 's' && i < dimension){
        printf("Ingrese sus numero: \n");
        scanf("%i", &arreglo[i]);
        printf("Desea continuar? s/n\n");
        fflush(stdin);
        scanf("%c", &op);
        i++;
    }
    return i;

}
