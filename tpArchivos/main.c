#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#define DIM_MAX 30
#include "prototipado.h"

int main()
{
    char archivo[DIM_MAX] = "Personas";
    Pila legajos;
    inicpila(&legajos);
    stAlumno persona[DIM_MAX];

 menu(archivo,persona,&legajos);

    return 0;
}



