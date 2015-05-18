#include "CharacterState.h"

#ifndef MORTALKOMBAT_TALLER1C2015_RECEIVINGDUCKKICK_H
#define MORTALKOMBAT_TALLER1C2015_RECEIVINGDUCKKICK_H


class ReceivingDuckingKick : public CharacterState {

public:
    ReceivingDuckingKick();
    ~ReceivingDuckingKick();
    void update(MKCharacter* character, Events aEvent);
    string getName();
    float getWidth();
};


#endif //MORTALKOMBAT_TALLER1C2015_RECEIVINGDUCKKICK_H
