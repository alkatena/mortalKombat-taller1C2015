#ifndef MORTALKOMBAT_TALLER1C2015_KICKRIGHTJUMPINGHITTING_H
#define MORTALKOMBAT_TALLER1C2015_KICKRIGHTJUMPINGHITTING_H


#include "CharacterState.h"

class KickRightJumpingHitting : CharacterState {

public:
    KickRightJumpingHitting();
    ~KickRightJumpingHitting();
    void update(MKCharacter* character, Events aEvent);
    
    string getName();
    float getWidth();

};


#endif //MORTALKOMBAT_TALLER1C2015_KICKRIGHTJUMPINGHITTING_H
