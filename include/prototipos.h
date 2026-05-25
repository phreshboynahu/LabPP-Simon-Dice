#ifndef PROTOTIPOS_H
#define PROTOTIPOS_H
//aca metemos todos los datos del jugador
struct ranking{
    char nombre[11];
    int puntaje;
};

//Mensaje de bienvenida al juego.
void bienvenida();

//Pide el nombre y la dificultad al usuario
bool pedirNombre(char nombre[]);
char pedirDificultad();

//Espera el enter para jugar.
void esperarEnter();

//Condiciona el inicio del juego.
bool inicioJuego(char nombre[], char *diff);

//Inicializamos la secuencia, usando la diff. para definir su lengitud.
int iniSecuencia(char diff,char sec_colores[]);

//Mostramos la secuencia, usando la diff. para definir su duracion en pantalla.
bool mostrarSecuencia(char diff,char sec_colores[], int *puntaje, int n);

//funcion para copiar el nombre desde el array suelto hacia el struct del ranking
void copiarNom(char destino[], char origen[]){ 

//Si el puntaje actual supera al record del diff, actualiza el leaderboard
void actualizarRecord(ranking *player,char diff, char nombre[], int puntaje);

// Muestra la tabla final con los mejores puntajes por nivel cuando se ingresa 'fin
void finjuegofin(ranking player[]);
#endif
