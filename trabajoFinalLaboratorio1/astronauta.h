#ifndef ASTRONAUTA_H_INCLUDED
#define ASTRONAUTA_H_INCLUDED
#define DIM_MAX_ARCHI 30
#define DIM_MAX_STR 40
#define DIM_MAX_TXT 256

///Estructura astronauta

typedef struct
{

int id;///automatico
char nombre[DIM_MAX_STR];
char apellido[DIM_MAX_STR];
char apodo[DIM_MAX_STR];
int edad;
char nacionalidad[DIM_MAX_STR];
char especialidad[DIM_MAX_STR]; //(piloto, astrofísico, ingeniero espacial, biólogo, etc)
int horasDeVuelo;           ///automatico
int cantMisionesRealizadas; ///automatico
int horasEnEEI;             ///automatico
int estado; //(1- Activo 2- Retirado, 3-EN MISION)

}stAstronauta;


///Prototipados astronauta

//varias

void limpiarPantalla();
int preguntarDato();
int contarRegistrosAstro(char archivo[]);
stAstronauta * crearArregloDinamicoAstro( int tam);


//validaciones

stAstronauta crearUnAstro(char astronauta[]);
int validarString(char auxNombre[]);
int validarEdad(int edad);
int validarNacionalidad(char nacionalidad[]);
void validarEspecialidad(char especialidad[]);
int validarEstado(int datoEstado);
void mostrarEspecialidad();
int encontrarUltimaID(char astronauta[]);///autoincrementar ID
int validarDigitosEnStrings(char auxNombre[]);
int validarCaracteresEnEnteroMision(int dato);

// archivos
void cargarUnAstroToArchivo(char archivoAstronautas[]);
void mostrarAstronautas(char archivoAstronautas[]);
void mostrarUnAstronauta(stAstronauta aux);



//Modificar

int validarIDastro(int dato,char archivoAstro[]);
void modificarUnAstro(stAstronauta* astro);
int encontrarPosicionAstroXID(char archivoAstronautas[],int datoID);
void cargarAstroModificado(char archivoAstronauta[]);


//Consulta

int archivoToArregloAstro(stAstronauta arrAstro[], char archivoAstro[]);

void mostrarArregloAstro(stAstronauta arrAstro[],int validos);

void ConsultaAstro(char archivoAstro[]);
void opcionesParaConsultarAstronauta();
void menuConsultarPorAstronauta(char archivoAstronautas[],stAstronauta arregloAstro[],int validos);
int buscarIDastro(stAstronauta astro[],int idBuscado,int validos);
int buscarNombreAstro(stAstronauta arregloAstro[],char nombre[],int validos);
int buscarApellidoAstro(stAstronauta arregloAstro[],char apellido[],int validos);
int buscarApodoAstro(stAstronauta arregloAstro[],char apodo[],int validos);
int buscarPorEdadUnAstro(stAstronauta arregloAstro[],int dato,int validos);
int buscarPaisAstro(stAstronauta arregloAstro[],char auxPais[],int validos);
int buscarAstronautasPorEstado(stAstronauta arregloAstro[],int estadoAstro,int validos);
stAstronauta buscarAstroConMayorExpHorasVuelo(stAstronauta arregloAstro[],int validos);
stAstronauta buscarAstroConMayorExpEnMisiones(stAstronauta arregloAstro[],int validos);
stAstronauta buscarAstroConMenorExpHorasVuelo(stAstronauta arregloAstro[],int validos);
stAstronauta buscarAstroConMenorExpEnMisiones(stAstronauta arregloAstro[],int validos);
int contarAstronautasXEstado(char archivoAstro[],int estado);





#endif // ASTRONAUTA_H_INCLUDED
