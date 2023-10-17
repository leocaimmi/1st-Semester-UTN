#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#define DIM_MAX_ARCHI 30
#define DIM_MAX_STR 40
#define DIM_MAX_TXT 256

//menu
void menuPrincipal(char archivoAstronautas[],char archivoNaves[],char archivoMisiones[]);
int validarOpcionMenu(int dato);
void pantallaDeCarga();
void logoUTN();
void despedida();
void dibujoLuna();
void dibujoSaturno();
void dibujoMarte();
void dibujoEEI();
void dibujoTierra();

//menu astro
void menuAstronauta(char archivoAstronauta[]);
void opcionMostrarAstronautas(char archivoAstro[]);
void dibujoAstronauta();

//menu nave
void dibujoNaves();
void opcionMostrarNaves(char archivoNaves[]);
void menuNaves(char archivoNaves[]);

// menu misiones
void dibujoMision();

void menuMisiones(char archivoMisiones[],char archivoNaves[], char archivoAstro[]);
void opcionMostrarMisiones(char archivoMisiones[],char archivoNaves[]);

#endif // MENU_H_INCLUDED
