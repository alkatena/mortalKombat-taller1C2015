#ifndef GAMECONTROLLER_H_
#define GAMECONTROLLER_H_

#include "SDL2/SDL.h"
#include "../model/constantes.h"
#include "SDL2/SDL_image.h"
#include <string>
#include <iostream>
#include <bits/stl_list.h>
#include "../model/MKCharacter.h"
#include "../model/stage/Layer.h"
#include "JoystickController.h"

using namespace std;

class GameController
{
public:
    GameController();

    ~GameController(void);

    void update(MKCharacter* character, MKCharacter* character2);

    SDL_Event* getEvent();

    void checkEvent();


private:

    int timer;
    int timerChar2;
    int hitTimer;
    int hitTimerChar2;
    JoystickController* joystickController;
    SDL_Event* mainEvent;

    SDL_Keycode previousKey;
    SDL_Keycode previousKeyChar2;

	void testElapsedTime(MKCharacter* character, MKCharacter* character2);
};

#endif /* GAMECONTROLLER_H_ */
