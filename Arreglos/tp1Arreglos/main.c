#include <stdio.h>
#include <stdlib.h>
/**1.Hacer una funci�n que reciba como par�metro un arreglo de n�meros enteros
y permita que el usuario ingrese valores al mismo por teclado.
La funci�n debe retornar la cantidad de elementos cargados en el arreglo (o pueden utilizar como puntero v�lidos).**/


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
