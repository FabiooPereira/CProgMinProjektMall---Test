#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H
#include <vector>
#include "Session.h"
#include <map>
class SceneManager
{
private:
    std::vector<Session *> sessions;

public:
    static std::string currentScene;
    SceneManager();
    static SceneManager *getInstance();
    ~SceneManager();

    void createScene(std::string namn, void (*build)());
    void loadScene(std::string name);
    Session *getScene(std::string namn);
    // void play
    void printScenes();
    void moveSceneToPosition(Session *scene);
};
extern SceneManager *manager;
#endif
