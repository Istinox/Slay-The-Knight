#pragma once
#include "Core/GameObject.h"
#include "Core/Component.h"
#include "Modules/InputModule.h"

class PlayerController : public Component
{
private:
	float speed;
public:
	PlayerController(float spd) {
		speed = spd;
	}

	void Update(float dt) override;
};

