#include <stdio.h>
#include <stdlib.h>
#include "../pila.h"
int main()
{
    ///Encontrar el menor elemento de una pila y guardarlo en otra. (sin variables enteras, solo pilas)Encontrar el menor elemento de una pila y guardarlo en otra. (sin variables enteras, solo pilas)
    char op = 's';
    Pila num1,menor,mayor,aux1;
    inicpila (&menor);
    inicpila (&mayor);
    inicpila (&num1);
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

    while(!pilavacia(&num1))///pregunta si tiene elementos
    {

        apilar(&menor, desapilar(&num1));///como tiene elementos apila el tope a "menor"

       while (!pilavacia(&num1)){///vuelve a preguntar si tiene contenido, como tiene contenido avanza

        if(tope(&num1)>tope(&menor))///el if pregunta, tope "num1" es mayor que tope "menor",si la rta es si, se apila en mayor, y el tope avanza a menor
        {

            apilar(&mayor, desapilar(&num1));///acumula el mayor de los topes

        }
        else
        {
            apilar(&mayor, desapilar(&menor));///descarte del que era "menor"
            apilar(&menor, desapilar(&num1));///ingresa el verdadero "menor"

        }


    }
    }


    printf("-------------PILA 1(VACIA)--------------\n");
    mostrar(&num1);
    printf("-------------PILA MAYOR---------------------\n");
    mostrar(&mayor);
    printf("-------------PILA MENOR----------------------\n");
    mostrar(&menor);



    return 0;
}
