#ifndef MORTALKOMBAT_TALLER1C2015_RECEVINGHIT_H
#define MORTALKOMBAT_TALLER1C2015_RECEVINGHIT_H

#include "Character.h"

class RecevingHit : public CharacterState {

public:
    RecevingHit();
    ~RecevingHit();
    void update(Character* character, Events aEvent );

private:
    int timer;
};


#endif //MORTALKOMBAT_TALLER1C2015_RECEVINGHIT_H
