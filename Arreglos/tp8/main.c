#include <stdio.h>
#include <stdlib.h>

/// Realizar una función que obtenga el máximo carácter de un arreglo dado

void obtenerMayor(char arr[], int validos);

int main() {

    char arr[5] = {'k', 'p', 't', 'q'};
    int validos = 4;
    obtenerMayor(arr, validos);
    return 0;
}

void obtenerMayor(char arr[], int validos){


    char mayor = arr[0];
    for(int i= 0; i<validos;i++){
        if (mayor < arr[i]){

            mayor = arr[i];
        }
    }


    printf("letra mayor: %c", mayor);
}
