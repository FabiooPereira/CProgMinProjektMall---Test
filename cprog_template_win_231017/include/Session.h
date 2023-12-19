#ifndef SESSION_H
#define SESSION_H

#include <vector>
#include "Component.h"
#include <memory>
namespace engine
{
	class Session
	{
	public:
		static std::shared_ptr<Session> getInstance(std::string name, void (*build)());
		Session(std::string name, void (*build)());
		~Session();
		void add(std::shared_ptr<Component> comp);
		void remove(std::shared_ptr<Component> comp);
		void run();

		void exit();
		void deleteComponentsInVector();

		const std::vector<std::shared_ptr<Component>> getComps() const { return components; }

		std::string getName();
		void (*build)();
		void unLoadScene();

	private:
		std::vector<std::shared_ptr<Component>> components;
		std::vector<std::shared_ptr<Component>> added, removed;
		std::string name;

		void checkCollision(std::shared_ptr<Component> collider);
		void collisionLoop();
		bool quit;
		bool cleared = false;
	};
}
#endif