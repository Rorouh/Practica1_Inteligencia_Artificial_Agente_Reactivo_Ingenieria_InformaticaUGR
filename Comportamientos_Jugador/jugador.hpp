#ifndef COMPORTAMIENTOJUGADOR_H
#define COMPORTAMIENTOJUGADOR_H
#include <queue>
#include "comportamientos/comportamiento.hpp"
using namespace std;

class ComportamientoJugador : public Comportamiento{

  public:
    ComportamientoJugador(unsigned int size) : Comportamiento(size){
      // Constructor de la clase
      // Dar el valor inicial a las variables de estado
      fil = col = 99;
      brujula = 0; // 0 - NORTE, 1 - ESTE, 2 - SUR , 3 - OESTE
      ultimaAccion = actIDLE;
      bien_situado=false;
      zapatillas = false;
      bikini =false;
      valor_pendientes = -1;
      // tiempo_movimiento = 0;
      // TAM = 100;
      // //Inicializacion de la matriz de tiempo la cual el jugador dejara un rasto para saber hacia donde ir y no repetir el mismo patron
      // for(int i=0; i< TAM;i++){
      //   for (int j = 0; j < TAM; j++){
      //     matriz_tiempo[i][j] = 0;
      //   }
      // }
      contador_giros=0;
      tamanio_mapa = size;
      inicio_juego=true;
      recargando = 0;
    }

    ComportamientoJugador(const ComportamientoJugador & comport) : Comportamiento(comport){}
    ~ComportamientoJugador(){}

    Action think(Sensores sensores);
    int interact(Action accion, int valor);
    void Vision(Sensores sensores);
    void GuardaUltimaAccion(Action accion, Sensores sensores,bool situado, int fil_aux, int col_aux);
    int AnalizaArboles(Sensores Sensores);

  private:
  int fil; int col; int brujula ;
  Action ultimaAccion;
  bool bikini;
  bool zapatillas;
  bool bien_situado;
  int valor_pendientes ; // 1 = recto; 2 =gira izq; 3 = gira der;
  queue<int> cola_pendientes;
  // int tiempo_movimiento;
  // int TAM;
  // int matriz_tiempo[100][100];
  int contador_giros;
  int tamanio_mapa;
  bool inicio_juego;
  int recargando;
  // Declarar aquí las variables de estado

};

#endif
