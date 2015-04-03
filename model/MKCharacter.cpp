#include "MKCharacter.h"

MKCharacter::MKCharacter(int initialPosX, int initialPosY)
{

	//tamaño del png = 87*136
	timeCheck = SDL_GetTicks();

	posX = initialPosX;
	posY = initialPosY;

	accY = 30;

	movement = "NONE";

}

MKCharacter::~MKCharacter(void)
{
}

void MKCharacter::Update()
{

	if (timeCheck + 5 < SDL_GetTicks()) {
		if (movement == "WALKINGRIGHT") {
			this->moveRight();
		}
		else if (movement == "WALKINGLEFT") {
			this->moveLeft();
		}
		else if (movement == "JUMPUP") {
			this->moveUp();
		}
		else {
			velY = 5;
			posY = 200;
		}

		timeCheck = SDL_GetTicks();
	}

}

void MKCharacter::moveRight() {

    //Verifico que no se vaya de la pantalla por derecha
    
    if(( posX + 5 + getWidth() < SCREEN_WIDTH ) )
    {
    	posX = posX + 5;
    }

}

void MKCharacter::moveLeft() {
	//Verifico que no se vaya de la pantalla por izquierda
	
	if(( posX - 5 + getWidth() > getWidth() ) )
	{
		posX = posX - 5;
	}

}

void MKCharacter::moveUp() {

	if (posY > 40 && posY <= 201)
	{
		float time = 0.003;

//		cout << "PosY:" << posY << "  Vel: " << velY << "   Time: " << time << " TimeCheck: " << timeCheckJump << endl;

		velY = velY - accY * time;

		posY = posY - velY;
	}
}

int MKCharacter::getWidth(){
	return CHARACTER_WIDTH;
}

int MKCharacter::getX() {
	return posX;
}

int MKCharacter::getY() {
	return posY;
}

string MKCharacter::getMovement() {
	return movement;
}

void MKCharacter::setMovement(string newMovement) {
	this->movement = newMovement;
}
