#include "SceneManager.h"
#include "Session.h"

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
        getScene(currentScene)->exit();
    }
    q.push(getScene(name));
    currentScene = name;

    // std::cout << "end of loadScene " + name << " and current scene is: " << currentScene << std::endl;
}

void SceneManager::runNext()
{
    q.front()->run();
}
SceneManager::~SceneManager()
{
}
SceneManager *manager = SceneManager::getInstance();