#include <SDL2/SDL.h>
#include <iostream>
#include "Session.h"
#include "System.h"

#define FPS 60

Session::Session()
{
}

Session::~Session()
{
	// std::cout << "session destruct" << this << std::endl;
}

void Session::add(std::shared_ptr<Component> comp)
{
	added.push_back(comp);
	// if (comp->isCollider())
	// 	colliders.push_back(comp);
}

void Session::remove(std::shared_ptr<Component> comp)
{
	removed.push_back(comp);
}

void Session::checkCollision(std::shared_ptr<Component> collider)
{

	// SDL_Rect rect = collider->getRect();
	// for (Component *c : colliders)
	// {
	// 	SDL_Rect rect2 = c->getRect();
	// 	if (collider != c && (rect.x + rect.w) > rect2.x && rect.x < (rect2.x + rect2.w) && (rect.y + rect.h) > rect2.y && rect.y < (rect2.y + rect2.h))
	// 		collider->onCollision(c);
	// }
	for (std::shared_ptr<Component> c : components)
	{
		if (SDL_HasIntersection(&collider->getRect(), &c->getRect()) == SDL_TRUE && collider != c)
		{
			// std::cout << "collision!" << endl;
			collider->onCollision(c);
		}
	}
}

void Session::collisionLoop()
{
	for (auto c : components)
	{
		if (c->isCollider())
		{
			checkCollision(c);
		}
	}
}
void Session::exit()
{
	std::cout << "exit";
	quit = true;
}

void Session::run()
{
	quit = false;
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
				for (std::shared_ptr<Component> c : components)
					c->mouseUp(event);
				break;
			case SDL_MOUSEBUTTONDOWN:
				for (std::shared_ptr<Component> c : components)
					c->mouseDown(event);
				break;
			case SDL_KEYDOWN:
				for (std::shared_ptr<Component> c : components)
					c->keyDown(event);
				break;
			case SDL_QUIT:
				quit = true;
				std::cout << "quit pressed" << std::endl;
				break;
			} // switch
		}	  // inre while event while

		collisionLoop();

		for (std::shared_ptr<Component> c : components)
			c->tick();

		for (std::shared_ptr<Component> c : added)
			components.push_back(c);
		added.clear();

		// deleteComponentsInVector(colliders);

		deleteComponentsInVector(components);

		removed.clear();

		SDL_RenderClear(sys.get_ren());
		SDL_SetRenderDrawColor(sys.get_ren(), 100, 100, 100, 0);
		for (std::shared_ptr<Component> c : components)
			c->draw();
		SDL_RenderPresent(sys.get_ren());

		int delay = nextTick - SDL_GetTicks();
		if (delay > 0)
			SDL_Delay(delay);
	} // yttre while
	std::cout << "end of run() ";

	for (std::shared_ptr<Component> c : components)
	{
		remove(c);
	}

	// deleteComponentsInVector(colliders);

	deleteComponentsInVector(components);

	removed.clear();
}

void Session::deleteComponentsInVector(std::vector<std::shared_ptr<Component>> &vec)
{
	for (std::shared_ptr<Component> c : removed)
	{
		for (std::vector<std::shared_ptr<Component>>::iterator i = vec.begin();
			 i != vec.end();)
		{
			if (*i == c)
			{
				i = vec.erase(i);
			}
			else
			{
				i++;
			}
		}
	}
}

Session startScreen;
Session ses;
Session gameoverScreen;