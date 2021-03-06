//
// Created by mauri on 20/05/15.
//

#ifndef MORTALKOMBAT_TALLER1C2015_WEAPON_H
#define MORTALKOMBAT_TALLER1C2015_WEAPON_H

#include <iostream>
#include "Throwable.h"

using namespace std;

class Weapon : public Throwable {
public:
    Weapon(float width, float height);
    ~Weapon();
    void update();
    bool isActive();
    void destroy();
    float getPositionX();
    float getPositionY();
    void throwWeapon(float initialPositionX, float initialPositionY, char direction);
    float getWidth();
    float getHeight();
    bool isImpact();

private:
    float speed;
    float positionX;
    float positionY;
    float height;
    float width;
    bool active;
    char direction;
    void stepForward();
    float traveledDistance;
    bool impact;

};


#endif //MORTALKOMBAT_TALLER1C2015_WEAPON_H
