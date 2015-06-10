//
// Created by mauri on 08/06/15.
//

#ifndef MORTALKOMBAT_TALLER1C2015_COMBOBUTTONSVIEW_H
#define MORTALKOMBAT_TALLER1C2015_COMBOBUTTONSVIEW_H
#include "stage/ImageSprite.h"
#include "ComboButtonsView.h"
#include "Position.h"
#include "../model/util/Timer.h"

typedef std::map<std::string, ImageSprite*> ButtonSpriteMap;

class ComboButtonsView {
public:
    ~ComboButtonsView();
    void draw();
    void addButton(Events button);
    static ComboButtonsView* getInstance();
    void init(SDL_Renderer* renderer);
    void activate();
    void deactivate();
    void comboDetected(std::vector<Events>* comboBuffer, int errorIndex);
    Timer* timer;

private:
    ComboButtonsView();
    static ComboButtonsView* instance;
    ButtonSpriteMap buttonSprites;
    std::vector<ImageSprite*> buffer;
    std::vector<Position> positions;
    std::vector<int> selectedButtons;
    bool activated;
    bool highLightingCombo;

    void shiftPositions();

    Timer *comboShowTimer;

};


#endif //MORTALKOMBAT_TALLER1C2015_COMBOBUTTONSVIEW_H
