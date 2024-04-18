#include <stdio.h>
#include <stdlib.h>

const int FILA = 2;
const int COL= 2;
const int COLUMNASx5= 5;


void cargarMatriz(int matriz[FILA][COL]);
void mostrarMatriz(int matriz[FILA][COL]);
int buscarDeterminante(int matriz[FILA][COL]);
int buscarInversa(int determinante);
void mostrarDeterminante(int determinante);

void cargarMatrices (int matriz[FILA][COL], int matriz2x5[FILA][COLUMNASx5]);
void mostrarMatrices (int matriz2x2[FILA][FILA], int matriz2x5[FILA][COLUMNASx5],int resultado[FILA][COLUMNASx5]);
void multiplicarMatrices(int resultado[FILA][COLUMNASx5],int matriz2x2[FILA][FILA], int matriz2x5[FILA][COLUMNASx5]);

void encontrarInversa(float matrizInversa[FILA][COL],int matriz2x2[FILA][COL],int deter);

int main()
{
    int matriz2x2[FILA][COL];
    //int matriz2x5[FILA][COLUMNASx5];
    //int resultado[FILA][COLUMNASx5];
    int matrizInversa[FILA][COL];

    cargarMatriz(matriz2x2);
    mostrarMatriz(matriz2x2);
    int determinante[FILA][COL];
    int deter = buscarDeterminante(matriz2x2);
    mostrarDeterminante(deter);
    buscarInversa(deter)?printf("\nSu matriz tiene inversa %i != 0\n",deter) : printf("\nSu matriz NO tiene inversa %i = 0\n",deter);
    encontrarInversa(matrizInversa,matriz2x2,deter);

    /**cargarMatrices(matriz2x2,matriz2x5);
    multiplicarMatrices(resultado,matriz2x2,matriz2x5);
    mostrarMatrices(matriz2x2,matriz2x5,resultado);*/


    return 0;
}

void cargarMatriz(int matriz[FILA][COL])
{

    printf("----------CARGA MATRIZ 2x2------------\n");
    for(int i=0; i<FILA; i++)
    {
        for(int j=0; j<FILA; j++)
        {
            printf("ingrese un numero a su matriz: ");
            scanf("%i", &matriz[i][j]);
        }
    }
}

void mostrarMatriz(int matriz[FILA][COL])
{

    for(int i = 0; i<FILA; i++)
    {
        printf("|");
        for(int j = 0; j<COL; j++)
        {
            printf(" %i ",matriz[i][j]);
        }
        printf("|\n");
    }
}
void mostrarDeterminante(int determinante)
{
    printf("Su determinante es : |%i|\n",determinante);
}
int buscarInversa(int determinante)
{
    if(determinante != 0)
    {
        return 1;
    }

    return 0;

}

int buscarDeterminante(int matriz[FILA][COL])
{

    int i = 0;
    int j = FILA - 1;
    int suma = 1;
    int sumaSecu = 1;
    int determinante = 0;

    while(i<FILA && j>= 0)
    {

        suma *= matriz[i][i];
        sumaSecu *= matriz[i][j];

        i++;
        j--;
    }
    determinante = suma - sumaSecu;

    return determinante;
}
void cargarMatrices (int matriz[FILA][COL], int matriz2x5[FILA][COLUMNASx5])
{
    printf("----------CARGA MATRIZ 2x2------------\n");
    for(int i=0; i<FILA; i++)
    {
        for(int j=0; j<FILA; j++)
        {
            printf("ingrese un numero a su matriz: ");
            scanf("%i", &matriz[i][j]);
        }
    }
    printf("\n----------CARGA MATRIZ 2x5------------\n\n");
    for (int i=0; i<FILA; i++)
    {
        for(int j=0; j<COLUMNASx5; j++)
        {
            printf("Ingrese un numero a la matriz: ");
            scanf("%i", &matriz2x5[i][j]);
        }
    }
}

void mostrarMatrices (int matriz2x2[FILA][FILA], int matriz2x5[FILA][COLUMNASx5],int resultado[FILA][COLUMNASx5])
{
    printf("----------MATRIZ 2x2----------\n\n");
    for(int i=0; i<FILA; i++)
    {
        printf("|");
        for (int j=0; j<FILA; j++)
        {
            printf(" %i ", matriz2x2[i][j]);
        }
        printf("|\n");
    }
    printf("\n----------MATRIZ 2x5----------\n\n");
    {
        for(int i=0; i<FILA; i++)
        {
            printf("|");

            for(int j=0; j<COLUMNASx5; j++)
            {
                printf(" %i ", matriz2x5[i][j]);
            }
            printf("|\n");
        }
    }
    printf("\n----------RESULTADO 2x5----------\n\n");
    {
        for(int i=0; i<FILA; i++)
        {
            printf("|");

            for(int j=0; j<COLUMNASx5; j++)
            {
                printf(" %i ", resultado[i][j]);
            }
            printf("|\n");
        }
    }
}

void multiplicarMatrices(int resultado[FILA][COLUMNASx5],int matriz2x2[FILA][FILA], int matriz2x5[FILA][COLUMNASx5])
{
    int i,j,k;
    for(i = 0; i<FILA; i++)
    {
        for(j = 0; j<COLUMNASx5; j++)
        {
            resultado[i][j] = 0;

            for(k = 0; k<FILA; k++)
            {
                resultado[i][j] += matriz2x2[i][k] * matriz2x5[k][j];
            }

        }
    }
}
///Hacer una función que calcule la matriz inversa de una matriz de 2x2.


void encontrarInversa(float matrizInversa[FILA][COL],int matriz2x2[FILA][COL],int deter)
{

    matrizInversa[0][0] = (float)  matriz2x2[1][1] / deter;
    matrizInversa[0][1] = (float)  -matriz2x2[0][1]/ deter;
    matrizInversa[1][0] = (float)  -matriz2x2[1][0]/ deter;
    matrizInversa[1][1] = (float)  matriz2x2[0][0] / deter;

    for(int i = 0; i<FILA; i++)
    {
        printf("|");
        for(int j = 0; j<COL; j++)
        {
            printf(" %.3f ",matrizInversa[i][j]);
        }
        printf("|\n");
    }

}
