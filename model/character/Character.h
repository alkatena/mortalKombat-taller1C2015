#ifndef MORTALKOMBAT_TALLER1C2015_CHARACTER_H
#define MORTALKOMBAT_TALLER1C2015_CHARACTER_H

#include <stddef.h>
#include "CharacterState.h"
#include "../constantes.h"

class CharacterState;

class Character {

public:
    Character();
    ~Character();
    void setState(CharacterState* state);
    void update(Events aEvent);

private:
    CharacterState* state;

};


#endif //MORTALKOMBAT_TALLER1C2015_CHARACTER_H
