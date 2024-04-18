#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#define DIM_MAX 30
#include "prototipado.h"
void cleanWindows()
{
    system("cls");
}


/**Crear una función que cargue un archivo de alumnos.
 Abrirlo de manera tal de verificar si el archivo ya está creado previamente. Cargar el archivo con 5 datos.
Cerrarlo dentro de la función */

stAlumno cargaUnAlumno() ///p de persona
{

    stAlumno p;

    printf("Ingrese el Nombre y Apellido: ");
    fflush(stdin);
    gets(p.nombreYapellido);
    printf("Ingrese la edad: ");
    fflush(stdin);
    scanf("%i",&p.edad);
    printf("Ingrese el legajo: ");
    fflush(stdin);
    scanf("%i",&p.legajo);
    printf("Ingrese el año que se encuentra cursando: ");
    fflush(stdin);
    scanf("%i",&p.anio);

    return p;
}

void cargarAlumnos(char archivo[])
{

    FILE* archi;
    stAlumno p;
    char op = 's';

    archi = fopen(archivo,"ab");

    if(archi != NULL)
    {

        while(op == 's'|| op == 'S')
        {
            p = cargaUnAlumno();
            op = operador();

            fwrite(&p,sizeof(stAlumno),1,archi);
        }

        fclose(archi);
    }

}

int operador()
{
    char op = 's';
    printf("(S/N)Para continuar la carga: ");
    fflush(stdin);
    scanf("%c",&op);
    return op;
}

///Crear una función que muestre por pantalla los registros de un archivo de alumnos. Modularizar.


void mostrarAlumno(stAlumno p)
{
    printf("\n-----------------------DATOS----------------------------\n");
    printf("Nombre y apellido es: %s\n",p.nombreYapellido);
    printf("La edad es: %i\n",p.edad);
    printf("El nro de legajo es: %i\n",p.legajo);
    printf("El año de cursada es: %i\n",p.anio);
    printf("----------------------------------------------------------\n");

}

void mostrarArchivo( char archivo[])
{

    FILE* archi;
    stAlumno p;
    int i = 0;
    archi=fopen(archivo,"rb");

    if(archi!= NULL)
    {

        while(fread(&p,sizeof(stAlumno),1,archi)>0)
        {
            mostrarAlumno(p);
        }

        fclose(archi);
    }

}

/**Crear una función que permita agregar de a un elemento al final del archivo. O sea, se debe abrir el archivo,
 se piden los datos (se llena una variable de tipo struct alumno), se escribe en el archivo y se cierra.*/

void agregarElemento(char archivo[])
{

    FILE * buffer;
    buffer = fopen(archivo,"ab");
    stAlumno archi;

    if(buffer!= NULL)
    {
        printf("-------------------Cargue un alumno------------------\n");
        archi = cargaUnAlumno();
        fwrite(&archi, sizeof(stAlumno), 1, buffer);
        fclose(buffer);
    }
}

/// Crear una función que pase a una pila los números de legajo de los alumnos mayores de edad.

void pasarLegajoToPila(char archivo[],Pila* mayoresLegajos)
{

    FILE* archi;
    archi = fopen(archivo,"rb");
    stAlumno persona;

    int mayor = 18;

    if(archi !=NULL)
    {
        while(fread(&persona,sizeof(stAlumno),1,archi)>0)
        {
            if(persona.edad >= mayor)
            {
                apilar(mayoresLegajos,persona.legajo);
            }
        }
        fclose(archi);
    }
}

///Dado un archivo de alumnos, hacer una función que cuente la cantidad de alumnos mayores a edad específica que se envía por parámetro.

int preguntarDato()
{
    int edad = 0;
    printf("Ingrese el dato: ");
    fflush(stdin);
    scanf("%i",&edad);
    return edad;
}


int contarMayores(char archivo[],int edad)
{

    FILE* archi;
    archi = fopen(archivo,"rb");
    stAlumno persona;
    int i = 0;

    if(archi !=NULL)
    {
        while(fread(&persona,sizeof(stAlumno),1,archi)>0)
        {
            if(persona.edad > edad)
            {
                i++;
            }
        }
        fclose(archi);
    }
    return i;
}

void mostrarCantidad(int edad)
{
    if(edad != 0)
    {
        puts("\n------------CANTIDAD SOLICITADA-------------------");
        printf("La cantidad de alumnos es:(%i)\n",edad);
        puts("---------------------------------------------------\n");
    }
    else if(edad <=0)
    {
        puts("---------------------------------------------------");
        printf("El dato solicitado es (0) o es invalido\n");
        puts("---------------------------------------------------\n");
    }
}

/**Dado un archivo de alumnos,
 mostrar por pantalla el nombre de todos los alumnos entre un rango de edades específico (por ejemplo, entre 17 y 25 años).
Dicho rango debe recibirse por parámetro. Modularizar*/

void rangoNombres(char archivo[],int desde,int hasta)
{

    FILE* archi;
    archi = fopen(archivo,"rb");
    stAlumno persona;
    int i = 0;

    if(archi !=NULL)
    {
        while(fread(&persona,sizeof(stAlumno),1,archi)>0)
        {
            if(persona.edad >= desde && persona.edad <= hasta)
            {
                mostrarAlumno(persona);
            }
        }
        fclose(archi);
    }
}

int rangoEdades(int*hasta)
{

    int desde = 0;

    printf("DESDE donde quiere mostrar los alumnos: ");
    fflush(stdin);
    scanf("%i",&desde);
    printf("HASTA donde quiere mostrar los alumnos: ");
    fflush(stdin);
    scanf("%i",hasta);

    return desde;
}
/**Dado un archivo de alumnos, mostrar los datos del alumno de mayor edad. Modularizar.*/

void encontrarMayorAlumno(char archivo[])
{

    FILE* archi;
    archi = fopen(archivo,"rb");
    stAlumno persona;
    stAlumno auxMayor;

    if(archi !=NULL)
    {
        while(fread(&persona,sizeof(stAlumno),1,archi)>0)
        {
            if(persona.edad > auxMayor.edad)
            {
                auxMayor = persona;
            }
        }
        fclose(archi);
    }
    mostrarAlumno(auxMayor);
}
/**Crear una función que retorne la cantidad de alumnos que cursan un determinado año. El año buscado se pasa por parámetro. */

int alumnosXAnio(char archivo[],int BuscarAnio)
{

    FILE* archi;
    archi = fopen(archivo,"rb");
    stAlumno persona;
    int i = 0;
    if(archi !=NULL)
    {
        while(fread(&persona,sizeof(stAlumno),1,archi)>0)
        {
            if(persona.anio == BuscarAnio)
            {
                i++;
            }
        }
        fclose(archi);
    }
    return i;
}

/**Crear una función que reciba como parámetro un arreglo de tipo alumno y lo copie en el archivo.
 Asimismo, realice otra función que pase los elementos del archivo a un arreglo de alumnos, filtrando los estudiantes de un año en particular.*/

int cargarArregloAlumnos(stAlumno p[])
{
    stAlumno aux;
    int i = 0;
    char op = 's';
    while(i<DIM_MAX && (op=='s' || op== 's'))
    {
        aux = cargaUnAlumno();
        p[i] = aux;
        i++;
        op = operador();
    }
    return i;
}

void arregloToArchivo(char archivo[],stAlumno p[],int validos)
{
    int i = 0;
    FILE* archi;
    archi = fopen(archivo,"ab");
    if(archi != NULL)
    {
        while(i<validos)
        {
            fwrite(&p[i],sizeof(stAlumno),1,archi);
            i++;
        }
        fclose(archi);
    }
}

void archivoToArreglo(char archivo[])
{

    stAlumno aux[DIM_MAX];
    int i = 0;
    int anio = 0;
    FILE* archi;
    archi = fopen(archivo,"rb");
    anio = preguntarDato();

    if(archi != NULL)
    {
        while(fread(&aux[i],sizeof(stAlumno),1,archi)>0)
        {
            if(anio == aux[i].anio)
            {
                i++;
            }
        }
        fclose(archi);
    }
    mostrarArregloAlumnos(aux,i);
}

void mostrarArregloAlumnos(stAlumno p[],int validos)
{
    for(int i = 0; i<validos; i++)
    {
        printf("Nombre: %s \n",p[i].nombreYapellido);
        printf("Edad: %i\n",p[i].edad);
        printf("Legajo: %i\n",p[i].legajo);
        printf("Año que cursa: %i\n",p[i].anio);
    }
}

void menu(char archivo[],stAlumno persona[],Pila* legajos){
///DEF variables para que no esten en el switch

    int edad = 0;
    int contEdad = 0;
    int desde = 0;
    int hasta = 0;
    int anio = 0;
    int cantidadAnio = 0;
    int validos = 0;

char op;
int opcionCase;
do{
cleanWindows();
opciones();
scanf("%i",&opcionCase);

    switch(opcionCase){
case 1:
    cargarAlumnos(archivo);
    break;
case 2:
    pasarLegajoToPila(archivo,&legajos);
    mostrar(&legajos);
    break;
case 3:
    edad = preguntarDato();
    contEdad = contarMayores(archivo,edad);
    mostrarCantidad(contEdad);
    break;
case 4:

    puts("------------------DESDE---------------------------\n");
    desde = preguntarDato();                                    ///EN EL SWITCH ACLARAR QUE DATO ESTA INGRESANDO EL USER
    puts("------------------HASTA----------------------------\n");
    hasta = preguntarDato();
    rangoNombres(archivo,desde,hasta);
    break;
case 5:
    encontrarMayorAlumno(archivo);
    break;
case 6:
    anio = preguntarDato();
    cantidadAnio = alumnosXAnio(archivo,anio);
    mostrarCantidad(cantidadAnio);
    break;
case 7:
    validos = cargarArregloAlumnos(persona);
    arregloToArchivo(archivo,persona,validos);
    break;
case 8:
    archivoToArreglo(archivo);
    break;
case 9:
    mostrarArchivo(archivo);
    break;

default:
    puts("-----------------------------------------------------\n");
    printf("ERROR... NO DISPONIBLE U OPCION INVALIDA");
    puts("\n----------------------------------------------------\n");
    }
    puts("\n-------------------QUE DESEA REALIZAR------------------\n");
    op = operador();


}while(op == 's' || op == 'S');
}

void opciones(){
puts("\n---------------------------ELEGIR OPCION-------------------------\n");
printf("1-Cargar alumnos\n");
printf("2-Pasar legajos elegidos\n");
printf("3-Mostrar cantidad por edad\n");
printf("4-Desde que edad y hasta que edad desea ver la informacion de los alumno\n");
printf("5-Averiguar la persona mas longeba\n");
printf("6-Averiguar la cantidad de personas por el anio en que cursa\n");
printf("7-Cargar un arreglo con alumnos(solo añade mas)\n");
printf("8-Muestra los alumnos por año que cursan\n");
printf("9-Muestra todos los alumnos\n");
printf("10-NO DISPONIBLE\n");
printf("11-NO DISPONIBLE\n");
printf("12-NO DISPONIBLE\n");
printf("13-NO DISPONIBLE\n");

}
