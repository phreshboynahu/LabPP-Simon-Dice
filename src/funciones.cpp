#include<iostream>
#include<string.h>
using namespace std;
//Mensaje de bienvenida al juego.
void bienvenida(){ 
printf("Bienvenido al Juego de SIMON ver. 1.0.");
}
//Inicio del juego, pide nombre y dificultad al usuario.
bool inicioJuego (char nombre[], char *diff){
    int i=0;
    char enter, c; //c es para ver si es un enter o espacio
    bool nombreOk = false;
    do
    {
        printf("\nIngrese su nombre (fin=fin del Juego): ");
        while ((c = getchar()) != '\n'){
            {   
                if(i < 9){
                    nombre[i]= c;
                    i++;
                }
            }
        if (i == 0) {
            printf("Error: No ingresó nada. Vuelva a intentarlo.\n");
        } else if (strcmp(nombre, "fin") == 0) {
            return false;
        } else {
            nombreOk = true;
        }
    }
    } while (!nombreOk);

    do{
        printf("\nIngrese nivel del Juego (p, i, a): ");
        scanf(" %c", diff);
            if (*diff!='p' && *diff!='P' &&
           *diff!='i' && *diff!='I' &&
           *diff!='a' && *diff!='A')
            {
                printf("Nivel del juego no es válido. Vuela a intentarlo.");
            }
            
    }while(*diff!='p' && *diff!='P' &&
           *diff!='i' && *diff!='I' &&
           *diff!='a' && *diff!='A');

    do{
        printf("\nPulse <enter> para comenzar el juego");
        getchar();
        enter = getchar();
    }while(enter!='\n');

    return true;
}

//Proceso del juego propiamente dicho. 

//Se debe generar la secuencia y mostrarsela al jugador, luego pegarte un tiro
//void juego(float &importeFinal, int &cantidadJugadas, int &aciertos, float valorApuesta, int nroApostado){
    //char secuencia[6]={'-'};
        //printf(" ¡GANASTE! (ﾉ◕ヮ◕)ﾉ*:･ﾟ✧\n");
        //printf(" Perdiste... (╥﹏╥)\n");
    
//}

//Preguntar si continua jugando.No olvidar que al menos se deben jugar 5 partidas.
//bool sigueJugando(float importeFinal, int cantidadJugadas){
    //char seguir;

    //if(cantidadJugadas % 5 == 0 && importeFinal>0){
        //printf("\n¿Querés seguir jugando? (S/N): ");
        //scanf(" %c", &seguir);

        //if (seguir == 'S'|| seguir == 's'){
        //    return true;
        //}else{
          //  return false;
        //}
    //}
        
    //if(importeFinal == 0){
      //  return false;
    //}
    //return true;
 //}

//Muestra el resultado de la partida.
//void informe(float importeInicial, int cantidadJugadas, int aciertos, float importeFinal){
    //printf("Presione cualquier tecla para continuar...");
    //getchar();
    //getchar();
    //system("clear");
    //printf("\n=====================================\n");
    //printf("            RESULTADOS  \n");
    //printf("=====================================\n");

    //printf("Dinero inicial: $%.2f\n", importeInicial);
    //printf("Cantidad de jugadas: %d\n", cantidadJugadas);
    //printf("Aciertos: %d \n", aciertos);
    //printf("Errores: %d \n", cantidadJugadas - aciertos);
    //printf("Dinero final: $%.2f\n", importeFinal);
//}

