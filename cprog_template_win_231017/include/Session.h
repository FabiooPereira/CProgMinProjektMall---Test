#ifndef SESSION_H
#define SESSION_H

#include "Component.h"
#include <vector>

class Session
{
public:
	Session();
	~Session();
	void add(Component *comp);
	void remove(Component *comp);
	void run();

private:
	std::vector<Component *> comps;
	std::vector<Component *> added, removed;
};

#endif