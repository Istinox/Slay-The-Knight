#pragma once
#include <Core/GameObject.h> 
#include <Components/PlayerController.h>
#include <Components/SpriteRenderer.h>
#include <Components/AnimationComponent.h>
#include <Components/CollisionComponent.h>
#include <Components/RigidBody.h>

class Player : public GameObject
{
private:
	float speed = 0.f;

	PlayerController* playerController;
	SpriteRenderer* spriteRenderer;
	AnimationComponent* animationComponent;
	CollisionComponent* collisionComponent;
	RigidBody* rigidBody;

public:
	Player(const std::string& texturePath, float spd);
};

