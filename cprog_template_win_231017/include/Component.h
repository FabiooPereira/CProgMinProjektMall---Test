#ifndef COMPONENT_H
#define COMPONENT_H
#include <SDL2/SDL.h>

class Component
{
public:
	virtual void mouseUp(const SDL_Event &eve) {}
	virtual void mouseDown(const SDL_Event &eve) {}
	virtual void draw() const = 0;
	const SDL_Rect &getRect() const { return rect; }
	virtual void tick() = 0;

protected:
	Component(int x, int y, int w, int h);

private:
	SDL_Rect rect;
	Component(const Component &) = delete;
	const Component &operator=(const Component &) = delete;
};

#endif
