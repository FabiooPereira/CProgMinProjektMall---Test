#include "SceneManager.h"
#include "Session.h"

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
    sessions.push_back(Session(name, build));
}
Session SceneManager::getScene(std::string name)
{
    for (auto s : sessions)
    {
        if (s.getName() == name)
        {
            return s;
        }
    }
    throw std::runtime_error("Ingen scene hittades");
}
void SceneManager::loadScene(std::string name)
{
    getScene(name).build();
    getScene(name).run();
}
SceneManager::~SceneManager(){
    
}
SceneManager *manager = SceneManager::getInstance();