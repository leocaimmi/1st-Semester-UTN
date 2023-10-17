#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "astronauta.h"
#include "naves.h"
#define DIM_MAX_ARCHI 15
#define DIM_MAX_STR 20

stNaves cargarUnaNave(char naves[]){

int dato = 0;
stNaves aux;
///Datos default
int ultimaID = encontrarUltimaIDNave(naves);
aux.id = ultimaID + 1;
aux.CantidadDeVuelosRealizados = 0;
aux.HorasDeVueloAcumuladas = 0;
aux.estado = 1;

validarTipoNave(aux.tipoDeNave);



return aux;
}

int encontrarUltimaIDNave(char naves[])
{

    int ultimaID;
    stNaves naveAux;
    FILE* aux;
    aux = fopen(naves,"rb");
    if(aux != NULL)
    {

        fseek(aux,sizeof(stNaves)*-1,SEEK_END);
        fread(&naveAux,sizeof(stNaves),1,aux);
        ultimaID = naveAux.id;
        fclose(aux);
    }
    return ultimaID;
}

void validarTipoNave(char nave[]){
int flag = 0;
tiposDeNave();
scanf("%i",&dato);
do{
switch(dato){
case 1:
    strcpy(nave,"StarShip");
    flag = 1;
    break;
case 2:
    strcpy(nave,"Falcon 9");
    flag = 1;
    break;
case 3:
    strcpy(nave,"Falcon Heavy");
    flag = 1;
    break;
default:
    printf("ERROR,ingrese una nave valida...\n");
    break;
}

}while(flag == 0);

}

void tiposDeNave(){
puts("----------------SELECCIONE UN TIPO DE NAVE------------------\n");
printf("1-StarShip\n");
printf("2-Falcon 9\n");
printf("3-Falcon Heavy\n");
}
