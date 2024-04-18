#include <stdio.h>
#include <stdlib.h>
#include"../pila.h"

///Contar los elementos de una pila (usar variables enteras)
int main()
{
   char op = 's';
   int contador = 0;
   Pila pilita;
   inicpila (&pilita);

   do{

    leer(&pilita);
    contador++;
    printf("ingrese sus elementos enteros\n");
    printf("Para seguir : 's' o 'x' para finalizar: ");
    fflush(stdin);
    scanf("%c",&op);


   }while(op == 's');

printf("La cantidad de elementos son:  %i",contador);









    return 0;
}
