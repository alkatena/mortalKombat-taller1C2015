//
// Created by mauri on 12/05/15.
//

#include "../model/json/json.h"
#include "Text.h"
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include "../model/util/Util.h"
using namespace std;

Text::Text(const char* text, SDL_Renderer *renderer, string position) {
    this->renderer = renderer;
    this->text = text;
    this->initText(position, {255, 255, 255});
}

Text::Text(const char *text, SDL_Renderer *renderer, string position, SDL_Color colour) {
    this->renderer = renderer;
    this->text = text;
    this->initText(position, colour);}

void Text::initText(string position, SDL_Color colour) {
    if( TTF_Init() == -1 ) {
        printf( "SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError() );
    }
    //Open the font

    TTF_Font* font = TTF_OpenFont("data/Fonts/mortalkombat3.ttf", 20);
    if (font == NULL) {
        cout << "No se pudo carga la tipografía." << endl;
    }

    //We need to first render to a surface as that's what TTF_RenderText
    //returns, then load that surface into a texture
    //SDL_Color colour = { 255, 255, 255 };

    SDL_Surface *surface = TTF_RenderText_Blended(font, this->text, colour);
    if (surface == NULL){
        TTF_CloseFont(font);
    }
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    if (texture == NULL){
        cout << "No se pudo cargar la textura." << endl;
    }

    this->textTexture = texture;
    this->draw.y = 5;
    this->draw.w = surface->w;
    this->draw.h = surface->h;

    if (position == "left")
        this->draw.x = 5;
    else if (position == "right")
        this->draw.x = Util::getInstance()->getLogicalWindowWidth() * Util::getInstance()->getScalingConstant() - surface->w - 5;
    else {
        this->draw.x = Util::getInstance()->getLogicalWindowWidth() * Util::getInstance()->getScalingConstant()/2 - surface->w;
        this->draw.h = surface->h*2;
        this->draw.w = surface->w*2;
        this->draw.y = 2;
    }
    SDL_FreeSurface(surface);
    TTF_CloseFont(font);
}

Text::~Text(){
    SDL_DestroyTexture(this->textTexture);
}

void Text::Draw() {
    SDL_RenderCopy(this->renderer, this->textTexture, NULL, &draw);
}

void Text::update(const char* text) {
    this->text = text;
    SDL_DestroyTexture(this->textTexture);
    this->initText("center", {255, 255, 255});
}

void Text::setPosition(int x, int y) {
    this->draw.x = x;
    this->draw.y = y;
}

int Text::getWidth() {
    return this->draw.w;
}


void Text::setDimensions(int width, int height) {
    this->draw.w = width;
    this->draw.h = height;
}

int Text::getHeight() {
    return this->draw.h;
}
