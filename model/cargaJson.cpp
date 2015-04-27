#include "CargaJson.h"

using namespace std;

bool cargaArchivoJSON(char* filename, float &charAncho, float &charAlto, float &stageWidth,
						float &stageHeight, float &floor, std::string &oponentSide,
						std::list<Layer*>* layers, int &z_index){

    extern logger* Mylog;
    char mensaje[200];
    strcpy(mensaje, "Intentando parsear archivo ");
    strcat(mensaje, filename);
    Mylog->Log(mensaje, ERROR_LEVEL_INFO);

    //verificar si existe filename
    if(!std::ifstream(filename)){
        strcpy(mensaje, "No existe el archivo ");
        strcat(mensaje, filename);
        Mylog->Log(mensaje, ERROR_LEVEL_ERROR);
        return false;
    }


	Json::Value root;   // will contains the root value after parsing.
	Json::Reader reader;
	std::ifstream test(filename, std::ifstream::binary);
	bool parsingSuccessful = reader.parse( test, root, false );
	if ( !parsingSuccessful )
	{
		//report to the user the failure and their locations in the document.
		Mylog->Log(reader.getFormatedErrorMessages().c_str(), ERROR_LEVEL_ERROR);
		return false;
	}


	Mylog->Log("----------Ventana-------", ERROR_LEVEL_INFO);

	if(root.isMember("ventana")){
        cargaVentana(root["ventana"]);
    }else{
        cargarVentanaPorDefault();
    }

    controlErroresVentana();

	Mylog->Log("----------Escenario-------", ERROR_LEVEL_INFO);
	stageWidth = 0.0;
	stageHeight = 0.0;
	floor = 0.0;

    const Json::Value escenarios = root["escenario"];

	if(root.isMember("escenario")){
        cargaEscenario(escenarios, stageWidth, stageHeight,floor);
	}else{
        cargaEscenarioPorDefault(stageWidth, stageHeight,floor);
	}

	controlErroresEscenario(stageWidth, stageHeight, floor);

    //*****************************

	Mylog->Log("----------Capas-------", ERROR_LEVEL_INFO);

    if(root.isMember("capas") && root["capas"].isArray()){
        const Json::Value capas = root["capas"];
        for ( unsigned int index = 0; index < capas.size(); ++index ){

            if(!capas[index].isMember("imagen_fondo") || !capas[index].isMember("ancho")){
                Mylog->Log("Archivo JSON invalido: capas mal formadas", ERROR_LEVEL_ERROR);
                break;
            }

            const char* filenameIMG = capas[index]["imagen_fondo"].asCString();

            //verificar si existe filename
            if(!std::ifstream(filenameIMG)){
                sprintf(mensaje, "No existe el archivo %s. Usando fileNotFound.png", filenameIMG);
                Mylog->Log(mensaje, ERROR_LEVEL_ERROR);
                filenameIMG = "data/fileNotFound.png";
            }

            float capaAncho = (capas[index].isMember("ancho") && capas[index]["ancho"].isNumeric()  && capas[index]["ancho"].asFloat()>0) ? capas[index]["ancho"].asFloat() : 0.0;


            if( capaAncho == 0.0){
            	capaAncho = ANCHOESCENARIO;
                   Mylog->Log("valor ancho de capa invalido: usando default", ERROR_LEVEL_WARNING);
               }

            strcpy(mensaje, "Capa ");
            strcat(mensaje, "%i");
            sprintf(mensaje, mensaje, index+1);
            strcat(mensaje, " imagen_fondo: ");
            strcat(mensaje, filenameIMG);
            strcat(mensaje, ", ancho: ");
            strcat(mensaje, capas[index]["ancho"].asString().c_str());

            Mylog->Log(mensaje, ERROR_LEVEL_INFO);

            Layer* aLayer = new Layer(capaAncho, filenameIMG);
            layers->push_back(aLayer);
        }

	}

    if(layers->empty()){//no hay capas en el archivo
        Mylog->Log("sin capas validas: usando default", ERROR_LEVEL_WARNING);

        Mylog->Log("Capa 1: imagen_fondo: data/stage2.jpg, ancho: 1280", ERROR_LEVEL_WARNING);
        Layer* aLayer = new Layer(1000, "data/bg_2.png");
        layers->push_back(aLayer);

        Mylog->Log("Capa 2: imagen_fondo: data/152.png, ancho: 266", ERROR_LEVEL_WARNING);
        Layer* subwayLayer = new Layer(600, "data/bg_1.png");
        layers->push_back(subwayLayer);
    }

	Mylog->Log("--------Personaje-------", ERROR_LEVEL_INFO);

	if(root.isMember("personaje") && root["personaje"].isArray()){
        const Json::Value personaje = root["personaje"];
        for ( unsigned int index = 0; index < personaje.size(); ++index ){
            cargaPersonaje(personaje[index], charAlto, charAncho, z_index);
        }
    }else{
        //CARGAR POR DEFAULT
    }


	Mylog->Log("--------oponente-------", ERROR_LEVEL_INFO);
	std::string side;
	const Json::Value oponente = root["oponente"];
	side = oponente["side"].asString();
	std::transform(side.begin(), side.end(),side.begin(), ::toupper);
	if (side == "LEFT")
	{
		oponentSide="LEFT";
		Mylog->Log("Lado Izquierdo", ERROR_LEVEL_INFO);
	}
	else if (side == "RIGHT")
	{
		oponentSide="RIGHT";
		Mylog->Log("Lado Derecho", ERROR_LEVEL_INFO);
	}
	else
	{
		Mylog->Log("Ubicacion del oponente invalida: usando default (RIGHT)", ERROR_LEVEL_WARNING);
		oponentSide="RIGHT";
	}

	Mylog->Log("Parseo completo", ERROR_LEVEL_INFO);
	return true;

}

void cargaPersonaje(Json::Value personaje, float &charAlto, float &charAncho, int &z_index){
    extern logger* Mylog;
    char mensaje[200];
    const char* filenameWalk = new char[200] ;
    const char* filenameStance = new char[200];
    const char* filenameJump = new char[200];
    const char* filenameSideJump = new char[200];

     charAlto = (personaje.isMember("alto") && personaje["alto"].isNumeric() && personaje["alto"].asFloat()>0) ?
                                                    personaje["alto"].asFloat() : 0.0;
     charAncho = (personaje.isMember("ancho") && personaje["ancho"].isNumeric() && personaje["ancho"].asFloat()>0) ?
                                                    personaje["ancho"].asFloat() : 0.0;
     z_index = (personaje.isMember("z-index") && personaje["z-index"].isInt() && personaje["z-index"].asInt()>0) ?
                                                        personaje["z-index"].asInt() : 0;

        if(personaje.isMember("sprites")){

            const Json::Value sprites = personaje["sprites"];


            if(!sprites.isMember("walk") || !sprites.isMember("stance")
                    || !sprites.isMember("jump") || !sprites.isMember("sideJump")){
                Mylog->Log("Archivo JSON invalido: capas mal formadas. Usando default", ERROR_LEVEL_ERROR);
                //CARGAR DEFAULT
                filenameWalk = strdup(DEFAULT_WALK);
                filenameStance = strdup(DEFAULT_STANCE);
                filenameJump = strdup(DEFAULT_JUMP);
                filenameSideJump = strdup(DEFAULT_SIDEJUMP);

            }else{
                filenameWalk = strdup(sprites["walk"].asString().c_str());
                filenameStance = strdup(sprites["stance"].asString().c_str());
                filenameJump = strdup(sprites["jump"].asString().c_str());
                filenameSideJump = strdup(sprites["sideJump"].asString().c_str());
            }

        }

    //verificar si existe filename
    if(!std::ifstream(filenameWalk)){
        sprintf(mensaje, "No existe el archivo %s. Usando archivo por defecto", filenameWalk);
        Mylog->Log(mensaje, ERROR_LEVEL_ERROR);
        filenameWalk = DEFAULT_WALK;
    }
    if(!std::ifstream(filenameStance)){
        sprintf(mensaje, "No existe el archivo %s. Usando archivo por defecto", filenameStance);
        Mylog->Log(mensaje, ERROR_LEVEL_ERROR);
        filenameWalk = DEFAULT_STANCE;
    }
    if(!std::ifstream(filenameJump)){
        sprintf(mensaje, "No existe el archivo %s. Usando archivo por defecto", filenameJump);
        Mylog->Log(mensaje, ERROR_LEVEL_ERROR);
        filenameWalk = DEFAULT_JUMP;
    }
    if(!std::ifstream(filenameSideJump)){
        sprintf(mensaje, "No existe el archivo %s. Usando archivo por defecto", filenameSideJump);
        Mylog->Log(mensaje, ERROR_LEVEL_ERROR);
        filenameWalk = DEFAULT_SIDEJUMP;
    }

    Util::getInstance()->setWalkStanceJumpSideJump(filenameWalk, filenameStance, filenameJump, filenameSideJump);


    if(charAlto == 0.0){
        charAlto  = ALTOPERSONAJE;
        Mylog->Log("valor alto del personaje invalido: usando default", ERROR_LEVEL_WARNING);
    }
    if(charAncho == 0.0){
        charAncho  = ANCHOPERSONAJE;
        Mylog->Log("valor ancho del personaje invalido: usando default", ERROR_LEVEL_WARNING);
    }
    if(z_index == 0){
    	z_index  = ZINDEXPERSONAJE;
        Mylog->Log("valor z-index del personaje invalido: usando default", ERROR_LEVEL_WARNING);
    }

    //log
    sprintf(mensaje, "Ancho: %1.2f, Alto: %1.2f, z-index: %i,\n Jump: %s, Walk: %s, Side jump: %s, Stance: %s",
                    charAncho, charAlto, z_index,
                    filenameJump, filenameWalk, filenameSideJump, filenameStance);

    Mylog->Log(mensaje, ERROR_LEVEL_INFO);

}


void cargaVentana(Json::Value ventana){
    Util::getInstance()->setWindowWidth( (ventana.isMember("ancho-px") && ventana["ancho-px"].isInt()  && ventana["ancho"].asInt()>0) ?
                                                        ventana["ancho-px"].asInt() : 0);
    Util::getInstance()->setWindowHeight( (ventana.isMember("alto-px") && ventana["alto-px"].isInt() && ventana["ancho"].asInt()>0) ?
                                                        ventana["alto-px"].asInt(): 0);
    Util::getInstance()->setLogicalWindowWidth( (ventana.isMember("ancho") && ventana["ancho"].isNumeric() && ventana["ancho"].asFloat()>0) ?
                                                        ventana["ancho"].asFloat() : 0.0);
}

void cargarVentanaPorDefault(){
    extern logger* Mylog;
    Mylog->Log("JSON invalido: falta nodo ventana. Usando default", ERROR_LEVEL_ERROR);
    Util::getInstance()->setWindowWidth(0);
    Util::getInstance()->setWindowHeight(0);
    Util::getInstance()->setLogicalWindowWidth(0.0);

}

void controlErroresVentana(){
    extern logger* Mylog;
    char mensaje[200];

        //control de errores ventana
        if( Util::getInstance()->getLogicalWindowWidth() == 0.0){
            Util::getInstance()->setLogicalWindowWidth(ANCHOVENTANAL);
            Mylog->Log("valor ancho logico de la ventana invalido: usando default", ERROR_LEVEL_WARNING);
        }
        if( Util::getInstance()->getWindowHeight() <= 0){
            Util::getInstance()->setWindowHeight(ALTOVENTANAPX);
            Mylog->Log("valor alto de la ventana invalido: usando default", ERROR_LEVEL_WARNING);
        }
        if( Util::getInstance()->getWindowWidth() <= 0){
            Util::getInstance()->setWindowWidth(ANCHOVENTANAPX);
            Mylog->Log("valor ancho de la ventana invalido: usando default", ERROR_LEVEL_WARNING);
        }
        sprintf(mensaje, "ancho-px: %i, alto px: %i, ancho: %1.2f",
                    Util::getInstance()->getWindowWidth(),
                    Util::getInstance()->getWindowHeight(),
                    Util::getInstance()->getLogicalWindowWidth()
        );
        Mylog->Log(mensaje, ERROR_LEVEL_INFO);
 }

	void cargaEscenario(Json::Value escenarios, float &stageWidth, float &stageHeight, float &floor){

        stageWidth = (escenarios.isMember("ancho") && escenarios["ancho"].isNumeric() && escenarios["ancho"].asFloat()>0) ?
                                                        escenarios["ancho"].asFloat() : 0.0;

        stageHeight = (escenarios.isMember("alto") && escenarios["alto"].isNumeric()  && escenarios["alto"].asFloat()>0 ) ?
                                                        escenarios["alto"].asFloat() : 0.0;

        floor = (escenarios.isMember("y-piso") && escenarios["y-piso"].isNumeric()  && escenarios["y-piso"].asFloat()>0 ) ?
                                                        escenarios["y-piso"].asFloat() : 0.0;

	}

	void cargaEscenarioPorDefault(float &stageWidth, float &stageHeight, float &floor){
        extern logger* Mylog;
        Mylog->Log("JSON invalido: falta nodo ventana. Usando default", ERROR_LEVEL_ERROR);

        stageWidth = 0.0 ;
        stageHeight = 0.0;
        floor = 0.0;
    }

void controlErroresEscenario(float &stageWidth, float &stageHeight, float &floor){
    extern logger* Mylog;
    char mensaje[200];
    //control de errores escenario
    if( stageWidth == 0.0){
        stageWidth = ANCHOESCENARIO;
        Mylog->Log("valor ancho de escenario invalido: usando default", ERROR_LEVEL_WARNING);
    }
    if( stageHeight <= 0){
        stageHeight = ALTOESCENARIO;
        Mylog->Log("valor alto de escenario invalido: usando default", ERROR_LEVEL_WARNING);
    }
    if( floor <= 0){
        floor = ALTURAPISOESCENARIO;
        Mylog->Log("valor altura piso invalido: usando default", ERROR_LEVEL_WARNING);
    }
    sprintf(mensaje, "ancho-px: %1.2f, alto-px: %1.2f, y-piso: %1.2f", stageWidth, stageHeight, floor);
    Mylog->Log(mensaje, ERROR_LEVEL_INFO);

    Util::getInstance()->setLogicalStageWidth(stageWidth);

    Util::getInstance()->setLogicalWindowHeight(stageHeight);

}


