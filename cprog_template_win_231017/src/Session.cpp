#include <SDL2/SDL.h>
#include <iostream>
#include "Session.h"
#include "System.h"
#include "SceneManager.h"

std::shared_ptr<Session> Session::getInstance(std::string name, void (*build)())
{
	return std::shared_ptr<Session>(new Session(name, build));
}

Session::Session(std::string name, void (*build)())
{
	this->name = name;
	this->build = build;
}

Session::~Session()
{
}

void Session::add(std::shared_ptr<Component> comp)
{
	added.push_back(comp);
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
	quit = true;
	manager->pop();
}

void Session::run()
{
	build();
	quit = false;
	cleared = false;
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
				exit();
				break;
			} // switch
		}	  // inre while event while

		collisionLoop();

		for (std::shared_ptr<Component> c : components)
			c->tick();

		for (std::shared_ptr<Component> c : added)
			components.push_back(c);
		added.clear();

		deleteComponentsInVector();

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
	if (!cleared)
	{
		unLoadScene();
	}

	// load nästa scen om det finns queud
	// här kördes koden som nu finns i unLoadScene()
	// det som fanns utanför while loopen kördes inte flrens programmet avslutades.
	// därför flyttades den avslutande koden till en metod som kallas på av scenemanager innan den laddar in nästa scen
}

void Session::unLoadScene()
{
	for (std::shared_ptr<Component> c : components)
	{
		remove(c); // lägger till alla komponenter för att tas bort
	}
	deleteComponentsInVector();
	removed.clear();
	cleared = true;
	Component::resetCounts(); // ser till att komponent räknaren rensas, blir inte fel utan den men kanske lättare att se vad som skapats under denna session
	std::cout << "unload scene! " + name << std::endl;
}
void Session::deleteComponentsInVector() // går igenom komponenterna som ska tas bort
{
	for (std::shared_ptr<Component> c : removed)
	{
		for (std::vector<std::shared_ptr<Component>>::iterator i = components.begin();
			 i != components.end();)
		{
			if (*i == c)
			{
				i = components.erase(i);
			}
			else
			{
				i++;
			}
		}
	}
}

std::string Session::getName()
{
	return name;
}