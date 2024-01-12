#ifndef COMPONENT_H
#define COMPONENT_H

#include <SDL2/SDL.h>
#include <string>
#include <vector>
#include <memory>
#include <iostream>

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

		virtual void onCollision(std::shared_ptr<Component> c);
		bool isCollider() { return collider; }
		void move(const int x, const int y);

		static void printCounts();
		static void resetCounts();

	protected:
		Component(int x, int y, int w, int h, bool c);
		Component(int x, int y, int w, int h);
		virtual ~Component();

	private:
		SDL_Rect rect;
		Component(const Component &) = delete;
		Component &operator=(const Component &) = delete;
		bool collider;
		static int createCount;
		static int deleteCount;
		static int leftOverCount;
	};
}
#endif
