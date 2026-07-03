#include "GameObjects/EnemyKnight.h"

EnemyKnight::EnemyKnight(const std::string& texturePath)
{
	createComponent<Transform>(500.f, 200.f);
	spriteRenderer = createComponent<SpriteRenderer>(texturePath);
	animationComponent = createComponent<AnimationComponent>();
	collisionComponent = createComponent<CollisionComponent>(sf::Vector2f(75.f, 75.f), sf::Color::Red, 1.f);
	rigidBody = createComponent<RigidBody>();

	collisionComponent->setCollisionType(CollisionType::Enemy);
}
