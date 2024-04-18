#include <stdio.h>
#include <stdlib.h>

const int DIM_MAX= 30;

int cargarArreglo(int arreglo[],int dimension);
int menorPosicion(int arreglo[],int validos, int primeraPos);
void ordenarSeleccion(int arreglo[], int validos);
void showArray(int arreglo[],int validos);
void insertar(int arreglo[],int validos,int dato);
int cargarInsercion(int arreglo[]);
int main()

{

    int arreglo[DIM_MAX];


    ///int validos = cargarArreglo(arreglo,dimension);
    /**int menor = menorPosicion(arreglo, validos,0);
    ordenarSeleccion(arreglo, validos);*/
    ///int validos = cargarInsercion(arreglo);


    showArray(arreglo,validos);
    return 0;
}

int cargarArreglo(int arreglo[],int dimension)
{

    char op = 's';
    int i = 0;

    while(i<dimension && op == 's')
    {

        printf("Agregue valores al arreglo: ");
        scanf("%i",&arreglo[i]);


        printf("s/n para continuar o finalizar\n");
        fflush(stdin);
        scanf("%c",&op);

        i++;
    }

    return i;
}

int menorPosicion(int arreglo[],int validos, int primeraPos)
{
    int menorPos = primeraPos;

    for(int i = primeraPos; i<validos; i++)
    {
        if(arreglo[i]<arreglo[menorPos])
        {
            menorPos = i;
        }
    }

    return menorPos;
}

void ordenarSeleccion(int arreglo[], int validos)
{

    int aux;
    int menor;

    for(int i = 0; i<validos; i++)
    {
       int menor = menorPosicion(arreglo,validos,i);

        aux = arreglo[i];
        arreglo[i] = arreglo[menor];
        arreglo[menor] = aux;

    }

}

void showArray(int arreglo[],int validos){

for(int i = 0;i<validos;i++){
    printf("su arreglo en la pos %i: %i\n",i,arreglo[i]);
}
}

void insertar(int arreglo[],int validos,int valor){


int i = validos - 1;
while(i>= 0 && arreglo[i] > valor){

   arreglo[i+ 1] = arreglo[i];

 i--;
    }
    arreglo[i + 1] = valor;
}

int cargarInsercion(int arreglo[]){

int valor;
char op;
int i = 0;
do{
    printf("que valores desea agregar: ");
    scanf("%i",&valor);

    insertar(arreglo,i,valor);
    i++;

    printf("s/n para continuar o finalizar\n");
    fflush(stdin);
    scanf("%c",&op);

}while(i<DIM_MAX && op == 's');

return i;
}

