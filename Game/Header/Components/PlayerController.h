#pragma once
#include "Core/GameObject.h"
#include "Core/Component.h"
#include "Modules/InputModule.h"

class PlayerController : public Component
{
private:
	float speed;
	bool isRunning = false;
	bool isWalking = false;
	bool isAttacking = false;
public:
	PlayerController(float spd) {
		speed = spd;
	}

	void Update(float dt) override;
	void SetSpeed(float value) { speed = value; }
};

