#include<iostream>
#include<string.h>
#include<unistd.h>
// niveles (largo de secuencia)
#define NIVEL_P 6
#define NIVEL_I 8
#define NIVEL_A 10

// tiempos por nivel
#define TIEMPO_COLOR_P 3
#define TIEMPO_COLOR_I 2
#define TIEMPO_COLOR_A 1

// puntaje por acierto
#define ACIERTO_NIVEL_P 1
#define ACIERTO_NIVEL_I 3
#define ACIERTO_NIVEL_A 5
using namespace std;

// mensajito de bienvenida bien tranqui
void bienvenida(){ 
    printf("Bienvenido al Juego de SIMON ver. 1.0.");
}

bool pedirNombre (char nombre[]){
    
    char c; 
    bool valido = false;

    do
    {
        int i=0; // contador de letras, tampoco nos vamos a escribir la biblia
        printf("\nIngrese su nombre (fin=fin del Juego): ");

        // vamos guardando letra por letra hasta enter
        while ((c = getchar()) != '\n'){
            {   
                if(i < 9){
                    nombre[i]= c;
                    i++;
                }   
            }
        }


        if (i == 0) {
            printf("Debe ingresar nombre del Jugador o fin para finalizar el juego. Vuelva a intentarlo\n");
        } 
        // palabra magica para rajar del juego
        else if (strcmp(nombre, "fin") == 0) {
            return false;
        } 
        else {
            valido = true;
        }

    } while (!valido);

     return true;
}

char pedirDificultad(){

    char diff;

    do{

        printf("\nIngrese nivel del Juego (p, i, a): ");
        scanf(" %c", &diff);

        // validacion de la dificultad
        if(diff!='p' && diff!='P' &&
           diff!='i' && diff!='I' &&
           diff!='a' && diff!='A'){

            printf("Nivel del juego no es válido. Vuelva a intentarlo.\n");
        }

    }while(diff!='p' && diff!='P' &&
           diff!='i' && diff!='I' &&
           diff!='a' && diff!='A');

    return diff;
}

void esperarEnter(){

    char enter;

    do
    {
        printf("\nPulse <enter> para comenzar el juego");

        // limpiamos buffer porque esta tomando un enter de otro lado (?)
        getchar();

        enter = getchar();

    } while (enter!='\n');
}

// aca arrancamos todo lo de iniciar el juego
bool inicioJuego(char nombre[], char *diff){

    if(!pedirNombre(nombre)){
        return false;
    }

    *diff = pedirDificultad();

    esperarEnter();

    return true;
}

int iniSecuencia(char diff, char sec_colores[]){

    int n=0; //largo de secuencia.

    // r = rojo, a = azul, v = verde, etc.
    switch (diff){ 

        case 'P':
        case 'p':
            n=NIVEL_P;
            break;

        case 'I':
        case 'i':
            n=NIVEL_I;
            break;

        case 'A':
        case 'a':
            n=NIVEL_A;
            break;
    }

    // generamos la secuencia random de colores
    for (int i = 0; i < n; i++) {

        switch (rand()%4+1){ 

            case 1:
                sec_colores[i]='r';
                break;

            case 2:
                sec_colores[i]='a';
                break;

            case 3:
                sec_colores[i]='n';
                break;

            case 4:
                sec_colores[i]='v';
                break;
        }
    }
    return n;
}

bool mostrarSecuencia(char diff,char sec_colores[],int *puntaje, int n){
    int segundos, ronda=0;

    char ingreso[11]={' '};
    int puntosPorAcierto;
    switch (diff)
    {
        case 'P':
        case 'p':
            puntosPorAcierto = ACIERTO_NIVEL_P;
            segundos = TIEMPO_COLOR_P;
            break;

        case 'I':
        case 'i':
            puntosPorAcierto = ACIERTO_NIVEL_I;
            segundos = TIEMPO_COLOR_I;
            break;

        case 'A':
        case 'a':
            puntosPorAcierto = ACIERTO_NIVEL_A;
            segundos = TIEMPO_COLOR_A;
            break;
    }

    for (int ronda = 1; ronda <= n; ronda++){

        for (int b = 0; b < ronda; b++){
            printf("|\t%c\t|\n", sec_colores[b]);
            sleep(segundos);

            // limpia pantalla pero solo en linux ojooooo
            system("clear");
        }

        printf("Que colores salieron? (ingresa %d colores seguidos): \n", ronda);

        // lectura del ingreso
        for(int i = 0; i < ronda; i++){
            ingreso[i] = getchar();
        }
        getchar(); // limpia el salto de linea en el buffer

        // chequeamos coincidencias
        for (int b = 0; b < ronda; b++){
            if(ingreso[b] != sec_colores[b]){
                printf("Perdiste... (╥﹏╥)\n");
                return false; // game over
            }
        }
        *puntaje += puntosPorAcierto;
        printf("Acertaste!(ﾉ◕ヮ◕)ﾉ*:･ﾟ✧ Puntaje hasta ahora: %d\n", *puntaje);
        sleep(2);
        system("clear");
    }
    return true; // osea si se paso el juego
}
void actualizarRecord(ranking player[], char diff, char nombre[], int puntaje) {
    if (diff=='p' && diff=='P'){
        if (player[0].puntaje < puntaje){    // dependiendo de diff comparar el puntaje actual.
            player[0].puntaje = puntaje;     // con 'leaderboard[posicion].puntaje' si es mayor  metele el nuevo nombre 
            strcpy(player[0].nombre, nombre);
    }
}if (diff=='i' && diff=='I'){
        if (player[1].puntaje < puntaje){
            player[1].puntaje = puntaje;
            strcpy(player[1].nombre, nombre);
    }
}if (diff=='a' && diff=='A'){
        if (player[2].puntaje < puntaje){
            player[2].puntaje = puntaje;
            strcpy(player[2].nombre, nombre);
    }
}
}

ranking player
void finjuegofin(ranking player[]){
    if (inicioJuego==false){
        printf("Resultados del juego:\n");
        printf("\tPrincipiante: %9s %d puntos\n",player[0].nombre, player[0].puntaje);
        printf("\tIntermedio: %9s %d puntos\n",player[1].nombre, player[1].puntaje);
        printf("\tAvanzado: %9s %d puntos\n",player[2].nombre, player[2].puntaje);
    }
}

