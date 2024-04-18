#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int CHARMAX = 20;

 void cargarCandidatos(char candidatos[][CHARMAX]);
 void mostrarTabla(char candidatos[][CHARMAX],int arr[][5]);

int main()
{

char candidatos[4][30];
int votos[5][5]={{1,194,48,206,45},{2,180,20,320,16},{3,221,90,140,20},{4,432,51,821,14},{5,820,61,946,18}};
mostrarTabla(candidatos,votos);

    return 0;
}

 ///Imprimir la tabla anterior con cabeceras incluidas.

 void cargarCandidatos(char candidatos[][CHARMAX]){
 char ascii = 65;
 strcpy(candidatos[0],"distrito");

 for(int i = 1;i<5;i++){
    strcpy(candidatos[i],"Candidato ");
    candidatos[i][10]=ascii;
    ascii++;
 }

 }


void mostrarTabla(char candidatos[][CHARMAX],int arr[][5]){

cargarCandidatos(candidatos);
for(int i = 0;i<5;i++){
    printf("\t| %s |",candidatos[i]);
}
printf("\n");
for(int i = 0;i<5;i++){

    for(int j = 0;j<5;j++){
        printf("\t| %i |\t",arr[i][j]);
    }
    printf("\n");
}

}
