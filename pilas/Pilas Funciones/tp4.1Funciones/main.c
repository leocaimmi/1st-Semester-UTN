#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
///Hacer una función que encuentre el menor elemento de una pila y lo retorna. La misma debe eliminar ese dato de la pila.
void cargarValores(Pila *valores);
void encontrarMenor(Pila *pila);


int main()
{
    Pila pila;
    inicpila(&pila);



    cargarValores(&pila);
    encontrarMenor(&pila);

    return 0;
}

void cargarValores(Pila *valores)
{

    char continuar = 's';
    do
    {

        leer(valores);
        printf("'s' para continuar, 'x' para finalizar");
        fflush(stdin);
        scanf("%c",&continuar);


    }
    while(continuar == 's');


}




void encontrarMenor(Pila *pila)
{


    Pila aux;

    inicpila(&aux);
    int menor;


    while(!pilavacia(pila))
    {

        menor = tope(pila);
        while(!pilavacia(pila))
        {

            apilar(&aux, desapilar(pila));
            if(menor > tope(&aux))
            {
                menor = tope(&aux);
                apilar(pila, desapilar(&aux));

            }

        }

    }

    printf("%i",menor);

}
