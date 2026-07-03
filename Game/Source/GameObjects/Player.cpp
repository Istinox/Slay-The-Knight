#include "GameObjects/Player.h"

Player::Player(const std::string& texturePath, float spd)
{
	speed = spd;

	createComponent<Transform>(1280.f / 2.f, 720.f / 2.f);
	playerController = createComponent<PlayerController>(speed);
	spriteRenderer = createComponent<SpriteRenderer>(texturePath);
	animationComponent = createComponent<AnimationComponent>();
	collisionComponent = createComponent<CollisionComponent>(sf::Vector2f(75.f, 75.f), sf::Color::Red, 1.f);
	rigidBody = createComponent<RigidBody>();

	collisionComponent->setCollisionType(CollisionType::Player);
}
