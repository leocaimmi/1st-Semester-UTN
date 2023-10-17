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

///varios
const char* paises[DIM_MAX_TXT] =
{
    "Afganistan",
    "Albania",
    "Alemania",
    "Andorra",
    "Angola",
    "Antigua y Barbuda",
    "Arabia Saudita",
    "Argelia",
    "Argentina",
    "Armenia",
    "Australia",
    "Austria",
    "Azerbaiyan",
    "Bahamas",
    "Bangladesh",
    "Barbados",
    "Barein",
    "Belgica",
    "Belice",
    "Benin",
    "Bielorrusia",
    "Birmania",
    "Bolivia",
    "Bosnia",
    "Botsuana",
    "Brasil",
    "Brunei",
    "Bulgaria",
    "Burkina Faso",
    "Burundi",
    "Butan",
    "Cabo Verde",
    "Camboya",
    "Camerun",
    "Canada",
    "Catar",
    "Chad",
    "Chile",
    "China",
    "Chipre",
    "Vaticano",
    "Colombia",
    "Comoras",
    "Corea del Norte",
    "Corea del Sur",
    "Costa de Marfil",
    "Costa Rica",
    "Croacia",
    "Cuba",
    "Dinamarca",
    "Dominica",
    "Ecuador",
    "Egipto",
    "El Salvador",
    "Emiratos Arabes Unidos",
    "Eritrea",
    "Eslovaquia",
    "Eslovenia",
    "Espana",
    "Estados Unidos",
    "Estonia",
    "Eswatini",
    "Etiopia",
    "Filipinas",
    "Finlandia",
    "Fiyi",
    "Francia",
    "Gabon",
    "Gambia",
    "Georgia",
    "Ghana",
    "Granada",
    "Grecia",
    "Guatemala",
    "Guinea",
    "Guinea Bisau",
    "Guinea Ecuatorial",
    "Guyana",
    "Haiti",
    "Honduras",
    "Hungria",
    "India",
    "Indonesia",
    "Irak",
    "Iran",
    "Irlanda",
    "Islandia",
    "Islas Marshall",
    "Islas Salomon",
    "Israel",
    "Italia",
    "Jamaica",
    "Japon",
    "Jordania",
    "Kazajistan",
    "Kenia",
    "Kirguistan",
    "Kiribati",
    "Kuwait",
    "Laos",
    "Lesoto",
    "Letonia",
    "Libano",
    "Liberia",
    "Libia",
    "Liechtenstein",
    "Lituania",
    "Luxemburgo",
    "Madagascar",
    "Malasia",
    "Malaui",
    "Maldivas",
    "Mali",
    "Malta",
    "Marruecos",
    "Mauricio",
    "Mauritania",
    "México",
    "Micronesia",
    "Moldavia",
    "Monaco",
    "Mongolia",
    "Montenegro",
    "Mozambique",
    "Namibia",
    "Nauru",
    "Nepal",
    "Nicaragua",
    "Niger",
    "Nigeria",
    "Noruega",
    "Nueva Zelanda",
    "Oman",
    "Paises Bajos",
    "Pakistan",
    "Palaos",
    "Panama",
    "Papua Nueva Guinea",
    "Paraguay",
    "Peru",
    "Polonia",
    "Portugal",
    "Reino Unido",
    "Republica Centroafricana",
    "Republica Checa",
    "Republica Democrática del Congo",
    "Republica Dominicana",
    "Ruanda",
    "Rumania",
    "Rusia",
    "Samoa",
    "San Cristobal y Nieves",
    "San Marino",
    "San Vicente y las Granadinas",
    "Santa Lucia",
    "Santo Tome y Príncipe",
    "Senegal",
    "Serbia",
    "Seychelles",
    "Sierra Leona",
    "Singapur",
    "Siria",
    "Somalia",
    "Sri Lanka",
    "Sudafrica",
    "Sudan",
    "Sudan del Sur",
    "Suecia",
    "Suiza",
    "Surinam",
    "Tailandia",
    "Tanzania",
    "Tayikistan",
    "Timor Oriental",
    "Togo",
    "Tonga",
    "Trinidad y Tobago",
    "Tunez",
    "Turkmenistan",
    "Turquia",
    "Tuvalu",
    "Ucrania",
    "Uganda",
    "Uruguay",
    "Uzbekistan",
    "Vanuatu",
    "Venezuela",
    "Vietnam",
    "Yemen",
    "Yibuti",
    "Zambia",
    "Zimbabue"
};

void limpiarPantalla()
{
    system("cls");
}


stAstronauta crearUnAstro(char astronauta[])
{
    stAstronauta aux;

    //para no tener que cambiar la id el usuario incia el programa ya con UN astronauta predeterminado

    ///datos por defecto para crear un astro
    int ultimaID = encontrarUltimaID(astronauta);
    aux.id = ultimaID+1; // arranca en 50
    aux.horasDeVuelo = 0;
    aux.cantMisionesRealizadas = 0;
    aux.horasEnEEI = 0;
    aux.estado = 1;// 1 activo, 2 retirado

    /// Validacion del astronauta
    puts("-----------------------DATOS DEL ASTRONAUTA-----------------------");
    do
    {
        printf("Ingrese el nombre del astronauta: \n");
        fflush(stdin);
        gets(aux.nombre);
    }
    while(validarString(aux.nombre)==0 || validarDigitosEnStrings(aux.nombre)== 1);

    do
    {
        printf("Ingrese el apellido del astronauta: \n");
        fflush(stdin);
        gets(aux.apellido);
    }
    while(validarString(aux.apellido)==0|| validarDigitosEnStrings(aux.apellido)== 1);

    do
    {
        printf("Ingrese el apodo del astronauta: \n");
        fflush(stdin);
        gets(aux.apodo);
    }
    while(validarString(aux.apodo)==0|| validarDigitosEnStrings(aux.apodo)== 1);

    do
    {
        printf("Ingrese la edad del astronauta: \n");
        fflush(stdin);
        scanf("%i",&aux.edad);
    }
    while(validarEdad(aux.edad)==0 && validarCaracteresEnEnteroMision(aux.edad)==0);

    do
    {
        printf("Ingrese el pais el astronauta: \n");
        fflush(stdin);
        gets(aux.nacionalidad);
    }
    while(validarNacionalidad(aux.nacionalidad)==0);

    validarEspecialidad(aux.especialidad);
    // como ya cargo todo el astronauta se incrementan las id para que se pueda cargar el siguiente astro con su nueva id


    return aux;
}
///validaciones
int validarString(char auxNombre[])
{
    if (strlen(auxNombre) > 20 || strlen(auxNombre) < 3)
    {
        printf("Ingrese una palabra entre 3 y 20 letras\n\n");
        return 0;
    }
    else
    {
        return 1;
    }


}

int validarEdad(int edad)
{

    if (edad < 18  || edad > 60)
    {
        printf("Ingrese una edad mayor a 18 y menor a 60 anios\n\n");
        return 0;
    }
    else
    {
        return 1;
    }
}

int validarNacionalidad(char nacionalidad[])
{
    int i = 0, maxPaises=192;


    while(i<maxPaises)
    {
        if(strcmpi(nacionalidad,paises[i])== 0)
        {
            return 1;
        }
        i++;
    }
    printf("|Error|ingrese un pais existente\n\n");
    return 0;
}

void validarEspecialidad(char especialidad[])
{

    int flag = 0;
    int op = 0;

        limpiarPantalla();
    do
    {

        puts("------------------INGRESE UNA OPCION--------------------\n");
        mostrarEspecialidad();
        scanf("%i",&op);

        switch(op)
        {
        case 1:
            strcpy(especialidad,"Piloto");
            flag = 1;
            break;
        case 2:
            strcpy(especialidad,"Astrofisico");
            flag = 1;
            break;
        case 3:
            strcpy(especialidad,"Ingeniero Espacial");
            flag = 1;
            break;
        case 4:
            strcpy(especialidad,"Biologo");
            flag = 1;
            break;
        case 5:
            strcpy(especialidad,"Programador espacial");///NO PONER MAS DE 3 PALABRAS PORQUE SE ROMPEN LAS HORAS ACUMULADAS
            flag = 1;
            break;
        default:
            limpiarPantalla();
            printf("OPCION INCORRECTA...Reintente\n");
            flag = 0;
            break;
        }

    }while(flag == 0);


}
void mostrarEspecialidad()
{

    printf("1-Piloto\n");
    printf("2-Astrofisico\n");
    printf("3-Ingeniero Espacial\n");
    printf("4-Biologo\n");
    printf("5-Programador espacial\n");

}
int validarEstado(int datoEstado)
{
    int flag = 0;
    if(datoEstado == 1 || datoEstado ==2)
    {
        flag = 1;
    }
    if(flag == 0)
    {
        puts("Por favor ingrese un estado valido..");
    }
    return flag;
}
int encontrarUltimaID(char astronauta[])
{

    int ultimaID;
    stAstronauta astroAux;
    FILE* aux;
    aux = fopen(astronauta,"rb");
    if(aux != NULL)
    {

        fseek(aux,sizeof(stAstronauta)*-1,SEEK_END);
        fread(&astroAux,sizeof(stAstronauta),1,aux);
        ultimaID = astroAux.id;
        fclose(aux);
    }
    else
    {
        puts("error con el archivo");
    }
    return ultimaID;
}

int validarDigitosEnStrings(char auxNombre[])
{

    int i = 0;
    int esUnNum;

    while(i<strlen(auxNombre))
    {
        esUnNum = isalpha(auxNombre[i]);
        if(esUnNum !=0)
        {
            i++;
        }
        else
        {
            puts("Error, hay datos numericos en el nombre...");
            return 1;
        }
    }
    return 0;
}


int validarCaracteresEnEnteroMision(int dato)
{
    int flag = 0;
    int i = 0;
    char esUnNum[DIM_MAX_STR];
    sprintf(esUnNum,"%d",dato);
    while(i<strlen(esUnNum))
    {
        esUnNum[i] = isdigit(esUnNum[i]);
        if(esUnNum == 0)
        {

            flag = 1;
        }


        i++;
    }
           if(flag == 1){
            puts("Error, hay caracteres en el nombre...");
           }
    return flag;
}


///CARGA DEL ARCHIVO

void cargarUnAstroToArchivo(char archivoAstronautas[])
{

    FILE* archi;
    stAstronauta aux;
    archi = fopen(archivoAstronautas,"ab");
    if(archi != NULL)
    {
        aux = crearUnAstro(archivoAstronautas);
        fwrite(&aux,sizeof(stAstronauta),1,archi);
        fclose(archi);
    }
    else
    {
        printf("error con el archivo\n");
    }
}

///MOSTRAR
void mostrarAstronautas(char archivoAstronautas[])
{

    FILE* astro = fopen(archivoAstronautas,"rb");
    stAstronauta aux;

    if(astro != NULL)
    {
        while(fread(&aux,sizeof(stAstronauta),1,astro)>0)
        {
            mostrarUnAstronauta(aux);
        }
        fclose(astro);
    }
    else
    {
        printf("Error con el archivo");
    }
}

void mostrarUnAstronauta(stAstronauta aux)
{

    puts("\n--------------------------------------------------------------------------");
    printf("ID............................: |%i| \n",aux.id);
    printf("Nombre........................: |%s| \n",aux.nombre);
    printf("Apellido......................: |%s| \n",aux.apellido);
    printf("Apodo.........................: |%s| \n",aux.apodo);
    printf("Edad..........................: |%i| \n",aux.edad);
    printf("Nacionalidad..................: |%s| \n",aux.nacionalidad);
    printf("Especialidad..................: |%s| \n",aux.especialidad);
    printf("Horas de vuelo acumulado......: |%i| \n",aux.horasDeVuelo);
    printf("Misiones espaciales realizadas: |%i| \n",aux.cantMisionesRealizadas);
    printf("Horas en la EEI...............: |%i| \n",aux.horasEnEEI);
    printf("Estado........................: |%i| \n",aux.estado);
    puts("--------------------------------------------------------------------------\n");


}

///MODIFICAR ASTRONAUTA

int validarIDastro(int dato,char archivoAstro[])
{
    stAstronauta aux;
    int flag =0;
    FILE * archi=fopen(archivoAstro,"rb");

    if(archi != NULL)
    {
        while(fread(&aux,sizeof(stAstronauta),1,archi)>0)
        {
            if (dato == aux.id)
            {
                flag=1;
            }
        }


        printf("Ingrese un ID de astronauta valido");



        fclose(archi);
    }
    else
    {
        printf("Error con el archivo");
    }

    return flag;
}


void cargarAstroModificado(char archivoAstronauta[])
{

    stAstronauta astro;


    FILE* buffer= fopen(archivoAstronauta,"r+b");

    int datoID = 0;
    int posAstro = 0;

    if(buffer != NULL)
    {

        do
        {

            limpiarPantalla();
            mostrarAstronautas(archivoAstronauta);

            puts("----------------------INGRESE LA ID DEL ASTRONAUTA A MODIFICAR----------------------");
            datoID = preguntarDato();

        }
        while(validarIDastro(datoID,archivoAstronauta)== 0);

        posAstro = encontrarPosicionAstroXID(archivoAstronauta,datoID)-1;     // devuelvo la posicion en la que esta el astronauta con el ID buscado

        fseek(buffer,sizeof(stAstronauta)*posAstro,SEEK_SET);              // muevo el indicador de posicion a donde se encuentra el astronauta con el ID buscado y le resto 1 para leerlo
        fread(&astro,sizeof(stAstronauta),1,buffer);                      // lo leo, se que me va a leer el astronauta que quiero ya que me movi una posicion atras

                                                                        // le paso la direccion de memoria del astronauta que acabo de leer y el indicador de pos va a aumentar por el read
        modificarUnAstro(&astro);
        fseek(buffer,sizeof(stAstronauta)*(-1),SEEK_CUR);               // por culpa del read debo moverme una posicion hacia atras para poder sobreescribir el astronauta modificado
        fwrite(&astro,sizeof(stAstronauta),1,buffer);                // escribo el astronauta modificado

        fclose(buffer);
    }
    else
    {
        printf("Error con el archivo");
    }

}

int contarRegistrosAstro(char archivo[])
{
    int cant=0;
    FILE*buffer=fopen(archivo,"rb");

    if(buffer != NULL)
    {
        fseek(buffer,sizeof(stAstronauta) -1,SEEK_END);
        cant= ftell(buffer) / sizeof(stAstronauta);
        fclose(buffer);
    }
    else
    {
        printf("Error con archivo");
    }

    return cant;
}


int preguntarDato()
{
    int dato= 0;
    printf("\nIngrese un dato: ");
    fflush(stdin);
    scanf("%i",&dato);
    return dato;
}


int encontrarPosicionAstroXID(char archivoAstronautas[],int datoID)
{
    int posAstro=0;
    int  flag=0;
    stAstronauta aux;

    FILE * archi=fopen(archivoAstronautas,"rb");

    if(archi != NULL)
    {
        while(fread(&aux,sizeof(stAstronauta),1,archi)>0 && (flag == 0))
        {
            if(aux.id == datoID)
            {
                posAstro= ftell(archi) / sizeof(stAstronauta);
                flag=1;
            }
        }

        fclose(archi);
    }
    else
    {
        printf("Error con el archivo");
    }


    return posAstro;

}



void modificarUnAstro(stAstronauta* astro)
{
    char continuar = 's';
    int opsw = 0;
    limpiarPantalla();
    do
    {
        puts("-----------ASTRONAUTA ELEGIDO-------");
        mostrarUnAstronauta(*astro);

        puts("1-Modificar Nombre");
        puts("2-Modificar apellido");
        puts("3-Modificar apodo");
        puts("4-Modificar edad");
        puts("5-Modificar estado");
        puts("6-No realizar ninguna modificacion");

        printf("Que desea cambiar?: ");
        scanf("%i",&opsw);

        switch(opsw)
        {
        case 1:
            do
            {
                printf("Ingrese el nuevo nombre\n");
                fflush(stdin);
                gets(astro->nombre);
            }
            while(validarString(astro->nombre)==0|| validarDigitosEnStrings(astro->nombre)== 1);
            break;
        case 2:
            do
            {
                printf("ingrese el nuevo apellido\n");
                fflush(stdin);
                gets(astro->apellido);
            }
            while(validarString(astro->apellido)==0|| validarDigitosEnStrings(astro->apellido)== 1);
            break;
        case 3:
            do
            {
                printf("Ingrese el nuevo apodo\n");
                fflush(stdin);
                gets(astro->apodo);
            }
            while(validarString(astro->apodo)==0|| validarDigitosEnStrings(astro->apodo)== 1);
            break;
        case 4:
            do
            {
                printf("Ingrese la nueva edad\n");
                fflush(stdin);
                scanf("%i",&astro->edad);
            }
            while(validarEdad(astro->edad)== 0);
            break;
        case 5:
            do
            {
                puts("Ingrese el nuevo estado:");
                puts("1. Activo");
                puts("2. Retirado");

                fflush(stdin);
                scanf("%i",&astro->estado);
            }
            while(validarEstado(astro->estado)==0);
            break;
        case 6:
            puts("\nNo se realizo ningun cambio \n");
            break;
        default:
            printf("Opcion no valida, reintente...\n");
            break;
        }

        printf("Quiere realizar otra modificacion al astronauta elegido?: (S/N)\n");
        fflush(stdin);
        continuar = getch(continuar);

        limpiarPantalla();
    }
    while(continuar == 's');
    puts("-----------Astronauta modificado-----------\n");
    mostrarUnAstronauta(*astro);


}


///LISTA/CONSULTA

void mostrarArregloAstro(stAstronauta arrAstro[],int validos)
{
    for (int i=0; i < validos; i++)
    {
        mostrarUnAstronauta(arrAstro[i]);
    }
}



int archivoToArregloAstro(stAstronauta arrAstro[], char archivoAstro[])
{
    int validos=0;
    stAstronauta aux;

    FILE* buffer= fopen(archivoAstro,"rb");


    if(buffer != NULL)
    {
        while(fread(&aux,sizeof(stAstronauta),1,buffer) > 0)
        {
            arrAstro[validos]= aux;
            validos++;
        }


        fclose(buffer);
    }
    else
    {

        printf("Error con archivo \n");
    }

    return validos;
}

stAstronauta * crearArregloDinamicoAstro(int tam)
{

    stAstronauta* arrAstro= malloc(sizeof(stAstronauta)*tam);
    return arrAstro;
}


void ConsultaAstro(char archivoAstro[])
{
    stAstronauta *arrAstro;
    int tam=contarRegistrosAstro(archivoAstro);

    arrAstro= crearArregloDinamicoAstro(tam);

    int validosAstro= archivoToArregloAstro(arrAstro,archivoAstro);

    menuConsultarPorAstronauta(archivoAstro,arrAstro,validosAstro);

}

void opcionesParaConsultarAstronauta()
{
    printf("1-Buscar astronauta por ID: \n");
    printf("2-Buscar todos los astronautas con un mismo nombre: \n");
    printf("3-Buscar todos los astronautas con un mismo apellido: \n");
    printf("4-Buscar astronauta por apodo: \n");
    printf("5-Mostrar astronautas por edad: \n");
    printf("6-Mostrar todos los astronautas de un pais: \n");
    printf("7-Buscar astronauta con mayor horas de vuelo: \n");
    printf("8-Buscar astronauta con la mayor cantidad de misiones realizadas: \n");
    printf("9-Buscar astronauta con menor horas de vuelo: \n");
    printf("10-Buscar astronauta con menor cantidad de misiones realizadas: \n");
    printf("11-Mostrar cantidad de astronautas en el sistema: \n");
}

void menuConsultarPorAstronauta(char archivoAstronautas[],stAstronauta arregloAstro[],int validos)
{

    stAstronauta aux;

    int op = 0;
    char continuar= 's';
    int dato = 0;
    char datoString[DIM_MAX_STR];

    do
    {
        mostrarArregloAstro(arregloAstro,validos);
        opcionesParaConsultarAstronauta();
        puts("Elija una opcion: ");
        scanf("%i",&op);
        limpiarPantalla();

        switch(op)
        {
        case 1:
            puts("-------------Ingrese el ID del astronauta que quiere buscar-------------");
            dato = preguntarDato();
            dato= buscarIDastro(arregloAstro,dato,validos);
            if (dato != -1)
            {
                printf("El astronauta con el ID: %i \n\n", arregloAstro[dato].id);
                mostrarUnAstronauta(arregloAstro[dato]);
            }
            else
            {
                printf("No se encontro ningun astronauta con el ID: %i", dato);
            }

            break;
        case 2:
            do
            {
                printf("Ingrese el nombre a buscar: \n");
                fflush(stdin);
                gets(datoString);
            }
            while(validarString(datoString)==0|| validarDigitosEnStrings(datoString)== 1);
            buscarNombreAstro(arregloAstro,datoString,validos) ?printf("Existen estos astronautas con el nombre: %s \n",datoString) : printf("No existen astronautas con ese nombre \n");

            break;
        case 3:


            do
            {
                printf("Ingrese el apellido a buscar: \n");
                fflush(stdin);
                gets(datoString);

            }
            while(validarString(datoString)==0|| validarDigitosEnStrings(datoString)== 1);
            buscarApellidoAstro(arregloAstro,datoString,validos) ? printf("Existen estos astronautas con el apellido: %s \n",datoString) : printf("No existen astronautas con ese apellido \n");


            break;
        case 4:
            do
            {
                printf("Ingrese el apodo a buscar: \n");
                fflush(stdin);
                gets(datoString);
            }
            while(validarString(datoString)==0|| validarDigitosEnStrings(datoString)== 1);
            buscarApodoAstro(arregloAstro,datoString,validos) ?printf("Existen estos astronautas con el apodo: %s \n",datoString) : printf("No existen astronautas con ese apodo \n");

            break;
        case 5:
            dato = 0;
            do
            {
                printf("Ingrese una edad para mostrar los astronautas: \n");
                fflush(stdin);
                scanf("%i",&dato);

            }
            while(validarEdad(dato)== 0);
            buscarPorEdadUnAstro(arregloAstro,dato,validos)?printf("Existen estos astronautas con esta edad|%i| \n",dato) : printf("No existen astronautas con esa edad \n");

            break;
        case 6:
            do
            {
                printf("Ingrese el pais para mostrar los astronautas: \n");
                fflush(stdin);
                gets(datoString);
            }
            while(validarNacionalidad(datoString)== 0);

            buscarPaisAstro(arregloAstro,datoString,validos);
            break;

        case 7:
            aux = buscarAstroConMayorExpHorasVuelo(arregloAstro,validos);
            puts("--------------------ASTRONAUTA CON MAYOR NUMERO DE HORAS DE VUELO--------------------\n");
            mostrarUnAstronauta(aux);
            break;
        case 8:
            aux = buscarAstroConMayorExpEnMisiones(arregloAstro,validos);
            puts("--------------------ASTRONAUTA CON MAYOR NUMERO DE MISIONES--------------------\n");
            mostrarUnAstronauta(aux);
            break;
        case 9:

            aux = buscarAstroConMenorExpHorasVuelo(arregloAstro,validos);
            puts("--------------------ASTRONAUTA CON MENOR NUMERO DE HORAS DE VUELO--------------------\n");
            mostrarUnAstronauta(aux);

            break;
        case 10:

            aux = buscarAstroConMayorExpHorasVuelo(arregloAstro,validos);
            puts("--------------------ASTRONAUTA CON MENOR NUMERO DE MISIONES--------------------\n");
            mostrarUnAstronauta(aux);
            break;
        case 11:
             dato = 0;
             dato = contarRegistrosAstro(archivoAstronautas);
              puts("--------------------ASTRONAUTA DEL SISTEMA--------------------\n");
              printf("La cantidad de astronautas del sistema son|%i|\n",dato);
            break;
        default:
            printf("OPCION NO VALIDA,reintente...\n");
            break;
        }

        printf("(S/N) para seleccionar otra opcion:\n");
        fflush(stdin);
        continuar = getch(continuar);
        limpiarPantalla();

    }
    while(continuar == 's');
}

int buscarIDastro(stAstronauta astro[],int idBuscado,int validos)
{

    int i = 0;

    while(i<validos)
    {
        if(astro[i].id == idBuscado)
        {
            return i;
        }
        i++;
    }
    return -1;
}

int buscarNombreAstro(stAstronauta arregloAstro[],char nombre[],int validos)
{

    int flag = 0;

    for(int i = 0; i<validos; i++)
    {
        if(strcmpi(arregloAstro[i].nombre,nombre)== 0)
        {
            mostrarUnAstronauta(arregloAstro[i]);
            flag= 1;
        }
    }
    return flag;
}

int buscarApellidoAstro(stAstronauta arregloAstro[],char apellido[],int validos)
{

    int flag = 0;

    for(int i = 0; i<validos; i++)
    {
        if(strcmpi(arregloAstro[i].apellido,apellido)== 0)
        {
            mostrarUnAstronauta(arregloAstro[i]);
            flag= 1;
        }
    }
    return flag;
}

int buscarApodoAstro(stAstronauta arregloAstro[],char apodo[],int validos)
{

    int flag = 0;

    for(int i = 0; i<validos; i++)
    {
        if(strcmpi(arregloAstro[i].apodo,apodo)== 0)
        {
            mostrarUnAstronauta(arregloAstro[i]);
            flag = 1;
        }
    }
    return flag;
}

int buscarPorEdadUnAstro(stAstronauta arregloAstro[],int dato,int validos)
{

    int i = 0;
    int flag = 0;
    while(i<validos)
    {
        if(arregloAstro[i].edad == dato)
        {
            mostrarUnAstronauta(arregloAstro[i]);
            flag = 1;
        }
        i++;
    }
    return flag;
}

int buscarPaisAstro(stAstronauta arregloAstro[],char auxPais[],int validos)
{

    int flag = 0;

    for(int i = 0; i<validos; i++)
    {
        if(strcmpi(arregloAstro[i].nacionalidad,auxPais)== 0)
        {
            mostrarUnAstronauta(arregloAstro[i]);
            flag= 1;
        }
    }
    return flag;
}

int buscarAstronautasPorEstado(stAstronauta arregloAstro[],int estadoAstro,int validos)
{
    char datoEstado[DIM_MAX_STR];
    if(estadoAstro == 1){
    strcpy(datoEstado,"Listo");
    }else if(estadoAstro == 0){
    strcpy(datoEstado,"Retirado");
    }else if(estadoAstro == 3){
    strcpy(datoEstado,"En mision");
    }

    int flag = 0;

    for (int i=0; i <validos; i++)
    {
        if(arregloAstro[i].estado == estadoAstro)
        {
            mostrarUnAstronauta(arregloAstro[i]);
            flag = 1;
        }
    }
    if(flag == 0){
        printf("No se encuentran astronautas en el estado %i (%s) \n\n",estadoAstro,datoEstado);
    }
    return flag;
}

stAstronauta buscarAstroConMayorExpHorasVuelo(stAstronauta arregloAstro[],int validos)
{
    stAstronauta aux;

    aux.horasDeVuelo=-1;

    for (int i=0; i < validos; i++)
    {
        if(arregloAstro[i].horasDeVuelo > aux.horasDeVuelo)
        {
            aux = arregloAstro[i];
        }
    }
    return aux;
}

stAstronauta buscarAstroConMayorExpEnMisiones(stAstronauta arregloAstro[],int validos)
{

    stAstronauta aux;

    aux.cantMisionesRealizadas=-1;

    for (int i=0; i < validos; i++)
    {
        if(arregloAstro[i].cantMisionesRealizadas > aux.cantMisionesRealizadas)
        {
            aux = arregloAstro[i];
        }
    }
    return aux;
}

stAstronauta buscarAstroConMenorExpHorasVuelo(stAstronauta arregloAstro[],int validos)
{
    int i=0;
    stAstronauta aux = arregloAstro[i];

    for (int i=0; i < validos; i++)
    {
        if(arregloAstro[i].horasDeVuelo < aux.horasDeVuelo)
        {
            aux = arregloAstro[i];
        }
    }
    return aux;


}

stAstronauta buscarAstroConMenorExpEnMisiones(stAstronauta arregloAstro[],int validos)
{
    int i=0;
    stAstronauta aux = arregloAstro[i];

    for (int i=0; i < validos; i++)
    {
        if(arregloAstro[i].cantMisionesRealizadas < aux.cantMisionesRealizadas)
        {
            aux = arregloAstro[i];
        }
    }
    return aux;


}

int contarAstronautasXEstado(char archivoAstro[],int estado)
{
    int cont=0;
    stAstronauta aux;
    FILE *buffer = fopen(archivoAstro,"rb");

    if(buffer!= NULL)
    {
        while(fread(&aux,sizeof(stAstronauta),1,buffer)>0)
        {
            if(aux.estado == estado)
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

