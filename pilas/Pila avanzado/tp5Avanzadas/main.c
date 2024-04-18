#include <stdio.h>
#include <stdlib.h>
#include "../pila.h"

/// Insertar un elemento en una pila ordenada de menor (tope) a mayor (base) de forma tal que se conserve el orden.
/// (Sin variables enteras, solo pilas)

int main()
{
    Pila valor, aux, num1;

    inicpila(&aux);
    inicpila(&valor);
    inicpila(&num1);

    apilar(&num1, 5);
    apilar(&num1, 4);
    apilar(&num1, 2);
    apilar(&num1, 1);


    apilar(&valor, 3);
    while(!pilavacia(&num1))
    {
        if(!pilavacia(&valor))
        {
            if(tope(&num1) > tope(&valor))
            {
                apilar(&aux, desapilar(&valor));
            }
        }

        apilar(&aux, desapilar(&num1));


    }


    while(!pilavacia(&aux))
    {
        apilar(&num1, desapilar(&aux));
    }


    mostrar(&num1);
    return 0;
}
