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

//Actualizamos la tabla de puntajes.
void actualizarRecord(jugador *mejor, char nombre[], int puntaje);

//En caso que se ingrese como nombre de jugador ‘fin’ ingresar el nombre y los puntos del jugador que mas puntaje obtuvo por dificultad.
void finjuegofin();
#endif