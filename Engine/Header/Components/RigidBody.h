#pragma once
#include "Core/Component.h"
#include "CollisionComponent.h"

class RigidBody : public Component
{
public:
	void OnCollision(GameObject* other) override;
	std::pair<float, float> computeOverlap(GameObject* other);
};

