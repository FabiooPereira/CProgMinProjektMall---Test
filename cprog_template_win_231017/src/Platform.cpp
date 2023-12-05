#include <Platform.h>
#include <Component.h>


class Platform::Platform : public Component {
    public:
    static Platform* Platform::getInstance(int x, int y, int w, int h){};
    virtual void draw() const {};
    void tick(){};

    private:
    Platform(int x, int y, int w, int h); 

};