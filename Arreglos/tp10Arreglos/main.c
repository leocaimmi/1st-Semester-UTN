#include <stdio.h>
#include <stdlib.h>
/**Realizar una función que invierta los elementos de un arreglo.  (sin utilizar un arreglo auxiliar)*/

void invertirArreglo (int arreglo[], int validos);
int main()
{

 int arreglo [5] = {1,2,3,4};
 int validos = 4;

   printf("Arreglo original: ");
    for (int i = 0; i < validos; i++) {
        printf("%d ", arreglo[i]);
    }
    printf("\n");

    invertirArreglo(arreglo, validos);

    printf("Arreglo invertido: ");
    for (int i = 0; i < validos; i++) {
        printf("%d ", arreglo[i]);
    }
    printf("\n");

    return 0;
}

void invertirArreglo (int arreglo[], int validos){


int j = validos -1;
int i = 0;


while(i < j){

int aux = arreglo[i];

arreglo[i] = arreglo[j];

arreglo[j] = aux;

i++;
j--;
}


}
