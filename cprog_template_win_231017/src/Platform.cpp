#include "Platform.h"


using namespace std;


    Platform* Platform::getInstance(int x, int y, int w, int h, bool collision){
        return new Platform(x,y,w,h,collision);
    };

    void Platform::draw() const {
        SDL_RenderCopy(sys.get_ren(), texture, NULL, &getRect());
    };

    void Platform::tick(){

    };

    Platform::~Platform(){};

    Platform::Platform(int x, int y, int w, int h, bool collision) : Component (x, y, w, h, collision) {
        texture = IMG_LoadTexture(sys.get_ren(), (constants::gResPath + "images/Platform.png").c_str());
    }; 

