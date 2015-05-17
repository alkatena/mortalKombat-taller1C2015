#ifndef MORTALKOMBAT_TALLER1C2015_CHARACTERSTATE_H
#define MORTALKOMBAT_TALLER1C2015_CHARACTERSTATE_H

#include "../MKCharacter.h"
#include "../constantes.h"
#include <map>
class MKCharacter;

class CharacterState {

public:
    virtual void update(MKCharacter * character, Events aEvent );

protected:
    void setState(MKCharacter * character, CharacterState* aState);
    map<Events, CharacterState>* eventMap;

};


#endif //MORTALKOMBAT_TALLER1C2015_CHARACTERSTATE_H

