#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
///Comparar la cantidad de elementos de las pilas A y B. Mostrar por pantalla el resultado.

int main()
{

    Pila pilaA, pilaB, aux1, aux2;
    char continuar = 's';
    char finalizar = 'f';
    inicpila (&pilaA);
    inicpila (&pilaB);
    inicpila (&aux1);
    inicpila (&aux2);

    do{

        leer(&pilaA);
        fflush(stdin);
        printf("para seguir ingresando valores en A ingrese s: ");
        scanf("%c",&continuar);



    }while (continuar == 's');

    printf("--------------------------------------------------\n");
    printf("-------------------- pila B ---------------------- \n");
      do{

        leer(&pilaB);
        fflush(stdin);
        printf("para seguir ingresando valores en B ingrese F: ");
        scanf("%c",&finalizar);


    }while (finalizar == 'f');


    while(!pilavacia(&pilaA)&& !pilavacia(&pilaB)){

        apilar(&aux1, desapilar(&pilaA));
        apilar(&aux2, desapilar(&pilaB));


    }

    printf("-----------------------------------------------------------\n");
    printf("----------------COMPARACION  ------------------------------\n");

if(pilavacia(&pilaA)&& pilavacia(&pilaB)){
    printf("la cantidad de elementos son iguales");



}else if (!pilavacia(&pilaA)){

printf("La pila A tiene mas cantidad de elementos");


}else if(!pilavacia(&pilaB)){

printf("La pila B tiene mas cantidad de elementos");




}




    return 0;
}
