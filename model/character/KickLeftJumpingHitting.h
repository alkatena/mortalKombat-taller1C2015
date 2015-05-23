#ifndef MORTALKOMBAT_TALLER1C2015_KICKLEFTJUMPINGHITTING_H
#define MORTALKOMBAT_TALLER1C2015_KICKLEFTJUMPINGHITTING_H


#include "CharacterState.h"

class KickLeftJumpingHitting : public CharacterState {

public:
    KickLeftJumpingHitting();
    ~KickLeftJumpingHitting();
    void update(MKCharacter* character, Events aEvent);
    
    string getName();
    float getWidth();
    bool isHitting();
    bool isJumping();
    bool isMovingLeft();
    bool impact();
    void disableImpact(MKCharacter* character);
};


#endif //MORTALKOMBAT_TALLER1C2015_KICKLEFTJUMPINGHITTING_H
