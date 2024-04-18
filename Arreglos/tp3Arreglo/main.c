#include <stdio.h>
#include <stdlib.h>
/**Hacer una función que reciba como parámetro un arreglo y la cantidad de elementos (válidos) cargados en él
y calcule la suma de sus elementos.*/

int mostrarValidos(int arreglo[], int dimension);
int sumaValores(int arreglo[],int validos,int dimension);
int main()
{
    int arreglo[10];
    int dimension = 10;
    int sum=0;
    int validos= mostrarValidos(arreglo, dimension);
    printf("validos: %i \n", validos);

    int suma = sumaValores(arreglo,validos, dimension);

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
int sumaValores(int arreglo[],int validos,int dimension){

int suma = 0;

for (int i = 0; i< validos; i++){
    printf ("arreglo [%i] = %i \n", i , arreglo[i]);
        suma += (float)arreglo[i];
    }
    printf("La suma de los elementos del arreglo es: %i", suma);

return suma;
}
