#pragma once
#include <Core/GameObject.h>
#include <Components/SpriteRenderer.h>
#include <Components/AnimationComponent.h>
#include <Components/CollisionComponent.h>
#include <Components/RigidBody.h>

class EnemyKnight : public GameObject
{
private:
	SpriteRenderer* spriteRenderer;
	AnimationComponent* animationComponent;
	CollisionComponent* collisionComponent;
	RigidBody* rigidBody;
public:
	EnemyKnight(const std::string& texturePath);
};

