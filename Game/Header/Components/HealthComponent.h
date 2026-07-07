#pragma once
#include "Core\Component.h"
#include "Core\GameObject.h"

class HealthComponent : public Component
{
public:
	int health = 0;

	HealthComponent(int _health) {
		health = _health;
	}

	void Update(float dt) override;
};

