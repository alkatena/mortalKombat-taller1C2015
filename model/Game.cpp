#include "Game.h"

Game::Game(float pScreenWidth, float pScreenHeight, float charAncho, float charAlto, Stage* pStage)
{
    ScreenWidth = pScreenWidth;
    ScreenHeight = pScreenHeight;
    stage = pStage;
    scorpion = new MKCharacter(INITIAL_POSITION_X, INITIAL_POSITION_Y, charAncho, charAlto);
    gameView = new GameView(ScreenWidth, ScreenHeight, scorpion, stage);
    gameController = new GameController();
}

Game::~Game()
{
    delete scorpion;
    delete gameView;
    delete gameController;
}

void Game::GameLoop()
{
    while (gameController->getEvent()->type != SDL_QUIT)
    {
        gameController->checkEvent();
        gameView->startRender();
        gameView->Render();
        gameController->update(scorpion, stage->getLayers());
        gameView->endRender();
    }
}