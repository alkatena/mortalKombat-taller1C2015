/*
 * InputController.h
 *
 *  Created on: 16/05/2015
 *      Author: her
 */

#ifndef INPUTCONTROLLER_H_
#define INPUTCONTROLLER_H_

#include "SDL2/SDL.h"
#include "KeyboardController.h"
#include "JoysticksControllerManager.h"
#include "../model/constantes.h"
#include "SDL2/SDL_image.h"
#include <string>
#include <iostream>
#include <bits/stl_list.h>
#include "../model/MKCharacter.h"
#include "../model/stage/Layer.h"
#include "MKStageController.h"
#include "AIController.h"
#include "MouseController.h"
#include "../model/ModeSelection.h"
#include "../model/CharacterSelection.h"

//class KeyboardController;
class ModeSelection;
class CharacterSelection;

class InputController {
public:
	InputController(MKStageController* stageController);
	virtual ~InputController();
	void update();
	void checkEvent();
	SDL_Event* getEvent();

	static void setVibrating(bool vibratingFlag);
	static bool isVibrating();
	void setStageController(MKStageController* stageController);
	void setCharacters(MKCharacter* character, MKCharacter* character2);
	void setModeSelection(ModeSelection* modeSelection);
	void setCharacterSelection(CharacterSelection* characterSelection);
	void enableAI();
	void disableAI();
	bool isAIEnabled();
	void disablePracticeAI();
	void enablePracticeAI();

private:
	JoysticksControllerManager* joystickControllerManager;
	KeyboardController* keyboardController;
    SDL_Event* mainEvent;
    bool joystickConnected;
    static bool vibrating;
	void setCharacterSide();
	MKStageController* stageController;
	MKCharacter* character;
	MKCharacter* character2;
	AIController* aiController;
	MouseController* mouseController;
	bool iaIsActive;

};

#endif
