#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

///Dadas dos pilas A y B que simulan conjuntos (cada conjunto no tiene elementos repetidos sobre sí mismo), realizar un programa que calcule en la pila C la operación de unión.
///A : base 1 2 3  tope
///B: base 2 3 5 7 tope
///Pila AUB = base 3 2 1 7 5 tope

int main()
{
    Pila A, B,auxA, repetidos, conjunto, unionAUB;
    char continuar = 's';
    char finalizar = 'f';
    inicpila(&A);
    inicpila(&B);
    inicpila(&unionAUB);
    inicpila(&repetidos);
    inicpila(&conjunto);

    printf("-----------PILA A------------\n");

    do
    {
        leer(&A);
        printf("ingrese 's' para continuar, 'X' para finalizar: ");
        fflush(stdin);
        scanf("%c",&continuar);


    }
    while(continuar == 's');

    printf("-----------PILA B------------\n");
    do
    {
        leer(&B);
        printf("ingrese 'f' para continuar, 'X' para finalizar: ");
        fflush(stdin);
        scanf("%c",&finalizar);


    }
    while(finalizar == 'f');


    while(!pilavacia(&A))
    {

        while(!pilavacia(&B))
        {

            if(tope(&A) == tope(&B))
            {

                apilar(&repetidos,desapilar(&B));

            }
            else
            {

               apilar(&conjunto, desapilar(&B));

            }


        }

        apilar(&conjunto, desapilar(&A));

        while(!pilavacia(&conjunto))
        {

            apilar(&B, desapilar(&conjunto));

        }


    }
    while(!pilavacia(&B))
{

    apilar(&conjunto, desapilar(&B));
}




    mostrar(&conjunto);

    mostrar(&repetidos);


    return 0;
}
