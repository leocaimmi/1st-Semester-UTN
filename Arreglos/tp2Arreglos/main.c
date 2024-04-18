#include <stdio.h>
#include <stdlib.h>
///Hacer una función que reciba como parámetro un arreglo y
///la cantidad de elementos (válidos) cargados en él y los muestre por pantalla.

int mostrarValidos(int arreglo[], int dimension);

int main()
{
    int arreglo[10];
    int dimension = 10;
    int validos= mostrarValidos(arreglo, dimension);
    printf("validos: %i \n", validos);

    for (int i = 0; i< validos; i++){
        printf ("arreglo [%i] = %i \n", i , arreglo[i]);
    }
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
