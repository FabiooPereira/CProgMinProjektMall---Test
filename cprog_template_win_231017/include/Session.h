#ifndef SESSION_H
#define SESSION_H

#include "Component.h"
#include <vector>
#include <string>
#include <memory>

namespace engine
{
	class Session
	{
	public:
		static std::shared_ptr<Session> getInstance(std::string name, void (*build)());
		~Session();
		void add(std::shared_ptr<Component> comp);
		void remove(std::shared_ptr<Component> comp);
		void run();

		Session& operator =(Session& other) = delete;

		void exit();
		void deleteComponentsInVector();

		const std::vector<std::shared_ptr<Component>> getComps() const { return components; }

		std::string getName();
		void unLoadScene();

	private:
		void (*build)();
		Session(std::string name, void (*build)());

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