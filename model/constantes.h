#ifndef CONSTANTES_H_
#define CONSTANTES_H_

#include "util/Util.h"
#include <map>

////ventana
const int ANCHOVENTANAPX                    =  700;
const int ALTOVENTANAPX                     =  500;
const float ANCHOVENTANAL                   =  400;

//escenario
const float ANCHOESCENARIO                  = 1000;
const float ALTOESCENARIO                   =  400;
const float ALTURAPISOESCENARIO             =   20;
const float LIFEBAR_RELATIVE_WIDTH          = 0.4; // Relative to logical window size
const float VIBRATION_SPEED                 = 0.8;
const int   VIBRATION_DURATION              = 33;
//
//// capa
//
//const float VELOCIDAD_DESPLAZAMIENTO_CAPAS = 4;

//personaje
const float ANCHOPERSONAJE                  =   68;
const float ALTOPERSONAJE                   =   125;
const int ZINDEXPERSONAJE                   =   3;
const char* const DEFAULT_WALK              = "data/scorpionWalk.png";
const char* const DEFAULT_STANCE            = "data/scorpionStance.png";
const char* const DEFAULT_JUMP              = "data/scorpionJump.png";
const char* const DEFAULT_SIDEJUMP          = "data/scorpionSideJump.png";
const char* const DEFAULT_DUCK          	= "data/scorpionDuck.png";
const char* const DEFAULT_HIGH_KICK         = "data/scorpionHighKick.png";
const char* const DEFAULT_LOW_KICK         	= "data/scorpionLowKick.png";
const char* const DEFAULT_DUCKING_KICK		= "data/scorpionDuckingKick.png";
const char* const DEFAULT_JUMPING_KICK		= "data/scorpionJumpingKick.png";
const char* const DEFAULT_JUMPING_PUNCH		= "data/scorpionJumpingPunch.png";
const char* const DEFAULT_DUCK_PUNCH		= "data/scorpionDuckPunch.png";
const char* const DEFAULT_HIGH_PUNCH		= "data/scorpionHighPunch.png";
const char* const DEFAULT_LOW_PUNCH			= "data/scorpionLowPunch.png";
const char* const DEFAULT_WINNER			= "data/scorpionWinner.png";
const char* const DEFAULT_BODYPARTS			= "data/scorpionBodyParts.png";
const char* const DEFAULT_FINISHER			= "data/scorpionFinisher.png";
const char* const DEFAULT_SHOOT				= "data/scorpionShooting.png";
const char* const DEFAULT_DIZZY				= "data/scorpionDizzy.png";
const char* const DEFAULT_FALL				= "data/scorpionFalling.png";
const char* const DEFAULT_BEINGHIT			= "data/scorpionBeingHit.png";
const char* const DEFAULT_BEINGHIT_DOWN		= "data/scorpionBeingHitDown.png";
const char* const DEFAULT_BLOCK				= "data/scorpionBlocking.png";
const char* const DEFAULT_BLOCKDOWN			= "data/scorpionBlockingDown.png";
const char* const DEFAULT_HEAD				= "data/scorpionHead.png";

const char* const MOVE_NAME_WALK          	= "walk";
const char* const MOVE_NAME_STANCE         	= "stance";
const char* const MOVE_NAME_JUMP         	= "jump";
const char* const MOVE_NAME_SIDEJUMP       	= "sideJump";
const char* const MOVE_NAME_DUCK         	= "duck";
const char* const MOVE_NAME_HIGH_KICK       = "highKick";
const char* const MOVE_NAME_LOW_KICK		= "lowKick";
const char* const MOVE_NAME_DUCKING_KICK	= "duckingKick";
const char* const MOVE_NAME_JUMPING_KICK	= "kickJump";
const char* const MOVE_NAME_PUNCHJUMP		= "punchJump";
const char* const MOVE_NAME_DUCK_PUNCH		= "duckPunch";
const char* const MOVE_NAME_HIGH_PUNCH		= "highPunch";
const char* const MOVE_NAME_LOW_PUNCH		= "lowPunch";
const char* const MOVE_NAME_WINNER			= "winner";
const char* const MOVE_NAME_BODYPARTS		= "bodyParts";
const char* const MOVE_NAME_FINISHER		= "finisher";
const char* const MOVE_NAME_SHOOT			= "shoot";
const char* const MOVE_NAME_DIZZY			= "dizzy";
const char* const MOVE_NAME_FALL			= "fall";
const char* const MOVE_NAME_BEINGHIT		= "beingHit";
const char* const MOVE_NAME_BEINGHIT_DOWN	= "beingHitDown";
const char* const MOVE_NAME_BLOCK			= "block";
const char* const MOVE_NAME_BLOCKDOWN		= "blockDown";
const char* const MOVE_NAME_HEAD			= "head";

const char* const NAME_CHARACTER_1          = "scorpion";
const char* const NAME_CHARACTER_2          = "raiden";
const int         FULL_LIFE                 = 100;

typedef std::map<std::string, int> Map;
const Map DAMAGE = {{"HighKickHitting", 10}, {"LowKickHitting", 10},{"HighPunchHitting", 5}, {"DuckingKickHitting", 15} ,{"DuckingPunch", 20},{"SHOOT", 10}, {"PunchLeftJumping", 15}, {"KickRightJumpingHitting", 15}, {"KickLeftJumpingHitting", 15}, {"PunchRightJumping", 15},{"LowPunchHitting", 5}, {"WeaponHitting", 20}};
//
//const int OPONENTLEFT                       =    1;
//const int OPONENTRIGHT                      =    2;
//
//
//Constantes de fluidez del juego
//Fija el delay que tiene el personaje para mover por la pantalla. (A mayor, mas lento se mueve)
//const int MOVEMENTDELAY                     =   15;
//Fija el delay que tiene el personaje para cambiar de direccion. (A mayor, mas tarda en cambiar de direccion. Osea, a mayor, patina mas)
const int COMMANDDELAY                      =  300;
const int COMMANDDELAYKIT                   =  600;
const int GAMEDELAY                         =   10;
////Velocidad inicial del salto del personaje.
//const float SPEED                             =  0.04285*ANCHOVENTANAL;
////Aceleracion aplicada al salto del personaje.
//const float ACCELERATION                      =  1.2285*ANCHOVENTANAL;

//const float INITIAL_POSITION_X = 0.2857*ANCHOVENTANAL;
//const float INITIAL_POSITION_Y = 0.2857*ANCHOVENTANAL;

//Alternative color
const double DEFAULT_INITIAL_H              = 40;
const double DEFAULT_FINAL_H                = 45;
const double DEFAULT_OFFSET                 = 30;

//joystick
const unsigned char DEFAULT_KEY[20] = "adwscezqxokljmnbypb";

//

enum Events { MoveRight, MoveLeft, Jump, Duck, WeaponHit, HighPunch, LowPunch, HighKick, LowKick, Block, ReceiveHit, ReceiveDuckingPunch, ReceiveDuckingKick, ReceiveWeapon, MoveRightRelease, MoveLeftRelease, DuckRelease, BlockRelease, DuckingKick, JumpingKickRight, JumpingKickLeft, JumpFinished};

#endif /* CONSTANTES_H_ */
