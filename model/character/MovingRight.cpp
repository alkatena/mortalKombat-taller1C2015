#include "MovingRight.h"

MovingRight::MovingRight() {
//    this->timer =
}

MovingRight::~MovingRight() {
}

void MovingRight::update(Character* character, Events aEvent) {
//    delete character->state; no estoy seguro si está bien, pero la idea es que como se cambia de estado, liberamos la memoria del anterior. no es costoso hacer estos news.
/*
    character->setState(new MovingRight());
*/    std::cout << "Update desde MovingRight." << std::endl;

}

void MovingRight::getState() {
    std::cout << "Moving right state." << endl;
}