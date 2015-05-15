#ifndef MORTALKOMBAT_TALLER1C2015_CHARACTERSTATE_H
#define MORTALKOMBAT_TALLER1C2015_CHARACTERSTATE_H

#include "Character.h"
#include "../MKEvents/MoveLeft.h"
#include "../MKEvents/MoveRight.h"


class CharacterState {

public:
    virtual inline void update(Character* character, MoveRight* aEvent ) = 0;
    virtual inline void update(Character* character, MoveLeft* aEvent ) = 0;

protected:
    void setState(Character*, CharacterState*);

};


#endif //MORTALKOMBAT_TALLER1C2015_CHARACTERSTATE_H
