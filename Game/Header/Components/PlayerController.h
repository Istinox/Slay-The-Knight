#pragma once
#include "Core/GameObject.h"
#include "Core/Component.h"
#include "Modules/InputModule.h"
#include <Components/AnimationComponent.h>
#include <Components/HealthComponent.h>
#include "Components/SpriteRenderer.h"

class PlayerController : public Component
{
private:
	float speed;
	bool isRunning = false;
	bool isWalking = false;
	bool isAttacking = false;
	SpriteRenderer* spriteRenderer = nullptr;
public:
	PlayerController(float spd) {
		speed = spd;
	}

	void Update(float dt) override;
	void SetSpeed(float value) { speed = value; }
};

