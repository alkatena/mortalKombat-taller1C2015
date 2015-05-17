#include "KeyboardController.h"
#include "InputController.h"
#include "../model/logger.h"
#include "EventController.h"

KeyboardController::KeyboardController()
{
    previousKey = 0;

    timer = SDL_GetTicks();

    hitTimerRaidenShootCheck = SDL_GetTicks();
    raidenShootTimeOutCompleted = true;

    hitTimerScorpionShootCheck = SDL_GetTicks();
    scorpionShootTimeOutCompleted = true;
}


KeyboardController::~KeyboardController(void)
{

}

//SDL_Event* GameControllKeyboardgetEvent() {
//    return mainEvent;
//}
//
//void KeyboardController::checkEvent() {
//    SDL_PollEvent(mainEvent);
//}

void KeyboardController::testElapsedTime(MKCharacter* character, MKCharacter* character2) {
	if (timer + COMMANDDELAY < SDL_GetTicks()) {
		character->setMovement("NONE");
		timer = SDL_GetTicks();
	}
	if (hitTimer + COMMANDDELAYKIT < SDL_GetTicks()) {
		character->setHit("NONE");
		character->setIsHiting(false);
		hitTimer = SDL_GetTicks();
	}
	if (timerChar2 + COMMANDDELAY < SDL_GetTicks()) {
		character2->setMovement("NONE");
		timerChar2 = SDL_GetTicks();
	}

	//raiden necesita mas tiempo para disparar q para todos los demas Hits
	if (character2->getHit() == "SHOOT"){
		if (hitTimerChar2 + COMMANDDELAYKIT + 500 < SDL_GetTicks()) {
			character2->setHit("NONE");
			character2->setIsHiting(false);
			hitTimerChar2 = SDL_GetTicks();
		}
	}else
	{
		if (hitTimerChar2 + COMMANDDELAYKIT < SDL_GetTicks()) {
			character2->setHit("NONE");
			character2->setIsHiting(false);
			hitTimerChar2 = SDL_GetTicks();
		}
	}
}



void KeyboardController::update(MKCharacter* character, MKCharacter* character2, SDL_Event* mainEvent) {
    extern logger* Mylog;

    switch (mainEvent->type){
    	case SDL_KEYDOWN:
			switch(mainEvent->key.keysym.sym) {
			case SDLK_RIGHT:
//							Mylog->Log("movimiento del personaje: hacia la derecha", ERROR_LEVEL_INFO);
//							character->setMovement("RIGHT");
//							previousKey = mainEvent->key.keysym.sym;
//							setCharacterSide(character, character2);
//							timer = SDL_GetTicks();

						EventController::moveRight(character, character2);
						break;
			case SDLK_LEFT:
//							Mylog->Log("movimiento del personaje: hacia la izquierda", ERROR_LEVEL_INFO);
//							character->setMovement("LEFT");
//							previousKey = mainEvent->key.keysym.sym;
//							setCharacterSide(character, character2);
//							timer = SDL_GetTicks();
						EventController::moveLeft(character, character2);
						break;
			case SDLK_UP:
//							if (previousKey == SDLK_UP){
//								Mylog->Log("movimiento del personaje: hacia arriba", ERROR_LEVEL_INFO);
//								character->setJump(true);
//								setCharacterSide(character, character2);
//							}
//							previousKey = mainEvent->key.keysym.sym;
						EventController::moveUp(character, character2);
						break;
			case SDLK_DOWN:
//							Mylog->Log("movimiento del personaje: agachandose", ERROR_LEVEL_INFO);
//							character->setMovement("DUCK");
//							previousKey = mainEvent->key.keysym.sym;
//							timer = SDL_GetTicks();
						EventController::moveDown(character, character2);

//				case SDLK_l:
//							//character2->setLife(character2->getLife()-10);
//							//character->setLife(character->getLife()-10);
//							//InputController::setVibrating(true);
//							previousKey = mainEvent->key.keysym.sym;
//							previousKeyChar2 = mainEvent->key.keysym.sym;
//							break;
			case SDLK_k:
//							if (previousKey == SDLK_DOWN){
//								Mylog->Log("movimiento del personaje: Patada baja", ERROR_LEVEL_INFO);
//								character->setHit("KICKDOWN");
//								previousKey = SDLK_DOWN;
//								character->setIsHiting(true);
//								hitTimer = SDL_GetTicks();
//							}
//							else{
//								Mylog->Log("movimiento del personaje: Pateando", ERROR_LEVEL_INFO);
//								character->setHit("KICK");
//								previousKey = mainEvent->key.keysym.sym;
//								character->setIsHiting(true);
//								hitTimer = SDL_GetTicks();
//							}
							EventController::highKick(character, character2);

						break;
			case SDLK_l:
							EventController::lowKick(character, character2);
						break;
			case SDLK_p:
//							if (previousKey == SDLK_LEFT){
//								character->setHit("PUNCHJUMPLEFT");
//								character->setJump(true);
//								Mylog->Log("movimiento del personaje: Golpe de puño con salto hacia la izquierda.", ERROR_LEVEL_INFO);
//								character->setIsHiting(true);
//								hitTimer = SDL_GetTicks();
//							}
//							else if (previousKey == SDLK_RIGHT){
//								character->setHit("PUNCHJUMPRIGHT");
//								character->setJump(true);
//								Mylog->Log("movimiento del personaje: Golpe de puño con salto hacia la derecha.", ERROR_LEVEL_INFO);
//								character->setIsHiting(true);
//								hitTimer = SDL_GetTicks();
//							}
//							else if (previousKey == SDLK_DOWN){
//								character->setHit("PUNCHUP");
//								Mylog->Log("movimiento del personaje: Golpe de puño ascendente.", ERROR_LEVEL_INFO);
//								character->setIsHiting(true);
//								hitTimer = SDL_GetTicks();
//							}
//							else{
//								Mylog->Log("movimiento del personaje: Golpe de puño.", ERROR_LEVEL_INFO);
//								character->setHit("PUNCH");
//								previousKey = mainEvent->key.keysym.sym;
//								character->setIsHiting(true);
//								hitTimer = SDL_GetTicks();
//							}

							EventController::highPunch(character, character2);
						break;
			case SDLK_i:
							EventController::lowPunch(character, character2);
						break;
			case SDLK_b:
//							if (previousKey == SDLK_DOWN) {
//								Mylog->Log("movimiento del personaje: Defensa.", ERROR_LEVEL_INFO);
//								character->setHit("DEFENSEDOWN");
//								previousKey = mainEvent->key.keysym.sym;
//								hitTimer = SDL_GetTicks();
//								break;
//							}
//							Mylog->Log("movimiento del personaje: Defensa.", ERROR_LEVEL_INFO);
//							character->setHit("DEFENSE");
//							previousKey = mainEvent->key.keysym.sym;
//							hitTimer = SDL_GetTicks();

							EventController::block(character, character2);
						break;
			case SDLK_u:
//							if ((SDL_GetTicks() < 150 + hitTimerScorpionShootCheck) || scorpionShootTimeOutCompleted){
//									Mylog->Log("movimiento del personaje: Disparando.", ERROR_LEVEL_INFO);
//									character->setHit("SHOOT");
//									previousKey = mainEvent->key.keysym.sym;
//									character->setIsHiting(true);
//									hitTimer = SDL_GetTicks();
//									scorpionShootTimeOutCompleted = false;
//									if (hitTimerScorpionShootCheck == 0)
//										hitTimerScorpionShootCheck = SDL_GetTicks();
//							}else
//							{
//								hitTimerScorpionShootCheck = 0;
//							}
							EventController::shoot(character, character2);
						break;
//				case SDLK_q:
//							Mylog->Log("movimiento del personaje: Mareado.", ERROR_LEVEL_INFO);
//							character->setHit("DIZZY");
//							previousKey = mainEvent->key.keysym.sym;
//							hitTimer = SDL_GetTicks();
//							break;
//				case SDLK_h:
//							Mylog->Log("movimiento del personaje: Recibiendo golpe.", ERROR_LEVEL_INFO);
//							character->setHit("BEINGHIT");
//							previousKey = mainEvent->key.keysym.sym;
//							hitTimer = SDL_GetTicks();
//							break;
//				case SDLK_e:
//							Mylog->Log("movimiento del personaje: Siendo arrojado.", ERROR_LEVEL_INFO);
//							character->setHit("FALLING");
//							if(character->getX() > character2->getX()){
//								character->moveRight();
//							}else{
//								character->moveLeft();
//							}
//							previousKey = mainEvent->key.keysym.sym;
//							hitTimer = SDL_GetTicks();
//							break;
//				case SDLK_y:
//							Mylog->Log("movimiento del personaje: Siendo arrojado.", ERROR_LEVEL_INFO);
//							character->setHit("WINNER");
//							previousKey = mainEvent->key.keysym.sym;
//							hitTimer = SDL_GetTicks();
//							break;

			/****************************************************************************************************/

			case SDLK_d:
//							Mylog->Log("movimiento del personaje: hacia la derecha", ERROR_LEVEL_INFO);
//							character2->setMovement("RIGHT");
//							previousKeyChar2 = mainEvent->key.keysym.sym;
//							setCharacterSide(character, character2);
//							timerChar2 = SDL_GetTicks();
						EventController::moveRight(character2, character);
						break;

			case SDLK_a:
//							Mylog->Log("movimiento del personaje: hacia la izquierda", ERROR_LEVEL_INFO);
//							character2->setMovement("LEFT");
//							previousKeyChar2 = mainEvent->key.keysym.sym;
//							setCharacterSide(character, character2);
//							timerChar2 = SDL_GetTicks();
						EventController::moveLeft(character2, character);
						break;
			case SDLK_w:
//							if (previousKeyChar2 == SDLK_w)	{
//								Mylog->Log("movimiento del personaje: hacia arriba", ERROR_LEVEL_INFO);
//								character2->setJump(true);
//								setCharacterSide(character, character2);
//							}
//							previousKeyChar2 = mainEvent->key.keysym.sym;
						EventController::moveUp(character2, character);
						break;
			case SDLK_z:
//							Mylog->Log("movimiento del personaje: agachandose", ERROR_LEVEL_INFO);
//							character2->setMovement("DUCK");
//							previousKeyChar2 = mainEvent->key.keysym.sym;;
//							timerChar2 = SDL_GetTicks();
						EventController::moveDown(character2, character);
						break;

			case SDLK_f:
//							if (previousKeyChar2 == SDLK_s){
//								Mylog->Log("movimiento del personaje: Patada baja", ERROR_LEVEL_INFO);
//								character2->setHit("KICKDOWN");
//								previousKeyChar2 = SDLK_s;
//								character2->setIsHiting(true);
//								hitTimerChar2 = SDL_GetTicks();
//							}
//							else{
//								Mylog->Log("movimiento del personaje: Pateando", ERROR_LEVEL_INFO);
//								character2->setHit("KICK");
//								previousKeyChar2 = mainEvent->key.keysym.sym;
//								character2->setIsHiting(true);
//								hitTimerChar2 = SDL_GetTicks();
//							}
						EventController::highKick(character2, character);
						break;
			case SDLK_g:
						EventController::lowKick(character2, character);
						break;
			case SDLK_c:
//							if (previousKeyChar2 == SDLK_a){
//								character2->setHit("PUNCHJUMPLEFT");
//								character2->setJump(true);
//								Mylog->Log("movimiento del personaje: Golpe de puño con salto hacia la izquierda.", ERROR_LEVEL_INFO);
//								character2->setIsHiting(true);
//								hitTimerChar2 = SDL_GetTicks();
//							}
//							else if (previousKeyChar2 == SDLK_g){
//								character2->setHit("PUNCHJUMPRIGHT");
//								character2->setJump(true);
//								Mylog->Log("movimiento del personaje: Golpe de puño con salto hacia la derecha.", ERROR_LEVEL_INFO);
//								character2->setIsHiting(true);
//								hitTimerChar2 = SDL_GetTicks();
//							}
//							else if (previousKeyChar2 == SDLK_s){
//								character2->setHit("PUNCHUP");
//								Mylog->Log("movimiento del personaje: Golpe de puño ascendente.", ERROR_LEVEL_INFO);
//								character2->setIsHiting(true);
//								hitTimerChar2 = SDL_GetTicks();
//							}
//							else{
//								Mylog->Log("movimiento del personaje: Golpe de puño.", ERROR_LEVEL_INFO);
//								character2->setHit("PUNCH");
//								previousKeyChar2 = mainEvent->key.keysym.sym;
//								character2->setIsHiting(true);
//								hitTimerChar2 = SDL_GetTicks();
//							}
						EventController::highPunch(character2, character);
						break;
			case SDLK_v:
						EventController::lowPunch(character2, character);
						break;
			case SDLK_x:
						EventController::block(character2, character);
						break;

			case SDLK_e:
//							if ((SDL_GetTicks() < 150 + hitTimerRaidenShootCheck) || raidenShootTimeOutCompleted){
//								Mylog->Log("movimiento del personaje: Disparando.", ERROR_LEVEL_INFO);
//								character2->setHit("SHOOT");
//								previousKeyChar2 = mainEvent->key.keysym.sym;
//								character2->setIsHiting(true);
//								hitTimerChar2 = SDL_GetTicks();

//						raidenShootTimeOutCompleted = false;
//								if (hitTimerRaidenShootCheck == 0)
//									hitTimerRaidenShootCheck = SDL_GetTicks();
//							}else
//							{
//								hitTimerRaidenShootCheck = 0;
//							}
						EventController::shoot(character2, character);
						break;
//				case SDLK_n:
//							if (previousKeyChar2 == SDLK_s) {
//								Mylog->Log("movimiento del personaje: Defensa.", ERROR_LEVEL_INFO);
//								character2->setHit("DEFENSEDOWN");
//								previousKeyChar2 = mainEvent->key.keysym.sym;
//								hitTimerChar2 = SDL_GetTicks();
//								break;
//							}
//					        Mylog->Log("movimiento del personaje: Defensa.", ERROR_LEVEL_INFO);
//					        character2->setHit("DEFENSE");
//					        previousKeyChar2 = mainEvent->key.keysym.sym;
//					        hitTimerChar2 = SDL_GetTicks();
//					        break;
//				case SDLK_i:
//							Mylog->Log("movimiento del personaje: Mareado.", ERROR_LEVEL_INFO);
//							character2->setHit("DIZZY");
//							previousKeyChar2 = mainEvent->key.keysym.sym;
//							hitTimerChar2 = SDL_GetTicks();
//							break;
//				case SDLK_b:
//							Mylog->Log("movimiento del personaje: Recibiendo golpe.", ERROR_LEVEL_INFO);
//							character2->setHit("BEINGHIT");
//							previousKeyChar2 = mainEvent->key.keysym.sym;
//							hitTimerChar2 = SDL_GetTicks();
//							break;
//				case SDLK_m:
//							Mylog->Log("movimiento del personaje: Siendo arrojado.", ERROR_LEVEL_INFO);
//							character2->setHit("FALLING");
//							if(character->getX() < character2->getX()){
//								character2->moveRight();
//							}else{
//								character2->moveLeft();
//							}
//							previousKeyChar2 = mainEvent->key.keysym.sym;
//							hitTimerChar2 = SDL_GetTicks();
//							break;
//				case SDLK_z:
//							Mylog->Log("movimiento del personaje: Siendo arrojado.", ERROR_LEVEL_INFO);
//							character2->setHit("WINNER");
//							previousKeyChar2 = mainEvent->key.keysym.sym;
//							hitTimerChar2 = SDL_GetTicks();
//							break;
			default:
				previousKey = mainEvent->key.keysym.sym;
				break;
			}
		break;

//		case SDL_KEYUP:
//			switch(mainEvent->key.keysym.sym){
//				case SDLK_DOWN:
//					previousKey = SDLK_0;
//					break;
//				case SDLK_UP:
//					previousKey = SDLK_0;
//					break;
//				case SDLK_RIGHT:
//					previousKey = SDLK_0;
//					break;
//				case SDLK_LEFT:
//					previousKey = SDLK_0;
//					break;
//
//				case SDLK_s:
//					previousKeyChar2 = SDLK_0;
//					break;
//				case SDLK_w:
//					previousKeyChar2 = SDLK_0;
//					break;
//				case SDLK_g:
//					previousKeyChar2 = SDLK_0;
//					break;
//				case SDLK_a:
//					previousKeyChar2 = SDLK_0;
//					break;
//				case SDLK_t:
//					//Uso este evento para q no vuelva a disparar hasta q no suelte la tecla
//					raidenShootTimeOutCompleted = true;
//					break;
//				case SDLK_o:
//					//Uso este evento para q no vuelva a disparar hasta q no suelte la tecla
//					scorpionShootTimeOutCompleted = true;
//					break;
//
//				default:
//					break;
//			}
//			testElapsedTime(character, character2);
//			break;
    	default:
    		testElapsedTime(character, character2);
    		break;
    }
}





