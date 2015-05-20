#include "JumpingLeft.h"
#include "CharacterStance.h"
#include "ReceivingDuckingPunch.h"
#include "PunchLeftJumping.h"
#include "WeaponHItting.h"
#include "MovingLeft.h"
#include "KickLeftJumpingHitting.h"

JumpingLeft::JumpingLeft() {
}

JumpingLeft::~JumpingLeft() {
}

void JumpingLeft::update(MKCharacter * character, Events aEvent) {
    switch (aEvent) {
        case HighPunch:
            character->setState(new PunchLeftJumping());
            break;
        case LowPunch:
            character->setState(new PunchLeftJumping());
            break;
        case HighKick:
            character->setState(new KickLeftJumpingHitting());
            break;
        case LowKick:
            character->setState(new KickLeftJumpingHitting());
            break;
        case ReceiveHit:
            character->setState(new ReceivingDuckingPunch());
            break;
        case ReceiveDuckingPunch:
            character->setState(new ReceivingDuckingPunch());
            break;
        case JumpFinished:
            character->setState(new CharacterStance());
            break;
        case ReceiveWeapon:
            character->setState(new ReceivingDuckingPunch());
            break;
        case WeaponHit:
            if (!character->getWeapon()->isActive()) {
                character->setState(new WeaponHitting());
            }
            break;
        default:
            break;
    }
}

bool JumpingLeft::isJumping() {
    return true;
}

string JumpingLeft::getName() {
    return "JumpingLeft";
}

bool JumpingLeft::isMovingLeft() {
    return true;
}
