#include <stdio.h>
#include <stdlib.h>

/**Realizar una función que indique si un elemento dado se encuentra en un arreglo de caracteres. */

int encontrarElemento(char arr[]);

int main() {

   char arr[24] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

    int encontrar = encontrarElemento(arr);

    return 0;
}

int encontrarElemento(char arr[])
{
    int i = 0;
    for (i = 0; i<24; i++){
        printf(" CARACTERES: %c \n", arr[i]);
        if(arr[i] == 's'){
            printf("Elemento encontrado: %c\n", arr[i]);
    break;
        }

    }
    return i;
}
