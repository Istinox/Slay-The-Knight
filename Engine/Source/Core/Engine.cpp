#include "Core/Engine.h"
#include "Managers/CollisionManager.h"

Engine* Engine::engine;

Engine* Engine::GetInstance()
{
    if (engine == nullptr)
    {
        engine = new Engine();
    }
    return engine;
}

void Engine::Run() {
    Init();
    sf::Clock clock;

    while (windowModule->getWindow().isOpen())
    {
        if (sceneManager->getCurrentScene() == nullptr) {
            return;
        }

        if (!sceneManager->getHasStartedScene()) {
            sceneManager->getCurrentScene()->Start();
            sceneManager->setHasStartedScene(true);

            windowTitle = "Horror Engine I (ver. 1.0.0) | " + sceneManager->getCurrentScene()->getName();
            windowModule->setWindowName(windowTitle);
        }

        float deltaTime = clock.restart().asSeconds();
        inputModule->HandleEvents(windowModule->getWindow());
        sceneManager->getCurrentScene()->Update(deltaTime);
        CollisionManager::handleCollision();

        windowModule->clear();
        sceneManager->getCurrentScene()->Render(windowModule->getWindow());
        windowModule->display();

        inputModule->ClearPressed();
    }
}

void Engine::Init() {
    const int windowWidth = 1280;
    const int windowHeight = 720;

    windowModule->create(sf::Vector2u({ windowWidth, windowHeight }), "???");
    windowModule->setWindowIcon(iconFilePath);
}