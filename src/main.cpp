#include<iostream>
#include<time.h>
#include<string.h>
#include<unistd.h>
#include"prototipos.h"
using namespace std;

int main (int argc, char *argv[]) {
    srand(time(NULL));
    bool inicio = true, gano;
    char nombre[11] = {' '}, sec_colores[NIVEL_A];
    char diff, seguir = 's';
    int puntaje=0;
    ranking player [3] = {0}; //ranking de jugadores
    bienvenida();
    while ((inicio)&&(seguir == 's' || seguir == 'S')){
        puntaje = 0;
        inicio = inicioJuego(nombre, &diff);
        if (inicio){
            int n = iniSecuencia(diff, sec_colores);
            gano = mostrarSecuencia(diff, sec_colores, &puntaje, n);
            if(gano = false){
                printf("Perdiste... :( \n");
            }
            else{
                printf("Ganaste... :D \n");
            }
            actualizarRecord(player, diff, nombre, puntaje);
            printf("Desea jugar otra partida? (s/n): ");
            scanf(" %c", &seguir);
            while ((seguir != 's' && seguir != 'S')&&(seguir != 'n' && seguir != 'N'))
            {
                printf("Debe ingresar S(s) o N(n). Vuelva a intentarlo");
                scanf(" %c", &seguir);
            }
        }
    }finjuegofin(player);
    return 0;
}