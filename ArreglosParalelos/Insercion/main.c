#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int DIMMAX = 30;
const int NOMBREMAX = 30;

void insertar(char nombres[][NOMBREMAX],int edad[],int legajo[],char datoNom[],int datoEdad [],int datoLegajo, int posFinal);
int cargarXInsercion (char nombres[][NOMBREMAX],int edad[],int legajo[]);
void showArray(char nombres[][NOMBREMAX],int edad[],int legajo[],int validos);



int main()
{

    char nombre[DIMMAX][NOMBREMAX];
    int edad[DIMMAX];
    int legajo[DIMMAX];

    int ordenar = cargarXInsercion (nombre,edad,legajo);
 showArray(nombre,edad,legajo,ordenar);


    return 0;
}

void insertar(char nombres[][NOMBREMAX],int edad[],int legajo[],char datoNom[],int datoEdad [],int datoLegajo, int posFinal)
{

    int i = posFinal - 1;

    while(i>= 0 && strcmp(nombres[i],datoNom)>0)
    {

        strcpy(nombres[i + 1],nombres[i]);
        edad[i + 1] = edad[i];
        legajo[i + 1] = legajo[i];

        i--;
    }
    strcpy(nombres[i + 1],datoNom);
    edad[i + 1] = datoEdad;
    legajo[i + 1] = datoLegajo;

}

int cargarXInsercion (char nombres[][NOMBREMAX],int edad[],int legajo[])
{

    int i = 0;
    char op = 's';
    char datoNom[DIMMAX];
    int user = 1;
    int datoEdad,datoLegajo;

    while(i<DIMMAX && op == 's')
    {

        printf("-----------DATOS DEL USUARIO:|%i|----------\n",user);
        printf("\nIngrese el nombre: ");
        fflush(stdin);
        gets(datoNom);

        printf("Ingrese la edad: ");
        fflush(stdin);
        scanf("%i",&datoEdad);

        printf("Ingrese el legajo : ");
        fflush(stdin);
        scanf("%i",&datoLegajo);

        insertar(nombres,edad,legajo,datoNom,datoEdad,datoLegajo,i);
        i++;
        user++;

        printf("Desea continuar?(s/n)");
        fflush(stdin);
        scanf("%c",&op);

    }
    return i;
}

void showArray(char nombres[][NOMBREMAX],int edad[],int legajo[],int validos)
{
    int user = 1;
     printf("-----------USUARIOS ACOMODADOS ALFABETICAMENTE----------\n",user);
    for(int i = 0; i<validos; i++)
    {
        printf("\n-----------USUARIO |%i|----------\n",user);
        printf("Nombre: %s\n",nombres[i]);
        printf("Edad: %i \n",edad[i]);
        printf("Nro Legajo: %i\n",legajo[i]);
        user++;
    }
}
