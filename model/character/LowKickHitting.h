#ifndef MORTALKOMBAT_TALLER1C2015_LOWKICKHITTING_H
#define MORTALKOMBAT_TALLER1C2015_LOWKICKHITTING_H


#include "../MKCharacter.h"

class LowKickHitting : public CharacterState {

public:
    LowKickHitting();
    ~LowKickHitting();
    void update(MKCharacter* character, Events aEvent );

private:
    int timer;

};


#endif //MORTALKOMBAT_TALLER1C2015_LOWKICKHITTING_H
