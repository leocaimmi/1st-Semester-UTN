#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
///Hacer una función que permita ingresar varios elementos a una pila, tanto como quiera el usuario.

void ingresarElemento (Pila *pila);

int main(){

    Pila pila;
    inicpila(&pila);
    ingresarElemento(&pila);
    mostrar(&pila);
    return 0;
}

void ingresarElemento(Pila *pila){
    char op = 's';
    do {
        leer(pila);
        printf("Si desea ingresar mas valores, ingrese s o cualquier otra letra: ");
        fflush(stdin);
        scanf("%c",&op);

    } while(op == 's');
}
