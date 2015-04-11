#include "Layer.h"
#include "../MKCharacter.h"
#include "../util/Util.h"

Layer::Layer(float width) {
    this->width = width;
    this->path = "default.png";
    this->left_border = 0;
}

Layer::Layer(float width, string path) {
    this->width = width;
    this->path = path;
    //Here depending on the width, the speed is set. Now depends of the z-index
    this->left_border = (this->width - Util::getInstance()->getLogicalWindowWidth()) /2;

    this->speed = ((this->getWidth() - Util::getInstance()->getLogicalWindowWidth()) / Util::getInstance()->getLogicalStageWidth()) * 5;
    if (this->width <= Util::getInstance()->getLogicalWindowWidth()) {
        this->left_border = (Util::getInstance()->getLogicalWindowWidth() - this->width) / 2;
        this->speed = ((Util::getInstance()->getLogicalWindowWidth() - this->getWidth()) / Util::getInstance()->getLogicalWindowWidth()) * 5;
       // this->speed = - this->speed;
    }
    //timeCheck = SDL_GetTicks();
}

Layer::~Layer() {

}

string Layer::getPath() {
    return this->path;
}

float Layer::getWidth() {
    return this->width;
}

void Layer::setWidth(float width) {
    this->width = width;
}

float Layer::getSpeed() {
    return this->speed;
}

void Layer::setLeft_border(float left_border) {
    this->left_border = left_border;
}

float Layer::getLeft_border() {
    float aux = this->left_border;
    return aux;
}

void Layer::moveLeft() {
    if (this->getWidth() > Util::getInstance()->getLogicalWindowWidth()) {
        if (this->left_border >= 0)
            this->left_border -= speed;
    }
    else {
        if ( this->left_border >= 0 )
            this->left_border -= speed;
    }
}

void Layer::moveRight() {
    /*if (this->left_border + Util::getInstance()->getLogicalWindowWidth() < this->getWidth() && this->getWidth() > Util::getInstance()->getLogicalWindowWidth() )
        this->left_border += speed;
    if (this->left_border + this->getWidth() <= Util::getInstance()->getLogicalWindowWidth() && this->getWidth() <= Util::getInstance()->getLogicalWindowWidth() )
        this->left_border += speed;*/

    if ( this->getWidth() > Util::getInstance()->getLogicalWindowWidth() ) {
        if (this->left_border + Util::getInstance()->getLogicalWindowWidth() < this->getWidth())
            this->left_border += speed;
    }
    else {
        if (this->left_border + this->getWidth() < Util::getInstance()->getLogicalWindowWidth())
            this->left_border += speed;
    }

/*    else
        if (this->left_border >= 0)
            this->left_border -= speed;
*//*
    }*/
}

void Layer::update() {
        if (movement == "RIGHT") {
            //if (this->getWidth() <= Util::getInstance()->getLogicalWindowWidth())
              //  this->moveLeft();
            //else
                this->moveRight();
        }
        else if (movement == "LEFT") {
            //if (this->getWidth() <= Util::getInstance()->getLogicalWindowWidth())
             //   this->moveRight();
            //else
                this->moveLeft();
        }
  //  if (this->getWidth() <= Util::getInstance()->getLogicalWindowWidth())
        cout << this->left_border << endl;

}

void Layer::setMovement(string move) {
    movement = move;
}
