#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H
#include <vector>
#include "Session.h"
#include <map>
#include <queue>
namespace engine
{
    class SceneManager
    {
    private:
        std::vector<std::shared_ptr<Session>> sessions;
        std::queue<std::shared_ptr<Session>> q;
        static std::string currentScene;

    public:
        static const std::string getCurrentScene() { return currentScene; }

        SceneManager();
        static SceneManager *getInstance();
        ~SceneManager();
        bool isQueueEmpty() { return q.empty(); }
        void runNext();
        void createScene(std::string name, void (*build)());
        void loadScene(std::string name);

        const std::shared_ptr<Session> getScene(std::string name);

        void pop() { q.pop(); }
        void deleteScene(std::string name);

        const void printScenes() const;
    };
    extern SceneManager *manager;
}
#endif
