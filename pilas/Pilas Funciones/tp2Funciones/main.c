#include <stdio.h>
#include <stdlib.h>
#include "../pila.h"

/// Hacer una función que pase todos los elementos de una pila a otra.


void ingresarElemento(Pila *pila);
void apilarPila(Pila *pila, Pila *aux);


int main()
{
    Pila pila, aux;
    inicpila (&pila);
    inicpila (&aux);

    ingresarElemento(&pila);

    apilarPila(&pila, &aux);

    return 0;
}

void ingresarElemento(Pila *pila)
{
    char op = 's';
    do
    {
        leer(pila);
        printf("Si desea ingresar mas valores, ingrese s o cualquier otra letra: ");
        fflush(stdin);
        scanf("%c",&op);

    }
    while(op == 's');

}


void apilarPila(Pila *pila, Pila *aux)
{

    while(!pilavacia(pila))
    {

        apilar(aux, desapilar(pila));

    }
    if (pilavacia(pila))
    {

        mostrar(pila);

    }
    mostrar(aux);
}
