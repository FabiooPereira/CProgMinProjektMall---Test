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

void SceneManager::deleteScene(std::string name)
{
    auto iteratorToRemove = std::find(sessions.begin(), sessions.end(), getScene(name));
    if (iteratorToRemove != sessions.end())
    {
        sessions.erase(iteratorToRemove);
    }
}

std::shared_ptr<Session> SceneManager::getScene(std::string name)
{
    for (auto s : sessions)
    {
        if (s->getName() == name)
        {
            return s;
        }
    }
    throw std::runtime_error("No scene named: " + name + " was found");
}
void SceneManager::loadScene(std::string name)
{
    if (!currentScene.empty()) // när programmet startas är currentScene tom
    {
        getScene(currentScene)->exit();
    }
    q.push(getScene(name));
    currentScene = name;
}

void SceneManager::runNext()
{
    q.front()->run();
}
SceneManager::~SceneManager()
{
}

const void SceneManager::printScenes() const
{
    for (std::shared_ptr<Session> s : sessions)
        std::cout << s << std::endl;
}

SceneManager *manager = SceneManager::getInstance();