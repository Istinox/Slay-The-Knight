#include "MainMenu.h"

void MainMenu::OnEnter()
{
    const int windowWidth = 1280;
    const int windowHeight = 720;

    std::string backgroundFilePath = "Assets/Backgrounds/background.png";
    std::string buttonFilePath = "Assets/GrayButton.png";
    std::string fontFilePath = "Assets/Fonts/PlaywriteNZBasic-Regular.ttf";

    background = CreateGameObject<GameObject>();
    title = CreateGameObject<GameObject>();
    subTitle = CreateGameObject<GameObject>();
    button = CreateGameObject<GameObject>();

    background->createComponent<Transform>(static_cast<float>(windowWidth) / 2, static_cast<float>(windowHeight) / 2);
    background->createComponent<SpriteRenderer>(backgroundFilePath);

    title->createComponent<Transform>(static_cast<float>(windowWidth) / 2, 100.f);
    title->createComponent<TextComponent>(fontFilePath, "Slay the Knight", sf::Color::Red, sf::Color::Black, 2.f);

    subTitle->createComponent<Transform>(static_cast<float>(windowWidth) / 2, 130.f);
    subTitle->createComponent<TextComponent>(fontFilePath, "Version - Prototype", sf::Color::Red, sf::Color::Black, 2.f, 15);

    button->createComponent<Transform>(static_cast<float>(windowWidth) / 2, 300.f);
    button->createComponent<SpriteRenderer>(buttonFilePath); // Alors.. Faudra changer la texture, svp.
    button->createComponent<InputComponent>();

    button->createComponent<ButtonComponent>([]() {
        SceneManager::getSceneManager()->getCurrentScene()->OnExit();
        SceneManager::getSceneManager()->setScene(new Level1);
        });
}
