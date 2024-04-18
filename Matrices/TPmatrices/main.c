#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int DIMMAX =  2;
const int MAXCOL = 2;

const int DIM_MAXC =  20;
const int MAX_COLC = 20;

/*void cargarMatriz(int matriz[DIMMAX][MAXCOL]);
void mostrarMatriz(int matriz[DIMMAX][MAXCOL],int suma, float promedio);
void cargarMatrizDeEnteros( int matriz[DIMMAX][MAXCOL]);
void matrizRandom(int matriz[DIMMAX][MAXCOL]);
int suma(int matriz[DIMMAX][MAXCOL]);
float promedio(int matriz[DIMMAX][MAXCOL]);
int encontrarDato(int matriz[DIMMAX][MAXCOL],int dato);*/

int cargarArregloDeCaracteres(char matrizCaracteres[DIM_MAXC][MAX_COLC]);
void mostrarArreglo (char matrizCaracteres[DIM_MAXC][MAX_COLC], int validos);
//int encontrarPalabra(char matrizPalabra[DIM_MAXC][MAX_COLC],int validos,char dato[]);
//void cargarUnDato(char dato[]);
void mostrarPalabraEncontrada(int dato);

void insetarPalabra(char matrizPalabra[DIM_MAXC][MAX_COLC],int validos,char dato[]);
void ordenarPalabras(char matrizPalabra[DIM_MAXC][MAX_COLC],int validos);
int main()
{
    //srand(time(NULL));

    int matriz[DIMMAX][MAXCOL];
    char matrizCaracteres[DIM_MAXC][MAX_COLC];
    char datoPalabra[DIM_MAXC];
    int dato = 0;
    /*cargarMatriz( matriz);
    //cargarMatrizDeEnteros(matriz);
    int sumaTotal = suma(matriz);
    float promediacion = promedio(matriz);

    printf("Que dato desea buscar?");
    fflush(stdin);
    scanf("%i",&dato);


    mostrarMatriz(matriz,sumaTotal,promediacion);
    encontrarDato(matriz, dato) ? printf("\nEl dato |%i| se ha encontrado en la matriz\n",dato) :printf("\nEl dato no se encuentra en la matriz\n");
    */
    int validos = cargarArregloDeCaracteres(matrizCaracteres);


    //cargarUnDato(datoPalabra);
    //int encontrado = encontrarPalabra(matrizCaracteres,validos,datoPalabra);
    //mostrarPalabraEncontrada(encontrado);

    ordenarPalabras(matrizCaracteres,validos);

    mostrarArreglo (matrizCaracteres,validos);
    return 0;
}

/**Hacer una función que reciba como parámetro una matriz de números enteros
y permita que el usuario ingrese valores al mismo por teclado.
 La función debe cargar la matriz por completo. */

void cargarMatriz(int matriz[DIMMAX][MAXCOL])
{
    for(int i = 0; i<DIMMAX; i++)
    {
        for(int j = 0; j<MAXCOL; j++)
        {
            printf("Cargue su matriz: ");
            scanf("%i",&matriz[i][j]);
        }
    }
}
void mostrarCaracter(int matriz[DIMMAX][MAXCOL])
{
    printf("-------MATRIZ------\n");
    for(int i = 0; i<DIMMAX; i++)
    {
        for(int j = 0; j<MAXCOL; j++)
            printf("|%i|",matriz[i][j]);

        printf("\n");
    }
}

/**Hacer una función que reciba como parámetro una matriz de números enteros
y que cargue la misma con números aleatorios (sin intervención del usuario).
La función debe cargar la matriz por completo. */

void cargarMatrizDeEnteros( int matriz[DIMMAX][MAXCOL])
{
    for(int i = 0; i<DIMMAX; i++)
        for(int j = 0; j<MAXCOL; j++)
            matriz[i][j] = rand()%99 + 1;
}

///Hacer una función tipo int que sume el contenido total de una matriz de números enteros.

void matrizRandom(int matriz[DIMMAX][MAXCOL])
{
    for(int i = 0; i<DIMMAX; i++)
        for(int j = 0; j<MAXCOL; j++)
            matriz[i][j] = rand()%100 + 1;
}

/// Hacer una función tipo int que sume el contenido total de una matriz de números enteros.

int suma(int matriz[DIMMAX][MAXCOL])
{

    int suma=0;
    for(int i = 0; i<DIMMAX; i++)
        for(int j = 0; j<MAXCOL; j++)
            suma += matriz[i][j];

    return suma;
}

/// Hacer una función tipo float que calcule el promedio de una matriz de números enteros.


float promedio(int matriz[DIMMAX][MAXCOL])
{
    return (float)suma(matriz) / (DIMMAX * MAXCOL);
}
/**Hacer una función que determine si un elemento se encuentra dentro de una matriz de números enteros.
La función recibe la matriz y el dato a buscar.*/

int encontrarDato(int matriz[DIMMAX][MAXCOL],int dato)
{
    for(int i = 0; i<DIMMAX; i++)
        for(int j = 0; j<MAXCOL; j++)
            if(dato == matriz[i][j])
                return 1;

    return 0;
}

/// Hacer una función que cargue un arreglo de palabras (strings).
/// La función debe retornar cuantas palabras se cargaron.  (puede ser a través del parámetro como puntero)

int cargarArregloDeCaracteres(char matrizCaracteres[DIM_MAXC][MAX_COLC])
{
    char op = 's';
    int i = 0;

    while(op == 's' && i<DIM_MAXC)
    {
        printf("Ingrese la palabra: ");
        fflush(stdin);
        scanf("%s",&matrizCaracteres[i]);
        i++;
        printf("Desea continuar? (s/n)\n");
        fflush(stdin);
        scanf("%c", &op);
    }
    return i;
}

void mostrarArreglo ( char matrizCaracteres[DIM_MAXC][MAX_COLC], int validos)
{
    for (int i = 0; i<validos; i++)
        printf("Palabra|%i|: %s \n",i, matrizCaracteres[i]);
}

/**Hacer una función que determine si un string se encuentra dentro de un arreglo de strings.
La función recibe el arreglo, la cantidad de palabras que contiene y la palabra a buscar.
///devuelve el índice de la fila en que se encuentra, de lo contrario -1*/


void cargarUnDato(char dato[])
{
    printf("Que palabra desea cargar/buscar: ");
    fflush(stdin);
    gets(dato);
}


int encontrarPalabra(char matrizPalabra[DIM_MAXC][MAX_COLC],int validos,char dato[])
{
    int flag = -1;
    for(int i = 0; i<validos; i++)
        if(strcmp(matrizPalabra[i],dato)==0)
            flag = i;
    return flag ;
}

void mostrarPalabraEncontrada(int dato)
{

    if (dato != -1)
        printf("su palabra  se encuentra en la posicion: %i ",dato) ;
    else
        printf("La palabra no se encuentra en el arreglo");
}

///Hacer una función (o varias) que ordene un arreglo de palabras por orden alfabético. (Por selección o inserción, el que más te guste).

void insetarPalabra(char matrizPalabra[DIM_MAXC][MAX_COLC],int validos,char dato[]){

int i = validos - 1;

while(i>= 0 && strcmp(matrizPalabra[i],dato)<0){
     strcpy(matrizPalabra[i+1],matrizPalabra[i]);

    i--;
}
    strcpy(matrizPalabra[i+1],dato);
}

void ordenarPalabras(char matrizPalabra[DIM_MAXC][MAX_COLC],int validos){
int i = 0;

while(i<validos){
insetarPalabra(matrizPalabra,i,matrizPalabra[i+1]);
    i++;
}

}

