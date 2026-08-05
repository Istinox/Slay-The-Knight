#pragma once
#include "Core/Component.h"
#include "Core/GameObject.h"
#include "CollisionComponent.h"

// Component principalement utilisé (dans ce cas précis) 
// pour gérer le comportement des GameObjects en cas de collision.

class RigidBody : public Component
{
public:
	void OnCollision(GameObject* other) override;
	std::pair<float, float> computeOverlap(GameObject* other);
};

