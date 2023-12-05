#include "Platform.h"


using namespace std;


    Platform* Platform::getInstance(int x, int y, int w, int h, bool collision = false){
        return new Platform(x,y,w,h,collision);
    };

    void Platform::draw() const {
        SDL_RenderCopy(sys.get_ren(), texture, NULL, &getRect());
    };

    void tick(){};

    Platform::~Platform(){};

    Platform::Platform(int x, int y, int w, int h, bool collision = false) : Component (x, y, w, h, collision) {
        texture = IMG_LoadTexture(sys.get_ren(), (constants::gResPath + "images/platform.jpg").c_str());
    }; 

