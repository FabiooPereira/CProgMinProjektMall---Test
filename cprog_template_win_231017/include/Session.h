#ifndef SESSION_H
#define SESSION_H

#include <vector>
#include "Component.h"

class Session
{
public:
	Session();
	~Session();
	void add(Component *comp);
	void remove(Component *comp);
	void run();

	const std::vector<Component *> getMovables() const
	{
		return colliders;
	}

private:
	std::vector<Component *> components;
	std::vector<Component *> added, removed;
	std::vector<Component *> colliders;

	void checkCollision(Component *collider);
	void collisionLoop();
};
extern Session ses;
#endif