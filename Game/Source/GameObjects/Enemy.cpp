#include "GameObjects/Enemy.h"

Enemy::Enemy(std::string texturePath, sf::Vector2f position)
{
	transform = createComponent<Transform>(position.x, position.y);
	spriteRenderer = createComponent<SpriteRenderer>(texturePath);
	animationComponent = createComponent<AnimationComponent>();
	collisionComponent = createComponent<CollisionComponent>(sf::Vector2f(75.f, 75.f), sf::Color::Red, 1.f);
	rigidBody = createComponent<RigidBody>();
	healthComponent = createComponent<HealthComponent>(100);

	collisionComponent->setCollisionType(CollisionType::Enemy);
}
