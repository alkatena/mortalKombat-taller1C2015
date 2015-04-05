#ifndef CONSTANTES_H_
#define CONSTANTES_H_

//ventana
const int ANCHOVENTANAPX                    =  800;
const int ALTOVENTANAPX                     =  600;
const float ANCHOVENTANAL                   =  800;

//escenario
const float ANCHOESCENARIO                  = 1280;
const float ALTOESCENARIO                   =  800;
const float ALTURAPISOESCENARIO             =   20;

//capa
const float ANCHOCAPA                       =  500;

//personaje
const float ANCHOPERSONAJE                  =   20;
const float ALTOPERSONAJE                   =   35;
const float ZINDEXPERSONAJE                 =    1;
const float SPRITESPERSONAJE                =    8;

const int OPONENTLEFT                       =    1;
const int OPONENTRIGHT                      =    2;


//Constantes de fluidez del juego
//Fija el delay que tiene el personaje para mover por la pantalla. (A mayor, mas lento se mueve)
const int MOVEMENTDELAY                     =   15;
//Fija el delay que tiene el personaje para cambiar de direccion. (A mayor, mas tarda en cambiar de direccion. Osea, a mayor, patina mas)
const int COMMANDDELAY                      =  500;
//Velocidad inicial del salto del personaje.
const int SPEED                             =   30;
//Aceleracion aplicada al salto del personaje.
const int ACCELERATION                      =  860;


#endif /* CONSTANTES_H_ */
