#ifndef MORTALKOMBAT_TALLER1C2015_LOWPUNCHHITTING_H
#define MORTALKOMBAT_TALLER1C2015_LOWPUNCHHITTING_H

#include "CharacterState.h"

class LowPunchHitting : public CharacterState {

public:
    LowPunchHitting();
    ~LowPunchHitting();
    void update(MKCharacter* character, Events aEvent );
    
    string getName();
    float getWidth();
    bool impact();
    void refreshTimer(MKCharacter* character);
    bool isHitting();


private:
    int timer;
};


#endif //MORTALKOMBAT_TALLER1C2015_LOWPUNCHHITTING_H
