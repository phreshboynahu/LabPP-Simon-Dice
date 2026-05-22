#include<iostream>
#include<time.h>
#include<string.h>
#include<unistd.h>
#include"prototipos.h"
using namespace std;

int main (int argc, char *argv[]) {
    srand(time(NULL));
    bool inicio, gano
    char nombre[11], leaderboard[12][12] = {'-'}, sec_colores[10];
    char diff, seguir;
    int puntaje;
    bienvenida();
    while ((inicio = inicioJuego(nombre, &diff))&&(seguir == 's' || seguir == 'S')&&!(seguir == 'n' || seguir == 'N'))
    {
        puntaje = 0;
        int n = iniSecuencia(diff, sec_colores);

        bool gano = mostrarSecuencia(diff, sec_colores, &puntaje, n);

        printf("Desea jugar otra partida? (s/n): ");
        scanf(" %c", &seguir);
    };

    printf("Puntaje final: %d\n", puntaje);

}
 