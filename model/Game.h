#ifndef GAME_H_
#define GAME_H_

#include "MKCharacter.h"
#include "../view/GameView.h"
#include "../controller/GameController.h"
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "stage/Stage.h"
#include <math.h>

const int INITIAL_POSITION_X = 200;
const int INITIAL_POSITION_Y = 200;

class Game
{
public:
    Game(float pScreenWidth, float pScreenHeight, float charAncho, float charAlto, Stage* stage);
    ~Game();
    void GameLoop();

private:

    MKCharacter* scorpion;
    Stage* stage;
    float ScreenWidth;
    float ScreenHeight;
    GameView* gameView;
    GameController* gameController;

};

#endif /* GAME_H_ */
