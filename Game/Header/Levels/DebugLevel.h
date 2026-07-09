#pragma once
#include "Scene.h"
#include "GameObject.h"
#include "SpriteRenderer.h"
#include "InputComponent.h"
#include "InputComponent.h"
#include "CollisionComponent.h"
#include "TextComponent.h"
#include <SoundComponent.h>

class DebugLevel : public Scene
{
public:
	DebugLevel() : Scene("Debug Level") {};

	void OnEnter() override; // On crée les GameObjects ici.
	void OnExit() override; // On détruit tout ici.

	void Start() override;
	void Update(float dt) override;
	void Render(sf::RenderWindow& window) override;

private:
	GameObject* CreateGameObject();
};
