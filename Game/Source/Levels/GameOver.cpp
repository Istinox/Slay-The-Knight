#include "Levels/GameOver.h"

void GameOver::OnEnter()
{
    const float windowWidth = 1280.f;
    const float windowHeight = 720.f;

    // Ce sont des placeholders.
    std::string backgroundFilePath = "Assets/Backgrounds/Background_Knight.jpg";
    std::string buttonStartPath = "Assets/ButtonStart.png";
    std::string buttonLeavePath = "Assets/ButtonLeave.png";
    std::string fontFilePath = "Assets/Fonts/PlaywriteNZBasic-Regular.ttf";

    background = CreateGameObject<GameObject>();
    title = CreateGameObject<GameObject>();
    subTitle = CreateGameObject<GameObject>();
    buttonStart = CreateGameObject<GameObject>();
    buttonLeave = CreateGameObject<GameObject>();

    background->createComponent<Transform>(windowWidth / 2, windowHeight / 2);
    background->createComponent<SpriteRenderer>(backgroundFilePath);

    title->createComponent<Transform>(windowWidth / 2, 120.f);
    //title->createComponent<TextComponent>(fontFilePath, "S", sf::Color::Red, sf::Color::Black, 2.f, 75);

    subTitle->createComponent<Transform>(windowWidth / 2, 200.f);
    //subTitle->createComponent<TextComponent>(fontFilePath, "V", sf::Color::White, sf::Color::Black, 2.f, 30);

    buttonStart->createComponent<Transform>(windowWidth / 2, 300.f);
    buttonStart->createComponent<SpriteRenderer>(buttonStartPath);
    buttonStart->createComponent<InputComponent>();

    buttonStart->createComponent<ButtonComponent>([]() {
        SceneManager::getSceneManager()->getCurrentScene()->OnExit();
        SceneManager::getSceneManager()->setScene(new Level1);
        });

    buttonLeave->createComponent<Transform>(windowWidth / 2, 400.f);
    buttonLeave->createComponent<SpriteRenderer>(buttonLeavePath);
    buttonLeave->createComponent<InputComponent>();

    buttonLeave->createComponent<ButtonComponent>([this]() {
        SceneManager::getSceneManager()->getCurrentScene()->OnExit();
        windowModule->getWindow().close(); // On devrait faire une fermeture plus propre du moteur.
        });
}
