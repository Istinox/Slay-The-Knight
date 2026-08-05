#include "Level1.h"

void Level1::OnEnter()
{
    std::string backgroundFilePath = "Assets/Backgrounds/map_level1.png";
    std::string characterFilePath = "Assets/placeholder_chr.png";
    std::string knightIdleFilePath = "Assets/Warrior/Warrior_Idle.png";
    std::string archerIdleFilePath = "Assets/Archer/Archer_Idle.png";

    background = CreateGameObject<Background>("background", backgroundFilePath);
    player = CreateGameObject<Player>("Player", knightIdleFilePath, 300.f);
    enemyKnight = CreateGameObject<EnemyKnight>("EnemyKnight", knightIdleFilePath);
    archer = CreateGameObject<Enemy>("Archer", archerIdleFilePath, sf::Vector2f({200.f, 200.f}));

    // Creation des collisionBox

    GameObject* houseCollision = CreateCollisionBox({ 1570.f, 120.f }, { 110.f, 120.f }, CollisionType::Wall);
    GameObject* houseTwoCollision = CreateCollisionBox({ 800.f, -200.f }, { 110.f, 120.f }, CollisionType::Wall);
    GameObject* WorldBorderUp = CreateCollisionBox({ 660.f, -310.f }, { 2500.f, 20.f }, CollisionType::WindowBorder);
    GameObject* WorldBorderDown = CreateCollisionBox({ 660.f, 1100.f }, { 2500.f, 20.f }, CollisionType::WindowBorder);
    GameObject* WorldBorderLeft = CreateCollisionBox({ -610.f, 400.f }, { 20.f, 1390.f }, CollisionType::WindowBorder);
    GameObject* WorldBorderRight = CreateCollisionBox({ 1900.f, 400.f }, { 20.f, 1390.f }, CollisionType::WindowBorder);
}

// Pour éviter les gros blocs de code.
GameObject* Level1::CreateCollisionBox(const sf::Vector2f& position, const sf::Vector2f& size, CollisionType type)
{
    GameObject* gameObject = CreateGameObject<GameObject>();

    gameObject->createComponent<Transform>(position.x, position.y);
    gameObject->createComponent<CollisionComponent>(size, sf::Color::Red, 1.f);
    gameObject->createComponent<RigidBody>();

    gameObject->getComponent<CollisionComponent>()->setCollisionType(type);

    return gameObject;
}
