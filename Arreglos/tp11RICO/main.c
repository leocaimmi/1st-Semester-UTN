#include <stdio.h>
#include <stdlib.h>

void ordenarInsercion(int arreglo[], int validos);
void insercion(int arreglo[],int ultimaPos, int dato);
void showArray(int arreglo[],int validos, char op);
int cargarArreglo(int arreglo[],int dimension);
void ordenamientoSeleccion(int array[], int validos);
int findMinIndex(int array[], int validos, int firstPos);
void mostrarArreglo(int arreglo[],int validos);

int main()
{
    int arreglo[100];
    int dimension=100;
    char op;


    int validos = cargarArreglo(arreglo,dimension);

    showArray(arreglo, validos,op);


    return 0;
}

int  cargarArreglo(int arreglo[],int dimension){
int i = 0;
char op = 's';
while(i < dimension && op == 's'){

printf("Ingrese un valor al array: ");
scanf("%i",&arreglo[i]);
i++;

printf("(s)aniadir | (n)finalizar \n");
fflush(stdin);
scanf("%c",&op);
}
return i;
}

void mostrarArreglo(int arreglo[],int validos){
for(int i = 0;i<validos;i++)
   printf("sus valoren cargados en la posicion %i son: (%i)\n",i,arreglo[i]);

}



void showArray(int arreglo[],int validos,char op){

    printf("ingrese s(seleccion)/i(insercion)");
    fflush(stdin);
    scanf("%c",&op);


switch(op){

    case 'i':
printf("------------------------------VALORES ORIGINALES-------------------------------\n\n");

   mostrarArreglo(arreglo,validos);

 printf("------------------------------INSERCION---------------------------------------\n\n");
 ordenarInsercion(arreglo,validos);
 mostrarArreglo(arreglo,validos);

break;

case 's':
printf("------------------------------VALORES ORIGINALES-------------------------------\n\n");

   mostrarArreglo(arreglo,validos);

 printf("------------------------------SELECCION---------------------------------------\n\n");

    ordenamientoSeleccion(arreglo,validos);
   mostrarArreglo(arreglo,validos);

break;
default :
    printf("error");

}
}

int findMinIndex(int array[], int validos, int firstPos) {
    int minIndex = firstPos; /// seteamos un indice para comparar
    for (int i = firstPos + 1; i < validos; i++)
        if (array[minIndex] > array[i]) // si el menor es mayor algo es mentira
            minIndex = i; // vas a comparar a partir de este valor
    return minIndex;

}

void ordenamientoSeleccion(int array[], int validos) {
    for (int i = 0; i < validos - 1; i++) {
        int minPos = findMinIndex(array, validos, i);

        int temp = array[i]; // no perder referencia al valor
        array[i] = array[minPos];
        array[minPos] = temp;


    }
}


void ordenarInsercion(int arreglo[], int validos)
{
    int i = 0;
    for(i;i<validos-1;i++)
        insercion(arreglo,i,arreglo[i+1]);
}

void insercion(int arreglo[],int ultimaPos, int dato)
{
   int i = ultimaPos;

   for(i;i>=0 && dato < arreglo[i]; i--)
    arreglo[i + 1] = arreglo[i];

       arreglo[i+1] = dato;
}
