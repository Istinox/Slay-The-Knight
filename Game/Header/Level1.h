#pragma once
#include "Core/Scene.h"
#include "Core/GameObject.h"
#include "Managers/CollisionManager.h"

#include "Components/SpriteRenderer.h"
#include "Components/AnimationComponent.h"
#include "Components/InputComponent.h"
#include "Components/CollisionComponent.h"
#include "Components/ShaderComponent.h"
#include "Components/CameraComponent.h"
#include "Components/ShapeComponent.h"

#include "Components/PlayerController.h"
#include "GameObjects/Background.h"
#include "GameObjects/Player.h"
#include "GameObjects/EnemyKnight.h"
#include <GameObjects/Enemy.h>
#include "GameObjects/Camera.h"

class Level1 : public Scene
{
private:
	Background* background = nullptr;
	Player* player = nullptr;
	EnemyKnight* enemyKnight = nullptr;
	Camera* camera = nullptr;
	Enemy* archer = nullptr;
public:
	Level1() : Scene("Level 1") {};

	void OnEnter() override; 

	GameObject* CreateCollisionBox(const sf::Vector2f& position, const sf::Vector2f& size, CollisionType type);
};
