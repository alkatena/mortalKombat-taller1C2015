#include "HighPunchHitting.h"
#include "CharacterStance.h"
#include "ReceivingDuckingKick.h"
#include "RecevingHit.h"
#include "ReceivingDuckingPunch.h"

HighPunchHitting::HighPunchHitting() {
    this->timer = 40;
}

HighPunchHitting::~HighPunchHitting() {

}

void HighPunchHitting::update(MKCharacter *character, Events aEvent) {
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
        case ReceiveWeapon:
            character->setState(new ReceivingDuckingPunch());
            break;
        default:
            break;
    }
    
}

float HighPunchHitting::getWidth() {
    return 1.55;
}

string HighPunchHitting::getName() {
	return "HighPunchHitting";
}

void HighPunchHitting::refreshTimer(MKCharacter* character) {
    if (this->timer == 0) {
        character->setState(new CharacterStance());
        this->timer = 40;
    }

    this->timer -= 1;
}

bool HighPunchHitting::isHitting() {
    return true;
}

bool HighPunchHitting::impact() {
    return (this->timer == 27);
}