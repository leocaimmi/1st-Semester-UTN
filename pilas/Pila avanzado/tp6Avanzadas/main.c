#include <stdio.h>
#include <stdlib.h>
#include "../pila.h"
///Usando lo resuelto en el ejercicio 4, pasar los elementos de una pila a otra de forma tal que la segunda pila quede ordenada de mayor (tope) a menor (base).
///Esto se llama método de ordenación por selección.


int main()
{
    char op = 's';
    Pila num1,menor,mayor,aux;
    inicpila (&menor);
    inicpila (&mayor);
    inicpila (&num1);
    inicpila(&aux);
    printf("----------ingrese sus elementos------------- \n");
    do
    {

        leer(&num1);
        printf("ingrese sus elementos");
        printf("'s' para seguir o 'x' para finalizar: ");
        fflush(stdin);
        scanf("%c",&op);

    }
    while(op == 's');

    while(!pilavacia(&num1))
    {

        apilar(&menor, desapilar(&num1));

        while (!pilavacia(&num1))
        {
            if(tope(&num1)>tope(&menor))
            {

                apilar(&mayor, desapilar(&num1));

            }
            else
            {
                apilar(&mayor, desapilar(&menor));
                apilar(&menor, desapilar(&num1));

            }


        }


    }
    while(!pilavacia(&mayor))
    {
        apilar(&aux, desapilar(&mayor));
        while(!pilavacia(&aux))
        {
            if(tope(&mayor) < tope(&aux))
            {
                apilar(&menor, desapilar(&mayor));

            }else{

            apilar(&menor, desapilar(&aux));
            }


        }


    }



    printf("-------------PILA 1(VACIA)--------------\n");
    mostrar(&aux);
    printf("-------------PILA MAYOR---------------------\n");
    mostrar(&mayor);
    printf("-------------PILA MENOR----------------------\n");
    mostrar(&menor);



    return 0;
}
