#include<iostream>
#include<time.h>
#include<string.h>
#include<unistd.h>
#include"prototipos.h"
using namespace std;

int main (int argc, char *argv[]) {
    srand(time(NULL));
    bool inicio = true, gano;
    char nombre[10] = {' '}, sec_colores[NIVEL_A];//nombre[10] es el array del jugador actual y sec_colores es la secuencia
    char diff, seguir = 's';
    int puntaje=0;//puntaje de jugador actual
    ranking player [3]; //ranking de jugadores
    bienvenida();
    while ((inicio)&&(seguir == 's' || seguir == 'S')){
        puntaje = 0;
        inicio = inicioJuego(nombre, &diff);
        if (inicio){
            int n = iniSecuencia(diff, sec_colores);
            gano = mostrarSecuencia(diff, sec_colores, &puntaje, n);
            if(gano == false){
                printf("Perdiste... :( \n");
            }
            else{
                printf("Ganaste... :D \n");
            }
            printf("Tu puntaje fue de: %d \n", puntaje);
            actualizarRecord(player, diff, nombre, puntaje);
            printf("Desea jugar otra partida? (s/n): ");
            scanf(" %c", &seguir);
            while ((seguir != 's' && seguir != 'S')&&(seguir != 'n' && seguir != 'N'))
            {
                printf("Debe ingresar S(s) o N(n). Vuelva a intentarlo");
                scanf(" %c", &seguir);
            }
            system("clear");
        }
    }finjuegofin(player);
    return 0;
}