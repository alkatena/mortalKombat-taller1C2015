#include "LowPunchHitting.h"
#include "CharacterStance.h"
#include "RecevingHit.h"
#include "ReceivingDuckingKick.h"
#include "ReceivingDuckingPunch.h"
#include "BeingOverPassedLeft.h"
#include "BeingOverPassedRight.h"
#include "TeleportationDoing.h"
#include "../../view/SoundManager.h"

LowPunchHitting::LowPunchHitting() {
    this->timer = 40;
    SoundManager::getInstance()->playSound("hit1");
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
        case ReceiveWeapon:
            character->setState(new ReceivingDuckingPunch());
            break;
        case OverPassed:
            if (character->getCharacterSide() == 'l') {
                character->setState(new BeingOverPassedLeft());
            } else {
                character->setState(new BeingOverPassedRight());
            };
            break;
        case Teleportation:
            character->setState(new TeleportationDoing());
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
    return (this->timer == 20);
}