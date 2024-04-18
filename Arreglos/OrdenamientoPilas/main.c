#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

void cargarPila(Pila* a);
void insertar(Pila* dada, Pila* datos);
void ordenamientoXInsercion(Pila* dada, Pila*dato);
int main()
{
Pila dada,datos;
inicpila (&dada);
inicpila (&datos);

    cargarPila(&datos);

    printf("valor por insercion: \n");
    leer(&datos);

    //insertar(&dada,&datos);
    ordenamientoXInsercion(&dada,&datos);

    mostrar(&dada);
    return 0;
}

void cargarPila(Pila* datos){
char op = 's';

do{

leer(datos);
printf("s/n para cargar o finalizar");
fflush(stdin);
scanf("%c",&op);


}while(op == 's'||op == 'S');

}

void insertar(Pila* dada, Pila* datos){

Pila aux;
inicpila(&aux);

while(!pilavacia(dada)&& tope(dada) > tope(datos)){

        apilar(&aux,desapilar(dada));
    }
    apilar(dada,desapilar(datos));

while(!pilavacia(&aux)){
apilar(dada,desapilar(&aux));
}
}

void ordenamientoXInsercion(Pila* dada, Pila*datos){

while(!pilavacia(datos)){

        insertar(dada,datos);
    }
}



