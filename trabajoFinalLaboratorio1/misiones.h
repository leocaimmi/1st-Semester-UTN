#ifndef MISIONES_H_INCLUDED
#define MISIONES_H_INCLUDED
#define DIM_MAX_ARCHI 30
#define DIM_MAX_STR 40
#define DIM_MAX_TXT 256

typedef struct {
    int IDMision;
    int IDNave;
    int estado; // 1.Listo 2.En vuelo 3.Retornada 4.Cancelada 5.Fallida)
    char destino[DIM_MAX_STR];
    char cargamento[DIM_MAX_STR];
    int tripulantes[DIM_MAX_STR];
    char detalleMision[DIM_MAX_TXT];

} stMision;


//varios
void retornarMisionXID(stMision* aux,char archivoMisiones[], int datoID);

int encontrarPosicionMision(char archivoMision[],int idMision);

/// validaciones
int validarIdMision(char archivoMisiones[], int datoID);
int validarDestinoMision(char archivoMisiones[], char destino[]);
int validarEstadoNaveMision(char archivoNaves[], int datoID);
int validarCaracteresEnEntero(int dato);
int validarSiMisionLista(char archivoMisiones[], int misionID);
int encontrarUltimaIDMision(char archivoMisiones[]);

int validarEstadoMisionAModificar();
int validarEstadoMision(int estadoVariable);


/// crear mision
stMision crearUnaMision(char archivoMisiones[], char archivoNaves[], char archivoAstro[]);
void elegirDestino(char archivoMisiones[], char destino[]);
void elegirCargamento(char cargamento[]);
void retornarTipoDeNave(char archivoNaves[], char tipoNave[], int datoID);
void cargarTripulantesMision(char archivoAstro[],int maxi,int IDTripulantes[]);
int disponibilidadTripulantesMision(char tipoNave[]);
void cambiarEstadoAstronauta(char archivoAstro[],int datoID,int estado);
void elegirDetallesDeLaMision(char detalles[]);
void detallesMisionXdestino(char detalles[],char destino[]);
int cantidadMaximaDeTripulantes(char archivoNaves[],int naveID);



/// mostrar
void mostrarDestino();
void mostrarCargamento();
void mostrarAstronautasDisponibles(char archivoAstro[]);
void mostrarTodasLasNavesDisponibles(char archivoNaves[]);
void mostrarUnaMision(stMision aux,int maxTripulantes);
void mostrarTodasLasMisiones(char archivoMisiones[],char archivoNaves[]);
void mostrarMisionesXEstado(char archivoMisiones[],char archivoNaves[],int estado);

///archivo
void cargarArchivoMisiones(char archivoAstro[], char archivoNaves[], char archivoMision[]);


///modificar
void modificarMisionLista(char archivoAstro[],char archivoMisiones[], char archivoNaves[]);
int posibilidadDeEstadoMision(int numRand);
void cambiarEstadoDeTripulantesMision(char archivoAstro[], int cantTripu,int tripulantes[], int estado);

void lanzarMision(stMision*auxMision, char archivoAstro[], char archivoNaves[], int maxTripu,char archivoMisiones[]);


void cambiarEstadoDeNaveMision(char archivoNaves[],int naveID,int estado);

void cancelarMision(stMision* aux, char archivoAstro[], char archivoNaves[],int maxTripu,char archivoMisiones[]);

void agregarEstadisticasATripulantes(char archivoAstro[],int tripulantes[],int maxTripu, int horasDeVuelo,char destino[]);
void agregarUnaEstadisticaATripulante(int posicion,char archivoAstro[],int horasDeVuelo,char destino[]);

void agregarEstadisticasANave(char archivoNaves[],int horasDeVuelo,int naveID);

void modificarMisionEnVuelo(char archivoMisiones[],char archivoNaves[], char archivoAstros[]);
void cambiarEstadoDeUnaMision(char archivoMisiones[],int idMision,int estado);
//consulta
void consultaMision(char archivoMisiones[]);
void opcionesConsulta();
int mostrarTotalDeMisiones(char archivoMisiones[]);
int contarMisionesPorEstado(char archivoMisiones[], int estado);


#endif // MISIONES_H_INCLUDED
