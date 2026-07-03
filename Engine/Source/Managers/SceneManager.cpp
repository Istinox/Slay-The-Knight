#include "Managers/SceneManager.h"

SceneManager* SceneManager::sceneManager;

SceneManager* SceneManager::getSceneManager()
{
    if (sceneManager == nullptr)
    {
        sceneManager = new SceneManager();
    }
    return sceneManager;
}

void SceneManager::setScene(Scene* scene) {
    if (currentScene != nullptr) {
        scene->OnExit();
    }
    currentScene = scene;
    hasStartedScene = false;
    scene->OnEnter();
}