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



// VOID inicioPredeterminado(recibe todos los archivos)
//creamos 3 (para poder utilizar al menos la nave mas mala)
//creamos 1 nave de cada tipo asi el usuario puede seguir creando naves hasta un maximo de 6
//misiones reseatado a 0


void menuPrincipal(char archivoAstronautas[],char archivoNaves[],char archivoMisiones[])
{
    int opsw;
    char op;
    pantallaDeCarga();
    limpiarPantalla();

    do{

        logoUTN();

        printf("Bienvenido, que desea elegir? \n");

        printf("1. Opciones Astronauta \n");
        printf("2. Opciones Naves \n");
        printf("3. Opciones Misiones \n");
        printf("\nIngrese su opcion: ");
        scanf("%i",&opsw);

        limpiarPantalla();

        switch(opsw)
        {
        case 1:
            menuAstronauta(archivoAstronautas);
            break;
        case 2:
            menuNaves(archivoNaves);
            break;
        case 3:
            menuMisiones(archivoMisiones,archivoNaves,archivoAstronautas);
            break;
        default:
            puts("Opcion no valida,reintente...");
            break;
        }

        puts("(S/N)Desea ingresar en otro menu: ");
        fflush(stdin);
        op= getch(op);
        limpiarPantalla();

    }while(op == 's');

    despedida();
}

void logoUTN()
{
    puts(" .----------------.  .----------------.  .------------------.      ");
    puts("| .--------------. || .--------------. || .---------------. |      ");
    puts("| | _____  _____ | || |  _________   | || |  ____  _____  | |      ");
    puts("| ||_   _||_   _|| || | |  _   _  |  | || | |_   \\|_   _| | |     ");
    puts("| |  | |    | |  | || | |_/ | | \\_|  | || |   |   \\ | |   | |    ");
    puts("| |  | |    | |  | || |     | |      | || |   | |\\ \\| |   | |    ");
    puts("| |   \\ '--' /   | || |    _| |_     | || |  _| |_\\   |   | |    ");
    puts("| |    `.__.'    | || |   |_____|    | || | |_____|\\__|   | |     ");
    puts("| |              | || |              | || |               | |      ");
    puts("| '--------------' || '--------------' || '---------------' |      ");
    puts(" '----------------'  '----------------'  '-----------------'       ");
    puts("\n");
}


void pantallaDeCarga()
{
    puts("-------------------------------------------------------------------------------------------------------------------------------------");
    puts("|     SSSSSSSSSSSSSSS                                                                                      XXXXXXX       XXXXXXX     |");
    puts("|   SS:::::::::::::::S                                                                                     X:::::X       X:::::X     |");
    puts("|  S:::::SSSSSS::::::S                                                                                     X:::::X       X:::::X     |");
    puts("|  S:::::S     SSSSSSS                                                                                     X::::::X     X::::::X     |");
    puts("|  S:::::S             ppppp   ppppppppp       aaaaaaaaaaaaa        cccccccccccccccc      eeeeeeeeeeee       X:::::X   X:::::X       |");
    puts("|  S:::::S             p::::ppp:::::::::p      a::::::::::::a     cc:::::::::::::::c    ee::::::::::::ee      X:::::X X:::::X        |");
    puts("|   S::::SSSS          p:::::::::::::::::p     aaaaaaaaa:::::a   c:::::::::::::::::c   e::::::eeeee:::::ee     X:::::X:::::X         |");
    puts("|    SS::::::SSSSS     pp::::::ppppp::::::p             a::::a  c:::::::cccccc:::::c  e::::::e     e:::::e      X:::::::::X          |");
    puts("|      SSS::::::::SS    p:::::p     p:::::p      aaaaaaa:::::a  c::::::c     ccccccc  e:::::::eeeee::::::e      X:::::::::X          |");
    puts("|         SSSSSS::::S   p:::::p     p:::::p    aa::::::::::::a  c:::::c               e:::::::::::::::::e      X:::::X:::::X         |");
    puts("|              S:::::S  p:::::p     p:::::p   a::::aaaa::::::a  c:::::c               e::::::eeeeeeeeeee      X:::::X X:::::X        |");
    puts("|              S:::::S  p:::::p    p::::::p  a::::a    a:::::a  c::::::c     ccccccc  e:::::::e             XX:::::X   X:::::XX      |");
    puts("|  SSSSSSS     S:::::S  p:::::ppppp:::::::p  a::::a    a:::::a  c:::::::cccccc:::::c  e::::::::e           X::::::X     X::::::X     |");
    puts("|  S::::::SSSSSS:::::S  p::::::::::::::::p   a:::::aaaa::::::a   c:::::::::::::::::c   e::::::::eeeeeeee   X:::::X       X:::::X     |");
    puts("|  S:::::::::::::::SS   p::::::::::::::pp     a::::::::::aa:::a   cc:::::::::::::::c    ee:::::::::::::e   X:::::X       X:::::X     |");
    puts("|   SSSSSSSSSSSSSSS     p::::::pppppppp        aaaaaaaaaa  aaaa     cccccccccccccccc      eeeeeeeeeeeeee   XXXXXXX       XXXXXXX     |");
    puts("|                       p:::::p                                                                                                      |");
    puts("|                       p:::::p                                                                                                      |");
    puts("|                      p:::::::p                                                                                                     |");
    puts("|                      p:::::::p                                                                                                     |");
    puts("|                      p:::::::p                                                                                                     |");
    puts("|                      ppppppppp                                                                                                     |");
    puts("-------------------------------------------------------------------------------------------------------------------------------------\n\n");
    printf("\t \t \t \t \t \t \t \t \t \t\t By: Leonardo Caimmi, Matias Blanco & Fabrizio Golisciano \n");
    system("pause");
}

void menuAstronauta(char archivoAstronauta[])
{
    char op;
    int opsw;

    do
    {

        dibujoAstronauta();

        printf("Que desea hacer?: ");
        opsw=preguntarDato();

        limpiarPantalla();

        switch(opsw)
        {
        case 1:
            cargarUnAstroToArchivo(archivoAstronauta);
            break;
        case 2:
            cargarAstroModificado(archivoAstronauta);
            break;
        case 3:
            opcionMostrarAstronautas(archivoAstronauta);
            break;
        case 4:
            ConsultaAstro(archivoAstronauta);
            break;
        case 5:
            return;
            break;
        default:
            limpiarPantalla();
            printf("Por favor ingrese un dato valido \n");
            break;
        }

        printf("\nQuiere volver al menu de astronauta? s/n: ");
        fflush(stdin);
        op = getch(op);
        limpiarPantalla();

    }
    while(op=='s');
}

void opcionMostrarAstronautas(char archivoAstro[])
{
    int opsw,estado;
    char op;
    int validosAstro= contarRegistrosAstro(archivoAstro);
    int tam = validosAstro;
    stAstronauta * arregloAstro;
    arregloAstro= crearArregloDinamicoAstro(tam);

    archivoToArregloAstro(arregloAstro,archivoAstro);

    do
    {

        puts("--------------------------------------------------------");
        puts("1. Mostrar todos los astronautas en la base de datos");
        puts("2. Mostrar los astronautas en mision.... (Estado= 3)");
        puts("3. Mostrar los astronautas disponibles.. (Estado= 1)");
        puts("4. Mostrar los astronautas dados de baja (Estado= 0)");
        puts("--------------------------------------------------------");
        opsw= preguntarDato();
        limpiarPantalla();
        switch(opsw)
        {
        case 1:
            mostrarAstronautas(archivoAstro);
            break;
        case 2:
            estado = 3;
            buscarAstronautasPorEstado(arregloAstro,estado,validosAstro);
            break;
        case 3:
             estado = 1;
            buscarAstronautasPorEstado(arregloAstro,estado,validosAstro);
            break;
            break;
        case 4:
            estado = 0;
            buscarAstronautasPorEstado(arregloAstro,estado,validosAstro);
            break;
        default:
            limpiarPantalla();
            printf("Por favor ingrese una opcion valida \n");
            break;
        }

        printf("Quiere seguir mostrando astronautas? s/n: ");
        fflush(stdin);
        op = getch(op);
        limpiarPantalla();

    }
    while(op=='s');
}

void menuNaves(char archivoNaves[])
{
    char op = 's';
    int opsw = 0;


    do
    {

        dibujoNaves();

        printf("Que desea realizar? ");
        opsw=preguntarDato();

        limpiarPantalla();

        switch(opsw)
        {
        case 1:
            cargarArchivoNaves(archivoNaves);
            break;
        case 2:
            cargarNaveModificada(archivoNaves);
            break;
        case 3:
            opcionMostrarNaves(archivoNaves);
            break;
        case 4:
            ConsultaNave(archivoNaves);
            break;
        case 5:
            return;
            break;
        default:
            printf("Has ingresado mal un dato, vuelve a intentarlo!!");
            break;
        }
        printf("\nQuiere volver al menu de naves? s/n: ");
        fflush(stdin);
        op = getch(op);
        limpiarPantalla();

    }
    while(op=='s');

}

void dibujoAstronauta()
{
    puts("----------------------------------------");
    puts("        _..._                          ");
    puts("      .'     '.      _                 ");
    puts("     /    .-''-\\   _/ \\              ");
    puts("   .-|   /: ^ ^ |  |   |                ");
    puts("   |  \\  |:    /.-'-./                ");
    puts("   | .-'-;:__.'    =/                  ");
    puts("   .'=  *=| UTN _.='                   ");
    puts("  /   _.  |    ;                       ");
    puts(" ;-.-'|    \\   |                      ");
    puts("/   | \\    _\\  _\\                   ");
    puts("\\__/'._;.  ==' ==\\                   ");
    puts("         \\    \\   |                  ");
    puts("         /    /   /                    ");
    puts("         /-._/-._/                     ");
    puts("        \\   `\\  \\                   ");
    puts("          `-._/._/                     ");
    puts("----------------------------------------");
    puts("\t   MENU ASTRONAUTAS");
    puts("----------------------------------------\n");
    puts("1. Dar de Alta a un astronauta (Crear uno nuevo)");
    puts("2. Modificar un astronauta");
    puts("3. Mostrar astronautas");   //1. TODOS 2.Disponibles 3. Dados de baja
    puts("4. Consultar datos de astronautas");
    puts("5. Volver al menu principal");

}

void dibujoNaves()
{
    puts("----------------------------------------------------------");
    puts(" /\\/\\/\\                            /  \\                   ");
    puts("| \\  / |                         /      \\                 ");
    puts("|  \\/  |                       /          \\               ");
    puts("|  /\\  |----------------------|     /\\     |              ");
    puts("| /  \\ |                      |    /  \\    |              ");
    puts("|/    \\|                      |   /    \\   |              ");
    puts("|\\    /|                      |  | (  ) |  |              ");
    puts("| \\  / |                      |  | (  ) |  |              ");
    puts("|  \\/  |                 /\\   |  |      |  |   /\\         ");
    puts("|  /\\  |                /  \\  |  |      |  |  /  \\        ");
    puts("| /  \\ |               |----| |  |      |  | |----|       ");
    puts("|/    \\|---------------|    | | /|   .  |\\ | |    |       ");
    puts("|\\    /|               |    | /  |   .  |  \\ |    |       ");
    puts("| \\  / |               |    /    |   .  |    \\    |       ");
    puts("|  \\/  |               |  /      |   .  |      \\  |       ");
    puts("|  /\\  |---------------|/        |   .  |        \\|       ");
    puts("| /  \\ |              /   UTN    |   .  |  UTN    \\       ");
    puts("|/    \\|              (          |      |          )      ");
    puts("|/\\/\\/\\|               |    | |--|      |--| |    |       ");
    puts("------------------------/  \\-----/  \\/  \\-----/  \\--------");
    puts("                        \\\\//     \\\\//\\\\//     \\\\//        ");
    puts("                         \\/       \\/  \\/       \\/         ");
    puts("--------------------------------------------------------------");

    puts("----------------------------------------------------------");
    puts("\t  MENU NAVES");
    puts("----------------------------------------------------------");
    puts("1. Cargar una nave");
    puts("2. Modificar una nave");
    puts("3. Mostrar naves");  // Estado: (0- mantenimiento 1- Lista para su uso 2- Actualmente en misión 3- De baja)
    puts("4. Consultar datos de naves");
    puts("5. Volver al menu principal");
}

void opcionMostrarNaves(char archivoNaves[])
{
    int opsw;
    int dato=0;
    char op='s';

    do
    {
        puts("--------------------------------------------------------");
        puts("1. Mostrar todas las naves en la base de datos");
        puts("2. Mostrar las naves en mantenimiento (Estado = 0)");
        puts("3. Mostrar las naves disponibles..... (Estado = 1)");
        puts("4. Mostrar las naves en mision....... (Estado = 2)");
        puts("5. Mostrar las naves dadas de baja... (Estado = 3)");
        puts("--------------------------------------------------------");

        opsw= preguntarDato();
        limpiarPantalla();
        switch(opsw)
        {


        case 1:
            mostrarTodasLasNaves(archivoNaves);
            break;
        case 2:
            dato = 0;
            dato = mostrarNavesXEstado(archivoNaves,dato);
            if(dato == 0)
            {
                puts("No hay naves en este estado...");
            }
            break;
        case 3:
            dato = 1;
            dato = mostrarNavesXEstado(archivoNaves,dato);
            if(dato == 0)
            {
                puts("No hay naves en este estado...");
            }
            break;
        case 4:
            dato = 2;
            dato = mostrarNavesXEstado(archivoNaves,dato);
            if(dato == 0)
            {
                puts("No hay naves en este estado...");
            }
            break;
        case 5:
            dato = 3;
            dato = mostrarNavesXEstado(archivoNaves,dato);
            if(dato == 0)
            {
                puts("No hay naves en este estado...");
            }
            break;
        default:
            limpiarPantalla();
            puts("Error ingrese una opcion valida...");

            break;
        }
        puts("\nQuiere seguir mostrando naves? s/n: ");
        fflush(stdin);
        op = getch(op);
        limpiarPantalla();

    }
    while(op=='s');


}

void dibujoMision(){
    puts("----------------------------------------------------------------------------------");
    puts(" .      .      .      .      .      .      .      .      .      .      .");
    puts(".                               .       .       .       .       .       .");
    puts("   .        .        .        .        .        .        .        .        .");
    puts("     .         .         .        _......____._        .         .");
    puts("   .          .          . ..--'"" .           ----------...          .");
    puts("                   _...--""        ................       `-.              .");
    puts("                .-'        ...:'::::;:::%:.::::::_;;:...     `-.");
    puts("             .-'       ..::::'''''   _...---'"""":::+;_::.      `.      .");
    puts("  .        .' .    ..::::'      _.-""               :::)::.       `.");
    puts("         .      ..;:::'     _.-'         .             f::'::    o __");
    puts("        /     .:::%'  .  .-                         .-.  ::;;:.  /---\\x");
    puts("  .   .'     ::.::'    .-     _.-------.           (   )  ::.:: |_.-' |");
    puts("     .'    ::;:'    .'     .-  .d@@b.   \\    .    . `-'   ::%::   \\_ _/    .");
    puts("    .'    :,::'    /   . _'    8@@@@8   j      .-'       :::::       o");
    puts("    | .  :.%:' .  j     (_)    `@@@P'  .'   .-          ::.::    .  f");
    puts("    |    ::::     (        -..____...-'  .-           .::::'       /");
    puts(".   |    `:`::    `.                ..--'        .  .::'::   .    /");
    puts("    j     `:::::    `-._____...---""             .::%:::'       .'  .");
    puts("     \\      ::.:%..             .       .    ...:,::::'       .'");
    puts(" .    \\       `:::`:..                ....::::.::::'       .-'          .");
    puts("       \\    .   ``:::%::`::.......:::::%::.::::''       .-'");
    puts("      . `.        . ``::::::%::::.::;;:::::'''      _.-'          .");
    puts("  .       `-..     .    .   ````'''''         . _.-'     .          .");
    puts("         .    ""--...____    .   ______......--' .         .         .");
    puts("  .        .        .    """"""""     .        .        .        .        .");
    puts(" .       .       .       .       .       .       .       .       .");
    puts("     .      .      .      .      .      .      .      .      .      .      .");
    puts("--------------------------------------------------------------------------------");

    puts("--------------------------------------------------------------------------------");
    puts("\t  MENU MISIONES");
    puts("--------------------------------------------------------------------------------");
    puts("1. Crear una mision ");
    puts("2. Lanzar una mision (LISTA)");
    puts("3. Determinar resultado de la mision (EN VUELO)");
    puts("4. Mostrar misiones");
    puts("5. Consultar datos de una mision");
    puts("6. Volver al menu principal");
}

void opcionMostrarMisiones(char archivoMisiones[],char archivoNaves[])
{
    int estado=0;
    int opsw;
    char op;

    do {

        puts("--------------------------------------------------------");
        puts("1. Mostrar todas las misiones en la base de datos");
        puts("2. Mostrar las misiones disponibles (Estado= 1)");
        puts("3. Mostrar las misiones en curso    (Estado= 2)");  // (Listo, En vuelo, Retornada, Cancelada, Fallida)
        puts("4. Mostrar las misiones retornadas  (Estado= 3)");
        puts("5. Mostrar las misiones canceladas  (Estado= 4)");
        puts("6. Mostrar las misiones fallidas    (Estado= 5)");
        puts("--------------------------------------------------------");
        opsw = preguntarDato();
        limpiarPantalla();
        switch(opsw) {
        case 1:

            mostrarTodasLasMisiones(archivoMisiones,archivoNaves);
            break;
        case 2:
            estado= 1;

            mostrarMisionesXEstado(archivoMisiones,archivoNaves,estado);

            break;
        case 3:
            estado= 2;
            mostrarMisionesXEstado(archivoMisiones,archivoNaves,estado);
            break;
        case 4:
            estado= 3;
             mostrarMisionesXEstado(archivoMisiones,archivoNaves,estado);
            break;
        case 5:
            estado= 4;
            mostrarMisionesXEstado(archivoMisiones,archivoNaves,estado);
            break;
        case 6:
            estado= 5;
            mostrarMisionesXEstado(archivoMisiones,archivoNaves,estado);
            break;
        default:
            printf("Por favor ingrese una opcion valida \n");
            break;
        }

        printf("Quiere seguir mostrando misiones? s/n: ");
        fflush(stdin);
        op = getch(op);
        limpiarPantalla();

    } while(op=='s');
}

void menuMisiones(char archivoMisiones[],char archivoNaves[], char archivoAstro[])
{
    char op = 's';
    int opsw = 0;



    do{

        dibujoMision();

        puts("Que desea realizar? ");
        opsw=preguntarDato();
        limpiarPantalla();

        switch(opsw){
            case 1:



                cargarArchivoMisiones(archivoAstro,archivoNaves,archivoMisiones);
                break;
            case 2:
                modificarMisionLista(archivoAstro,archivoMisiones,archivoNaves);
                break;
            case 3:
                modificarMisionEnVuelo(archivoMisiones,archivoNaves,archivoAstro);
                break;
            case 4:
                opcionMostrarMisiones(archivoMisiones,archivoNaves);
                break;
            case 5:
                consultaMision(archivoMisiones);
                break;
            case 6:
                return 0;
                break;
            default:
                limpiarPantalla();
                printf("Has ingresado mal un dato, vuelve a intentarlo");
                break;
        }
        puts("\nQuiere volver al menu de misiones?: s/n");
        fflush(stdin);
        op = getch(op);
        limpiarPantalla();

    } while(op=='s');

}

void dibujoMarte() {

    puts("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWNWWNWWWWWWWWWWWWWWWWWWWWWWNWWWWWWWWWWWWWWW");
    puts("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW");
    puts("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWNXK0kddollccccllodxkKXNWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW");
    puts("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWNX0xol:,'............ ...':okKNWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW");
    puts("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWNKkdl::;;;;,,'''''.'.......     .;d0NWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW");
    puts("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWXOdc::lddlcc:;,,,;,,,,''.......      .:kXWWWWWWWWWWWWWWWWWWWWWWWWWWWWW");
    puts("WWWWWWWWWWWWWWWWWWWWWWWWWWWWXOdlccccoxdllc:;;;;:;;;;,,.........       ,xXWWWWWWWWWWWWWWWWWWWWWWWWWWW");
    puts("WWWWWWWWWWWWWWWWWWWWWWWWWWN0dlcccclloollc:::;;;;,,'''''.........        ;ONWWWWWWWWWWWWWWWWWWWWWWWWW");
    puts("WWWWWWWWWWWWWWWWWWWWWWWWWXkollclclloollcc::::;;,,,'''''''.......         .oXWWWWWWWWWWWWWWWWWWWWWWWW");
    puts("WWWWWWWWWWWWWWWWWWWWWWWWXkollllcclolllcccccc:cc:;;;,,,,,,''.......         :KWWWWWWWWWWWWWWWWWWWWWWW");
    puts("WWWWWWWWWWWWWWWWWWWWWWWXkoloolccllllllllllllllc:;;;;;;;;,,,'.......         :KWWWWWWWWWWWWWWWWWWWWWW");
    puts("WWWWWWWWWWWWWWWWWWWWWWNOolooolllollllllllllllc:;,,,,;;;;;,,,''......         lXWWWWWWWWWWWWWWWWWWWWW");
    puts("WWWWWWWWWWWWWWWWWWWWWW0o::llccoollllccllccccc:;;;,,,;;;;,,''''.......        .xNWWWWWWWWWWWWWWWWWWWW");
    puts("WWWWWWWWWWWWWWWWWWWWWXklc:c:;:lllcclc::c:;;;;;;;;;;;;:::;,,,,''......         :KWWWWWWWWWWWWWWWWWWWW");
    puts("WWWWWWWWWWWWWWWWWWWWWKdccccc::lllllll:::::;,,,;;;;;;;:cc:;;;,,'......         .kWWWWWWWWWWWWWWWWWWWW");
    puts("WWWWWWWWWWWWWWWWWWWWWOocloolccclllolc:;;::;,,,,,,,,,;;:c:;;,,'......          .dWWWWWWWWWWWWWWWWWWWW");
    puts("WWWWWWWWWWWWWWWWWWWWNOoldddoolllooolclll:;;;;;;,;;,,'',::;,,''......           oNWWWWWWWWWWWWWWWWWWW");
    puts("WWWWWWWWWWWWWWWWWWWWN0ooddooolloollcclooc;;;;;;;;;;,'.',,,,,''......          .dWWWWWWWWWWWWWWWWWWWW");
    puts("WWWWWWWWWWWWWWWWWWWWWKxddddllooolc:;;:clc:;;;;:;;;,,'....''..........         .kWWWWWWWWWWWWWWWWWWWW");
    puts("WWWWWWWWWWWWWWWWWWWWWXkddollllodllc;,;::;:::::;;;,,,'''..............         :KWWWWWWWWWWWWWWWWWWWW");
    puts("WWWWWWWWWWWWWWWWWWWWWW0xoocccclolllc::::;;::;;;;;,'''''''............        .xWWWWWWWWWWWWWWWWWWWWW");
    puts("WWWWWWWWWWWWWWWWWWWWWWNOooollcllllc:clccc:;,;;,;;,'.....''','........        cXWWWWWWWWWWWWWWWWWWWWW");
    puts("WWWWWWWWWWWWWWWWWWWWWWWXxlllooollccllllc:::;;;,;;,'.......','.........      :KWWWWWWWWWWWWWWWWWWWWWW");
    puts("WWWWWWWWWWWWWWWWWWWWWWWWKxlllllllllolllc;;;;;;;;;;,,'.....''..........     cKWWWWWWWWWWWWWWWWWWWWWWW");
    puts("WWWWWWWWWWWWWWWWWWWWWWWWWXOdoolccloolccc::::::::cccc:,,'''''''''''....   .oXWWWWWWWWWWWWWWWWWWWWWWWW");
    puts("WWWWWWWWWWWWWWWWWWWWWWWWWWNKkollccccccccc:ccc:;;:;;;,,,;;;;,,,,''....   ;kNWWWWWWWWWWWWWWWWWWWWWWWWW");
    puts("WWWWWWWWWWWWWWWWWWWWWWWWWWWWX0dcc::;;;:c::clcc:;,,,,,,,,,;;;,,'....   ,xXWWWWWWWWWWWWWWWWWWWWWWWWWWW");
    puts("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWXOdc;,,,,;;;:ccc::;;;;,,,,''''....   .:xXWWWWWWWWWWWWWWWWWWWWWWWWWWWWW");
    puts("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWNKkoc;,,;;;;,,'''''''........  ..:d0NWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW");
    puts("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWNXOkdl:;,'...............,:okKNWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW");
    puts("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWNKOkxdoolllllllodxOKXWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW");
    puts("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW");
    puts("NWWNWWWWWWWWWWWWNWWWWWWWWWNWWNWWWWWWNWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWNWWWWWWWWWWWWNWWWWWWW");
}

void dibujoSaturno () {

    puts("                                                                    ..;===+.");
    puts("                                                                .:=iiiiii=+=");
    puts("                                                             .=i))=;::+)i=+,");
    puts("                                                          ,=i);)I)))I):=i=;");
    puts("                                                       .=i==))))ii)))I:i++");
    puts("                                                     +)+))iiiiiiii))I=i+:'");
    puts("                                .,:;;++++++;:,.       )iii+:::;iii))+i='");
    puts("                             .:;++=iiiiiiiiii=++;.    =::,,,:::=i));=+'");
    puts("                           ,;+==ii)))))))))))ii==+;,      ,,,:=i))+=:");
    puts("                         ,;+=ii))))))IIIIII))))ii===;.    ,,:=i)=i+");
    puts("                        ;+=ii)))IIIIITIIIIII))))iiii=+,   ,:=));=,");
    puts("                      ,+=i))IIIIIITTTTTITIIIIII)))I)i=+,,:+i)=i+");
    puts("                     ,+i))IIIIIITTTTTTTTTTTTI))IIII))i=::i))i='");
    puts("                    ,=i))IIIIITLLTTTTTTTTTTIITTTTIII)+;+i)+i`");
    puts("                   =i))IIITTLTLTTTTTTTTTIITTLLTTTII+:i)ii:'");
    puts("                   +i))IITTTLLLTTTTTTTTTTTTLLLTTTT+:i)))=,");
    puts("                   =))ITTTTTTTTTTTLTTTTTTLLLLLLTi:=)IIiii;");
    puts("                  .i)IIITTTTTTTTLTTTITLLLLLLLT);=)I)))))i;");
    puts("                  :))IIITTTTTLTTTTTTLLHLLLLL);=)II)IIIIi=:");
    puts("                  :i)IIITTTTTTTTTLLLHLLHLL)+=)II)ITTTI)i=");
    puts("                  .i)IIITTTTITTLLLHHLLLL);=)II)ITTTTII)i+");
    puts("                  =i)IIIIIITTLLLLLLHLL=:i)II)TTTTTTIII)i'");
    puts("                +i)i)))IITTLLLLLLLLT=:i)II)TTTTLTTIII)i;");
    puts("              +ii)i:)IITTLLTLLLLT=;+i)I)ITTTTLTTTII))i;");
    puts("             =;)i=:,=)ITTTTLTTI=:i))I)TTTLLLTTTTTII)i;");
    puts("           +i)ii::,  +)IIITI+:+i)I))TTTTLLTTTTTII))=,");
    puts("         :=;)i=:,,    ,i++::i))I)ITTTTTTTTTTIIII)=+'");
    puts("       .+ii)i=::,,   ,,::=i)))iIITTTTTTTTIIIII)=+");
    puts("      ,==)ii=;:,,,,:::=ii)i)iIIIITIIITIIII))i+:'");
    puts("     +=:))i==;:::;=iii)+)=  `:i)))IIIII)ii+'");
    puts("   .+=:))iiiiiiii)))+ii;");
    puts("  .+=;))iiiiii)));ii+");
    puts(" .+=i:)))))))=+ii+");
    puts(".;==i+::::=)i=;");
    puts(",+==iiiiii+,");
    puts("`+=+++;`");
}

void dibujoLuna () {

    puts("                     .--------------.");
    puts("                .---'  o        .    `---.");
    puts("             .-'    .    O  .         .   `-.");
    puts("          .-'     @@@@@@       .             `-.");
    puts("        .'@@   @@@@@@@@@@@       @@@@@@@   .    `.");
    puts("      .'@@@  @@@@@@@@@@@@@@     @@@@@@@@@         `.");
    puts("     /@@@  o @@@@@@@@@@@@@@     @@@@@@@@@     O     \\ ");
    puts("    /        @@@@@@@@@@@@@@  @   @@@@@@@@@ @@     .  \\ ");
    puts("   /@  o      @@@@@@@@@@@   .  @@  @@@@@@@@@@@     @@ \\ ");
    puts("  /@@@      .   @@@@@@ o       @  @@@@@@@@@@@@@ o @@@@ \\ ");
    puts(" /@@@@@                  @ .      @@@@@@@@@@@@@@  @@@@@ \\ ");
    puts(" |@@@@@    O    `.-./  .        .  @@@@@@@@@@@@@   @@@  | ");
    puts(" / @@@@@        --`-'       o        @@@@@@@@@@@ @@@    .  ");
    puts(" |@ @@@@ .  @  @    `    @            @@      . @@@@@@   | ");
    puts(" |   @@                         o    @@   .     @@@@@@   | ");
    puts(" |  .     @   @ @       o              @@   o   @@@@@@.  | ");
    puts(" \\     @    @       @       .-.       @@@@       @@@    / ");
    puts(" |  @    @  @              `-'     . @@@@     .    .    |" );
    puts(" \\ .  o       @  @@@@  .              @@  .           . /");
    puts("  \\      @@@    @@@@@@       .                   o     /");
    puts("   \\    @@@@@   @@\\@@    /        O          .        /");
    puts("    \\ o  @@@       \\ \\  /  __        .   .     .--.  /");
    puts("     \\      .     . \\.-.---                   `--'  /");
    puts("      `.             `-'      .                   .'");
    puts("        `.    o     / | `           O     .     .'");
    puts("          `-.      /  |        o             .-'");
    puts("             `-.          .         .     .-'");
    puts("                `---.        .       .---'");
    puts("                     `--------------'");
}

void dibujoTierra () {

    puts("              _-o#&&*''''?d:>b\\_               ");
    puts("          _o/'`''  '',, dMF9MMMMMHo_            ");
    puts("       .o&#'        `'MbHMMMMMMMMMMMHo.         ");
    puts("     .o"" '         vodM*$&&HMMMMMMMMMM?.       ");
    puts("    ,'              $M&ood,~'`(&##MMMMMMH\\     ");
    puts("   /               ,MMMMMMM#b?#MMMMMMMHMMML     ");
    puts("  &              ?MMMMMMMMMMMMMMMMM7MMM$R*Hk    ");
    puts(" ?$.            :MMMMMMMMMMMMMMMMMMM/HMMM|`*L   ");
    puts("|               |MMMMMMMMMMMMMMMMMMMMbMH'   T,  ");
    puts("$H#:            `*MMMMMMMMMMMMMMMMMMMMb#}'  `?  ");
    puts("]MMH#             ""*""""*#MMMMMMMMMMMMM'    -  ");
    puts("MMMMMb_                   |MMMMMMMMMMMP'     :  ");
    puts("HMMMMMMMHo                 `MMMMMMMMMT       .  ");
    puts("?MMMMMMMMP                  9MMMMMMMM}       -  ");
    puts("-?MMMMMMM                  |MMMMMMMMM?,d-    '  ");
    puts(" :|MMMMMM-                 `MMMMMMMT .M|.   :   ");
    puts("  .9MMM[                    &MMMMM*' `'    .    ");
    puts("   :9MMk                    `MMM#'        -     ");
    puts("     &M}                     `          .-      ");
    puts("      `&.                             ./        ");
    puts("        `~,                        ../          ");
    puts("           '. _                 /-'             ");
    puts("              '`--._,dd###pp=""''               ");
    puts("                                                ");
    puts("");
}

void dibujoEEI () {

    puts("                /\\");
    puts("                ||");
    puts("               ====");
    puts("               |  |");
    puts("               |  |");
    puts("               ====");
    puts("               XXXX");
    puts("               |\\/|");
    puts("               |/\\|");
    puts("               |\\/|");
    puts("               |/\\|");
    puts("               |\\/|");
    puts("               |/\\|");
    puts("              /____\\");
    puts("              |    |");
    puts("              |    |");
    puts("             /      \\");
    puts("            /        \\");
    puts("           /          \\");
    puts("          /            \\");
    puts("         /              \\");
    puts("         ----------------");
    puts("         |--------------|");
    puts("         |              |");
    puts("         |     ______   |");
    puts("         |     |        |");
    puts("         |     |---     |");
    puts("         |     |_____   |");
    puts("         |     ______   |");
    puts("         |     |        |");
    puts("         |     |---     |");
    puts("         |     |_____   |");
    puts("         |              | ");
    puts("         |     -----    |");
    puts("         |       |      |");
    puts("         |       |      |");
    puts("         |       |      |");
    puts("         |     -----    |");
    puts("         |              |");
    puts("         |      __      |");
    puts("        /|      ||      |\\");
    puts("       / |      ||      | \\");
    puts("      /  |      ||      |  \\");
    puts("     /   |      ||      |   \\");
    puts("-----    |      HH      |    -----");
    puts("|   |    |      HH      |    |   |");
    puts("|   |    |      HH      |    |   |");
    puts("|   |    |      HH      |    |   |");
    puts("|   |    |______HH______|    |   |");
    puts("--------/       HH       \\--------");
}

void despedida()
{
    puts(" _    _           __ _             _ _              _              _                                                               ");
    puts("| |  | |         / _(_)           | (_)            | |            | |                                                              ");
    puts("| |__| | __ _   | |_ _ _ __   __ _| |_ ______ _  __| | ___     ___| |  _ __  _ __ ___   __ _ _ __ __ _ _ __ ___   __ _             ");
    puts("|  __  |/ _` |  |  _| | '_ \\ / _` | | |_  / _` |/ _` |/ _ \\   / _ \\ | | '_ \\| '__/ _ \\ / _` | '__/ _` | '_ ` _ \\ / _` |            ");
    puts("| |  | | (_| |  | | | | | | | (_| | | |/ / (_| | (_| | (_) | |  __/ | | |_) | | | (_) | (_| | | | (_| | | | | | | (_| |  _   _   _ ");
    puts("|_|  |_|\\__,_|  |_| |_|_| |_|\\__,_|_|_/___\\__,_|\\__,_|\\___/   \\___|_| | .__/|_|  \\___/ \\__, |_|  \\__,_|_| |_| |_|\\__,_| (_) (_) (_)");
    puts("                                                                      | |               __/ |                                      ");
    puts("                                                                      |_|              |___/                                       ");


    puts("                       |        |                                             ");
    puts("                       |        |  //                 \\\\ | |                ");
    puts("                       \\        | //                 /_\\\\| |         _.-~  ");
    puts("                        \\       |||                 |  ||/ |     _.-~        ");
    puts("                 ________\\      |||                  \\ ||  |__.-~           ");
    puts("                /       /~`. ___\\||___________________/||_/______________     ");
    puts("              _/_______/__/]---.               _____               ;:         ");
    puts("             /         /( )/\\   `._____________\\    \\               :         ");
    puts("            /         / /\\ \\    / .=============\\    \\             ::         ");
    puts("           /         / / / /\\   | :            | \\(_)_\\            ::         ");
    puts("          /         / / / /-\\\\ _\\'             | |\\  \\             ::         ");
    puts("         /        /' / / /._/.'_'.             | |/\\  \\            ::         ");
    puts("        /        /  / / / - / _-  \\____________|_/ /\\  \\           ::         ");
    puts("       /        /'  / / /-   |      \\====/\\======= /  \\_ \\          ::        ");
    puts("      /        /   / : (  - -\\      \\_(/ /\\    / /    \\ \\           ::        ");
    puts("     /...----'   /  . `. -   \\ -_   _'.\\\\ /|  / /|     \\ \\          ::        ");
    puts("     \\           \\  /`. `._  /\\   _-    \\\\/  / / |      \\ \\         ::        ");
    puts("      \\___________\\/  `. `._..'\\_______.'___/ /| |       \\ \\_       :         ");
    puts("               /'.      `.....' |==========/ / \\ \\        \\_ \\      ::        ");
    puts("              /-_   :  --..___ \\/       / / /   \\ \\         \\ \\_    ::        ");
    puts("              |-._   :          \\      / / /     \\ \\         \\_ \\   ::        ");
    puts("              |-_ '-._\\ - -_   - \\____/_/ /-      \\ \\     __   \\ \\   ::       ");
    puts("        __..--|-      /\\          \\====/ /  \\      \\ \\_.-~  \\   \\ \\  ::       ");
    puts("__..--~~.   . |     _.| \\          \\  / /  -     _. \\ \\      \\   \\ \\ ::       ");
    puts("'  .  '   .   |__.-'  |   \\__       \\/ /     _.-    \\_/      /    \\ \\ ::      ");
    puts(" __--~~  . .  |       |____\\ '----___\\/   _.-             _.-      \\ \\::      ");
    puts("  __--''      |       /====-\\        |    \\            _.-          \\ \\:      ");
    puts(" ..--~~ .- .. |  .    |     |        / _.- \\        _.-              \\_\\      ");
    puts("   .   .      |_-     /     |_--  --/.-     \\    _.-________________________  ");
    puts(" . . .   .  . |      /______|______/      _.-\\_.-        ..    . '  .  /      ");
    puts("    .   .     |______|=====/' -_- '/   _.-      .    .            .   /       ");
    puts(" .       .    |'     '|   /--__   /_.-   .        .       .         ./        ");
    puts(". .  .       /|___----|  /    -_ (____    .     .    .            . /         ");
    puts("            / |   -   |_ |___________ \\  .    .           .    .   /          ");
    puts(" . .   .'  / /|_-  -  \\ \\ \\___________/   .      .    .         . <           ");
    puts("          /___\\ ______- /__/ /           .     .             .   . '-._       ");
    puts(" '. .  . /=====\\_______/==/ / ..     .      .      .      .       .    '~~-.__");
    puts("   .  . /_/ /          _//_/      .           .       .            .          ");
    puts(" . .  .    /           /         .       .       .          ' .      .        ");
    puts("          /           /     .       .    '    ,.        .       .           ' ");
    puts(" . .     /           /   .        .         .       .       .         '   .   ");
    puts("  .   . / ___       / .         .        ..      '      .         . ..       .");
    puts("     __/_/  \\\\     /___    .      . .         .     .       '             .   ");
    puts("  .'  //     \\\\   /    `.                                                     ");
    puts(".'   /_|.'..'.\\\\ /       `.   .         .       '         .       .       .   ");
    puts("      _|_______\\\\_         \\       . .    .        .            .     '  .    ");
    puts("     \\___     ___/        // .          .     .        .               .      ");
    puts("         '---'          .'/       .               .         .              .  ");
    puts("`.                    .'.'   .        .               .            .    .     ");
    puts("`.`.________________.'.'  .       .        .              .          .        ");
    puts("  `.________________.'UTN                                                     ");
    puts(".     .          .          .         .        .          .      .            ");

}
