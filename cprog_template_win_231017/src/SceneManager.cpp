#include "SceneManager.h"
#include "Session.h"
#include "algorithm"

std::string SceneManager::currentScene = "";
SceneManager::SceneManager()
{
}
SceneManager *SceneManager::getInstance()
{
    static SceneManager instance;
    return &instance;
}

void SceneManager::createScene(std::string name, void (*build)())
{
    sessions.push_back(Session::getInstance(name, build));
}
Session *SceneManager::getScene(std::string name)
{
    for (auto s : sessions)
    {
        if (s->getName() == name)
        {
            return s;
        }
    }
    throw std::runtime_error("Ingen scene hittades");
}
void SceneManager::loadScene(std::string name)
{
    if (!currentScene.empty()) // när programmet startas är currentScene tom
    {
        getScene(currentScene)->unLoadScene(); // rensar scenen på komponenter
    }
    currentScene = name;
    getScene(name)->build(); // bygger scenene
    getScene(name)->run();   // startar nya scenens händelseloop
}
SceneManager::~SceneManager()
{
}
void SceneManager::printScenes()
{
    for (Session *s : sessions)
    {
        std::cout << s->getName() << std::endl;
    }
}
void SceneManager::moveSceneToPosition(Session *scene, int index)
{
    auto it = std::find(sessions.begin(), sessions.end(), scene);

    if (it != sessions.end() && index < sessions.size())
    {
        int currentIndex = std::distance(sessions.begin(), it);

        if (currentIndex != index)
            ;
        {
            sessions.erase(it);
            sessions.insert(sessions.begin() + index, scene);
        }
    }
    else
    {
        std::cerr << "Invalid session or position specified for moving the scene." << std::endl;
    }
}
SceneManager *manager = SceneManager::getInstance();