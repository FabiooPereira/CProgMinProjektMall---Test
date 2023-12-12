#ifndef SESSION_H
#define SESSION_H

#include <vector>
#include "Component.h"
#include <memory>
class Session
{
public:
	Session();
	~Session();
	void add(std::shared_ptr<Component> comp);
	void remove(std::shared_ptr<Component> comp);
	void run();

	const std::vector<std::shared_ptr<Component>> getMovables() const
	{
		return colliders;
	}

private:
	std::vector<std::shared_ptr<Component>> components;
	std::vector<std::shared_ptr<Component>> added, removed;
	std::vector<std::shared_ptr<Component>> colliders;

	void checkCollision(std::shared_ptr<Component> collider);
	void collisionLoop();
};
extern Session ses;
#endif