#include "Components/RigidBody.h"

void RigidBody::OnCollision(GameObject* other)
{
	Transform* ownerTransform = owner->getComponent<Transform>();

	auto [overlapX, overlapY] = computeOverlap(other);

	if (overlapX < overlapY)
	{
		ownerTransform->setAxisX(ownerTransform->getPreviousPosition().x);
	}
	else if (overlapY < overlapX)
	{
		ownerTransform->setAxisY(ownerTransform->getPreviousPosition().y);
	}
	else
	{
		ownerTransform->setPosition(ownerTransform->getPreviousPosition());
	}

	//if (other->getName() == "EnemyKnight")
	//{
	//}
}

// Gestion des collisions AABB.
std::pair<float, float> RigidBody::computeOverlap(GameObject* other) {

    CollisionComponent* ownerCol = owner->getComponent<CollisionComponent>();
    float A_left = ownerCol->getCollisionBox().position.x;
    float A_right = ownerCol->getCollisionBox().position.x + ownerCol->getCollisionBox().size.x;
    float A_top = ownerCol->getCollisionBox().position.y;
    float A_bottom = ownerCol->getCollisionBox().position.y + ownerCol->getCollisionBox().size.y;

    CollisionComponent* otherCol = other->getComponent<CollisionComponent>();
    float B_left = otherCol->getCollisionBox().position.x;
    float B_right = otherCol->getCollisionBox().position.x + otherCol->getCollisionBox().size.x;
    float B_top = otherCol->getCollisionBox().position.y;
    float B_bottom = otherCol->getCollisionBox().position.y + otherCol->getCollisionBox().size.y;

    float overlapX = std::min(A_right, B_right) - std::max(A_left, B_left);
    float overlapY = std::min(A_bottom, B_bottom) - std::max(A_top, B_top);

    return { overlapX, overlapY };
}
