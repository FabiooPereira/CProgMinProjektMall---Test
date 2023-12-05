#include "Session.h"
#include <SDL2/SDL.h>
// #include "Component.h"
#include "System.h"

using namespace std;

#define FPS 60

Session::Session()
{
}

Session::~Session()
{
}
void Session::add(Component *comp)
{
	added.push_back(comp);
}

void Session::remove(Component *comp)
{
	removed.push_back(comp);
}

void Session::checkCollision(Component *collider)
{
}
void Session::collisionLoop()
{
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
		}	  // inre while

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