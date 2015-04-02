#include "GameController.h"

GameController::GameController()
{
    mainEvent = new SDL_Event();

    timer = SDL_GetTicks();
}


GameController::~GameController(void)
{
    delete mainEvent;
}

SDL_Event* GameController::getEvent() {
    return mainEvent;
}

void GameController::checkEvent() {
    SDL_PollEvent(mainEvent);    
}

void GameController::update(MKCharacter* character) {
    if (mainEvent->type == SDL_KEYDOWN)
        {
            if (mainEvent->key.keysym.sym == SDLK_RIGHT)
            {
                character->setMovement("WALKINGRIGHT");
                timer = SDL_GetTicks();
                //right = true;
            }
            else if (mainEvent->key.keysym.sym == SDLK_LEFT)
            {
                character->setMovement("WALKINGLEFT");
                timer = SDL_GetTicks();
                //left = true;
            }
        }
        else if (timer + 500 < SDL_GetTicks()) {
            character->setMovement("NONE");
            timer = SDL_GetTicks();
        }

    character->Update();
}



