#ifndef COMPONENT_H
#define COMPONENT_H
#include <SDL2/SDL.h>

namespace engine
{
	class Component
	{
	public:
		virtual void mouseUp(const SDL_Event &eve) {}
		virtual void mouseDown(const SDL_Event &eve) {}
		virtual void keyUp(const SDL_Event &eve) {}
		virtual void keyDown(const SDL_Event &eve) {}
		virtual void draw() const = 0;
		const SDL_Rect &getRect() const { return rect; }
		void setRect(const SDL_Rect &newRect);
		virtual void tick() = 0;

		bool getCollision();
		virtual void onCollision(Component *c) {}
		bool isCollider() { return collision; }

	protected:
		Component(int x, int y, int w, int h, bool c);
		Component(int x, int y, int w, int h);

	private:
		SDL_Rect rect;
		Component(const Component &) = delete;
		const Component &operator=(const Component &) = delete;
		bool collision;
	};
}
#endif
