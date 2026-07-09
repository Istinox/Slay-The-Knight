#include "Levels/Level1.h"

void Level1::OnEnter()
{
    const int windowWidth = 1280;
    const int windowHeight = 720;

    std::string backgroundFilePath = "Assets/Backgrounds/background.png";
    std::string characterFilePath = "Assets/placeholder_chr.png";
    std::string knightIdleFilePath = "Assets/Warrior/Warrior_Idle.png";

    background = CreateGameObject<Background>("background", backgroundFilePath);
    player = CreateGameObject<Player>("Player", knightIdleFilePath, 200.f);
    enemyKnight = CreateGameObject<EnemyKnight>("EnemyKnight", knightIdleFilePath);
    camera = CreateGameObject<Camera>("Camera", 300.f, sf::FloatRect({ 640, 360 }, { 1280, 720 })); // 854x480 = 480p

    GameObject* square = CreateGameObject<GameObject>();
    Transform* transformSquare = square->createComponent<Transform>(400.f, 300.f);
    ShapeComponent* squareShape = square->createComponent<ShapeComponent>(sf::Vector2f{50.f, 50.f});
    CollisionComponent* collisionSquare = square->createComponent<CollisionComponent>(sf::Vector2f(50.f, 50.f), sf::Color::Red, 1.f);
    RigidBody* squareRigidBody = square->createComponent<RigidBody>();

    collisionSquare->setCollisionType(CollisionType::Enemy);
}