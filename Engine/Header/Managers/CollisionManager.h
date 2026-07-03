#pragma once
#include <vector>
#include "Components/CollisionComponent.h"
#include "CollisionType.h"

class CollisionComponent;

class CollisionManager
{
private:
	static std::vector<CollisionComponent*> colliders;
    static float overlapX;
    static float overlapY;

    static const int MAX_LAYER = 6;
public:
    static bool shouldCollide(CollisionComponent colliderA, CollisionComponent colliderB);
    static bool checkCollisionAABB(sf::FloatRect colliderA, sf::FloatRect colliderB);
    static void handleCollision();
    static std::vector<CollisionComponent*>& getCollidersVector();

    float getOverlapX() { return overlapX; }
    float getOverlapY() { return overlapY; }
};