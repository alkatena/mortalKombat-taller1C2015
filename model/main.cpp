#include <iostream>
#include "Game.h"
#include "CargaJson.h"

using namespace std;

int main(int argc, char* argv[]) {

    int anchoPantalla;
    int altoPantalla;
    float stageWidth;
    float stageHeight;
    float charAncho;
    float charAlto;
    float floor;
    bool carga = cargaArchivoJSON(argv[1], anchoPantalla, altoPantalla, charAncho, charAlto, stageWidth, stageHeight, floor);

	if(!carga) {
        char* file = "Escenario.json";
        cargaArchivoJSON(file, anchoPantalla, altoPantalla, charAncho, charAlto, stageWidth, stageHeight, floor);
	}

    //Load layers
    list<Layer*>* layers = new list<Layer*>();

    Layer* aLayer = new Layer(1280, "data/stage2.jpg");
    layers->push_back(aLayer);

    Layer* subwayLayer = new Layer(266, "data/152.png");
    layers->push_back(subwayLayer);

    //Load stage
    Stage* stage = new Stage(layers, stageWidth, stageHeight, floor);

    cout << "ancho: " <<anchoPantalla << endl;
    cout << "alto: " <<altoPantalla << endl;

    Game* game = new Game(anchoPantalla, altoPantalla, charAncho, charAlto, stage);

	game->GameLoop();

	delete game;
    delete aLayer;
    delete subwayLayer;
    delete layers;
    delete stage;

	return 0;
}
