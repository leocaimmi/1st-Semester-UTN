#include <stdio.h>
#include <stdlib.h>
#include "../pila.h"
/// Suponiendo la existencia de una pila LÍMITE, pasar los elementos de la pila DADA que sean mayores o iguales que el tope de LIMITE a la pila MAYORES,
///y los elementos que sean menores a la pila MENORES.

int main()
{
    Pila LIMITE, DADA, MAYORES, MENORES;

    char continuar = 's';
    char finalizar = 'f';
    inicpila(&LIMITE);
    inicpila(&DADA);
    inicpila(&MAYORES);
    inicpila(&MENORES);

    printf("-------------PILA LIMITE-----------------\n");

    do
    {

        leer(&LIMITE);

        printf("s para seguir ingresando valores: ");
        fflush(stdin);
        scanf("%c",&continuar);

    }
    while(continuar == 's');

    printf("-------------PILA DADA-----------------\n");
    do
    {

        leer(&DADA);
        fflush(stdin);
        printf("f para seguir ingresando valores: ");
        fflush(stdin);
        scanf("%c",&finalizar);


    }
    while(finalizar == 'f');

/// Suponiendo la existencia de una pila LÍMITE, pasar los elementos de la pila DADA que sean mayores o iguales que el tope de LIMITE a la pila MAYORES,
///y los elementos que sean menores a la pila MENORES.

    while (!pilavacia(&DADA))
    {

        if (tope(&DADA)>= tope(&LIMITE))
        {

            apilar(&MAYORES, desapilar(&DADA));

        }
        else
        {

            apilar(&MENORES,desapilar(&DADA));

        }


    }
    printf("-------------PILA LIMITE-----------------\n");
    mostrar(&LIMITE);
    printf("-------------PILA MAYORES-----------------\n");
    mostrar(&MAYORES);
    printf("-------------PILA MENORES-----------------\n");
    mostrar(&MENORES);
    return 0;
}
