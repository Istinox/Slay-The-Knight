#include "Core/Scene.h"

Scene::Scene(std::string name) { sceneName = name; }

Scene::~Scene()
{
	for (GameObject* gameObject : gameObjects) {
		delete gameObject;
	}
	gameObjects.clear();
}

void Scene::OnExit() {
    for (GameObject* gameObject : gameObjects) {
        delete gameObject;
    }
    gameObjects.clear();
}

void Scene::Start() {
    for (GameObject* gameObject : gameObjects) {
        gameObject->Start();
    }
}

void Scene::Update(float dt) {
    for (GameObject* gameObject : gameObjects) {
        gameObject->Update(dt);
    }
}

void Scene::Render(sf::RenderWindow& window) {
    for (GameObject* gameObject : gameObjects) {
        gameObject->Render(window);
    }
}

GameObject* Scene::findByTag(std::string name)
{
    for (GameObject* gameObject : gameObjects)
    {
        if (gameObject->getName() == name)
        {
            return gameObject;
        }
    }
    return nullptr;
}
