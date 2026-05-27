#include<iostream>
#include<string.h>
#include<unistd.h>
#include<stdio_ext.h>
#include"prototipos.h"

using namespace std;

// mensajito de bienvenida
void bienvenida(){ 
    printf("Bienvenido al Juego de SIMON ver. 1.0.");
}

bool pedirNombre (char nombre[]){
    char c; 
    bool valido = false;
    do
    {
        int i=0; // contador de letras
        printf("\nIngrese su nombre (fin=fin del Juego): ");
        /*getchar();
        // codigo viejo q usaba getchar y guardaba basura
        while ((c = getchar()) != '\n'){
            {   
                if(i < 9){
                    nombre[i]= c;
                    i++;
                }   
            }
        }*/
        __fpurge(stdin);
        scanf("%[^ \n]", nombre);
        __fpurge(stdin);
        while ((strlen(nombre)==1))
        {
            printf("Debe ingresar nombre del Jugador o fin para finalizar el juego. Vuelva a intentarlo\n");
            scanf("%[^ \n]", nombre);
            __fpurge(stdin);
        }

        // palabra magica para salir del juego
        if (strcmp(nombre, "fin") == 0) {
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

            printf("Nivel del juego no es valido. Vuelva a intentarlo.\n");
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

        __fpurge(stdin);

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

    // ajustes acorde la dificultad
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
    // r = rojo, a = azul, v = verde, etc.
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

char convMinusc(char c){ //le suma 32 a las letras ascii mayuscula para que sean minuscula
    if(c >= 65 && c <= 90){
        c = c + 32;
    }

    return c;
}

bool mostrarSecuencia(char diff,char sec_colores[],int *puntaje, int n){
    int segundos, ronda=0;

    char ingreso[NIVEL_A+1]={' '};
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
            system("clear");
            printf("Color numero %d\n", b+1);
            printf("|\t%c\t|\n", sec_colores[b]);
            sleep(segundos);

            // limpia pantalla pero solo en linux
            system("clear");
        }

        // lectura del ingreso
        for(int i = 0; i < ronda; i++){;
            printf("\nCual fue el color %d?: ", i+1);
            scanf(" %c", &ingreso[i]);
            ingreso[i] = convMinusc(ingreso[i]);
            if(ingreso[i] != sec_colores[i]){ // chequeamos coincidencias
                system("clear");
                return false; // game over
            }
            //printf("ingreso[%d]=%c | sec[%d]=%c\n", i, ingreso[i], i, sec_colores[i]); // debug, muestra valores
            system("clear");
        }
        *puntaje += puntosPorAcierto;;
        system("clear");
    }
    return true; // solo cuando se paso el juego
}

void copiarNom(char destino[], char origen[]){ //basicamente pasa caracter por caracter de un array a otro
    int i = strlen(origen);
    while(i >= 0){
        destino[i] = origen[i];
        i--;
    }
}

void actualizarRecord(ranking player[], char diff, char nombre[], int puntaje) {
    if (diff=='p' || diff=='P'){			// dependiendo de diff comparar el puntaje actual.
        if (player[0].puntaje < puntaje){   // con "player[posicion].puntaje" si es menor se sobreescribe con el nuevo nombre y puntaje
            player[0].puntaje = puntaje;     
            copiarNom(player[0].nombre, nombre);
    	}
	}if (diff=='i' || diff=='I'){
        if (player[1].puntaje < puntaje){
            player[1].puntaje = puntaje;
            copiarNom(player[1].nombre, nombre);
    	}
	}if (diff=='a' || diff=='A'){
        if (player[2].puntaje < puntaje){
            player[2].puntaje = puntaje;
            copiarNom(player[2].nombre, nombre);
    	}
	}
}
void finjuegofin(ranking player[]){
        printf("Resultados del juego:\n");
        printf("\tPrincipiante: %s %d puntos\n",player[0].nombre, player[0].puntaje);
        printf("\tIntermedio: %s %d puntos\n",player[1].nombre, player[1].puntaje);
        printf("\tAvanzado: %s %d puntos\n",player[2].nombre, player[2].puntaje);
}