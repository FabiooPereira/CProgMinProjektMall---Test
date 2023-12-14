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
    static Session *currentSession;
    SceneManager();
    static SceneManager *getInstance();
    ~SceneManager();

    void createScene(std::string namn, void (*build)());
    // void addScene(Session session, void(*build)());
    void loadScene(std::string name);
    // void runCurrentScene();
    Session *getScene(std::string namn);
    // void play
    void printScenes();
    void moveSceneToPosition(Session *scene);
};
extern SceneManager *manager;
#endif
