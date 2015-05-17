#ifndef MORTALKOMBAT_TALLER1C2015_MOVINGLEFT_H
#define MORTALKOMBAT_TALLER1C2015_MOVINGLEFT_H

#include "Character.h"
#include "CharacterState.h"

class MovingLeft : public CharacterState {

public:
    MovingLeft();
    ~MovingLeft();
    void update(Character* character, Events aEvent );

private:
    int timer;
};


#endif //MORTALKOMBAT_TALLER1C2015_MOVINGLEFT_H

