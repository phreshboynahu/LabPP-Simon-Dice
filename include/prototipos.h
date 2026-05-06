#ifndef PROTOTIPOS_H
#define PROTOTIPOS_H
void bienvenida();
//Mensaje de bienvenida al juego.

bool inicioJuego (char nombre[],char &diff);
//Inicio los valores del juego y solicito si el usuario desea jugar y el importe con que arranca.

//float apuesta(float importeFinal);
//Solicitar el valor de la apuesta. Se debe controlar queno supere el importe existe.

//int apostado();
//Solicitar el numero al que desea apostar, controlar que este entre 1 y 6.

//void juego(float &importeFinal, int &cantidadJugadas, int &aciertos, float valorApuesta, int nroApostado);
//Proceso del juego propiamente dicho. 
//Se debe generar el numero del dado al azar, comparar y determinar si gana o pierde.

//bool sigueJugando(float importefinal, int cantidadJugadas);
//Preguntar si continua jugando.No olvidar que al menos se deben jugar 5 partidas.

//void informe(float importeInicial, int cantidadJugadas, int aciertos, float importeFinal);
//Muestra el resultado de la partida.

#endif