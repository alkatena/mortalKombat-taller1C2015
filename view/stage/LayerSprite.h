#ifndef MORTALKOMBAT_TALLER1C2015_LAYERSPRITE_H
#define MORTALKOMBAT_TALLER1C2015_LAYERSPRITE_H

#include <iostream>
#include <SDL2/SDL_render.h>
#include <math.h>
#include <SDL2/SDL_image.h>

using namespace std;

class LayerSprite {

public:
    LayerSprite(SDL_Renderer* passed_renderer, string FilePath, float screenWidth, float screenHeight);
    ~LayerSprite();
    void Draw();
    void update(float);
    float getCropWidthRelation();

private:
    SDL_Renderer* renderer;
    SDL_Texture* texture;
    SDL_Rect draw;

    SDL_Rect crop;
    int img_width;
    int img_height;
};


#endif //MORTALKOMBAT_TALLER1C2015_LAYERSPRITE_H
