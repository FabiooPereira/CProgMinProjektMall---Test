#ifndef SESSION_H
#define SESSION_H

#include <vector>
#include "Component.h"
#include <memory>
class Session
{
public:
	Session(std::string name, void (*build)());
	~Session();
	void add(std::shared_ptr<Component> comp);
	void remove(std::shared_ptr<Component> comp);
	void run();
	// const std::vector<std::shared_ptr<Component>> getMovables() const
	// {
	// 	return colliders;
	// }
	void exit();
	void deleteComponentsInVector();
	std::vector<std::shared_ptr<Component>> components;
	std::string getName();
	void (*build)();

private:
	std::vector<std::shared_ptr<Component>> added, removed;
	// std::vector<std::shared_ptr<Component>> colliders;
	std::string name;
	
	void checkCollision(std::shared_ptr<Component> collider);
	void collisionLoop();
	bool quit;
};
// extern Session startScreen;
// extern Session ses;
// extern Session gameoverScreen;

#endif