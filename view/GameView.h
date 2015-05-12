#ifndef GAMEVIEW_H_
#define GAMEVIEW_H_

#include "../view/character/CharacterSprite.h"
#include "../model/MKCharacter.h"
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "../model/stage/Layer.h"
#include "stage/LayerSprite.h"
#include "../model/stage/Stage.h"
#include "stage/LifeView.h"
#include "character/Painter.h"
#include "Text.h"
#include <string>
#include <math.h>

using namespace std;

class GameView
{
public:
    GameView(float ScreenWidth, float ScreenHeight, MKCharacter* character, MKCharacter* character2,
             Stage* stage, string OponentSide, Painter* painter);
    ~GameView();
    void Render();
    void LoadSprites(string name1, string name2);

    void startRender();
    void endRender();

private:

    MKCharacter* scorpion;
    MKCharacter* raiden;
    Stage* stage;

    Text* characterName;
    Text *characterTwoName;

    LifeView* characterOneLifebarView;
    LifeView* characterTwoLifebarView;
    CharacterSprite* scorpionWalk;
    CharacterSprite* scorpionStance;
    CharacterSprite* scorpionJump;
    CharacterSprite* scorpionDuck;
    CharacterSprite* scorpionSideJump;
    CharacterSprite* scorpionKick;
    CharacterSprite* scorpionKickDown;
    CharacterSprite* scorpionPunchJump;
    CharacterSprite* scorpionPunchUp;
    CharacterSprite* scorpionPunch;
    CharacterSprite* scorpionWinner;
    CharacterSprite* scorpionBodyParts;
    CharacterSprite* scorpionFinisher;
    CharacterSprite* scorpionShoot;
    CharacterSprite* scorpionShootOne;
    CharacterSprite* scorpionShootTwo;
    CharacterSprite* scorpionDizzy;
    CharacterSprite* scorpionFall;
    CharacterSprite* scorpionBeingHit;
    CharacterSprite* scorpionBeingHitDown;
    CharacterSprite* scorpionBlockDown;
    CharacterSprite* scorpionBlock;
    CharacterSprite* scorpionHead;


    CharacterSprite* raidenWalk;
    CharacterSprite* raidenStance;
    CharacterSprite* raidenJump;
    CharacterSprite* raidenDuck;
    CharacterSprite* raidenSideJump;
    CharacterSprite* raidenKick;
    CharacterSprite* raidenKickDown;
	CharacterSprite* raidenPunchJump;
	CharacterSprite* raidenPunchUp;
	CharacterSprite* raidenPunch;
	CharacterSprite* raidenWinner;
	CharacterSprite* raidenBodyParts;
	CharacterSprite* raidenFinisher;
	CharacterSprite* raidenShoot;
	CharacterSprite* raidenShootOne;
	CharacterSprite* raidenShootTwo;
	CharacterSprite* raidenShootThree;
	CharacterSprite* raidenShootFour;
	CharacterSprite* raidenShootFive;
	CharacterSprite* raidenShootSix;
	CharacterSprite* raidenShootSeven;
	CharacterSprite* raidenShootEight;
	CharacterSprite* raidenShootNine;
	CharacterSprite* raidenShootTen;
	CharacterSprite* raidenShootEleven;
	CharacterSprite* raidenShootZero;
	CharacterSprite* raidenDizzy;
	CharacterSprite* raidenFall;
	CharacterSprite* raidenBeingHit;
    CharacterSprite* raidenBeingHitDown;
    CharacterSprite* raidenBlockDown;
    CharacterSprite* raidenBlock;
	CharacterSprite* raidenHead;

    //list<LayerSprite*>* layerSprites = new list<LayerSprite*>();
    LayerSprite** layerSprites;
    int layerCount;

    SDL_Window* window;
    SDL_Renderer* renderer;
    float screenWidth;
    float screenHeight;
    string oponentSide;

    void runCharacter();
	void RestartAllScorpionSprites();
	void RestartAllRaidenSprites();
	double shootWidthCalculatedDistance();
	double shootWidthCalculatedDistanceRaiden();
	void restartRaidenShootSprites();
	void RaidenShootSetPosX(int currentFrame2, CharacterSprite* shootChar2);
    Painter* painter;

    int currenFramePrevious;
};

#endif /* GAMEVIEW_H_ */
