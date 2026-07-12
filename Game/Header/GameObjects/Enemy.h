#pragma once
#include "Core\GameObject.h"
#include <Components/HealthComponent.h>
#include <Components/RigidBody.h>
#include <Components/CollisionComponent.h>
#include <Components/AnimationComponent.h>
#include <Components/SpriteRenderer.h>

class Enemy : public GameObject
{
private:
	Transform* transform;
	SpriteRenderer* spriteRenderer;
	AnimationComponent* animationComponent;
	CollisionComponent* collisionComponent;
	RigidBody* rigidBody;
	HealthComponent* healthComponent;
public:
	Enemy(std::string texturePath, sf::Vector2f position);
};

