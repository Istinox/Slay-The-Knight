//#include "DebugLevel.h"
//
//void DebugLevel::OnEnter()
//{
//    const int windowWidth = 800;
//    const int windowHeight = 600;
//
//    std::string characterFilePath = "Assets/placeholder_chr.png"; // J'ai un resourceManager !
//    std::string backgroundFilePath = "Assets/background_flower.jpg";
//    std::string fontFilePath = "Assets/Fonts/PlaywriteNZBasic-Regular.ttf";
//
//    GameObject* background = CreateGameObject();
//    GameObject* character = CreateGameObject();
//    GameObject* character2 = CreateGameObject();
//    GameObject* titleHUD = CreateGameObject();
//
//    background->createComponent<Transform>(static_cast<float>(windowWidth) / 2, static_cast<float>(windowHeight) / 2);
//    background->createComponent<SpriteRenderer>(backgroundFilePath);
//
//    character->createComponent<Transform>(static_cast<float>(windowWidth) / 2, static_cast<float>(windowHeight) / 2);
//    character->createComponent<SpriteRenderer>(characterFilePath);
//    character->createComponent<InputComponent>();
//    character->createComponent<CollisionComponent>(sf::Color::Red, 2.f);
//
//    character2->createComponent<Transform>(static_cast<float>(windowWidth) / 2 + 100.f, static_cast<float>(windowHeight) / 2 + 100.f);
//    character2->createComponent<SpriteRenderer>(characterFilePath);
//    character2->createComponent<CollisionComponent>(sf::Color::Red, 2.f);
//
//    titleHUD->createComponent<Transform>(static_cast<float>(windowWidth) / 2, 50.f);
//    titleHUD->createComponent<TextComponent>(fontFilePath, "Ceci est un titre :D", sf::Color::Red, sf::Color::Blue, 2.f);
//}
//
//void DebugLevel::OnExit() {
//    for (GameObject* gameObject : gameObjects) {
//        delete gameObject;
//    }
//    gameObjects.clear();
//    std::cout << "Destruction de la scene !" << std::endl;
//}
//
//void DebugLevel::Start() {
//    for (GameObject* gameObject : gameObjects) {
//        gameObject->Start();
//    }
//}
//
//void DebugLevel::Update(float dt) {
//    for (GameObject* gameObject : gameObjects) {
//        if (!gameObject->getActive())
//            continue;
//
//        gameObject->Update(dt);
//        gameObjects.at(1)->getComponent<InputComponent>()->handleInputPlayer(dt);
//    }
//
//    // CollisionManager::handleCollision();
//}
//
//void DebugLevel::Render(sf::RenderWindow& window) {
//    for (GameObject* gameObject : gameObjects) {
//        if (!gameObject->getActive())
//            continue;
//        gameObject->Render(window);
//    }
//}
//
//GameObject* DebugLevel::CreateGameObject() {
//    GameObject* gameObject = new GameObject;
//    gameObjects.push_back(gameObject);
//    return gameObject;
//}