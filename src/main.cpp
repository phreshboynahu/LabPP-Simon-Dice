#include<iostream>
#include<time.h>
#include<string.h>
#include"prototipos.h"
using namespace std;

int main (int argc, char *argv[]) {
    srand(time(NULL));
    bool inicio;
    char nombre[10]={'-'}, leaderboard[10][10]={'-'}, diff;
    int aciertos;
    bienvenida();
    inicio = inicioJuego(nombre, diff);
    printf("%s, %c", nombre, diff);
    //while (inicio) {
    //valorApuesta = apuesta(importeFinal);
    //nroApostado = apostado();
    //juego(importeFinal, cantidadJugadas, aciertos, valorApuesta,nroApostado);
    //inicio = sigueJugando(importeFinal, cantidadJugadas);
//}
//informe(importeInicial, cantidadJugadas, aciertos, importeFinal);
    return 0;
}
 