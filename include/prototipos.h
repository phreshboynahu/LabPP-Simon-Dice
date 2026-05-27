#ifndef PROTOTIPOS_H
#define PROTOTIPOS_H
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
//Datos de los jugadores en el ranking
struct ranking{
    char nombre[10]={'-'};
    int puntaje = 0;
};

//Mensaje de bienvenida al juego.
void bienvenida();

//Pide el nombre y la dificultad al usuario.
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
void copiarNom(char destino[], char origen[]);

//Convierte carateres hacia minuscula. (Ej. 'V' hacia 'v' para que no se asuste el comparador de arreglos)
char convMinusc(char c);

//Si el puntaje actual supera al record del diff, actualiza el leaderboard.
void actualizarRecord(ranking *player,char diff, char nombre[], int puntaje);

// Muestra la tabla final con los mejores puntajes por nivel cuando se ingresa 'fin'.
void finjuegofin(ranking player[]);
#endif