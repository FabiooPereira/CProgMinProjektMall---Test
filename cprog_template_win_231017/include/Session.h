#ifndef SESSION_H
#define SESSION_H

#include "Component.h"
#include <vector>

namespace engine
{
	class Session
	{
	public:
		Session();
		~Session();
		void add(Component *comp);
		void remove(Component *comp);
		void run();
		std::vector<Component *> colliders;
		

	private:
		std::vector<Component *> comps;
		std::vector<Component *> added, removed;

		void checkCollision(Component *collider);
		void collisionLoop();
	};
}
#endif