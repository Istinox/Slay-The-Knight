#pragma once
#include "Core/Scene.h"

class SceneManager
{
private:
    static SceneManager* sceneManager;
    Scene* currentScene = nullptr;
    bool hasStartedScene = false;
public:
    static SceneManager* getSceneManager();
    void setScene(Scene* scene);

    Scene* getCurrentScene() {
        return currentScene;
    }

    bool getHasStartedScene() {
        return hasStartedScene;
    }

    void setHasStartedScene(bool state) {
        hasStartedScene = state;
    }

};

