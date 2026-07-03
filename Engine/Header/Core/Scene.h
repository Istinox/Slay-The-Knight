#pragma once
#include <string>
#include <vector>
#include "Core/GameObject.h"

class Scene
{
protected:
	std::string sceneName;
	std::vector<GameObject*> gameObjects;
public:
	Scene(std::string name);
	virtual ~Scene();

	virtual void OnEnter() = 0;
	virtual void OnExit();

	virtual void Start();
	virtual void Update(float dt);
	virtual void Render(sf::RenderWindow& window);

	std::string getName() { return sceneName; }

	GameObject* findByTag(std::string name);

	template <typename T, typename... Params>
	T* CreateGameObject(std::string name = "???", Params... parameters)
	{
		T* gameObject = new T(parameters...);
		gameObject->setName(name);
		gameObjects.push_back(gameObject);
		return gameObject;
	}
};

