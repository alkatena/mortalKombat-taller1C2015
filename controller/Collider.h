		#ifndef MORTALKOMBAT_TALLER1C2015_COLLIDER_H
#define MORTALKOMBAT_TALLER1C2015_COLLIDER_H

#include <stdlib.h>
#include "../model/MKCharacter.h"

class Collider {

public:
    Collider();
    ~Collider();

    void update(MKCharacter* character1, MKCharacter* character2, bool cameraMoved, bool endFight);

private:

    bool superpositionLeft(MKCharacter* character1, MKCharacter* character2);

    bool superpositionRight(MKCharacter *character1, MKCharacter *character2);

    bool superpositionUp(MKCharacter* character1, MKCharacter* character2);

    bool superpositionDown(MKCharacter* character1, MKCharacter* character2);

    void checkHits(MKCharacter* character1, MKCharacter* character2, bool endFight);

    bool superpositionWeaponDown(Throwable* weapon, MKCharacter* character2);

    bool superpositionWeaponLeft(Throwable* weapon, MKCharacter* character2);

    bool superpositionWeaponRight(Throwable* weapon, MKCharacter* character2);

    void checkOverPassing(MKCharacter* character1, MKCharacter* character2);

    bool overPassedRight;

    double initialX;
};


#endif //MORTALKOMBAT_TALLER1C2015_COLLIDER_H
