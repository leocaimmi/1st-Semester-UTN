#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "astronauta.h"
#include "nave.h"
#include "menu.h"
#include "misiones.h"
#define DIM_MAX_ARCHI 30
#define DIM_MAX_STR 40
#define DIM_MAX_TXT 256



// validar

void validarTipoNave(char tipoNave[])
{

    int flag = 0, dato=0;
    do
    {
    tiposDeNave();
    dato=preguntarDato();
        switch(dato)
        {
        case 1:
            strcpy(tipoNave,"StarShip");
            flag = 1;
            break;
        case 2:
            strcpy(tipoNave,"Falcon 9");
            flag = 1;
            break;
        case 3:
            strcpy(tipoNave,"Falcon Heavy");
            flag = 1;
            break;
        default:
            printf("ERROR,ingrese una nave valida...\n");
            flag = 0;
            break;
        }

    } while(flag == 0);

}
int validarCantNave(int cont)
{
    int maximo=5;
    // esta funcion sirve para los 3 tipos de nave

    if(cont > maximo)
    {
        printf("La cantidad de naves esta llena \n");
        return 0; // Aqui ya excedio el maximo de naves
    }
    printf("Tiene esta cantidad de naves fabricadas: %i \n",cont);
    return 1; // El usuario va a poder seguir cargando ya que no excede el maximo de naves

}
int validarIDNave(char archivoNave[], int dato)
{
    stNaves aux;
    int flag=0;
    FILE * buffer=fopen(archivoNave, "rb");

    if(buffer != NULL)
    {
        while(fread(&aux,sizeof(stNaves),1,buffer)> 0)
        {
            if(dato == aux.idNave)
            {
                flag = 1;
            }
        }
        fclose(buffer);
    }
    else
    {
        printf("Error con el archivo");
    }
    if(flag == 0)
    {
        puts("No existe el ID de la nave solicitado\n");
    }
    return flag;

}
int validarSiNaveEstaOcupada(int estado)
{
    int alta=1,baja=3;
    if (estado ==alta || estado == baja)
    {
        return 0;
    }

    if(estado==0)
    {
        puts("Error la nave esta en mantenimiento");
    }
    if(estado==2)
    {
        puts("Error la nave esta actualmente en mision");
    }

    return 1;
}

// cargar nave

stNaves cargarUnaNave(char archivoNaves[])
{
    stNaves aux;

///Datos default
    int ultimaID =encontrarUltimaIDNave(archivoNaves);
    aux.idNave = ultimaID + 1;
    aux.CantidadDeVuelosRealizados = 0;
    aux.HorasDeVueloAcumuladas = 0;
    aux.estado = 1;

    validarTipoNave(aux.tipoDeNave);



    return aux;
}

int encontrarUltimaIDNave(char archivoNaves[])
{

    int ultimaID;
    stNaves naveAux;
    FILE* aux;
    aux = fopen(archivoNaves,"rb");
    if(aux != NULL)
    {

        fseek(aux,sizeof(stNaves)*-1,SEEK_END);
        fread(&naveAux,sizeof(stNaves),1,aux);
        ultimaID = naveAux.idNave;
        fclose(aux);
    }
    else
    {
        puts("error con el archivo");
    }
    return ultimaID;
}

void tiposDeNave()
{
    puts("----------------SELECCIONE UN TIPO DE NAVE------------------\n");
    puts("1-StarShip (Lleva 7 astronautas obligatorio)");
    puts("2-Falcon 9 (Lleva 5 astronautas obligatorio)");
    puts("3-Falcon Heavy (Lleva 3 astronautas obligatorio)");
}

// carga del archivo

int contarNaveXtipo(char archivoNaves[], char tipoNave[])
{
    int cont=1;
    stNaves aux;
    FILE * buffer= fopen(archivoNaves, "rb");
    if(buffer != NULL)
    {
        while(fread(&aux,sizeof(stNaves),1,buffer) > 0)
        {
            if(strcmpi(aux.tipoDeNave,tipoNave) == 0)
            {
                cont++;
            }
        }
        fclose(buffer);
    }
    else
    {
        puts("Error con el archivo");
    }
    return cont;
}


void cargarArchivoNaves(char archivoNaves[])
{

    int cont=0;
    stNaves aux;

    FILE * buffer=fopen(archivoNaves,"ab");

    if(buffer != NULL)
    {
        aux = cargarUnaNave(archivoNaves);
        cont = contarNaveXtipo(archivoNaves,aux.tipoDeNave);

        if(validarCantNave(cont)==1)
        {
            fwrite(&aux,sizeof(stNaves),1,buffer);
        }

        fclose(buffer);
    }

    else
    {
        puts("Error con el archivo");
    }




}

int contarRegistrosNaveParaElArregloDinamico(char archivoNaves[])
{
    int cant=0;
    FILE* buffer= fopen(archivoNaves,"rb");
    if(buffer != NULL)
    {
        fseek(buffer,sizeof(stNaves)-1,SEEK_END);
        cant=ftell(0)/sizeof(stNaves);
        fclose(buffer);
    }
    else
    {
        puts("Error con el archivo");
    }

    return cant;
}
// mostrar naves

void mostrarUnaNave(stNaves aux)
{
    puts("---------------------NAVE---------------------");
    printf("ID...............................:|%i|  \n",aux.idNave);
    printf("Tipo de nave.....................:|%s|  \n",aux.tipoDeNave);
    printf("Cantidad de vuelos realizados....:|%i|  \n",aux.CantidadDeVuelosRealizados);
    printf("Horas de vuelo acumuladas........:|%i|  \n",aux.HorasDeVueloAcumuladas);
    printf("ESTADO...........................:|%i|  \n",aux.estado);
    puts("----------------------------------------------");

}
void mostrarTodasLasNaves(char archivoNaves[])
{
    stNaves aux;
    FILE* buffer=fopen(archivoNaves,"rb");

    if(buffer != NULL)
    {
        while(fread(&aux,sizeof(stNaves),1,buffer) > 0)
        {
            mostrarUnaNave(aux);
        }
        fclose(buffer);
    }
    else
    {
        printf("Error con el archivo\n");
    }

}


//modificar nave


int encontrarPosicionNaveXID(char archivoNaves[], int IDNave)
{
    stNaves aux;
    int posNave=0, flag=0;
    FILE * buffer = fopen(archivoNaves,"rb");

    if(buffer != NULL)
    {
        while(fread(&aux,sizeof(stNaves),1,buffer) > 0 && flag == 0)
        {
            if (aux.idNave == IDNave)
            {
                posNave = ftell(buffer)/sizeof(stNaves);
                flag = 1;
            }
        }
        fclose(buffer);
    }
    else
    {
        puts("Error con el archivo");
    }
    return posNave;

}

void cargarNaveModificada(char archivoNaves[])
{
    int datoID=0, posNave=0;
    stNaves aux;
    FILE * buffer=fopen(archivoNaves,"r+b");

    if(buffer != NULL)
    {
        do
        {

            mostrarTodasLasNaves(archivoNaves);
            puts("-----------INGRESE EL ID DE LA NAVE QUE QUIERE MODIFICAR-------------");
            datoID = preguntarDato();
            limpiarPantalla();

        }
        while(validarIDNave(archivoNaves,datoID)== 0 || validarSiNaveEstaOcupada(aux.estado) == 0);



        posNave=encontrarPosicionNaveXID(archivoNaves,datoID)-1;

        fseek(buffer,sizeof(stNaves)*posNave,SEEK_SET);
        fread(&aux,sizeof(stNaves),1,buffer);
        modificarUnaNave(&aux);
        fseek(buffer,sizeof(stNaves)*-1,SEEK_CUR);
        fwrite(&aux,sizeof(stNaves),1,buffer);



        fclose(buffer);
    }
    else
    {
        printf("Error con el archivo \n");
    }

}
void modificarUnaNave(stNaves* aux)
{
    int opsw, dato;
    char op='s';

    do
    {

        puts("\n------------------NAVE ELEGIDA------------------");
        mostrarUnaNave(*aux);

        puts("1. Estado (Alta/Baja)");
        puts("2. Volver al menu de naves");
        puts("Que desea modificar?: ");
        scanf("%i",&opsw);

        switch(opsw)
        {
        case 1:
            do
            {
                puts("Ingrese 1 para dar de Alta/Reparar");
                puts("Ingrese 3 para dar de Baja");
                dato=preguntarDato();
                aux->estado= dato;
            }
            while(validarEstadoNave(dato)== 0);
            break;
        case 2:
            break;
        default:
            puts("Ingrese una opcion valida");
            break;
        }
        puts("--------------------NAVE MODIFICADA----------------------");
        mostrarUnaNave(*aux);

        puts("(S/N)Desea seguir modificando la nave?");
        fflush(stdin);
        op = getch(op);

    }
    while(op == 's');

}

int validarEstadoNave(int dato)
{
    if (dato == 1 || dato == 3)
    {
        return 1;
    }

    puts("Ingrese un estado valido");
    return 0;
}


//arreglo

int archivoToArregloNaves(char archivoNaves[],stNaves arrNaves[])
{
    stNaves aux;
    int i=0;
    FILE* buffer=fopen(archivoNaves,"rb");

    if(buffer != NULL)
    {
        while(fread(&aux,sizeof(stNaves),1,buffer)>0)
        {
            arrNaves[i]= aux;
            i++;
        }
        fclose(buffer);
    }
    else
    {
        puts("Error con el archivo");
    }
    return i;
}
stNaves* crearArregloDinamicoNave(int tam)
{

    stNaves* arrNave= malloc(sizeof(stNaves)*tam);
    return arrNave;
}
void mostrarArregloNave(stNaves arrNaves[], int validos)
{
    for (int i=0; i < validos; i++)
    {
        mostrarUnaNave(arrNaves[i]);
    }

}

//consultar nave

void ConsultaNave(char archivoNaves[])
{
    int tam= contarRegistrosNave(archivoNaves);
    stNaves* arrNaves;
    arrNaves= crearArregloDinamicoNave(tam);
    int validosNaves= 0;

    //stNaves arrNaves[DIM_MAX_STR];

    validosNaves=archivoToArregloNaves(archivoNaves,arrNaves);

    menuConsultarPorNave(archivoNaves,arrNaves,validosNaves);

}
void opcionesParaConsultarNaves()
{
    puts("1.Mostrar nave por ID");
    puts("2.Preguntar cuantas naves existen en total");
    puts("3.Preguntar cuantas naves de un tipo especifico existen"); //menu tipo nave
    puts("4.Buscar nave con mayor horas de vuelo acumuladas");
    puts("5.Buscar nave con menor horas de vuelo acumuladas");
    puts("6.Buscar nave con mayor cantidad de vuelos realizados");
    puts("7.Buscar nave con menor cantidad de vuelos realizados");


}
void menuConsultarPorNave(char archivoNaves[],stNaves arrNaves[], int validos)
{
    int posicionNave = 0;
    int dato=0;

    char op='s';
    int opsw=0;
    int pos=0;


    do
    {
        mostrarArregloNave(arrNaves,validos);

        opcionesParaConsultarNaves();

        printf("\nElija una opcion: ");
        opsw = preguntarDato();

        switch(opsw)
        {
        case 1:
            puts("-------Ingrese el ID de la nave que quiere buscar----------");

            dato = preguntarDato();
            pos= buscarNaveXID(arrNaves,validos,dato);
            if(pos != -1)
            {
                printf("La nave con el ID: %i\n",dato);
                mostrarUnaNave(arrNaves[pos]);

            }
            else
            {
                printf("No se encontro ninguna nave con el ID: %i",pos);
            }
            break;
        case 2:

            dato = contarRegistrosNave(archivoNaves);
            printf("En total hay un total de |%i| naves\n",dato);

            break;
        case 3:
            dato = menuTipoNaves(arrNaves,validos);
            printf("En total hay un total de |%i| naves del tipo de nave elegido\n", dato);
            break;
        case 4:
            posicionNave = navesConMayorHoraDeVuelo(arrNaves,validos);
            puts("----------------------NAVE CON MAYOR HORAS DE VUELO-----------------------");
            mostrarUnaNave(arrNaves[posicionNave]);
            break;
        case 5:
            posicionNave = navesConMenorHoraDeVuelo(arrNaves,validos);
            puts("----------------------NAVE CON MENOR HORAS DE VUELO-----------------------");
            mostrarUnaNave(arrNaves[posicionNave]);
            break;
        case 6:
            posicionNave = naveConMayorVuelosRealizados(arrNaves,validos);
            puts("--------------NAVE CON MAYOR CANTIDAD DE VUELOS REALIZADOS----------------");
            mostrarUnaNave(arrNaves[posicionNave]);
            break;
        case 7:
            posicionNave =naveConMenorVuelosRealizados(arrNaves,validos);
            puts("--------------NAVE CON MENOR CANTIDAD DE VUELOS REALIZADOS----------------");
            mostrarUnaNave(arrNaves[posicionNave]);
            break;

        default:
            puts("ERROR opcion invalida,reintente...");
            break;

        }

        printf("\nQuiere seguir consultando datos? s/n: ");
        fflush(stdin);
        op = getch(op);
        limpiarPantalla();

    }
    while(op=='s');

}

int menuTipoNaves(stNaves arregloNave[], int validos)
{
    int dato=0, resultado=0;
    char tipo[DIM_MAX_STR];

    limpiarPantalla();

    puts("Elija el tipo de nave que desea saber su cantidad:");
    puts("------------------------------------------");
    puts("1. StarShip");
    puts("2. Falcon 9");
    puts("3. Falcon Heavy");
    puts("------------------------------------------");
    dato = preguntarDato();

    switch(dato)
    {
    case 1:
        strcpy(tipo,"starship");
        resultado = cantNavesXTipos(arregloNave,validos,tipo);
        break;
    case 2:
        strcpy(tipo,"falcon 9");
        resultado = cantNavesXTipos(arregloNave,validos,tipo);
        break;
    case 3:
        strcpy(tipo,"falcon heavy");
        resultado = cantNavesXTipos(arregloNave,validos,tipo);
        break;
    default:
        puts("Por favor ingrese una opcion correcta");
        break;
    }

    return resultado;

}

int buscarNaveXID(stNaves arr[],int validos, int datoID)
{
    int i=0;
    while(i < validos)
    {
        if(arr[i].idNave == datoID)
        {
            return i;
        }
        i++;
    }
    return -1;
}

int cantNavesXTipos(stNaves arr[], int validos, char tipo[])
{
    int cant=0;
    for(int i=0; i < validos; i++)
    {
        if(strcmpi(arr[i].tipoDeNave,tipo)==0)
        {
            cant++;
        }
    }
    return cant;
}


int navesConMayorHoraDeVuelo(stNaves arregloNave[],int validos)
{

    stNaves aux;
    aux.HorasDeVueloAcumuladas = 0;
    int posMayor = 0;
    int i = 0;
    while(i<validos)
    {
        if(arregloNave[i].HorasDeVueloAcumuladas > aux.HorasDeVueloAcumuladas)
        {
            aux = arregloNave[i];
            posMayor = i;
        }
        i++;
    }
    return posMayor;
}

int navesConMenorHoraDeVuelo(stNaves arregloNave[],int validos)
{

    stNaves aux;
    aux.HorasDeVueloAcumuladas = 0;
    int posMenor = 0;
    int i = 0;
    while(i<validos)
    {
        if(arregloNave[i].HorasDeVueloAcumuladas <= aux.HorasDeVueloAcumuladas)
        {
            aux = arregloNave[i];
            posMenor = i;
        }
        i++;
    }

    return posMenor;
}


int naveConMayorVuelosRealizados(stNaves arregloNave[],int validos)
{

    int naveMayor = 0;
    stNaves aux;
    aux.CantidadDeVuelosRealizados = 0;

    int i = 0;
    while(i<validos)
    {
        if(arregloNave[i].CantidadDeVuelosRealizados > aux.CantidadDeVuelosRealizados)
        {
            aux = arregloNave[i];
            naveMayor = i;
        }
        i++;
    }
    return naveMayor;
}

int naveConMenorVuelosRealizados(stNaves arregloNave[],int validos)
{

    int naveMenor = 0;
    stNaves aux;
    aux.CantidadDeVuelosRealizados = 0;

    int i = 0;
    while(i<validos)
    {
        if(arregloNave[i].CantidadDeVuelosRealizados <= aux.CantidadDeVuelosRealizados)
        {
            aux = arregloNave[i];
            naveMenor = i;
        }
        i++;
    }

    return naveMenor;
}

int mostrarNavesXEstado(char archivoNaves[], int estado)
{
    int flag = 0;
    stNaves aux;
    FILE * buffer=fopen(archivoNaves,"rb");
    if(buffer != NULL)
    {
        while(fread(&aux,sizeof(stNaves),1,buffer) > 0)
        {
            if(aux.estado == estado)
            {
                mostrarUnaNave(aux);
                flag = 1;
            }

        }
        fclose(buffer);
    }
    else
    {
        printf("Error con el archivo\n");
    }
    return flag;
}
int contarRegistrosNave(char archivoNaves[])
{
    int cant=0;
    FILE* buffer= fopen(archivoNaves,"rb");
    if(buffer != NULL)
    {
        fseek(buffer,sizeof(stNaves)-1,SEEK_END);
        cant=ftell(buffer)/sizeof(stNaves);
        fclose(buffer);
    }
    else
    {
        puts("Error con el archivo");
    }

    return cant;
}

int contarXestadoNave(char archivoNave[],int estado){

int contador = 0;
stNaves aux;
FILE* bufferNave;
bufferNave = fopen(archivoNave,"rb");
if(bufferNave != NULL){
    while(fread(&aux,sizeof(stNaves),1,bufferNave)>0){
        if(aux.estado == estado){
            contador++;
        }

    }
    fclose(bufferNave);
}else{
puts("ERROR en el archivo");
}
return contador;
}




