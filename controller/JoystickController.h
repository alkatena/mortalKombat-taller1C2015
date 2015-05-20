//
// Created by mauri on 03/05/15.
//

#ifndef MORTALKOMBAT_TALLER1C2015_JOYSTICKCONTROLLER_H
#define MORTALKOMBAT_TALLER1C2015_JOYSTICKCONTROLLER_H
#include <iostream>
#include "../model/MKCharacter.h"
#include "../model/util/Util.h"

using namespace std;

class JoystickController
{
public:
    JoystickController(char);
    ~JoystickController(void);

    void update(MKCharacter* character, MKCharacter* character2, SDL_Event* joystickEvent);
    SDL_Event* getEvent();
private:
    char joystickNumber;

        //botones
    unsigned char c0jump;
    unsigned char c0duck;
    unsigned char c0left;
    unsigned char c0right;
    unsigned char c0LowPunch;
    unsigned char c0HighPunch;
    unsigned char c0HighKick;
    unsigned char c0LowKick;
    unsigned char c0block;
    unsigned char c0shoot;
    unsigned char c0duckPunch;

    int c0previousAxis;
    int c0previousAxisValue;
	bool c0blockReleased;
	bool c0ducked;
	bool c0walkingLeft;
	bool c0walkingRight;


	void setDucked(bool value);
	void setWalkingLeft(bool value);
	void setWalkingRight(bool value);

	void KeyUP_Right(unsigned char pressedAxis, int pressedAxisValue,bool printCout, MKCharacter* character, MKCharacter* character2);
	void KeyUP_Down(unsigned char pressedAxis, int pressedAxisValue,bool printCout, MKCharacter* character, MKCharacter* character2);
	void KeyUP_Left(unsigned char pressedAxis, int pressedAxisValue,bool printCout, MKCharacter* character, MKCharacter* character2);
};
#endif //MORTALKOMBAT_TALLER1C2015_JOYSTICKCONTROLLER_H
