#include <stdio.h>
#include <stdlib.h>
///Realizar una función que determine si un arreglo es capicúa.


int arrayCapicua(int arreglo[], int validos);

int main()
{

    int arreglo[5] = {4, 3, 2};
    int validos = 3;
   (arrayCapicua(arreglo,validos)) ? printf("Es capicua") : printf("No es capicua");

    return 0;
}

int arrayCapicua(int arreglo[], int validos)
{
    int i = 0;
    int j = validos - 1;
    while(i!=j && i < j)
    {


        if(arreglo[i] != arreglo[j])
        {
            return 0;
        }
        i++;
        j--;
    }
    return 1;

}
