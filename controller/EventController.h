/*
 * EventController.h
 *
 *  Created on: 16/05/2015
 *      Author: her
 */
#ifndef EVENTCONTROLLER_H_
#define EVENTCONTROLLER_H_

#include "SDL2/SDL.h"
#include "../model/constantes.h"
#include "SDL2/SDL_image.h"
#include <string>
#include <iostream>
#include <bits/stl_list.h>
#include "../model/MKCharacter.h"
#include "../model/stage/Layer.h"
#include "MKStageController.h"
#include "../model/character/ComboManager.h"

using namespace std;

struct Commands {
	bool upPressed;
	bool downPressed;
	bool leftPressed;
	bool rightPressed;
	bool highPunchPressed;
	bool lowPunchPressed;
	bool highKickPressed;
	bool lowKickPressed;
	bool blockPressed;
	bool weaponThrowPressed;
};

class EventController : public MKStageController {


public:
	EventController(std::vector<Events>* combo1, std::vector<Events>* combo2,std::vector<Events>* combo3,
					std::vector<Events>* combo4,std::vector<Events>* combo5,std::vector<Events>* combo6,
					std::vector<Events>* fatality);
	virtual ~EventController();
	void moveRight(int n);
	void moveLeft(int n);
	void moveUp(int n);
	void moveDown(int n);
	void highKick(int n);
	void lowKick(int n);
	void highPunch(int n);
	void lowPunch(int n);
	void shoot(int n);
	void block(int n);
	void duckPunch();

	virtual void moveLeftRelease(int n) ;
	virtual void moveRightRelease(int n);
	virtual void moveDownRelease(int n);
	virtual void moveUpRelease(int n);
	virtual void lowKickRelease(int n);
	virtual void highKickRelease(int n);
	virtual void lowPunchRelease(int n);
	virtual void highPunchRelease(int n);
	virtual void blockRelease(int n);
	virtual void weaponRelease(int n);

	ComboManager* getComboManager();
	void setCharacterToMove(MKCharacter* character);
private:
	static void Void();
	MKCharacter* characterToMove;

	Commands commands[3];

	ComboManager* comboManager;
};

#endif /* EVENTCONTROLLER_H_ */
