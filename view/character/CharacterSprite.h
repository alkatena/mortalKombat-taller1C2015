#ifndef MKSPRITE_H_
#define MKSPRITE_H_

#include <iostream>
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

using namespace std;

class CharacterSprite
{
public:
    CharacterSprite(SDL_Renderer* passed_renderer, string FilePath, int x, int y, int w, int h, int frames);

    ~CharacterSprite(void);
    void Draw();

    void Play(int BeginFrame, int EndFrame, float Speed);
    void WalkBack(int BeginFrame, int EndFrame, float Speed);
    int getX();
    void setX(int passedX);
    void reset();

private:

    SDL_Texture* texture;
    SDL_Rect draw;

    SDL_Rect crop;

    int img_width;
    int img_height;
    int CurrentFrame;
    int animationDelay;

    int framesX;

    SDL_Renderer* renderer;
};

#endif /* MKSPRITE_H_ */
