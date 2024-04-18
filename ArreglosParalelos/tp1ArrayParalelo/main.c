#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int maxNombre = 30;
const int dimMax = 20;


int cargarArreglo(int edad[],char nombre[][maxNombre],int legajos[]);
void showArray(int edad[],char nombre[][maxNombre],int legajos[], int validos);
int buscarLegajo(int legajos[],int validos);
void encontrarLegajoBuscado(int edad[],char nombre[][maxNombre],int legajos[], int validos,int pos);

int buscarMenorNombre(char nombres[][maxNombre],int validos,int firstPos);
void ordenarSeleccion(char nombre[][maxNombre],int edad[],int legajos[], int validos);

void insertar(char nombre[][maxNombre],int edad[],int legajos[], int validos, char auxNom[]);
void ordenarInsercion(char nombre[][maxNombre],int edad[],int legajos[], int validos);



int main()
{

    int edad [dimMax] ;
    int legajos [dimMax];
    char nombre[dimMax][maxNombre];



    int validos = cargarArreglo(edad,nombre, legajos);
    // int busqueda = buscarLegajo(legajos,validos);
    //encontrarLegajoBuscado( edad, nombre, legajos,validos,  busqueda);

//ordenarSeleccion(nombre,edad,legajos,validos);

    ordenarInsercion(nombre,edad,legajos,validos);



    showArray(edad, nombre, legajos, validos);
    return 0;
}


int cargarArreglo(int edad[],char nombre[][maxNombre],int legajos[])
{

    int i = 0;
    char op = 's';

    while(i<dimMax && op == 's')
    {
        printf("----------INGRESE LOS DATOS---------\n");
        printf("\nIngrese el nombre: ");
        fflush(stdin);
        scanf("%s",&nombre[i]);

        printf("Que edad tiene la persona: ");
        scanf("%i",&edad[i]);

        printf("Cual es el legajo de la persona: ");
        scanf("%i",&legajos[i]);

        printf("\nDesea continuar(s/n): ");
        fflush(stdin);
        scanf("%c",&op);
        i++;

    }
    return i;
}

void showArray(int edad[],char nombre[][maxNombre],int legajos[],int validos)
{

    for(int i = 0; i<validos; i++)
    {
        printf("Nombre: %s \n",nombre[i]);
        printf("Edad: %i \n",edad[i]);
        printf("Legajo: %i \n",legajos[i]);
        printf("--------------------------\n");
    }
}


/// Crear una función que busque dentro del arreglo de legajos y retorne la posición de un determinado valor.
int buscarLegajo(int legajos[],int validos)
{
    int i =0;
    int legajoABuscar=0;

    printf("Que legajo desea buscar? \n");
    fflush(stdin);
    scanf("%i", &legajoABuscar);
    while(i<validos)
    {

        if (legajoABuscar == legajos[i])
        {
            //printf("La posicion del legajo encontrado es: %i", i);

        }
        i++;
    }
    return i;
}


/**Hacer una función que reciba como parámetro todos los arreglos y encuentre el nombre correspondiente a un determinado legajo y lo imprima por pantalla.
Se debe invocar la función 2.*/
void encontrarLegajoBuscado(int edad[],char nombre[][maxNombre],int legajos[], int validos,int pos)
{



    int i =0;
    while(i<validos)
    {
        if (legajos[i] == pos )
        {
            printf("Nombre: %s \n",nombre[i]);
            printf("Edad: %i \n",edad[i]);
            printf("Legajo: %i \n",legajos[i]);
            printf("--------------------------\n");


        }
        i++;

    }

}


int buscarMenorNombre(char nombres[][maxNombre],int validos,int firstPos)
{

    int i = firstPos;
    int menorPos =  firstPos;

    for(i; i<validos; i++)
    {
        if(strcmp(nombres[i],nombres[menorPos])< 0)
        {
            menorPos =i;
        }
    }
    return menorPos;
}

void ordenarSeleccion(char nombre[][maxNombre],int edad[],int legajos[], int validos)
{

    int menorPos = 0;
    char aux[maxNombre];
    int auxiliar = 0, i = 0;

    for(i; i<validos; i++)
    {

        menorPos = buscarMenorNombre(nombre,validos,i);

        auxiliar = edad[i];
        edad[i] = edad[menorPos];
        edad[menorPos] = auxiliar;

        auxiliar = legajos[i];
        legajos[i] = legajos[menorPos];
        legajos[menorPos] = auxiliar;

        strcpy(aux,nombre[i]);
        strcpy(nombre[i],nombre[menorPos]);
        strcpy(nombre[menorPos],aux);

    }
}


void insertar(char nombre[][maxNombre],int edad[],int legajos[], int validos, char auxNom[])
{

    int i = validos -1;

    while( i >= 0 && (strcmp(nombre[i],auxNom[i])<0))
    {


        nombre[i + 1] = nombre[i];
        edad[i + 1] = edad[i];
        legajos[i + 1] = legajos[i];
        i--;

    }
    nombre[i + 1] = auxNom;
    edad[i + 1] = edad[i];
    legajos[i + 1] = legajos[i];

}

void ordenarInsercion(char nombre[][maxNombre],int edad[],int legajos[], int validos)
{
    int i = 0;
    char nombreInsertar[];
    nombreInsertar[i] = nombre[i];
    while(i<validos)
    {
        insertar(nombre,edad,legajos,i,nombreInsertar)
        i++;

    }

}
