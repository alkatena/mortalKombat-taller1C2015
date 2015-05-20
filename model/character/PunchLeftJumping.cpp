#include "PunchLeftJumping.h"

PunchLeftJumping::PunchLeftJumping() {

}

PunchLeftJumping::~PunchLeftJumping() {

}

void PunchLeftJumping::update(MKCharacter *character, Events aEvent) {
	switch (aEvent) {
        case ReceiveHit:
            character->setState(new ReceivingDuckingPunch());
            break;
        case ReceiveDuckingPunch:
            character->setState(new ReceivingDuckingPunch());
            break;
        case JumpFinished:
            character->setState(new CharacterStance());
        default:
            break;

    }
}

string PunchLeftJumping::getName() {
	return "PunchLeftJumping";
}

float PunchLeftJumping::getWidth() {
    return 1.2;
}

bool PunchLeftJumping::isJumping() {
    return true;
}

bool PunchLeftJumping::isMovingLeft() {
    return true;
}

bool PunchLeftJumping::isHitting() {
    return true;
}