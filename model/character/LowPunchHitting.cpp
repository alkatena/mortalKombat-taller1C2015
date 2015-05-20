#include "LowPunchHitting.h"
#include "CharacterStance.h"
#include "RecevingHit.h"
#include "ReceivingDuckingKick.h"
#include "ReceivingDuckingPunch.h"

LowPunchHitting::LowPunchHitting() {
    this->timer = 40;
}

LowPunchHitting::~LowPunchHitting() {

}

void LowPunchHitting::update(MKCharacter *character, Events aEvent) {
    switch (aEvent) {
        case ReceiveHit:
            character->setState(new RecevingHit());
            break;
        case ReceiveDuckingKick:
            character->setState(new ReceivingDuckingKick());
            break;
        case ReceiveDuckingPunch:
            character->setState(new ReceivingDuckingPunch());
            break;
        default:
            break;
    }
}

float LowPunchHitting::getWidth() {
    return 1.55;
}

string LowPunchHitting::getName() {
    return "LowPunchHitting";
}

void LowPunchHitting::refreshTimer(MKCharacter* character) {
    if (this->timer == 0) {
        character->setState(new CharacterStance());
        this->timer = 40;
    }

    this->timer -= 1;
}

bool LowPunchHitting::isHitting() {
    return true;
}

bool LowPunchHitting::impact() {
    return (this->timer == 27);
}