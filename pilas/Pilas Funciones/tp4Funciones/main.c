#include <stdio.h>
#include <stdlib.h>
#include "pila.h"


/// Hacer una función que encuentre el menor elemento de una pila y lo retorna. La misma debe eliminar ese dato de la pila.


int menorElemento(Pila* pila);

int main()
{

    Pila pilita;
    inicpila(&pilita);
    leer(&pilita);
    leer(&pilita);
    leer(&pilita);
    int menorAFull = menorElemento(&pilita);
    printf("Tu menor es : %i", menorAFull);


    return 0;
}


int menorElemento(Pila* pila)
{

    Pila aux;
    inicpila(&aux);
    int menor = tope(pila);
    int flag = 0;
    while(!pilavacia(pila)) // busca el menor de la pila
    {
        if(menor > tope(pila))
        {
            menor = tope(pila);
        }
        apilar(&aux, desapilar(pila));
    }

    //ya tenemos el menor

    while(!pilavacia(&aux))
    {
        if (tope(&aux) == menor && flag == 0)
        {
            desapilar(&aux);
            flag = 1;
        }
        else
        {
            apilar(pila, desapilar(&aux));
        }

    }

    return menor;
}
