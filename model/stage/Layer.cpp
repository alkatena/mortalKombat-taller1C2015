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
    this->init();
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
        if ( this->left_border >= speed  )
            this->left_border -= speed;

    extern logger* Mylog;
    char mensaje[200] = "";
    strcpy(mensaje, "capa ");
    strcat(mensaje, this->getPath().c_str());
    strcat(mensaje, " se mueve. Nueva posicion: %1.2f");
    sprintf(mensaje, mensaje, left_border);
    Mylog->Log(mensaje, ERROR_LEVEL_INFO);
}

void Layer::moveRight() {

    if ( this->getWidth() > Util::getInstance()->getLogicalWindowWidth() ) {
        if (this->left_border + Util::getInstance()->getLogicalWindowWidth() < this->getWidth())
            this->left_border += speed;
    }
    else {
        if (this->left_border + this->getWidth() < Util::getInstance()->getLogicalWindowWidth())
            this->left_border += speed;
    }
    extern logger* Mylog;
    char mensaje[200] = "";
    strcpy(mensaje, "capa ");
    strcat(mensaje, this->getPath().c_str());
    strcat(mensaje, " se mueve. Nueva posicion: %1.2f");
    sprintf(mensaje, mensaje, left_border);
    Mylog->Log(mensaje, ERROR_LEVEL_INFO);
}

void Layer::update() {
        if (movement == "RIGHT") {
                this->moveRight();
        }
        else if (movement == "LEFT") {
                this->moveLeft();
        }

}

void Layer::setMovement(string move) {
    movement = move;
}

void Layer::init() {
    this->left_border = (this->width - Util::getInstance()->getLogicalWindowWidth()) /2;

    this->speed =  ((this->getWidth() - Util::getInstance()->getLogicalWindowWidth()) / Util::getInstance()->getLogicalStageWidth()) * 5;
    if (this->width <= Util::getInstance()->getLogicalWindowWidth()) {
        this->left_border = (Util::getInstance()->getLogicalWindowWidth() - this->width) / 2;
        this->speed =  ((Util::getInstance()->getLogicalWindowWidth() - this->getWidth()) / Util::getInstance()->getLogicalStageWidth()) * 5;

    }
}
