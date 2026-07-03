#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
#include "Managers/ResourceManager.h"

#define RED "\033[31m" // Pour les erreurs.
#define GRAY "\033[90m" // Pour les infos de debug.
#define RESET_COLOR "\033[0m"

class GameObject;

class Component
{
protected:
	GameObject* owner = nullptr;
public:
	virtual ~Component() = default;

	virtual void Start() {};
	virtual void Render(sf::RenderWindow& window) {};
	virtual void Update(float dt) {};

	void SetOwner(GameObject* owner);
	GameObject* GetOwner();

	virtual void OnCollision(GameObject* other) {};
};

