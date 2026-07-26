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
	healthComponent = createComponent<HealthComponent>(100);
	cameraComponent = createComponent<CameraComponent>(300.f, sf::FloatRect({ 640, 360 }, { 1280, 720 }));

	collisionComponent->setCollisionType(CollisionType::Player);

	animationComponent->AddAnimation("Idle", "Assets/Warrior/Warrior_Idle.png");
	animationComponent->AddAnimation("Walk", "Assets/Warrior/Warrior_Run.png");
	animationComponent->AddAnimation("Attack", "Assets/Warrior/Warrior_Attack1.png");
}
