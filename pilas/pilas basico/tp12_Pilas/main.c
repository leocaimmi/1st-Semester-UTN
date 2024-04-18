#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
///Suponiendo la existencia de una pila MODELO (vacía o no), eliminar de la pila DADA todos los elementos que existan en MODELO.



int main()
{
    Pila modelo, dada, descarte, auxD, auxM ;

    char continuar = 's';
    char finalizar = 'f';
    inicpila (&modelo);
    inicpila (&dada);
    inicpila (&descarte);
    inicpila (&auxD);
    inicpila (&aux3);
    printf("-------------------PILA MODELO----------------\n");
    do
    {

        leer(&modelo);
        printf("s para cargar valores, x letra para continuar: ");
        fflush(stdin);
        scanf("%c",&continuar);



    }
    while(continuar =='s');

    printf("-------------------PILA DADA----------------\n");

    do
    {

        leer(&dada);
        printf("f para cargar valores, x letra para continuar: ");
        fflush(stdin);
        scanf("%c", &finalizar);



    }
    while(finalizar =='f');

    mostrar(&dada);


    while(!pilavacia(&modelo) && !pilavacia(&dada))
    {
        if(tope(&dada) == tope(&modelo))
        {
            apilar(&descarte, desapilar(&dada));///aux1 es donde quedan los que son iguales en ambas pilas
        }
        else
        {
            apilar(&auxD, desapilar(&dada));

        }
        apilar(&aux3,desapilar(&modelo));


    }
    while(!pilavacia(&auxD))
    {

        apilar(&dada, desapilar(&auxD));
    }
    apilar(&auxM, desapilar(&modelo));

    printf("--------------DADA NEW--------------");
    mostrar(&dada);


    return 0;

}
