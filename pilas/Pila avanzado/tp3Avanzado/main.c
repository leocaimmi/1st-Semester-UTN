#include <stdio.h>
#include <stdlib.h>
#include "../pila.h"
int main()
{
   ///Calcular el promedio de los valores de una pila (usar variables)
    char op = 's';
   int contador = 0;
   Pila num1, aux1;
   inicpila (&num1);
   float promedio = 0;
   int suma = 0;
  printf("-------------ingreso de datos para promediar-------------\n");
   do{

    leer(&num1);
    suma += tope(&num1);
    contador++;
    printf("ingrese valores para promediar en su pila: \n");
    printf("'s' para seguir 'x' para promediar: \n");
    fflush(stdin);
    scanf("%c",&op);

   }while(op == 's');

printf("---------------PROMEDIO HERE DOWN--------------------\n");
   promedio = (float) suma/contador;

   printf("su promedio es de: %.2f",promedio);


    return 0;
}
