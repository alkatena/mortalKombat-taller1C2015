/*
 * InputController.cpp
 *
 *  Created on: 16/05/2015
 *      Author: her
 */

#include "InputController.h"
bool InputController::vibrating = false;

InputController::InputController() {
	this->mainEvent = new SDL_Event();
	this->keyboardController = new KeyboardController();

	SDL_Init(SDL_INIT_JOYSTICK);
	joystickConnected = false;
	if (SDL_NumJoysticks() > 0)	{
		this->joystickControllerManager = new JoysticksControllerManager();
		joystickConnected = true;
	}

}

InputController::~InputController() {
    if (joystickConnected)
    	delete joystickControllerManager;
    delete mainEvent;
    delete this->keyboardController;
}

SDL_Event* InputController::getEvent() {
    return mainEvent;
}

void InputController::checkEvent() {
    SDL_PollEvent(mainEvent);
}

void InputController::setVibrating(bool vibratingFlag) {
	vibrating = vibratingFlag;
}

bool InputController::isVibrating() {
	return vibrating;
}

void InputController::setCharacterSide(MKCharacter* character, MKCharacter* character2)
{
    if(character->getX() <= character2->getX()){
    	character->setCharacterSide('l');
    	character2->setCharacterSide('r');
    }else{
    	character->setCharacterSide('r');
    	character2->setCharacterSide('l');
    }
}

void InputController::update(MKCharacter* character, MKCharacter* character2) {

	this->setCharacterSide(character, character2);

	this->keyboardController->update(character, character2, this->getEvent());

	if(joystickConnected)
	{
		this->joystickControllerManager->update(character, character2, this->getEvent());
	}
}

