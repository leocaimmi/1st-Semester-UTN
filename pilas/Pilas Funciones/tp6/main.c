#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

/// 6. Hacer una función que inserta en una pila ordenada un nuevo elemento, conservando el orden de ésta.


void pilaOrdenada(Pila *pila, Pila *num);

int main()
{

    Pila pila;
    inicpila(&pila);
    Pila num;
    inicpila(&num);
    apilar(&pila, 5);
    apilar(&pila, 4);
    apilar(&pila, 3);
    printf("Ingrese el numero: \n");

    leer(&num);

    pilaOrdenada(&pila, &num);



    return 0;
}


void pilaOrdenada(Pila *pila, Pila *num)
{
    Pila aux, aux2;
    inicpila(&aux);
    inicpila(&aux2);
    int flag = 0 ;
    int numero = tope(num);
    while(!pilavacia(pila))
    {
        apilar(&aux, desapilar(pila));

        while(!pilavacia(&aux))
        {
            if(tope(&aux) > tope(num))
            {
                apilar(&aux2, desapilar(num));
                apilar(&aux2, desapilar(&aux));
            }
            else
            {

                apilar(&aux2, desapilar(&aux));

            }


        }

    }



 apilar(&aux2, numero);
//mostrar(num);
//mostrar(&aux2);
 apilar(&aux2,numero);


    while(!pilavacia(&aux2))
    {




        apilar(pila, desapilar(&aux2));


        if(tope(pila) == numero && flag == 0)
        {
            desapilar(pila);
            flag = 1;

        }else if (pila) == numero && flag == 0)
        {
            desapilar(pila);
            flag = 1;


    }
}
mostrar(&aux2);
mostrar(pila);



}
