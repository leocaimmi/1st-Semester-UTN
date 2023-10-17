#ifndef NAVES_H_INCLUDED
#define NAVES_H_INCLUDED
#define DIM_MAX_ARCHI 30
#define DIM_MAX_STR 40
#define DIM_MAX_TXT 256

typedef struct{
int idNave;
char tipoDeNave[DIM_MAX_STR]; //(Starship, Falcon 9, Falcon Heavy) sólo pueden ser esas tres naves, ningún otro tipo se acepta.
int CantidadDeVuelosRealizados;
int HorasDeVueloAcumuladas;
int estado; // (0- mantenimiento 1- Lista para su uso 2- Actualmente en misión 3- De baja)
}stNaves;

// validar
void validarTipoNave(char tipoNave[]);
int validarCantNave(int cont);
int validarSiNaveEstaOcupada(int estado);
int validarIDNave(char archivoNave[], int dato);
int validarEstadoNave(int dato);

int contarNaveXtipo(char archivoNaves[], char tipoNave[]);



// Cargar nave
stNaves cargarUnaNave(char archivoNaves[]);
int encontrarUltimaIDNave(char archivoNaves[]);
void tiposDeNave();


// archivos
void cargarArchivoNaves(char archivoNaves[]);
int contarRegistrosNaveParaElArregloDinamico(char archivoNaves[]);      ///esta funcion me devuelve el tamaño exacto para el arreglo dinamico


// mostrar
void mostrarUnaNave(stNaves aux);
void mostrarTodasLasNaves(char archivoNaves[]);
int menuTipoNaves(stNaves arregloNave[], int validos);

// modificar

int encontrarPosicionNaveXID(char archivoNaves[], int IDNave);
void cargarNaveModificada(char archivoNaves[]);
void modificarUnaNave(stNaves * aux);



// arreglo
int archivoToArregloNaves(char archivoNaves[],stNaves arrNaves[]);
stNaves* crearArregloDinamicoNave(int tam);
void mostrarArregloNave(stNaves arrNaves[], int validos);

// consulta

void ConsultaNave(char archivoNaves[]);
void opcionesParaConsultarNaves();
void menuConsultarPorNave(char archivoNaves[],stNaves arrNaves[], int validos);
int buscarNaveXID(stNaves arr[],int validos, int datoID);
int contarRegistrosNave(char archivoNaves[]);                           ///tuve que crear esta funcion de contar registros ya que esta tengo que dividir la cantidad de registro por el tamaño de la estructura
int cantNavesXTipos(stNaves arr[], int validos, char tipo[]);



int navesConMayorHoraDeVuelo(stNaves arregloNave[],int validos);        ///devuelve la posicion donde se encuentra la nave con mayor horas de vuelo
int navesConMenorHoraDeVuelo(stNaves arregloNave[],int validos);        ///devuelve la posicion donde se encuentra la nave con menor horas de vuelo
int naveConMayorVuelosRealizados(stNaves arregloNave[],int validos);    ///devuelve la posicion donde se encuentra la nave con mayor cantidad de vuelos realizados
int naveConMenorVuelosRealizados(stNaves arregloNave[],int validos);    ///devuelve la posicion donde se encuentra la nave con menor cantidad de vuelos realizados
int mostrarNavesXEstado(char archivoNaves[], int estado);               ///Cambie la ubi de esta funcion ya que no se utilizaba antes y me sirve para la consulta
int contarXestadoNave(char archivoNave[],int estado);
#endif // NAVES_H_INCLUDED



