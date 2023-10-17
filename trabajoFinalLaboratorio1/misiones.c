#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "astronauta.h"
#include "nave.h"
#include "menu.h"
#include "misiones.h"
#define DIM_MAX_ARCHI 30
#define DIM_MAX_STR 40
#define DIM_MAX_TXT 256




// crear una mision

stMision crearUnaMision(char archivoMisiones[], char archivoNaves[], char archivoAstro[])
{

    int cant=0, estadoNave=2;

    stMision aux;


    int ultimaID = encontrarUltimaIDMision(archivoMisiones);
    aux.estado = 1;   // autoincremental
    aux.IDMision = ultimaID +1; // autoincremental

    do
    {
        limpiarPantalla();
        mostrarNavesXEstado(archivoNaves,1);
        printf("Ingrese el ID de la nave que desea utilizar: ");
        aux.IDNave = preguntarDato();
    }
    while (validarIDNave(archivoNaves,aux.IDNave) == 0 && validarEstadoNaveMision(archivoNaves,aux.IDNave) == 0);

    cant= cantidadMaximaDeTripulantes(archivoNaves,aux.IDNave); // retorno los validos de la nave para los tripulantes

     // aca cambio el estado de la nave a en mision ya que no quiero que se vuelva a elegir
    cambiarEstadoDeNaveMision(archivoNaves,aux.IDNave,estadoNave);


    if(contarAstronautasXEstado (archivoAstro,1) < cant)
    {
        puts("No hay astronautas disponibles, cargue mas");

    }
    else
    {

    elegirDestino(archivoMisiones, aux.destino);  // el usuario elije el destino

    elegirCargamento(aux.cargamento); // se lleva un cargamento

    cargarTripulantesMision(archivoAstro,cant,aux.tripulantes); // se cargan los tripulantes dependiendo la nave

    detallesMisionXdestino(aux.detalleMision,aux.destino); // los detalles de la mision se ponen de manera predeterminada
    }




    return aux;
}




int encontrarUltimaIDMision(char archivoMisiones[])
{

    int ultimaID;
    stMision misionAux;
    FILE* aux;
    aux = fopen(archivoMisiones,"rb");
    if(aux != NULL)
    {

        fseek(aux,sizeof(stMision)*(-1),SEEK_END);
        fread(&misionAux,sizeof(stMision),1,aux);
        ultimaID = misionAux.IDMision;

        fclose(aux);
    }
    else
    {
        puts("error con el archivo");
    }
    return ultimaID;
}

int cantidadMaximaDeTripulantes(char archivoNaves[],int naveID)
{
    int cant=0;
    char auxTipoNave[DIM_MAX_STR];
    stNaves aux;
    FILE * buffer=fopen(archivoNaves,"rb");
    if(buffer != NULL)
    {
        while(fread(&aux,sizeof(stNaves),1,buffer)>0)
        {
            if(aux.idNave == naveID)
            {
                strcpy(auxTipoNave,aux.tipoDeNave);
                cant=disponibilidadTripulantesMision(auxTipoNave);
            }
        }
        fclose(buffer);
    }
    else
    {
        puts("Error con el archivo");
    }


    return cant;
}

void mostrarTodasLasNavesDisponibles(char archivoNaves[])
{
    stNaves aux;
    int disponible=1;

    FILE*buffer=fopen(archivoNaves,"rb");

    if (buffer != NULL)
    {
        while(fread(&aux,sizeof(stNaves),1,buffer) >0)
        {
            if(aux.estado == disponible)
            {
                mostrarUnaNave(aux);
            }
        }

        fclose(buffer);
    }
    else
    {
        puts("Error con el archivo");
    }

}

void mostrarDestino()
{
    puts("--------------------Destinos--------------------");
    puts("1. Orbita Terrestre");
    puts("2. Estacion Espacial Internacional");
    puts("3. La Luna");
    puts("4. Marte");
    puts("5. Saturno");
}
void elegirDestino(char archivoMisiones[], char destino[])
{

    int opsw = 0;
    int flag = 0;

    do
    {
        limpiarPantalla();
        mostrarDestino();
        puts("Ingrese el destino que desea ir: ");
        opsw = preguntarDato();
        limpiarPantalla();
        switch(opsw)
        {
        case 1:

            flag = validarDestinoMision(archivoMisiones, "Orbita Terrestre");

            if (flag == 1 )
            {
                puts("Ya existe una mision a ese destino, intente con otro destino..");
            }
            else
            {

                strcpy(destino,"Orbita Terrestre");
                flag = 0;
            }



            break;
        case 2:
            flag = validarDestinoMision(archivoMisiones, "EEI");
            if (flag == 1)
            {
                puts("Ya existe una mision a ese destino, intente con otro destino..");
            }
            else
            {

                strcpy(destino, "EEI");
                flag = 0;
            }
            break;
        case 3:
            flag = validarDestinoMision(archivoMisiones, "La luna");
            if (flag == 1)
            {
                puts("Ya existe una mision a ese destino, intente con otro destino..");
            }
            else
            {

                strcpy(destino,"La luna");
                flag = 0;
            }
            break;

        case 4:
            flag = validarDestinoMision(archivoMisiones, "Marte");
            if (flag == 1)
            {
                puts("Ya existe una mision a ese destino, intente con otro destino..");
            }
            else
            {

                strcpy(destino, "Marte");
                flag = 0;
            }
            break;

        case 5:
            flag = validarDestinoMision(archivoMisiones, "Saturno");
            if (flag == 1)
            {
                puts("Ya existe una mision a ese destino, intente con otro destino..");
            }
            else
            {

                strcpy(destino, "Saturno");
                flag = 0;
            }
            break;

        default:
            flag =1;
            printf("Dato incorrecto, ingrese una opcion valida...");
            break;
        }
    }
    while(flag == 1);
    puts("-------------------------------------");
    printf("Destino elegido: %s\n",destino);
    puts("-------------------------------------");
    system("pause");

}

int validarDestinoMision(char archivoMisiones[], char destino[])
{
    stMision aux;
    int flag = 0;
    FILE * buffer = fopen(archivoMisiones, "rb");

    if (buffer != NULL)
    {
        while ((fread(&aux,sizeof(stMision),1,buffer) > 0) && flag == 0)
        {

            if ((strcmpi(aux.destino,destino) == 0) && aux.estado == 2)
            {
                flag = 1;
            }
        }
        fclose(buffer);
    }
    else
    {
        printf("Error en el archivo");
    }

    return flag;
}
int validarIdMision(char archivoMisiones[], int datoID)
{
    int flag = 0;
    stMision aux;
    FILE* buffer = fopen(archivoMisiones,"rb");

    if (buffer != NULL)
    {
        while(fread(&aux,sizeof(stMision),1,buffer) > 0 && flag == 0)
        {
            if (aux.IDMision == datoID)
            {
                flag = 1;
            }
        }
        fclose(buffer);
    }
    else
    {
        puts("ERROR, archivo invalido");
    }
    if(flag == 0)
    {
        puts("Error, ID incorrecto...");
    }

    return flag;
}
int validarEstadoNaveMision(char archivoNaves[], int datoID)
{

    int flag = 0;
    stNaves aux;
    FILE* buffer = fopen(archivoNaves,"rb");

    if (buffer != NULL)
    {
        while(fread(&aux,sizeof(stNaves),1,buffer) > 0 && flag == 0)
        {
            if (aux.estado == 1 && aux.idNave == datoID)
            {
                flag = 1;
            }
        }
        fclose(buffer);
    }
    else
    {
        puts("ERROR, archivo invalido");
    }

    if(flag == 0)
    {
        puts("La nave no esta disponible");
    }
    return flag;
}

void mostrarCargamento()
{
    puts("--------------------Tipos de Cargamento--------------------");
    puts("1. Satelite");
    puts("2. Insumos para la EEI");
    puts("3. R.O.V.E.R.");
    puts("4. Aparatos Electronicos");
    puts("5. Kit de primeros auxilios");
    puts("6. Kit mecanico");
    puts("------------------------------------------------------------");
}
void elegirCargamento(char cargamento[])
{
    int flag=0;
    int opsw = 0;

    do
    {
        mostrarCargamento();
        printf("Ingrese el tipo de cargamento que desea llevar: ");
        opsw = preguntarDato();

        switch(opsw)
        {
        case 1:
            strcpy(cargamento,"Satelite");
            flag=0;
            break;
        case 2:
            strcpy(cargamento,"Insumos para la EEI");
            flag=0;
            break;
        case 3:
            strcpy(cargamento,"R.O.V.E.R.");
            flag=0;
            break;
        case 4:
            strcpy(cargamento,"Aparatos Electronicos");
            flag=0;
            break;
        case 5:
            strcpy(cargamento,"Kit de primeros auxilios");
            flag=0;
            break;
        case 6:
            strcpy(cargamento,"Kit mecanico");
            flag=0;
            break;
        default:
            printf("Dato incorrecto, ingrese una opcion valida...\n");
            flag=1;
            break;

        }

        limpiarPantalla();
    }
    while(flag==1);


}


int disponibilidadTripulantesMision(char tipoNave[])
{
    int dato=0;

    if(strcmpi(tipoNave, "starship")==0)
    {
        dato= 7;

    }

    if(strcmpi(tipoNave, "falcon 9")==0)
    {
        dato= 5;

    }

    if(strcmpi(tipoNave,"falcon heavy")==0)
    {
        dato= 3;
    }

    return dato;
}

//se eligen los tripulantes para la mision
void cargarTripulantesMision(char archivoAstro[],int maxi,int IDTripulantes[])
{
    int estado=3;
    int i=0;
    int IDAstro = 0;
    do
    {
        mostrarAstronautasDisponibles(archivoAstro);
        puts("------------Estos son todos los astronautas disponibles---------------\n");
        puts("|Aclaracion: es necesario completar el maximo de astronautas de la nave elegida|");
        printf("MAXIMO :%i \n",maxi);
        printf("|Usted va %i de %i|\n",i,maxi);
        puts("\nIngrese el ID del astronauta que desea mandar a la mision");

        do
        {
            IDAstro= preguntarDato();
        }
        while(validarIDastro(IDAstro,archivoAstro)== 0);

        cambiarEstadoAstronauta(archivoAstro,IDAstro,estado); //modificar estado a 3 (EN MISION)


        IDTripulantes[i]=IDAstro; //cargar un tripulante a la mision

        i++;
        printf("%i de %i astronautas \n",i,maxi);


        limpiarPantalla();
    }
    while(i < maxi);

    if(i == maxi)
    {
        puts("Se alcanzo el limite maximo de tripulantes");
    }


}


// mostrar astros con estado 1
void mostrarAstronautasDisponibles(char archivoAstro[])
{
    stAstronauta aux;
    FILE * buffer= fopen(archivoAstro, "rb");

    if(buffer != NULL)
    {
        while(fread(&aux,sizeof(stAstronauta),1,buffer)>0)
        {
            if(aux.estado == 1)
            {
                mostrarUnAstronauta(aux);
            }
        }
        fclose(buffer);
    }
    else
    {
        puts("Error con el archivo");
    }


}

// se le cambia el estado al astronauta
void cambiarEstadoAstronauta(char archivoAstro[],int datoID,int estado)
{

    stAstronauta aux;
    FILE* buffer=fopen(archivoAstro,"r+b");

    int posAstro=0;

    if(buffer != NULL)
    {


        posAstro=encontrarPosicionAstroXID(archivoAstro,datoID)-1;
        fseek(buffer,sizeof(stAstronauta)*posAstro,SEEK_SET);
        fread(&aux,sizeof(stAstronauta),1,buffer);
        aux.estado = estado;

        fseek(buffer,sizeof(stAstronauta)*(-1),SEEK_CUR);
        fwrite(&aux,sizeof(stAstronauta),1,buffer);


        fclose(buffer);
    }
    else
    {

        puts("ERROR en el archivo");
    }

}

//se ingresan los detalles de la mision
void detallesMisionXdestino(char detalles[],char destino[])
{
    if(strcmpi(destino,"orbita terrestre") ==0)
    {
        dibujoTierra();
        strcpy(detalles, "Mision a la Orbita Terrestre: Se debe entregar el cargamento dentro de la Orbita terrestre, a la Sala de Investigacion. Una vez entregado, volver a la base");
    }
    if(strcmpi(destino,"eei") ==0)
    {
        dibujoEEI();
        strcpy(detalles, "Mision a la E.E.I: Se debe entregar el cargamento a la E.E.I, al centro de Operaciones Especiales. Una vez entregado, volver a la base");
    }
    if(strcmpi(destino,"marte") ==0)
    {
        dibujoMarte();
        strcpy(detalles, "Mision a Marte: Se debe entregar el cargamento a la estacion de Marte, al Capitan Matias S. Doe. Una vez entregado, volver a la base");
    }
    if(strcmpi(destino,"saturno") ==0)
    {
        dibujoSaturno();
        strcpy(detalles, "Mision a Saturno: Se debe entregar el cargamento a la estacion de Saturno, al Oficial Leonardo K. Smith. Una vez entregado, volver a la base");
    }
    if(strcmpi(destino,"la luna") ==0)
    {
        dibujoLuna();
        strcpy(detalles, "Mision a la Luna: Se debe entregar el cargamento al campamento espacial, al Guardia Fabrizio Lemus. Una vez entregado, volver a la base");

    }
    puts("\n\n----------------------------------------------");
    printf("%s",detalles);
}

// cargar archivo mision

void cargarArchivoMisiones(char archivoAstro[], char archivoNaves[], char archivoMision[])
{
    stMision aux;
    FILE* buffer= fopen(archivoMision,"ab");
    int estado = 1;

    if(contarXestadoNave(archivoNaves,estado) != 0){
            if(buffer != NULL)
    {
        aux =crearUnaMision(archivoMision,archivoNaves,archivoAstro);
        fwrite(&aux,sizeof(stMision),1,buffer);
        fclose(buffer);
    }
    else
    {
        puts("Error con el archivo");
    }
    }
    else
    {
        puts("No hay naves disponibles");
    }


}

//mostrar UNA mision

void mostrarUnaMision(stMision aux,int maxTripulantes)
{
    puts("\n------------------------MISION-------------------------");
    printf("ID de la mision..............: %i \n",aux.IDMision);
    printf("Destino......................: %s \n",aux.destino);
    printf("Estado.......................: %i \n",aux.estado);
    printf("ID de la nave................: %i \n",aux.IDNave);
    printf("Cargamento...................: %s \n",aux.cargamento);
    printf("ID de los tripulantes........: ");

    for(int i=0; i < maxTripulantes; i++)
    {
        printf("|%i|",aux.tripulantes[i]);
    }


    printf("\nDetalles de la mision........: \n%s\n",aux.detalleMision);

    puts("---------------------------------------------------------");
}

//mostrar TODAS las misiones

void mostrarTodasLasMisiones(char archivoMisiones[],char archivoNaves[])
{
    stMision aux;
    int cant=0;

    FILE* buffer= fopen(archivoMisiones,"rb");

    if(buffer != NULL)
    {
        while(fread(&aux,sizeof(stMision),1,buffer)>0)
        {
            //me retorna el tipo de nave para poder saber el maximo de tripulantes y de carga de la nave
            cant= cantidadMaximaDeTripulantes(archivoNaves,aux.IDNave);//ya sabiendo el tipo de nave puedo sacar los validos de tripulantes


            mostrarUnaMision(aux,cant); // muestro la mision
        }

        fclose(buffer);
    }
    else
    {
        puts("Error, no hay misiones cargadas...");
    }

}

//retornar una mision por ID

void retornarMisionXID(stMision* aux,char archivoMisiones[], int datoID)
{

    int flag=0;
    FILE* buffer=fopen(archivoMisiones,"rb");
    stMision auxMision;
    if(buffer != NULL)
    {
        while((fread(&auxMision,sizeof(stMision),1,buffer)>0) && flag ==0)
        {
            if(auxMision.IDMision == datoID)
            {
                *aux = auxMision;
                flag = 1;
            }
        }
        fclose(buffer);
    }
    else
    {
        puts("Error con el archivo");
    }

}

//validar si la mision esta lista
int validarSiMisionLista(char archivoMisiones[], int misionID)
{
    stMision aux;
    int flag=0;
    int disponible=1;
    FILE* buffer=fopen(archivoMisiones,"rb");

    if(buffer != NULL)
    {
        while(fread(&aux,sizeof(stMision),1,buffer) >0 && flag==0)
        {
            if(aux.IDMision == misionID && aux.estado == disponible)
            {
                flag= 1;
            }
        }
        fclose(buffer);
    }
    else
    {
        puts("Error con el archivo");
    }
    return flag;
}

//modificar mision con estado lista(decidir si despegar o cancelar)

void modificarMisionLista(char archivoAstro[],char archivoMisiones[], char archivoNaves[])
{
    int misionID=0, dato=0,flag=0, maxTripu=0,estadoMisiones=1;

    stMision aux;

    do
    {
        limpiarPantalla();
        mostrarMisionesXEstado(archivoMisiones,archivoNaves,estadoMisiones);
        puts("\n-------------------------------------------------------");
        puts("Estas son todas las misiones listas");
        puts("Ingrese el ID de la mision que quiere modificar");
        puts("Ingrese -1 para salir al menu");
        misionID= preguntarDato();

        if(misionID == -1)
        {
            return 0;
        }


    }
    while(validarSiMisionLista(archivoMisiones,misionID)==0 );

        retornarMisionXID(&aux,archivoMisiones,misionID);

        maxTripu= cantidadMaximaDeTripulantes(archivoNaves,aux.IDNave);

    while(flag == 0)
    {

        limpiarPantalla();
        mostrarUnaMision(aux,maxTripu);
        puts("----------------------------------------------------");
        puts("Usted eligio esta mision");
        puts("----------------------------------------------------");
        puts("Que desea hacer?");
        puts("1. Lanzar mision (esto hara que el estado de mision pasara a 'En vuelo', la nave a 'Actualmente en mision' y los tripulantes a 'En mision')\n");
        puts("2. Cancelar mision(se cambiara el estado de la mision a 'cancelado' y todos los tripulantes se liberaran a estado 'Listo')\n");
        dato = preguntarDato();
        switch(dato)
        {
        case 1:

            lanzarMision(&aux,archivoAstro,archivoNaves,maxTripu,archivoMisiones);
            flag = 1;
            puts("Mision lanzada con exito");
            break;
        case 2:
            cancelarMision(&aux,archivoAstro,archivoNaves,maxTripu,archivoMisiones);
            flag= 1;
            puts("Mision cancelada");
            break;
        default:
            puts("Ingrese un dato correcto");
            flag= 0;
            break;
        }

    }


}





// lanzo la mision por lo tanto modifico todo

void lanzarMision(stMision*auxMision, char archivoAstro[], char archivoNaves[], int maxTripu,char archivoMisiones[])
{

    int numRand=rand()%100;
    int enVuelo=2;

    //cambio el estado de la mision a envuelo
    cambiarEstadoDeUnaMision(archivoMisiones,auxMision->IDMision,enVuelo);
    //cambio el estado de la nave a en vuelo

    cambiarEstadoDeNaveMision(archivoNaves,auxMision->IDNave,enVuelo);

    // tengo que agregar las horas de vuelo y las misiones realizadas a naves y los tripulantes

    agregarEstadisticasATripulantes(archivoAstro,auxMision->tripulantes,maxTripu,numRand, auxMision->destino);

    agregarEstadisticasANave(archivoNaves,numRand,auxMision->IDNave);
}

// le agrego horas de vuelo a los tripulantes y le sumo una mision realizada
void agregarEstadisticasATripulantes(char archivoAstro[],int tripulantes[],int maxTripu, int horasDeVuelo,char destino[])
{

    int pos=0;

    FILE* buffer=fopen(archivoAstro,"r+b");
    if(buffer != NULL)
    {

        for (int i=0; i < maxTripu; i++)
        {
            pos= encontrarPosicionAstroXID(archivoAstro,tripulantes[i])-1;
            agregarUnaEstadisticaATripulante(pos,archivoAstro,horasDeVuelo,destino);

        }
        fclose(buffer);
    }
    else
    {
        puts("Error con el archivo");
    }
}



void agregarUnaEstadisticaATripulante(int posicion,char archivoAstro[],int horasDeVuelo,char destino[])
{
    stAstronauta auxAstro;
    FILE* buffer = fopen(archivoAstro,"r+b");
    if( buffer != NULL)
    {
        fseek(buffer,sizeof(stAstronauta)*posicion,SEEK_SET);
        fread(&auxAstro,sizeof(stAstronauta),1,buffer);

        if(strcmp(destino,"EEI")==0)
        {
            auxAstro.horasEnEEI+=horasDeVuelo;
        }


        auxAstro.horasDeVuelo += horasDeVuelo;
        auxAstro.cantMisionesRealizadas += 1;


        fseek(buffer,sizeof(stAstronauta)*(-1),SEEK_CUR);
        fwrite(&auxAstro,sizeof(stAstronauta),1,buffer);


        fclose(buffer);
    }
    else
    {
        puts("Error con el archivo");
    }

}


//le agrego horas de vuelo a la nave y le sumo una mision realizada
void agregarEstadisticasANave(char archivoNaves[],int horasDeVuelo,int naveID)
{
    stNaves auxNave;
    int pos=0;
    FILE* buffer= fopen(archivoNaves,"r+b");

    if(buffer != NULL)
    {
        pos= encontrarPosicionNaveXID(archivoNaves,naveID)-1;
        fseek(buffer,sizeof(stNaves)*pos,SEEK_SET);
        fread(&auxNave,sizeof(stNaves),1,buffer);

        auxNave.HorasDeVueloAcumuladas += horasDeVuelo;
        auxNave.CantidadDeVuelosRealizados += 1;

        fseek(buffer,sizeof(stNaves)*(-1),SEEK_CUR);
        fwrite(&auxNave,sizeof(stNaves),1,buffer);

        fclose(buffer);
    }
    else
    {
        puts("Error con el archivo");
    }


}


//// posibilidad con numero rand
//int posibilidadDeEstadoMision(int numRand)
//{
//    if(numRand > 50)
//    {
//        return ;
//    }
//
//    return 5;
//}


// cambiar el estado de los tripulantes de una mision
void cambiarEstadoDeTripulantesMision(char archivoAstro[], int cantTripu,int tripulantes[], int estado)
{


    FILE* buffer;
    buffer = fopen(archivoAstro,"r+b");
    if(buffer != NULL)
    {
        for(int i = 0; i<cantTripu; i++)
        {
            cambiarEstadoAstronauta(archivoAstro,tripulantes[i],estado);

        }
        fclose(buffer);
    }
    else
    {
        puts("Error con el archivo");
    }


}

//cambiar el estado de una nave de una mision
void cambiarEstadoDeNaveMision(char archivoNaves[],int naveID,int estado)
{
    int pos=0;
    stNaves auxNave;

    FILE* bufferNave= fopen(archivoNaves,"r+b");

    if(bufferNave != NULL)
    {

        pos = encontrarPosicionNaveXID(archivoNaves,naveID)-1;
        fseek(bufferNave,sizeof(stNaves)*pos,SEEK_SET);
        fread(&auxNave,sizeof(stNaves),1,bufferNave);

        auxNave.estado = estado;

        fseek(bufferNave,sizeof(stNaves)*(-1),SEEK_CUR);
        fwrite(&auxNave,sizeof(stNaves),1,bufferNave);

        fclose(bufferNave);
    }
    else
    {
        puts("Error con el archivo");
    }

}


void cancelarMision(stMision* aux, char archivoAstro[], char archivoNaves[],int maxTripu,char archivoMisiones[])
{
    int disponible=1;
    int estadoCancelada=4;
    //cambio el estado a mision cancelada

    cambiarEstadoDeUnaMision(archivoMisiones,aux->IDMision,estadoCancelada);


    //tengo que devolver todo a la normalidad
    cambiarEstadoDeTripulantesMision(archivoAstro,maxTripu,aux->tripulantes,disponible);
    cambiarEstadoDeNaveMision(archivoNaves,aux->IDNave,disponible);

}

void modificarMisionEnVuelo(char archivoMisiones[],char archivoNaves[], char archivoAstros[])
{
    int estado = 2;
    int idMision = 0;
    int validos=0;
    int estadoVariable = 0;
    stMision auxMision;
    do
    {
        mostrarMisionesXEstado(archivoMisiones,archivoNaves,estado); //muestra las misiones en vuelo
        puts("-----------------------------------------------------------");
        puts("Ingrese el ID correspondiente de la mision: ");
        puts("Para volver al menu ingrese -1");
        idMision = preguntarDato();
        if(idMision == -1)
        {
            return 0;
        }

    }
    while(validarIdMision(archivoMisiones,idMision) == 0);

    retornarMisionXID(&auxMision,archivoMisiones,idMision);

    estadoVariable = validarEstadoMisionAModificar(); // elijo si la mision fallo o retorno

    cambiarEstadoDeUnaMision(archivoMisiones,idMision,estadoVariable); //aca cambiamos el estado de la mision

    validos= cantidadMaximaDeTripulantes(archivoNaves,auxMision.IDNave);

    if(estadoVariable ==3) // si es retornada vuelve todo a la normalidad
    {
        // dibujo exitoso

        cambiarEstadoDeTripulantesMision(archivoAstros,validos,auxMision.tripulantes,1);
        cambiarEstadoDeNaveMision(archivoNaves,auxMision.IDNave,1);
    }
    else if(estadoVariable == 5) // si la mision es fallida la nave se rompe y los astros vuelven a estar activos
    {
        // dibujo nave rota

        cambiarEstadoDeTripulantesMision(archivoAstros,validos,auxMision.tripulantes,1);
        cambiarEstadoDeNaveMision(archivoNaves,auxMision.IDNave,0);
    }
}


int validarEstadoMisionAModificar()
{
    int op=0, flag = 0,estado=0;
    do
    {
        do
        {
            puts("-------------------Resultado de la mision--------------------");
            puts("1-Nave retornada y mision exitosa..(estado 3)");
            puts("2-Nave rota y mision fallida..(estado 5)");
            puts("Ingrese el estado de la mision: ");
            op = preguntarDato();

        }
        while(validarEstadoMision(op) == 0);



        switch(op)
        {
        case 1:
            puts("La mision fue exitosa...");
            estado = 3;
            flag = 1;
            break;
        case 2:
            puts("La mision resulto fallida...");
            estado = 5;
            flag = 1;
            break;
        default:
            puts("Opcion invalida, reintente...");
            break;
        }
    }
    while(flag == 0);

    return estado;
}
int validarEstadoMision(int estadoVariable)
{
    int flag = 0;

    if(estadoVariable == 1 || estadoVariable == 2)
    {
        flag = 1;
    }
    if(flag == 0)
    {
        puts("Ingrese una opcion valida...");

    }
    return flag;
}
void mostrarMisionesXEstado(char archivoMisiones[],char archivoNaves[],int estado)
{
    int flag = 0;
    int cant = 0;
    stMision auxMision;
    FILE* bufferMision;
    bufferMision = fopen(archivoMisiones,"rb");
    if(bufferMision != NULL)
    {
        while(fread(&auxMision,sizeof(stMision),1,bufferMision)>0)
        {

            if(estado == auxMision.estado)
            {

                cant = cantidadMaximaDeTripulantes(archivoNaves,auxMision.IDNave);
                mostrarUnaMision(auxMision,cant);
                flag = 1;
            }
        }
        fclose(bufferMision);
    }
    else
    {
        puts("Error, no hay misiones de este tipo disponibles");
    }
    if(flag == 0){
        puts("No se encuentran misiones de este tipo...");
    }


}

void cambiarEstadoDeUnaMision(char archivoMisiones[],int idMision,int estado)
{

    int posMision = 0;

    FILE* bufferMisiones;
    bufferMisiones = fopen(archivoMisiones,"r+b");
    stMision aux;

    if(bufferMisiones != NULL)
    {

        posMision = encontrarPosicionMision(archivoMisiones,idMision)-1;

        fseek(bufferMisiones,sizeof(stMision)*posMision,SEEK_SET);
        fread(&aux,sizeof(stMision),1,bufferMisiones);

        aux.estado = estado;

        fseek(bufferMisiones,sizeof(stMision)*(-1),SEEK_CUR);
        fwrite(&aux,sizeof(stMision),1,bufferMisiones);

        fclose(bufferMisiones);
    }
    else
    {
        puts("ERROR en el archivo");
    }

}

int encontrarPosicionMision(char archivoMision[],int idMision)
{
    int posMision=0;
    stMision aux;

    FILE * bufferMision=fopen(archivoMision,"rb");

    if(bufferMision != NULL)
    {
        while(fread(&aux,sizeof(stMision),1,bufferMision)>0)
        {
            if(aux.IDMision == idMision)
            {

                posMision = ftell(bufferMision)/sizeof(stMision);

            }
        }

        fclose(bufferMision);
    }
    else
    {
        printf("Error con el archivo");
    }

    return posMision;
}
//consulta
void consultaMision(char archivoMisiones[])
{

///auxiliares
    int cantidadTotal = 0;
    int estado = 0;


    char op = 's';
    int opsw = 0;

    do
    {
        opcionesConsulta();
        puts("Que opcion elige: ");
        opsw = preguntarDato();

        switch(opsw)
        {
        case 1:
            cantidadTotal = mostrarTotalDeMisiones(archivoMisiones);
            puts("--------------------TOTAL DE MISIONES------------------------");
            if(cantidadTotal >0)
            {
                printf("El total de misiones en el sistema son:(%i)\n",cantidadTotal);
            }
            else
            {
                puts("No hay misiones de este tipo...");
            }
            break;
        case 2:
            estado = 1;
            cantidadTotal = contarMisionesPorEstado(archivoMisiones,estado);
            puts("---------------------MISIONES LISTAS(1)----------------------------");
            if(cantidadTotal >0)
            {
                printf("El total de misiones listas en el sistema son:(%i)\n",cantidadTotal);
            }
            else
            {
                puts("No hay misiones de este tipo...");
            }
            break;
        case 3:
            estado = 2;
            cantidadTotal = contarMisionesPorEstado(archivoMisiones,estado);
            puts("---------------------MISIONES EN VUELO(2)----------------------------");
            if(cantidadTotal >0)
            {
                printf("El total de misiones en vuelo en el sistema son:(%i)\n",cantidadTotal);
            }
            else
            {
                puts("No hay misiones de este tipo...");
            }

            break;
        case 4:
            estado = 3;
            cantidadTotal = contarMisionesPorEstado(archivoMisiones,estado);
            puts("---------------------MISIONES RETORNADAS(3)----------------------------");
            if(cantidadTotal >0)
            {
                printf("El total de misiones retornadas en el sistema son:(%i)\n",cantidadTotal);
            }
            else
            {
                puts("No hay misiones de este tipo...");
            }

            break;
        case 5:
            estado = 4;
            cantidadTotal = contarMisionesPorEstado(archivoMisiones,estado);
            puts("---------------------MISIONES CANCELADAS(4)----------------------------");
            if(cantidadTotal > 0)
            {
                printf("El total de misiones canceladas en el sistema son:(%i)\n",cantidadTotal);
            }
            else
            {
                puts("No hay misiones de este tipo...");
            }
            break;
        case 6:
            estado = 5;
            cantidadTotal = contarMisionesPorEstado(archivoMisiones,estado);
            puts("---------------------MISIONES FALLIDAS(5)----------------------------");
            if(cantidadTotal>0)
            {

                printf("El total de misiones fallidas en el sistema son:(%i)\n",cantidadTotal);
            }
            else
            {
                puts("No hay misiones de este tipo...");
            }

            break;
        default:
            puts("Opcion no valida...");
            break;

        }
        puts("(S/N) si desea volver a consultar otro dato sobre misiones");
        fflush(stdin);
        op = getch(op);

        limpiarPantalla();
    }
    while(op == 's');

}

void opcionesConsulta()
{

    puts("1-Mostrar cantidad de misiones en total............");
    puts("2-Mostrar cantidad de misiones listas....(estado 1)");
    puts("3-Mostrar cantidad de misiones en vuelo..(estado 2)");
    puts("4-Mostrar cantidad de misiones retornadas(estado 3)");
    puts("5-Mostrar cantidad de misiones canceladas(estado 4)");
    puts("6-Mostrar cantidad de misiones fallidas..(estado 5)");

}

///total de misiones.
int mostrarTotalDeMisiones(char archivoMisiones[])
{

    int cantTotal = 0;

    FILE* bufferMisiones;
    bufferMisiones = fopen(archivoMisiones,"rb");
    if(bufferMisiones != NULL)
    {

        fseek(bufferMisiones,sizeof(0),SEEK_END);
        cantTotal = ftell(bufferMisiones)/sizeof(stMision);

        fclose(bufferMisiones);
    }
    else
    {
        puts("ERROR en el archivo");
    }

    return cantTotal;
}

///misiones en vuelo
int contarMisionesPorEstado(char archivoMisiones[], int estado)
{

    stMision auxMision;
    int contEstado = 0;

    FILE* bufferMision;
    bufferMision = fopen(archivoMisiones,"rb");
    if(bufferMision != NULL)
    {
        while(fread(&auxMision,sizeof(stMision),1,bufferMision)>0)
        {
            if(estado == auxMision.estado)
            {
                contEstado++;
            }
        }
        fclose(bufferMision);
    }
    else
    {
        puts("ERROR en el archivo");
    }
    return contEstado;
}


