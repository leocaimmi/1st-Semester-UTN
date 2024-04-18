#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int main()
{

    ///Sumar los elementos de una pila (usar variables enteras)

    Pila num1,aux1  ;

    inicpila(&num1);
    inicpila(&aux1);

    int suma = 0;


    leer(&num1);
    leer(&num1);

    for(int i = 0; i<2; i++)
    {

    apilar(&aux1, desapilar(&num1));
    suma += tope(&aux1 );


    }

printf("su suma es %i",suma);
mostrar(&aux1);















    return 0;
}
