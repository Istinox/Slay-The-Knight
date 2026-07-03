#include "Managers/CollisionManager.h"

std::vector<CollisionComponent*> CollisionManager::colliders;

bool CollisionManager::shouldCollide(CollisionComponent colliderA, CollisionComponent colliderB)
{
    bool CollisionMatrix[MAX_LAYER][MAX_LAYER] = 
    {
        0, 0, 0, 0, 0, 0, // None
        0, 1, 1, 1, 1, 1, // Player
        0, 1, 1, 1, 1, 1, // Enemy
        0, 1, 1, 0, 0, 1, // Wall
        0, 1, 1, 0, 0, 1, // WindowBorder
        0, 1, 1, 1, 0, 0  // Bullet
    };

    int colliderTypeA = static_cast<int>(colliderA.getCollisionType());
    int colliderTypeB = static_cast<int>(colliderB.getCollisionType());

    if (!CollisionMatrix[colliderTypeA][colliderTypeB])
    {
        return false;
    }
    else {
        return true;
    }
}

bool CollisionManager::checkCollisionAABB(sf::FloatRect colliderA, sf::FloatRect colliderB)
{
    if ((colliderB.position.x >= colliderA.position.x + colliderA.size.x)
        || (colliderB.position.x + colliderB.size.x <= colliderA.position.x)
        || (colliderB.position.y >= colliderA.position.y + colliderA.size.y)
        || (colliderB.position.y + colliderB.size.y <= colliderA.position.y))
        return false;
    else {
        return true;
    }
}

void CollisionManager::handleCollision()
{
    for (CollisionComponent* colliderA : colliders)
    {
        for (CollisionComponent* colliderB : colliders)
        {
            if (!shouldCollide(*colliderA, *colliderB)) continue;

            if (colliderA == colliderB) continue;

            if (checkCollisionAABB(colliderA->getCollisionBox(), colliderB->getCollisionBox())) {
                colliderA->GetOwner()->OnCollision(colliderB->GetOwner());
                colliderB->GetOwner()->OnCollision(colliderA->GetOwner());
            }
        }
    }
}

std::vector<CollisionComponent*>& CollisionManager::getCollidersVector()
{
    return colliders;
}
