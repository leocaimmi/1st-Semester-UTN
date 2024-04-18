#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
///Verificar si una pila DADA es capicúa.

int main()
{
    Pila dada, comparar, aux;
    char continuar = 's';
    int topeCapi;
    inicpila (&dada);
    inicpila (&comparar);
    inicpila (&aux);

    do
    {

        leer(&dada);
        printf("ingrese 'S' para 'X' para finalizar: ");
        fflush(stdin);
        scanf("%c",&continuar);


    }
    while(continuar == 's');



    while(!pilavacia(&dada))
    {

        topeCapi = tope(&dada);
        apilar(&aux, topeCapi);
        apilar(&comparar, desapilar(&dada));


    }

    while(!pilavacia(&comparar))
    {

        apilar(&dada, desapilar(&comparar));

    }if (tope(&dada)== tope(&aux)){

        printf("Tu numero es capicua");

    }else{

    printf("Tu numero NO ES capicua");
    }

mostrar(&dada);
mostrar(&comparar);
mostrar(&aux);

    return 0;
}
