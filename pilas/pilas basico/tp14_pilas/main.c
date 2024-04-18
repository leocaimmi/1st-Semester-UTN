#include <stdio.h>
#include <stdlib.h>
#include "../pila.h"


/// 14. Determinar si la cantidad de elementos de la pila DADA es par.
///Si es par, pasar el elemento del tope de la pila AUX a la pila PAR y si es impar pasar el tope a la pila IMPAR.
/// (NO contar los elementos)

int main()
{
    Pila dada,par,impar,aux;

    inicpila(&dada);
    inicpila(&par);
    inicpila(&impar);
    inicpila(&aux);

    leer(&dada);

    leer(&dada);


/// 14. Determinar si la cantidad de elementos de la pila DADA es par.
/// Si es par, pasar el elemento del tope de la pila AUX a la pila PAR y si es impar pasar el tope a la pila IMPAR.
/// (NO contar los elementos)

    while(!pilavacia(&dada)){

        apilar(&aux, desapilar(&dada));
        if(!pilavacia (&dada)){
            apilar(&aux, desapilar(&dada));
        } else {
            apilar(&impar, desapilar(&aux));
        }
    }

    if(!pilavacia(&impar)){
        printf("Es impar");
    } else {
        apilar(&par, desapilar(&aux));
        printf("eSS par");
        mostrar(&aux);
    }


    return 0;
}
