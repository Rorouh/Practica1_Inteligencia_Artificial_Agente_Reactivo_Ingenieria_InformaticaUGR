#include "../Comportamientos_Jugador/jugador.hpp"
#include <iostream>
#include <queue>
using namespace std;


void ComportamientoJugador::Vision(Sensores sensores){

    int fila = sensores.posF;
    int columna = sensores.posC;
    int col_aux,fil_aux,pos=1;
    brujula = sensores.sentido;
    mapaResultado[fila][columna] = sensores.terreno[0];
    for(int j=0;j < 4 ; j++){

        if (brujula == 0){
            
            if(pos >=1 and pos <=3){
                col_aux = -1;
                fil_aux = -1;
                for(int i=1; i <= 3 ; i++){
                    mapaResultado[fila+fil_aux][columna+col_aux] = sensores.terreno[i];
                    col_aux++;
                    pos++;
                }
            }else if(pos >=4 and pos <= 8){
                col_aux = -2;
                fil_aux = -2;
                for(int i=4; i <= 8; i++){
                    mapaResultado[fila+fil_aux][columna+col_aux] = sensores.terreno[i];
                    col_aux++;
                    pos++;
                }
            }else if(pos >=9){
                col_aux = -3;
                fil_aux = -3;
                for(int i=9; i <= 15 ; i++){
                    mapaResultado[fila+fil_aux][columna+col_aux] = sensores.terreno[i];
                    col_aux++;
                    pos++;
                }
            }
        }else if( brujula ==1 ){
            if(pos >=1 and pos <=3){
                col_aux = 1;
                fil_aux = -1;
                for(int i=1; i <= 3 ; i++){
                    mapaResultado[fila+fil_aux][columna+col_aux] = sensores.terreno[i];
                    fil_aux++;
                    pos++;
                }
            }else if(pos >=4 and pos <= 8){
                col_aux = 2;
                fil_aux = -2;
                for(int i=4; i <= 8; i++){
                    mapaResultado[fila+fil_aux][columna+col_aux] = sensores.terreno[i];
                    fil_aux++;
                    pos++;
                }
            }else if(pos >=9){
                col_aux = 3;
                fil_aux = -3;
                for(int i=9; i <= 15 ; i++){
                    mapaResultado[fila+fil_aux][columna+col_aux] = sensores.terreno[i];
                    fil_aux++;
                    pos++;
                }
            }
        }else if( brujula ==2 ){
            if(pos >= 1 and pos <=3){
                col_aux = 1;
                fil_aux = 1;
                for(int i=1; i <= 3 ; i++){
                    mapaResultado[fila+fil_aux][columna+col_aux] = sensores.terreno[i];
                    col_aux--;
                    pos++;
                }
            }else if(pos >=4 and pos <= 8){
                col_aux = 2;
                fil_aux = 2;
                for(int i=4; i <= 8; i++){
                    mapaResultado[fila+fil_aux][columna+col_aux] = sensores.terreno[i];
                    col_aux--;
                    pos++;
                }
            }else if(pos >=9){
                col_aux = 3;
                fil_aux = 3;
                for(int i=9; i <= 15 ; i++){
                    mapaResultado[fila+fil_aux][columna+col_aux] = sensores.terreno[i];
                    col_aux--;
                    pos++;
                }
            }
        }else if( brujula ==3 ){
            if(pos >=1 and pos <=3){
                col_aux = -1;
                fil_aux = 1;
                for(int i=1; i <= 3 ; i++){
                    mapaResultado[fila+fil_aux][columna+col_aux] = sensores.terreno[i];
                    fil_aux--;
                    pos++;
                }
            }else if(pos >=4 and pos <= 8){
                col_aux = -2;
                fil_aux = 2;
                for(int i=4; i <= 8; i++){
                    mapaResultado[fila+fil_aux][columna+col_aux] = sensores.terreno[i];
                    fil_aux--;
                    pos++;
                }
            }else if(pos >=9){
                col_aux = -3;
                fil_aux = 3;
                for(int i=9; i <= 15 ; i++){
                    mapaResultado[fila+fil_aux][columna+col_aux] = sensores.terreno[i];
                    fil_aux--;
                    pos++;
                }
            }
        }
        
    }
    
}

int ComportamientoJugador::interact(Action accion, int valor){
  return false;
}

void ComportamientoJugador::GuardaUltimaAccion(Action accion,Sensores sensores, bool situado,int fil_aux,int col_aux){
    //RECORDAR LA ULTIMA ACCION
    ultimaAccion = accion;
    // if(situado){
    //         if(sensores.terreno[0] == 'X' or sensores.terreno[0] == 'K' or sensores.terreno[0] == 'D'){
    //             matriz_tiempo[fil_aux][col_aux] = 0;
    //         }else{
    //             matriz_tiempo[fil_aux][col_aux] += 1;
    //         }
    //     }
}
Action ComportamientoJugador::think(Sensores sensores){

	cout << "Posicion: fila " << sensores.posF << " columna " << sensores.posC << " ";
	switch(sensores.sentido){
		case 0: cout << "Norte" << endl; break;
		case 1: cout << "Este" << endl; break;
		case 2: cout << "Sur " << endl; break;
		case 3: cout << "Oeste" << endl; break;
	}
	cout << "Terreno: ";
	for (int i=0; i<sensores.terreno.size(); i++)
		cout << sensores.terreno[i];
	cout << endl;

	cout << "Superficie: ";
	for (int i=0; i<sensores.superficie.size(); i++)
		cout << sensores.superficie[i];
	cout << endl;

	cout << "Colisión: " << sensores.colision << endl;
	cout << "Reset: " << sensores.reset << endl;
	cout << "Vida: " << sensores.vida << endl;
	cout << endl;
    cout << "zapatillas" << zapatillas << endl;
    cout << "bikini" << bikini << endl;
    

    
        
    Action accion = actIDLE;
    switch (ultimaAccion){
        case actFORWARD:
            switch (brujula) {
                case 0: fil--; break;
                case 1: col++; break;
                case 2: fil++; break;
                case 3: col--; break;
            }
            break;
        case actTURN_L:
            brujula = (brujula+3)%4;
            //girar_derecha = (rand()%2 == 0);
            break;
        case actTURN_R:
            brujula = (brujula+1)%4;
            //girar_derecha = (rand()%2 == 0);
            break;
    }
    //------------------------------Actualizacion del mapa que sabemos que es por defecto así.------------------------------
    if( ((sensores.terreno[0] == 'A' or sensores.terreno[0] == 'B' or sensores.terreno[0] =='X')) and (inicio_juego)){
        accion = actFORWARD;
        if(sensores.terreno[2] == 'M' or sensores.terreno[2] == 'P'){
            accion = actTURN_R;
        }
        GuardaUltimaAccion(accion,sensores,bien_situado,fil,col);
        return accion;
    }
    if(inicio_juego){
        for(int i=0;i<tamanio_mapa;i++){
            for(int j=0;j<3;j++){
                mapaResultado[i][j] = 'P';
            }
            for(int j=tamanio_mapa-3;j<tamanio_mapa;j++){
                mapaResultado[i][j] = 'P';
            }
        }
        for(int j=0;j<tamanio_mapa;j++){
            for(int i = 0; i<3;i++){
                mapaResultado[i][j] = 'P';
            }            
            for(int i = tamanio_mapa-3;i<tamanio_mapa;i++){
                mapaResultado[i][j] = 'P';
            }
        }
        //                          Actualizacion de la memoria principal importante del jugador al iniciar el juego
        switch (sensores.nivel)
            {
            case 0:
                bien_situado = true;
                fil = sensores.posF;
                col = sensores.posC;
                break;
            default:
                bien_situado=false;
                fil=-1;     //Como no tiene sensores, tendra valores basura hasta que pase por 'G'
                col=-1;     //en el caso del nivel 2,3,4
                break;
            }
        inicio_juego=false;
    }
    //------------------------------Actualizacion reset del personaje------------------------------
    if(sensores.reset){
        switch (sensores.nivel)
        {
        case 0:
            bien_situado = true;
            fil = sensores.posF;
            col = sensores.posC;
            zapatillas = false;
            bikini=false;
            inicio_juego=true;
            break;
        default:
            bien_situado=false;
            fil=-1;     //Como no tiene sensores, tendra valores basura hasta que pase por 'G'
            col=-1;     //en el caso del nivel 2,3,4
            zapatillas = false;
            bikini=false;
            inicio_juego=true;
            break;
        }
    }
    
    //------------------------------Actualizacion del campo de vision------------------------------

    if ( bien_situado ){
        Vision(sensores);
    }

    //------------------------------Decidir la nueva accion------------------------------

    //------------------------------Decision ante un lobo delante o aldeano delante------------------------------
    if( sensores.superficie[2] == 'l' or sensores.superficie[2] == 'a'){
        contador_giros = rand()%2 + 2;
        if(contador_giros == 2){
            accion = actTURN_L;
        }else{
            accion = actTURN_R;
        }
        GuardaUltimaAccion(accion,sensores,bien_situado,fil,col);
        return accion;
    }
    //------------------------------En el caso de iniciar el juego en una casilla Arbol o Agua------------------------------
    
    
    if( sensores.terreno[0] == 'G' and !bien_situado){
        fil = sensores.posF;
        col = sensores.posC;
        bien_situado = true;
    }
    //--------------------------------Reaccion del personaje ante estar en una casilla de recarga y tener poca bateria--------------------------------
    
    if(sensores.terreno[0] == 'D'){
        zapatillas = true;
    }
    if( sensores.terreno[0] == 'K'){
        bikini = true;
    }

    if( sensores.terreno[0] == 'X' and sensores.bateria <=2500){
        accion = actIDLE;
        if(recargando == 200){
            if(sensores.terreno[2] != 'M' or sensores.terreno[2] != 'P'){
                accion = actFORWARD;
            }else{
                accion = actTURN_L;
            }

        }
        recargando++;
        GuardaUltimaAccion(accion,sensores,bien_situado,fil,col);
        return accion;
    }
    //------------------------------Activacion de objetos------------------------------
    
    if(sensores.terreno[0] == 'D'){
        zapatillas=true;
    }
    if( sensores.terreno[0] == 'K'){
        bikini = true;
    }


    if(!cola_pendientes.empty()){
        valor_pendientes=cola_pendientes.front();
        cola_pendientes.pop();
        if(valor_pendientes==1){
            if(sensores.terreno[2] != 'P'){
                accion = actFORWARD;
                GuardaUltimaAccion(accion,sensores,bien_situado,fil,col);
                return accion;
            }
            
        }else if( valor_pendientes == 2){
            accion = actTURN_L;
            GuardaUltimaAccion(accion,sensores,bien_situado,fil,col);
            return accion;
        }else if (valor_pendientes == 3){
            accion = actTURN_R;
            GuardaUltimaAccion(accion,sensores,bien_situado,fil,col);
            return accion;
        }
    }
    
    

    if( (sensores.terreno[2] == 'T' or sensores.terreno[2] == 'S' or sensores.terreno[2] == 'G' or 
        sensores.terreno[2] == 'K' or sensores.terreno[2] == 'D' or sensores.terreno[2] == 'X')){
            accion = actFORWARD;
            recargando = 0;
    }
    if (sensores.terreno[2] == 'A' and !bikini){
        contador_giros = rand()%2 + 2;
        if(contador_giros == 2){
            accion = actTURN_L;
            // if(matriz_tiempo[fil][col] > 5 and sensores.terreno[7] != 'P'){
            //     accion = actFORWARD;
            //     contador_giros = rand()%2 + 2;
            //     if(contador_giros == 2){
            //         cola_pendientes.push(2);
            //     }else{
            //         cola_pendientes.push(3);
            //     }
            // }
        }else{
            accion = actTURN_R;
        }
        recargando = 0;
        
    }
    if(sensores.terreno[2] == 'B' and !zapatillas){
        contador_giros = rand()%2 + 2;
        if(contador_giros == 2){
            accion = actTURN_L;
            // if(matriz_tiempo[fil][col] > 5){
            //     accion = actFORWARD;
            //     contador_giros = rand()%2 + 2;
            //     if(contador_giros == 2){
            //         cola_pendientes.push(2);
            //     }else{
            //         cola_pendientes.push(3);
            //     }
            // }
        }else{
            accion = actTURN_R;
        }
        recargando = 0;
    }
    //--------------------------------Reaccion del personaje si pasa por casilla de Arbol o agua con sus objetos correspondientes--------------------------------
    if(bikini and sensores.terreno[2] == 'A'){
        accion = actFORWARD;
        recargando = 0;
        //contador_giros = rand()%2 + 2;
        // if(contador_giros == 2){
        //     cola_pendientes.push(2);
        // }else{
        //     cola_pendientes.push(3);
        // }
        GuardaUltimaAccion(accion,sensores,bien_situado,fil,col);
        return accion;
    }
    if(zapatillas and sensores.terreno[2] == 'B'){
        accion = actFORWARD;
        recargando = 0;
        // contador_giros = rand()%2 + 2;
        // if(contador_giros == 2){
        //     cola_pendientes.push(2);
        // }else{
        //     cola_pendientes.push(3);
        // }
        GuardaUltimaAccion(accion,sensores,bien_situado,fil,col);
        return accion;
    }
    //--------------------------------Reaccion ante la vision del jugador sin informacion--------------------------------
    
    //                          -----PUERTAS DE UN SOLO HUECO-----
    if((sensores.terreno[1] == 'M' and sensores.terreno[11] == 'M' ) 
            and (sensores.terreno[5] == 'T' or  sensores.terreno[5] == 'S')
            and sensores.terreno[2] != 'M'){
        accion = actFORWARD;
        cola_pendientes.push(1);
        cola_pendientes.push(2);
        recargando = 0;
        GuardaUltimaAccion(accion,sensores,bien_situado,fil,col);
        return accion;
    }
    if((sensores.terreno[3] == 'M' and sensores.terreno[13] == 'M')
            and (sensores.terreno[7] == 'T' or sensores.terreno[7] == 'S')
            and sensores.terreno[2] != 'M'){
        accion = actFORWARD;
        cola_pendientes.push(1); 
        cola_pendientes.push(3);
        recargando = 0;
        GuardaUltimaAccion(accion,sensores,bien_situado,fil,col);
        return accion;
    }

    //                         -----PUERTAS DE DOS HUECOS-----
    if(sensores.terreno[11] == 'M' and ((sensores.terreno[1] == 'T' and sensores.terreno[5] == 'T') or (sensores.terreno[1] == 'S' and sensores.terreno[5] == 'S'))){
        accion =actFORWARD;
        cola_pendientes.push(1);
        cola_pendientes.push(2);
        GuardaUltimaAccion(accion,sensores,bien_situado,fil,col);
        return accion;
    }
    if(sensores.terreno[13] == 'M' and ((sensores.terreno[7] == 'T' or sensores.terreno[3] == 'T') or (sensores.terreno[7] == 'S' or sensores.terreno[3] == 'S'))){
        accion = actFORWARD;
        cola_pendientes.push(1);
        cola_pendientes.push(3);
        GuardaUltimaAccion(accion,sensores,bien_situado,fil,col);
        return accion;
    }

    //--------------------------------Reaccion ante la vision del jugador sin informacion--------------------------------

    if (((sensores.terreno[1] == 'K' or sensores.terreno[1] == 'D' or sensores.terreno[1] == 'G')) or sensores.terreno[1] == 'X'){
        contador_giros = rand()%2 +2;
        if(contador_giros == 2){
            accion = actFORWARD;
            cola_pendientes.push(2);
            cola_pendientes.push(1);
        }
        
    }
    if( ((sensores.terreno[3] == 'K' or sensores.terreno[3] == 'D' or sensores.terreno[3] == 'G')) or sensores.terreno[3] == 'X'){
        contador_giros = rand()%2 +2;
        if(contador_giros == 2){
            accion = actFORWARD;
            cola_pendientes.push(3);
            cola_pendientes.push(1);
        }
        
    }
    if( ((sensores.terreno[4] == 'K' or sensores.terreno[4] == 'D' or sensores.terreno[6] == 'D'  or sensores.terreno[5] == 'K'  or sensores.terreno[4] == 'G'
            or sensores.terreno[5] == 'G')) or sensores.terreno[4] == 'X' or sensores.terreno[5] == 'X'){
        if(sensores.terreno[2] != 'M' and sensores.terreno[6] != 'M' and sensores.terreno[1] != 'M' and sensores.terreno[5] != 'M'){
            contador_giros = rand()%2 +2;
            if(contador_giros == 2){
                accion = actFORWARD;
                cola_pendientes.push(1);
                cola_pendientes.push(2);
                if(sensores.terreno[4] == 'K' or sensores.terreno[4] == 'D'){
                    cola_pendientes.push(1);
                }
            }
        }
    }
    if( ((sensores.terreno[8] == 'K' or sensores.terreno[8] == 'D' or sensores.terreno[7] == 'K' or sensores.terreno[7] == 'D'))
         or sensores.terreno[8] == 'X'  or sensores.terreno[8] == 'G' or sensores.terreno[7] == 'G' or sensores.terreno[7] == 'X'){
        if(sensores.terreno[2] != 'M' and sensores.terreno[6] != 'M' and sensores.terreno[3] != 'M' and sensores.terreno[7] != 'M'){
            
            contador_giros = rand()%2 +2;
            if(contador_giros == 2){
                accion = actFORWARD;
                cola_pendientes.push(1);
                cola_pendientes.push(3);
                if(sensores.terreno[8] == 'K' or sensores.terreno[8] == 'D' or sensores.terreno[8] == 'X'){
                    cola_pendientes.push(1);
                }
            }
        }
    }
    if( ( sensores.terreno[9] == 'K' or sensores.terreno[9] == 'D' or sensores.terreno[10] == 'K' or sensores.terreno[10] == 'D' )
            or sensores.terreno[9] == 'X'  or sensores.terreno[9] == 'G' or sensores.terreno[10] == 'G'  or sensores.terreno[10] == 'X' ){
        if(sensores.terreno[2] != 'M' and sensores.terreno[6] != 'M' and sensores.terreno[5] != 'M' ){
            
            contador_giros = rand()%2 +2;
            if(contador_giros == 2){
                accion = actFORWARD;
                cola_pendientes.push(1);
                cola_pendientes.push(1);
                cola_pendientes.push(2);
                cola_pendientes.push(1);
                if(sensores.terreno[9] == 'K' or sensores.terreno[9] == 'D'){
                    cola_pendientes.push(1);
                }
            }

        }
        //else if(sensores.terreno[2] != 'M' and sensores.terreno[6] != 'M' and sensores.terreno[11] != 'M' and sensores.terreno[12] != 'M'){
        //     accion =actFORWARD;
        //     cola_pendientes.push(1);
        //     cola_pendientes.push(1);
        //     cola_pendientes.push(2);
        //     cola_pendientes.push(1);
        //     cola_pendientes.push(1);
        //     if(sensores.terreno[9] == 'K' or sensores.terreno[9] == 'D'){
        //         cola_pendientes.push(1);
        //     }
        // }
    }
    if( ((sensores.terreno[15] == 'G' or sensores.terreno[15] == 'K' or sensores.terreno[15] == 'D' or sensores.terreno[13] == 'K' or sensores.terreno[13] == 'D'))
            or sensores.terreno[15] == 'X'  or sensores.terreno[15] == 'G'
            or sensores.terreno[13] == 'G'){
        if(sensores.terreno[2] != 'M' and sensores.terreno[6] != 'M' and sensores.terreno[7] != 'M'){
            
            contador_giros = rand()%2 +2;
            if(contador_giros == 2){
                accion = actFORWARD;
                cola_pendientes.push(1);
                cola_pendientes.push(1);
                cola_pendientes.push(3);
                cola_pendientes.push(1);
                if(sensores.terreno[15] == 'K' or sensores.terreno[15] == 'D'){
                    cola_pendientes.push(1);
                }
            }
        }
        //else if(sensores.terreno[2] != 'M' and sensores.terreno[6] != 'M' and sensores.terreno[11] != 'M' and sensores.terreno[12] != 'M'){
        //     accion =actFORWARD;
        //     cola_pendientes.push(1);
        //     cola_pendientes.push(1);
        //     cola_pendientes.push(3);
        //     cola_pendientes.push(1);
        //     cola_pendientes.push(1);
        //     if(sensores.terreno[15] == 'K' or sensores.terreno[15] == 'D'){
        //         cola_pendientes.push(1);
        //     }
        // }
    }

    // ----------------------------Colision con precipicio--------------------------------
    // if(sensores.terreno[2] == 'P' and brujula == 0){
    //     accion = actTURN_R;
    //     cola_pendientes.push(1); //Recto
    //     cola_pendientes.push(3); //Der
    // }else if(sensores.terreno[2] == 'P' and brujula == 2){
    //     accion = actTURN_L;
    //     cola_pendientes.push(1);
    //     cola_pendientes.push(2);

    // }else if(sensores.terreno[2] == 'P' and brujula == 3){
    //     contador_giros = rand()%2 +2;
    //     if(contador_giros == 2){
    //         accion = actTURN_L;
    //     }else{
    //         accion = actTURN_R;
    //     }
    // }else if(sensores.terreno[2] == 'P' and brujula == 1){
    //     contador_giros = rand()%2 +2;
    //     if(contador_giros == 2){
    //         accion = actTURN_L;
    //     }else{
    //         accion = actTURN_R;
    //     }
    // }
    if(sensores.terreno[2] == 'P'){
        contador_giros = rand()%2 +2;
        if(contador_giros == 2){
            accion = actTURN_R;
            // cola_pendientes.push(1);
            // cola_pendientes.push(3);
        }else{
            accion = actTURN_L;
            // cola_pendientes.push(1);
            // cola_pendientes.push(2);
        }
    }
    
    //-----------------------------Colision con muros (Casas)-----------------------------
    if(sensores.terreno[2] == 'M'){
        if(brujula == 0){
            contador_giros = rand()%2 + 2;
            if(contador_giros == 2){
                accion = actTURN_L;
            }else{
                accion = actTURN_R;
            }
            // if(matriz_tiempo[fil][col-1] <= matriz_tiempo[fil][col+1]){
            //     accion = actTURN_R;
            //     // cola_pendientes.push(1);
            //     // cola_pendientes.push(2);
            // }else{
            //     accion = actTURN_L;
            //     // cola_pendientes.push(1);
            //     // cola_pendientes.push(3);
            // }
        }else if(brujula == 1){
            contador_giros = rand()%2 + 2;
            if(contador_giros == 2){
                accion = actTURN_L;
            }else{
                accion = actTURN_R;
            }
            // if(matriz_tiempo[fil-1][col] <= matriz_tiempo[fil+1][col]){
            //     accion = actTURN_L;
            //     // cola_pendientes.push(1);
            //     // cola_pendientes.push(3);
            // }else{
            //     accion = actTURN_R;
            //     // cola_pendientes.push(1);
            //     // cola_pendientes.push(2);
            // }
        }else if(brujula == 3){
            contador_giros = rand()%2 + 2;
            if(contador_giros == 2){
                accion = actTURN_L;
            }else{
                accion = actTURN_R;
            }
            // if(matriz_tiempo[fil-1][col] <= matriz_tiempo[fil+1][col]){
            //     accion = actTURN_R;
            //     // cola_pendientes.push(1);
            //     // cola_pendientes.push(2);
            // }else{
            //     accion = actTURN_L;
            //     // cola_pendientes.push(1);
            //     // cola_pendientes.push(3);
            // }
        }else if(brujula == 2){
            contador_giros = rand()%2 + 2;
            if(contador_giros == 2){
                accion = actTURN_L;
            }else{
                accion = actTURN_R;
            }
            // if(matriz_tiempo[fil][col-1] <= matriz_tiempo[fil][col+1]){
            //     accion = actTURN_L;
            //     // cola_pendientes.push(1);
            //     // cola_pendientes.push(3);
            // }else{
            //     accion = actTURN_R;
            //     // cola_pendientes.push(1);
            //     // cola_pendientes.push(2);
            // }
        }
        
        GuardaUltimaAccion(accion,sensores,bien_situado,fil,col);
        return accion;
    }

    //-----------------------------Actualizador del mapa y control del estado del personaje-----------------------------
    
    GuardaUltimaAccion(accion,sensores,bien_situado,fil,col);
	return accion;
    
}

