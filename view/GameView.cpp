#include "GameView.h"

GameView::GameView(float ScreenWidth, float ScreenHeight, MKCharacter* character, MKCharacter* character2, Stage* pStage, string OponentSide) {

	oponentSide = OponentSide;
	this->window = NULL;
    this->window = SDL_CreateWindow("Mortal Kombat", 0, 0, (int) ScreenWidth, (int) ScreenHeight, SDL_WINDOW_SHOWN);

    if (this->window == NULL) {

        std::cout << "Window couldn't be created" << std::endl;
    }

    this->renderer = NULL;
    this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_TARGETTEXTURE);

    this->screenWidth = ScreenWidth;
    this->screenHeight = ScreenHeight;

    this->stage = pStage;
    this->scorpion = character;
    this->raiden = character2;
 	this->LoadSprites(this->scorpion->getName(), this->raiden->getName());

    layerCount = this->stage->getLayers()->size();
    layerSprites = new LayerSprite*[layerCount-1];


    this->characterOneLifebarView = new LifeView(this->renderer, "data/lifebar.png", Util::getInstance()->getLogicalWindowWidth() * LIFEBAR_RELATIVE_WIDTH, false);
    this->characterTwoLifebarView = new LifeView(this->renderer, "data/lifebar.png", Util::getInstance()->getLogicalWindowWidth() * LIFEBAR_RELATIVE_WIDTH, true);

    std::list<Layer*>::iterator it = this->stage->getLayers()->begin();

    int i = 0;

    // We load the sprites and put them into an array
    for(it; it != this->stage->getLayers()->end(); it++) {
        layerSprites[i] = new LayerSprite(this->renderer,(*it)->getPath(),screenWidth,screenHeight, (*it)->getWidth());
        //cout << "paths; " << (*it)->getPath() << endl;

        i++;
    }
}

GameView::~GameView() {
    delete characterOneLifebarView;
    delete characterTwoLifebarView;

    delete scorpionJump;
	delete scorpionWalk;
    delete scorpionStance;
    delete scorpionSideJump;
    delete scorpionDuck;
    delete  scorpionKick;
    delete  scorpionKickDown;
    delete  scorpionPunchJump;
    delete  scorpionPunchUp;
    delete  scorpionPunch;
    delete  scorpionWinner;
    delete  scorpionBodyParts;
    delete  scorpionFinisher;
    delete  scorpionShoot;
    delete  scorpionDizzy;
    delete  scorpionFall;
    delete  scorpionBeingHit;
    delete  scorpionBlockDown;
    delete  scorpionBlock;
    delete  scorpionHead;
    delete  raidenWalk;
    delete  raidenStance;
    delete  raidenJump;
    delete  raidenSideJump;
    delete  raidenDuck;
    delete  raidenKick;
    delete  raidenKickDown;
    delete  raidenPunchJump;
    delete  raidenPunchUp;
    delete  raidenPunch;
    delete  raidenWinner;
    delete  raidenBodyParts;
    delete  raidenFinisher;
    delete  raidenShoot;
    delete  raidenDizzy;
    delete  raidenFall;
    delete  raidenBeingHit;
    delete  raidenBlockDown;
    delete  raidenBlock;
    delete  raidenHead;

    for (int i = 1 ; i < layerCount ; i++) {
        delete layerSprites[i];
    }
    delete layerSprites;

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}

void GameView::Render() {
    int i = 0;
    bool painted = false;
    // We render the layers' sprites iterating through the layerSprites' array
    std::list<Layer*>::iterator it = this->stage->getLayers()->begin();
    for(it; it != this->stage->getLayers()->end(); it++) {
        if (scorpion->getZ_index() == i+1) {
            this->runCharacter();
            layerSprites[i]->update((*it)->getLeft_border());
            layerSprites[i]->Draw();
            painted = true;
        } else {
            layerSprites[i]->update((*it)->getLeft_border());
            layerSprites[i]->Draw();
        }
        i++;
    }

    characterOneLifebarView->Draw(this->scorpion->getLife());
    characterTwoLifebarView->Draw(this->raiden->getLife());

    if (!painted) {
        this->runCharacter();
    }
}

void GameView::LoadSprites(string name1, string name2) {
    bool colorAltered = false;
    if (name1 == name2) {
        colorAltered = true;
    }
	scorpionWalk = new CharacterSprite(this->renderer, scorpion->getFileMovement(MOVE_NAME_WALK) , scorpion->getX(),scorpion->getY(), scorpion->getWidth(),scorpion->getHeight(), 9, oponentSide, false, false);
    scorpionStance = new CharacterSprite(this->renderer, scorpion->getFileMovement(MOVE_NAME_STANCE), scorpion->getX(),scorpion->getY(), scorpion->getWidth(),scorpion->getHeight(), 7, oponentSide, false, false);
    scorpionJump = new CharacterSprite(this->renderer, scorpion->getFileMovement(MOVE_NAME_JUMP), scorpion->getX(),scorpion->getY(), scorpion->getWidth(),scorpion->getHeight(), 9, oponentSide, false, false);
    scorpionSideJump = new CharacterSprite(this->renderer, scorpion->getFileMovement(MOVE_NAME_SIDEJUMP), scorpion->getX(), scorpion->getY(), scorpion->getWidth(), scorpion->getHeight(), 8, oponentSide, false, false);
    scorpionDuck = new CharacterSprite(this->renderer, scorpion->getFileMovement(MOVE_NAME_DUCK), scorpion->getX(), scorpion->getY(), scorpion->getWidth(), scorpion->getHeight(), 6, oponentSide, true, false);
    scorpionKick = new CharacterSprite(this->renderer, scorpion->getFileMovement(MOVE_NAME_KICK), scorpion->getX(), scorpion->getY(), scorpion->getWidth(), scorpion->getHeight(), 5, oponentSide, false, false);
    scorpionKickDown = new CharacterSprite(this->renderer, scorpion->getFileMovement(MOVE_NAME_KICKDOWN), scorpion->getX(), scorpion->getY(), scorpion->getWidth(), scorpion->getHeight(), 5, oponentSide, false, false);
    scorpionPunchJump = new CharacterSprite(this->renderer, scorpion->getFileMovement(MOVE_NAME_PUNCHJUMP), scorpion->getX(), scorpion->getY(), scorpion->getWidth(), scorpion->getHeight(), 3, oponentSide, false, false);
    scorpionPunchUp = new CharacterSprite(this->renderer, scorpion->getFileMovement(MOVE_NAME_PUNCHUP), scorpion->getX(), scorpion->getY(), scorpion->getWidth(), scorpion->getHeight(), 5, oponentSide, false, false);
    scorpionPunch = new CharacterSprite(this->renderer, scorpion->getFileMovement(MOVE_NAME_PUNCH), scorpion->getX(), scorpion->getY(), scorpion->getWidth(), scorpion->getHeight(), 6, oponentSide, false, false);
    scorpionWinner = new CharacterSprite(this->renderer, scorpion->getFileMovement(MOVE_NAME_WINNER), scorpion->getX(), scorpion->getY(), scorpion->getWidth(), scorpion->getHeight(), 4, oponentSide, false, false);
    scorpionBodyParts = new CharacterSprite(this->renderer, scorpion->getFileMovement(MOVE_NAME_BODYPARTS), scorpion->getX(), scorpion->getY(), scorpion->getWidth(), scorpion->getHeight(), 8, oponentSide, false, false);
    scorpionFinisher = new CharacterSprite(this->renderer, scorpion->getFileMovement(MOVE_NAME_FINISHER), scorpion->getX(), scorpion->getY(), scorpion->getWidth(), scorpion->getHeight(), 26, oponentSide, false, false);
    scorpionShoot = new CharacterSprite(this->renderer, scorpion->getFileMovement(MOVE_NAME_SHOOT), scorpion->getX(), scorpion->getY(), scorpion->getWidth(), scorpion->getHeight(), 9, oponentSide, false, false);
    scorpionDizzy = new CharacterSprite(this->renderer, scorpion->getFileMovement(MOVE_NAME_DIZZY), scorpion->getX(), scorpion->getY(), scorpion->getWidth(), scorpion->getHeight(), 7, oponentSide, false, false);
    scorpionFall = new CharacterSprite(this->renderer, scorpion->getFileMovement(MOVE_NAME_FALL), scorpion->getX(), scorpion->getY(), scorpion->getWidth(), scorpion->getHeight(), 7, oponentSide, false, false);
    scorpionBeingHit = new CharacterSprite(this->renderer, scorpion->getFileMovement(MOVE_NAME_BEINGHIT), scorpion->getX(), scorpion->getY(), scorpion->getWidth(), scorpion->getHeight(), 3, oponentSide, false, false);
    scorpionBlockDown = new CharacterSprite(this->renderer, scorpion->getFileMovement(MOVE_NAME_BLOCKDOWN), scorpion->getX(), scorpion->getY(), scorpion->getWidth(), scorpion->getHeight(), 2, oponentSide, false, false);
    scorpionBlock = new CharacterSprite(this->renderer, scorpion->getFileMovement(MOVE_NAME_BLOCK), scorpion->getX(), scorpion->getY(), scorpion->getWidth(), scorpion->getHeight(), 3, oponentSide, false, false);
    scorpionHead = new CharacterSprite(this->renderer, scorpion->getFileMovement(MOVE_NAME_HEAD), scorpion->getX(), scorpion->getY(), scorpion->getWidth(), scorpion->getHeight(), 9, oponentSide, false, false);

    raidenWalk = new CharacterSprite(this->renderer, raiden->getFileMovement(MOVE_NAME_WALK) , raiden->getX(),raiden->getY(), raiden->getWidth(),raiden->getHeight(), 9, oponentSide, false, colorAltered);
	raidenStance = new CharacterSprite(this->renderer, raiden->getFileMovement(MOVE_NAME_STANCE), raiden->getX(),raiden->getY(), raiden->getWidth(),raiden->getHeight(), 10, oponentSide, false, colorAltered);
	raidenJump = new CharacterSprite(this->renderer, raiden->getFileMovement(MOVE_NAME_JUMP), raiden->getX(),raiden->getY(), raiden->getWidth(),raiden->getHeight(), 4, oponentSide, false, colorAltered);
	raidenSideJump = new CharacterSprite(this->renderer, raiden->getFileMovement(MOVE_NAME_SIDEJUMP), raiden->getX(), raiden->getY(), raiden->getWidth(), raiden->getHeight(), 8, oponentSide, false, colorAltered);
	raidenDuck = new CharacterSprite(this->renderer, raiden->getFileMovement(MOVE_NAME_DUCK), raiden->getX(), raiden->getY(), raiden->getWidth(), raiden->getHeight(), 3, oponentSide, true, colorAltered);
	raidenKick = new CharacterSprite(this->renderer, raiden->getFileMovement(MOVE_NAME_KICK), raiden->getX(), raiden->getY(), raiden->getWidth(), raiden->getHeight(), 5, oponentSide, false, colorAltered);
	raidenKickDown = new CharacterSprite(this->renderer, raiden->getFileMovement(MOVE_NAME_KICKDOWN), raiden->getX(), raiden->getY(), raiden->getWidth(), raiden->getHeight(), 5, oponentSide, false, colorAltered);
	raidenPunchJump = new CharacterSprite(this->renderer, raiden->getFileMovement(MOVE_NAME_PUNCHJUMP), raiden->getX(), raiden->getY(), raiden->getWidth(), raiden->getHeight(), 3, oponentSide, false, colorAltered);
	raidenPunchUp = new CharacterSprite(this->renderer, raiden->getFileMovement(MOVE_NAME_PUNCHUP), raiden->getX(), raiden->getY(), raiden->getWidth(), raiden->getHeight(), 5, oponentSide, false, colorAltered);
	raidenPunch = new CharacterSprite(this->renderer, raiden->getFileMovement(MOVE_NAME_PUNCH), raiden->getX(), raiden->getY(), raiden->getWidth(), raiden->getHeight(), 9, oponentSide, false, colorAltered);
	raidenWinner = new CharacterSprite(this->renderer, raiden->getFileMovement(MOVE_NAME_WINNER), raiden->getX(), raiden->getY(), raiden->getWidth(), raiden->getHeight(), 14, oponentSide, false, colorAltered);
	raidenBodyParts = new CharacterSprite(this->renderer, raiden->getFileMovement(MOVE_NAME_BODYPARTS), raiden->getX(), raiden->getY(), raiden->getWidth(), raiden->getHeight(), 8, oponentSide, false, colorAltered);
	raidenFinisher = new CharacterSprite(this->renderer, raiden->getFileMovement(MOVE_NAME_FINISHER), raiden->getX(), raiden->getY(), raiden->getWidth(), raiden->getHeight(), 26, oponentSide, false, colorAltered);
	raidenShoot = new CharacterSprite(this->renderer, raiden->getFileMovement(MOVE_NAME_SHOOT), raiden->getX(), raiden->getY(), raiden->getWidth(), raiden->getHeight(), 9, oponentSide, false, colorAltered);
	raidenDizzy = new CharacterSprite(this->renderer, raiden->getFileMovement(MOVE_NAME_DIZZY), raiden->getX(), raiden->getY(), raiden->getWidth(), raiden->getHeight(), 7, oponentSide, false, colorAltered);
	raidenFall = new CharacterSprite(this->renderer, raiden->getFileMovement(MOVE_NAME_FALL), raiden->getX(), raiden->getY(), raiden->getWidth(), raiden->getHeight(), 6, oponentSide, true, colorAltered);
	raidenBeingHit = new CharacterSprite(this->renderer, raiden->getFileMovement(MOVE_NAME_BEINGHIT), raiden->getX(), raiden->getY(), raiden->getWidth(), raiden->getHeight(), 4, oponentSide, false, colorAltered);
	raidenBlockDown = new CharacterSprite(this->renderer, raiden->getFileMovement(MOVE_NAME_BLOCKDOWN), raiden->getX(), raiden->getY(), raiden->getWidth(), raiden->getHeight(), 2, oponentSide, false, colorAltered);
	raidenBlock = new CharacterSprite(this->renderer, raiden->getFileMovement(MOVE_NAME_BLOCK), raiden->getX(), raiden->getY(), raiden->getWidth(), raiden->getHeight(), 3, oponentSide, false, colorAltered);
	raidenHead = new CharacterSprite(this->renderer, raiden->getFileMovement(MOVE_NAME_HEAD), raiden->getX(), raiden->getY(), raiden->getWidth(), raiden->getHeight(), 9, oponentSide, false, colorAltered);

}
void GameView::RestarAllScorpionSprites()
{
	scorpionFall->reset();
	scorpionDuck->reset();
	scorpionJump->reset();
	scorpionSideJump->reset();
	scorpionKick->reset();
	scorpionKickDown->reset();
	scorpionPunchUp->reset();
	scorpionPunch->reset();
	scorpionPunchJump->reset();
	scorpionShoot->reset();
	scorpionDizzy->reset();
	scorpionBeingHit->reset();
	scorpionBlockDown->reset();
	scorpionBlock->reset();
}

void GameView::RestarAllRaidenSprites()
{
	raidenFall->reset();
	raidenDuck->reset();
	raidenJump->reset();
	raidenSideJump->reset();
	raidenKick->reset();
	raidenKickDown->reset();
	raidenPunchUp->reset();
	raidenPunchJump->reset();
	raidenPunch->reset();
	raidenShoot->reset();
	raidenDizzy->reset();
	raidenBeingHit->reset();
	raidenBlockDown->reset();
	raidenBlock->reset();
}
void GameView::startRender() {
    SDL_RenderClear(renderer);
}

void GameView::endRender() {
    SDL_RenderPresent(renderer);
}

void GameView::runCharacter() {
    CharacterSprite* sprite;

    if (scorpion->isJumping() && scorpion->getJumpMovement() == "NONE" && scorpion->getHit() == "NONE") {
        sprite = scorpionJump;
        sprite->Play(300);
    }
    //HA: Aca hay q preguntar de q lado esta el oponente para ver si gira para un lado o el otro
    else if (scorpion->isJumping() && scorpion->getJumpMovement() == "RIGHT" && scorpion->getHit() == "NONE") {
        sprite = scorpionSideJump;
        sprite->Play(50);
    }
    else if (scorpion->isJumping() && scorpion->getJumpMovement() == "LEFT" && scorpion->getHit() == "NONE") {
        sprite = scorpionSideJump;
        sprite->PlayBack(50);
    }
    else if (scorpion->getMovement() == "NONE" && scorpion->getHit() == "NONE") {
        sprite = scorpionStance;
        RestarAllScorpionSprites();
        sprite->Play(100);
    }
    else if (scorpion->getMovement() == "RIGHT" && scorpion->getHit() == "NONE") {
    	sprite = scorpionWalk;
    	if(scorpion->getX() < raiden->getX()){
    		sprite->Play(100);
		}else{
			sprite->PlayBack(100);
		}
    }
    else if (scorpion->getMovement() == "LEFT" && scorpion->getHit() == "NONE") {
    	sprite = scorpionWalk;
    	if(scorpion->getX() > raiden->getX()){
			sprite->Play(100);
		}else{
			sprite->PlayBack(100);
		}
    }
    else if (scorpion->getMovement() == "DUCK") {
        sprite = scorpionDuck;
        sprite->Play(20);
    }
    else if (scorpion->getHit() == "KICK") {
		sprite = scorpionKick;
		sprite->Play(100);
	}
    else if (scorpion->getHit() == "KICKDOWN") {
    		sprite = scorpionKickDown;
    		sprite->Play(100);
    }
    else if (scorpion->getHit() == "PUNCH") {
    		sprite = scorpionPunch;
    		sprite->Play(100);
    }
    else if (scorpion->getHit() == "SHOOT") {
    		sprite = scorpionShoot;
    		sprite->PlayShoot(100);
    }
    else if (scorpion->getHit() == "DEFENSE") {
    		sprite = scorpionBlock;
    		sprite->Play(100);
    }
    else if (scorpion->getHit() == "DIZZY") {
    		sprite = scorpionDizzy;
    		sprite->Play(150);
    }
    else if (scorpion->getHit() == "BEINGHIT") {
    		sprite = scorpionBeingHit;
    		sprite->Play(150);
    }
    else if (scorpion->getHit() == "FALLING") {
    		sprite = scorpionFall;
    		sprite->PlayFall(250);
    }
    else if ((scorpion->getHit() == "PUNCHJUMPLEFT" || scorpion->getHit() == "PUNCHJUMPRIGHT")) {
    	if (scorpion->isJumping() )
    	{
			sprite = scorpionPunchJump;
			sprite->Play(400);
    	}
    	else
    	{
            sprite = scorpionStance;
            RestarAllScorpionSprites();
            sprite->Play(100);
    	}
	}
    else if (scorpion->getHit() == "WINNER") {
    		sprite = scorpionWinner;
    		sprite->Play(150);
    }
    else if (scorpion->getHit() == "PUNCHUP") {
        		sprite = scorpionPunchUp;
        		sprite->Play(150);
	};

    /****************************************************************************************************/

    CharacterSprite* sprite2;

    if (raiden->isJumping() && raiden->getJumpMovement() == "NONE" && raiden->getHit() == "NONE") {
        sprite2 = raidenJump;
        sprite2->Play(700);
    }
    //HA: Aca hay q preguntar de q lado esta el oponente para ver si gira para un lado o el otro
    else if (raiden->isJumping() && raiden->getJumpMovement() == "RIGHT" && raiden->getHit() == "NONE") {
        sprite2 = raidenSideJump;
        sprite2->Play(50);
    }
    else if (raiden->isJumping() && raiden->getJumpMovement() == "LEFT" && raiden->getHit() == "NONE") {
        sprite2 = raidenSideJump;
        sprite2->PlayBack(50);
    }
    else if (raiden->getMovement() == "NONE" && raiden->getHit() == "NONE") {
        sprite2 = raidenStance;
        RestarAllRaidenSprites();
        sprite2->Play(50);
    }
    else if (raiden->getMovement() == "RIGHT" && raiden->getHit() == "NONE") {
		sprite2 = raidenWalk;
		if(scorpion->getX() > raiden->getX()){
			sprite2->Play(100);
		}else{
			sprite2->PlayBack(100);
		}
    }
    else if (raiden->getMovement() == "LEFT" && raiden->getHit() == "NONE") {
		sprite2 = raidenWalk;
		if(scorpion->getX() < raiden->getX()){
			sprite2->Play(100);
		}else{
			sprite2->PlayBack(100);
		}
    }
    else if (raiden->getMovement() == "DUCK") {
        sprite2 = raidenDuck;
        sprite2->Play(150);
    }
    else if (raiden->getHit() == "KICK") {
		sprite2 = raidenKick;
		sprite2->Play(100);
	}
    else if (raiden->getHit() == "KICKDOWN") {
    		sprite2 = raidenKickDown;
    		sprite2->Play(100);
    }
    else if (raiden->getHit() == "PUNCH") {
    		sprite2 = raidenPunch;
    		sprite2->Play(100);
    }
    else if (raiden->getHit() == "SHOOT") {
    		sprite2 = raidenShoot;
    		sprite2->PlayShoot(100);
    }
    else if (raiden->getHit() == "DEFENSE") {
    		sprite2 = raidenBlock;
    		sprite2->Play(100);
    }
    else if (raiden->getHit() == "DIZZY") {
    		sprite2 = raidenDizzy;
    		sprite2->Play(150);
    }
    else if (raiden->getHit() == "BEINGHIT") {
    		sprite2 = raidenBeingHit;
    		sprite2->Play(100);
    }
    else if (raiden->getHit() == "FALLING") {
    		sprite2 = raidenFall;
    		sprite2->PlayFall(250);
    }
    else if ((raiden->getHit() == "PUNCHJUMPLEFT" || raiden->getHit() == "PUNCHJUMPRIGHT")) {
    	if (raiden->isJumping() )
    	{
			sprite2 = raidenPunchJump;
			sprite2->Play(400);
    	}
    	else
    	{
            sprite2 = raidenStance;
            RestarAllRaidenSprites();
            sprite2->Play(100);
    	}
	}
    else if (raiden->getHit() == "WINNER") {
    		sprite2 = raidenWinner;
    		sprite2->Play(150);
    }
    else if (raiden->getHit() == "PUNCHUP") {
		sprite2 = raidenPunchUp;
		sprite2->Play(150);
	};

    if(scorpion->getX() < raiden->getX()){
        sprite->switchSide('r');
        sprite2->switchSide('l');
    }else{
        sprite->switchSide('l');
        sprite2->switchSide('r');
    }

    sprite->setX(scorpion->getX());
    sprite->setY(scorpion->getY());
    sprite->Draw();

    sprite2->setX(raiden->getX());
    sprite2->setY(raiden->getY());
    sprite2->Draw();
}

