#include "Game.h"

Game::Game(int pScreenWidth, int pScreenHeight, float pLogicalScreenWidth,
                float charAncho, float charAlto, Stage* pStage, string OponentSide, int z_index)
{
    this->ScreenWidth = pScreenWidth;
    this->ScreenHeight = pScreenHeight;
    this->logicalScreenWidth = pLogicalScreenWidth;
    this->stage = pStage;
    this->oponentSide = OponentSide;
    scorpion = new MKCharacter(INITIAL_POSITION_X, INITIAL_POSITION_Y, charAncho, charAlto, z_index);
    this->gameView = new GameView(ScreenWidth, ScreenHeight, scorpion, stage, oponentSide);
    this->gameController = new GameController();
    this->cameraController = new CameraController();

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
        gameController->update(scorpion);
        cameraController->update(scorpion, stage->getLayers());
        gameView->endRender();
        SDL_Delay(15);
    }
}
