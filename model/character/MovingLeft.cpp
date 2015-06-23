#include "MovingLeft.h"
#include "CharacterStance.h"
#include "JumpingLeft.h"
#include "ReceivingDuckingPunch.h"
#include "WeaponHItting.h"
#include "LowPunchHitting.h"
#include "LowKickHitting.h"
#include "HighKickHitting.h"
#include "HighPunchHitting.h"
#include "Ducking.h"
#include "RecevingHit.h"
#include "ReceivingDuckingKick.h"
#include "BeingOverPassedLeft.h"
#include "BeingOverPassedRight.h"
#include "Blocking.h"
#include "TeleportationDoing.h"
#include "WeaponHittingIce.h"
#include "FatalityHitting.h"
#include "BeingPushed.h"

MovingLeft::MovingLeft() {
    this->timer = 10;
}

MovingLeft::~MovingLeft() {
}

void MovingLeft::update(MKCharacter * character, Events aEvent) {
    switch (aEvent) {
        case Jump:
            character->setState(new JumpingLeft());
            break;
        case Duck:
            character->setState(new Ducking());
            break;
        case HighKick:
            character->setState(new HighKickHitting());
            break;
        case HighPunch:
            character->setState(new HighPunchHitting());
            break;
        case LowPunch:
            character->setState(new LowPunchHitting());
            break;
        case LowKick:
            character->setState(new LowKickHitting());
            break;
        case WeaponHit:
            if (!character->getWeapon()->isActive()) {
                character->setState(new WeaponHitting());
            }
            break;
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
        case MoveRight:
            character->setState(new MovingRight());
            break;
        case MoveLeftRelease:
        	character->setState(new CharacterStance());
        	break;
        case Block:
            character->setState(new Blocking());
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
        case WeaponHitIce:
            if (character->getName() == "raiden"){
                character->setState(new WeaponHittingIce());
            }
            break;
        case FatalityHit:
            if (character->getFatalityEnable())
                character->setState(new FatalityHitting());
            break;
        case ReceivingFlyHit:
            if (character->getName() == "scorpion") {
                character->setState(new BeingPushed());
            }
            break;
        default:
            break;
    }
}

bool MovingLeft::isMovingLeft() {
    return true;
}

string MovingLeft::getName() {
    return "MovingLeft";
}

