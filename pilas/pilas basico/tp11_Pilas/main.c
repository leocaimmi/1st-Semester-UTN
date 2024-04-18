#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
///. Suponiendo la existencia de una pila MODELO que no esté vacía, eliminar de la pila DADA todos los elementos que sean iguales al tope de la pila MODELO.

int main()
{
    Pila modelo, dada, aux1, aux2;

    inicpila (&modelo);
    inicpila (&dada);
    inicpila (&aux1);

    leer(&modelo);
    leer(&dada);
    leer(&dada);
    leer(&dada);
    leer(&dada);
    leer(&dada);
    leer(&dada);



    while(!pilavacia(&dada)&& !pilavacia(&modelo)){

        if (tope(&dada)!=tope(&modelo)){
             apilar(&aux1, desapilar(&dada));


          }else{
          desapilar(&dada);
          }
    }
      while(!pilavacia(&aux1)){
        apilar(&dada, desapilar(&aux1));

      }



    printf("----------------------pila MODELO-------------------------");
    mostrar(&modelo);
    printf("----------------------pila DADA-------------------------");
    mostrar(&dada);







    return 0;
}
