#include "LowKickHitting.h"
#include "../MKCharacter.h"
#include "CharacterStance.h"
#include "ReceivingDuckingKick.h"
#include "RecevingHit.h"

LowKickHitting::LowKickHitting() {
    this->timer = 40;
}

LowKickHitting::~LowKickHitting() {

}

void LowKickHitting::update(MKCharacter* character, Events aEvent) {
    switch (aEvent) {
        case DuckingKick:
            character->setState(new ReceivingDuckingKick());
            break;
        case ReceiveHit:
            character->setState(new RecevingHit());
            break;
        default:
            break;
    }
}

float LowKickHitting::getWidth() {
    return 1.88;
}

void LowKickHitting::refreshTimer(MKCharacter* character) {

    if (this->timer == 0) {
        character->setState(new CharacterStance());
        this->timer = 40;
    }

    this->timer -= 1;
}

string LowKickHitting::getName() {
	return "LowKickHitting";
}

bool LowKickHitting::impact() {
    return (this->timer == 14);
}