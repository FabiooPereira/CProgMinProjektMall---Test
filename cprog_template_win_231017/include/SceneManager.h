#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H
#include <vector>
#include "Session.h"
#include <map>
#include <queue>
class SceneManager
{
private:
    std::vector<Session *> sessions;
    std::queue<Session *> q;

public:
    static std::string currentScene;
    SceneManager();
    static SceneManager *getInstance();
    ~SceneManager();
    bool isQueueEmpty() { return q.empty(); }
    void runNext();
    void createScene(std::string name, void (*build)());
    void loadScene(std::string name);
    Session *getScene(std::string namn);
    // void play
    void printScenes();
    void moveSceneToPosition(Session *scene, int index);
};
extern SceneManager *manager;
#endif
