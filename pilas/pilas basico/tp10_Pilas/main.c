#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
///Cargar las pilas A y B, y luego compararlas, evaluando si son completamente iguales (en cantidad de elementos, valores que contienen y posición de los mismos).
///Mostrar por pantalla el resultado.


int main()
{
    Pila pilaA, pilaB, aux1, aux2;
    char continuar = 's';
    char finalizar = 'f';
    inicpila (&pilaA);
    inicpila (&pilaB);
    inicpila (&aux1);
    inicpila (&aux2);

    do
    {

        leer(&pilaA);
        fflush(stdin);
        printf("para seguir ingresando valores en A ingrese s: ");
        scanf("%c",&continuar);



    }
    while (continuar == 's');

    printf("--------------------------------------------------\n");
    printf("-------------------- pila B ---------------------- \n");
    do
    {

        leer(&pilaB);
        fflush(stdin);
        printf("para seguir ingresando valores en B ingrese F: ");
        scanf("%c",&finalizar);


    }
    while (finalizar == 'f');

    mostrar(&pilaA);
    mostrar(&pilaB);



    while(!pilavacia(&pilaA)&& !pilavacia(&pilaB) && tope(&pilaA) == tope(&pilaB))
    {

        apilar(&aux1, desapilar(&pilaA));

        apilar(&aux2, desapilar(&pilaB));





    }

     if(tope(&aux1) != tope(&aux2))
        {

            printf("sus valores tienen mismo tope\n");
        }else{

        printf("sus valores tienen distinto tope\n");
        }



    printf("----------------------------------------------------------\n");
    printf("----------------COMPARACION  ------------------------------\n");

    if(pilavacia(&pilaA)&& pilavacia(&pilaB))
    {
        printf("la cantidad de elementos son iguales");



    }
    else if (!pilavacia(&pilaA))
    {

        printf("La pila A tiene mas cantidad de elementos");


    }
    else if(!pilavacia(&pilaB))
    {

        printf("La pila B tiene mas cantidad de elementos");




    }
    mostrar(&aux1);
    mostrar(&aux2);

    return 0;
}
