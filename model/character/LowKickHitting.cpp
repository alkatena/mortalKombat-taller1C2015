#include "LowKickHitting.h"
#include "../MKCharacter.h"
#include "CharacterStance.h"
#include "ReceivingDuckingKick.h"
#include "ReceivingHit.h"

LowKickHitting::LowKickHitting() {
    this->timer = 10;
}

LowKickHitting::~LowKickHitting() {

}

void LowKickHitting::update(MKCharacter* character, Events aEvent) {
    this->timer -= 1;
    if (this->timer == 0) {
        character->setState(new CharacterStance());
        this->timer = 10;
    } else {
        switch (aEvent) {
            case DuckingKick:
                character->setState(new ReceivingDuckingKick());
                break;
            case JumpingKickLeft:
                character->setState(new ReceivingHit());
                break;
            case JumpingKickRight:
                character->setState(new ReceivingHit());
                break;
            default:
                break;
        }
    }
}

float LowKickHitting::getWidth() {
    return 0;
}

string LowKickHitting::getName() {
	return "LowKickHitting";
}