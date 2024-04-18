#include <stdio.h>
#include <stdlib.h>
/** Realizar una función que sume los elementos de un arreglo de números reales (float) de dimensión 100.
(se recomienda hacer una función para cargar y otra para mostrar para este tipo de dato asociado al arreglo)*/


int cargarArreglo(float arreglo[],int dimension);
float sumarValidos(float arreglo[],int validos);
void mostrarArregloFloat(float arr[], int validos);

int main()
{
    float arreglo[100];
    int dimension = 100;
    int validos = cargarArreglo( arreglo, dimension);
    mostrarArregloFloat(arreglo , validos);

    float suma = sumarValidos(arreglo,validos);

    printf("El resultado de la suma del arreglo float es %.2f \n", suma);
    return 0;
}

int cargarArreglo(float arreglo[],int dimension)
{

    char continuar = 's';

    int i = 0;

    while(continuar == 's'&&i <dimension)
    {

        printf("ingrese un numero ");
        scanf("%f",&arreglo[i]);
        i++;
        printf("'s' para continuar, 'x' para finalizar\n");
        fflush(stdin);
        scanf("%c",&continuar);


    }
    printf("los numeros validos son: = %i \n",i);

    return i;
}

float sumarValidos(float arreglo[],int validos)
{

    float suma = 0;
    for(int i = 0; i<validos; i++)
    {

        suma+=arreglo[i];

    }
    return suma;
}


void mostrarArregloFloat(float arr[], int validos)
{
    printf("El arreglo float\n");
    for(int i = 0; i < validos ; i++)
    {
        printf("arr(%i) = %.2f \n", i, arr[i]);
    }
}

