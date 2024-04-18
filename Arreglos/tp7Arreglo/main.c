#include <stdio.h>
#include <stdlib.h>

/**Realizar una función que inserte un carácter en un arreglo ordenado alfabéticamente, conservando el orden. */
void insertar (char arreglo[], int val, char nueva);
int main()
{

    char arreglo[4] = {'a', 'b', 'd'};
    int val = 3;
    insertar (arreglo, 3, 'z');

    for(int i =0; i< 4; i++ )
    {

        printf("%c", arreglo[i]);

    }

    return 0;
}

void insertar (char arreglo[], int val, char nueva)
{
    int i = val - 1;
    char aux;

    while(i >= 0 && nueva < arreglo[i])
    {
        arreglo[i + 1] = arreglo[i];
        i--;
    }


    arreglo[i + 1] = nueva;




}
