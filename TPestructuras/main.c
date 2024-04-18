#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DIM_MAX 30

typedef struct
{
    int matricula;
    char nombre[DIM_MAX];
    char genero;
} stAlumno;

void cleanWindows();

int alumnos (stAlumno persona[]);
stAlumno cargarEstudiante();
void mostrarArreglo(stAlumno persona[], int validos);
void encontrarXMatricula (stAlumno persona[],int validos);
int buscarMatricula(stAlumno persona[],int validos,int matricula);

void encontrarXNombre (stAlumno persona[],int validos);

void elegirOp(stAlumno persona[], int validos);
int opciones();
int encontrarMenorMatricula(stAlumno persona[],int validos,int firstPos);
void ordenamientoXSeleccion(stAlumno persona[], int validos);
void MostrarXGenero(stAlumno persona[],int validos);
void insertarMatriculaNueva(stAlumno persona[],int validos);
void mostrarMatricula(stAlumno persona[],int validos);

void insertar (stAlumno persona[],int validos,stAlumno dato);
void ordenamientoXInsercion(stAlumno persona[],int validos);

void cantidadXGenero(stAlumno persona[],int validos);
void mostrarCantidadXGenero(stAlumno persona[],int m,int w,int o);

int main()
{
    stAlumno persona[30];
    int firstPos = 0;
    int validos = alumnos(persona);

    elegirOp(persona, validos);

    return 0;
}

void cleanWindows()
{
    system("cls");
}


///Hacer una función que cargue un arreglo de alumnos, hasta que el usuario lo decida.

int alumnos (stAlumno persona[])
{
    int i = 0;
    int alumno = 1;
    char op = 's';
    while(i<DIM_MAX && (op == 's'||op =='S'))
    {
        printf("-----------DATOS DEL ALUMNO %i------------\n",alumno);

        persona[i] = cargarEstudiante();
        i++;
        alumno++;
        printf("Desea cargar agregar mas alumnos? (s/n) \n");
        fflush(stdin);
        scanf("%c",&op);

    }

    cleanWindows();
    return i;
}

stAlumno cargarEstudiante()
{

    stAlumno persona;
    printf("\nIngrese la matricula: ");
    fflush(stdin);
    scanf("%i",&persona.matricula);

    printf("Ingrese el nombre del alumno: ");
    fflush(stdin);
    scanf("%s",&persona.nombre);

    printf("Ingrese el genero(m/f/o): ");
    fflush(stdin);
    scanf("%c",&persona.genero);
    return persona;
}



void mostrarArreglo(stAlumno persona[], int validos)
{
    for(int i = 0; i<validos; i++)
    {
        printf("\n---------------INFORMACION DEL ALUMNO %s--------------- \n ",persona[i].nombre);
        printf("\nLa matricula es: %i \n",persona[i].matricula);
        printf("El nombre es: %s \n",persona[i].nombre);
        printf("El genero es: %c \n",persona[i].genero);
    }
}


///Hacer una función que muestre por pantalla los datos de un alumno, conociendo su matrícula. Modularizar.

void encontrarXMatricula (stAlumno persona[],int validos)
{

    int matricula = 0;

    printf("Que matricula desea buscar: ");
    fflush(stdin);
    scanf("%i",&matricula);

    int posMatri = buscarMatricula(persona,validos,matricula);
    for(int i = 0; i<validos; i++)
    {
        if(posMatri == persona[i].matricula)
        {
            printf("-------------------------------------------\n");
            printf("Nro de matricula: %i\n",persona[i].matricula);
            printf("Nombre: %s\n",persona[i].nombre);
            printf("Genero: %c\n",persona[i].genero);
            printf("-------------------------------------------");
        }
    }
        if(posMatri == -1)
        {
            printf("-------------------------------------------\n");
            printf("No se encontro la matricula o hubo un error\n");
            printf("-------------------------------------------\n");
        }

}

int buscarMatricula(stAlumno persona[],int validos,int matricula)
{

    int flag = -1;
    int i = 0;
    while(i<validos && flag == -1)
    {
        if(matricula == persona[i].matricula)
        {
            flag = persona[i].matricula;
        }
        i++;
    }
    return flag;
}


void encontrarXNombre (stAlumno persona[],int validos)
{

    char nombre[DIM_MAX];
    int i = 0;
    printf("Que nombre desea buscar: ");
    fflush(stdin);
    scanf("%s",&nombre);

    while(i<validos)
    {
        if(strcmp(nombre,persona[i].nombre)== 0)
        {
            printf("LOS DATOS PERTENECIENTES A :%s",persona[i].nombre);
            printf("\nNro de matricula: %i\n",persona[i].matricula);
            printf("Nombre: %s\n",persona[i].nombre);
            printf("Genero: %c\n",persona[i].genero);
        }
        i++;
    }
}
/**Hacer una función principal que pruebe el funcionamiento de todos los incisos anteriores, con un menú de opciones para poder ejecutar todas las funciones requeridas.
Tengan presente la correcta declaración y el ámbito de variables.*/


void elegirOp(stAlumno persona[], int validos)
{
    char continuar;
    do
    {
        int op = opciones();
        switch(op)
        {
        case 1:
            encontrarXMatricula(persona, validos);
            break;
        case 2:
            encontrarXNombre(persona, validos);
            break;
        case 3:
            ordenamientoXSeleccion(persona,validos);
            mostrarArreglo(persona,validos);
            break;
        case 4:
            MostrarXGenero(persona,validos);

            break;
        case 5:
            insertarMatriculaNueva(persona,validos);
            mostrarMatricula(persona,validos);
            break;
        case 6:
            ordenamientoXInsercion(persona,validos);
            break;
        case 7:
            cantidadXGenero(persona,validos);
            break;
        case 8:
            mostrarArreglo(persona,validos);
            break;
        default:
            printf("---------Error--------");
        }
        printf("\n(S/N) para elegir otra opcion o para finalizar: ");
        fflush(stdin);
        scanf("%c",&continuar);
        cleanWindows();
    }
    while(continuar == 's'||continuar == 'S');

}

int opciones()
{

    int op = 0;
    printf("-----------------INGRESE UNA OPCION A REALIZAR-------------\n");
    printf("Que desea realizar? \n\t 1)Encontrar un alumno por matricula\n\t 2) Encontrar un alumno por nombre \n\t 3) Ordenar por seleccion|MATRICULAS|\n");
    printf("\t 4) Mostrar por genero.\n\t 5) Insertar una matricula \n\t 6) Ordenamiento por Insercion|NOMBRES|\n\t 7) Saber cuantos alumnos hay de cada genero\n");
    printf("\t 8)Mostrar los alumnos cargados originalmente\n");
    scanf("%i",&op);

    return op;
}


int encontrarMenorMatricula(stAlumno persona[],int validos,int firstPos)
{

    int posMenor = firstPos;
    int i = posMenor;

    while(i<validos)
    {
        if(persona[posMenor].matricula > persona[i].matricula)
        {
            posMenor = i;
        }

        i++;
    }
    return posMenor;
}

void ordenamientoXSeleccion(stAlumno persona[], int validos)
{
    int menor = 0;
    stAlumno aux;
    int i = 0;
    while(i<validos)
    {

        menor = encontrarMenorMatricula(persona,validos,i);
        aux = persona[i];
        persona[i]=persona[menor];
        persona[menor]=aux;
        i++;
    }
}
///Hacer una función que muestre por pantalla los datos de los estudiantes de un género determinado (se envía por parámetro). Modularizar.

void MostrarXGenero(stAlumno persona[],int validos)
{

    int i = 0;
    char op = 'm';

    printf("Que genero desea mostrar|m,f,o|?: ");
    fflush(stdin);
    scanf("%c",&op);

    while(i<validos)
    {
        if(op == persona[i].genero)
        {
            printf("La persona con el genero |%c| es: %s\n",op,persona[i].nombre);
        }
        i++;
    }

}

///Hacer una función que inserte en un arreglo ordenado por matrícula un nuevo dato, conservando el orden.

void insertarMatriculaNueva(stAlumno persona[],int validos)
{

    int dato = 0;
    int i = 0;
    int j = validos - 1;
    printf("Que matricula desea insertar?: ");
    fflush(stdin);
    scanf("%i",&dato);


    while(i<validos)
    {
        ordenamientoXSeleccion(persona,validos);
        persona[j+1].matricula = dato;
        i++;
    }

}

void mostrarMatricula(stAlumno persona[],int validos)
{
    for(int i = 0; i<validos+1; i++)
    {
        printf("Matricula existentes son y/o agregadas: (%i) \n",persona[i].matricula);
    }
}

///Hacer una función que ordene el arreglo de alumnos por medio del método de inserción. El criterio de ordenación es el nombre.

void insertar (stAlumno persona[],int validos,stAlumno dato)
{

    int i = validos ;

    while(i>=0 && strcmp(persona[i].nombre,dato.nombre)>0)
    {
      persona[i+1] = persona[i];
        i--;
    }
   persona[i+1] = dato;

}

void ordenamientoXInsercion(stAlumno persona[],int validos)
{
    int i = 0;

    stAlumno aux[DIM_MAX];
    stAlumno dato;
    for(int j = 0; j<validos; j++)
    {
        aux[j] = persona[j];
    }

    dato = aux[i+1];
    while(i<validos - 1)
    {
        insertar(aux,i,dato);
        i++;
    }
    mostrarArreglo(aux,validos);
}

///Hacer una función que cuente y retorne la cantidad de estudiantes de un género determinado (se envía por parámetro) que tiene un arreglo de alumnos.

void cantidadXGenero(stAlumno persona[],int validos)
{

    int men= 0;
    int women = 0;
    int other = 0;
    int i = 0;

    while(i<validos)
    {
        if('m'== persona[i].genero||'M'== persona[i].genero)
        {
            men++;
        }
        else if('f'== persona[i].genero||'F'== persona[i].genero)
        {
            women++;
        }
        else if('o'== persona[i].genero||'O'== persona[i].genero)
        {
            other++;
        }
        i++;
    }
    mostrarCantidadXGenero(persona,men,women,other);
}

void mostrarCantidadXGenero(stAlumno persona[],int m,int w,int o)
{
    char op;

    printf("Que opcion desea mostrar m|f|o?: ");
    fflush(stdin);
    scanf("%c",&op);

    if (op == 'm'||op == 'M')
    {
        printf("La cantidad de alumnos de genero masculino: %i",m);
    }
    else if(op=='f'||op == 'F')
    {
        printf("La cantidad de alumnos de genero femenino: %i",w);
    }
    else if(op=='o'||op == 'O')
    {
        printf("La cantidad de genero no definido u otro es: %i",m);
    }
}
