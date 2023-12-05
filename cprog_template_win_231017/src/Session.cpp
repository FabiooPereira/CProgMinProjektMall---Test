#include "Session.h"
#include <SDL2/SDL.h>
// #include "Component.h"
#include "System.h"
#include <iostream>

using namespace std;

#define FPS 60

namespace engine
{
	Session::Session()
	{
	}

	Session::~Session()
	{
	}
	void Session::add(Component *comp)
	{
		added.push_back(comp);
		if (comp->isCollider())
			colliders.push_back(comp);
	}

	void Session::remove(Component *comp)
	{
		removed.push_back(comp);
	}

	void Session::checkCollision(Component *collider)
	{

		// for (Component* c : colliders)
		// {
		//     SDL_Rect rect2 = collider->getRect();
		//     if ((rect.x + rect.w) > rect2.x && rect.x < (rect2.x + rect2.w) && (rect.y + rect.h) > rect2.y && rect.y < (rect2.y + rect2.h))
		//         collider->onCollision(c);
		// }
		for (Component *c : colliders)
		{

			if (SDL_HasIntersection(&collider->getRect(), &c->getRect()) == SDL_TRUE && collider != c)
			{
				collider->onCollision(c);
			}
		}
	}

	void Session::collisionLoop()
	{
		for (auto c : colliders)
		{
			checkCollision(c);
		}
	}

	void Session::run()
	{
		bool quit = false;

		Uint32 tickInterval = 1000 / FPS;
		while (!quit)
		{
			Uint32 nextTick = SDL_GetTicks() + tickInterval;
			SDL_Event event;
			while (SDL_PollEvent(&event))
			{
				switch (event.type)
				{
				case SDL_MOUSEBUTTONUP:
					for (Component *c : comps)
						c->mouseUp(event);
					break;
				case SDL_MOUSEBUTTONDOWN:
					for (Component *c : comps)
						c->mouseDown(event);
					break;
				case SDL_KEYDOWN:
					for (Component *c : comps)
						c->keyDown(event);
					break;
				case SDL_QUIT:
					quit = true;
					break;
				} // switch
			}	  // inre while event while

			collisionLoop();

			for (Component *c : comps)
				c->tick();

			for (Component *c : added)
				comps.push_back(c);
			added.clear();

			for (Component *c : removed)
			{
				for (vector<Component *>::iterator i = comps.begin();
					 i != comps.end();)
				{
					if (*i == c)
					{
						i = comps.erase(i);
					}
					else
					{
						i++;
					}
				}
			}
			removed.clear();
			SDL_RenderClear(sys.get_ren());
			SDL_SetRenderDrawColor(sys.get_ren(), 100, 100, 100, 0);
			for (Component *c : comps)
				c->draw();
			SDL_RenderPresent(sys.get_ren());

			int delay = nextTick - SDL_GetTicks();
			if (delay > 0)
				SDL_Delay(delay);
		} // yttre while
	}
}