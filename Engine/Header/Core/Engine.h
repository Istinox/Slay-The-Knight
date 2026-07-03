#pragma once
#include <SFML/Graphics.hpp>
#include "Core/Scene.h"
#include "Modules/InputModule.h"
#include "Modules/WindowModule.h"
#include "Managers/SceneManager.h"

class Engine {
public:
    static Engine* GetInstance();
    void Run();

private:
    static Engine* engine;
    InputModule* inputModule = InputModule::getInputModule();
    SceneManager* sceneManager = SceneManager::getSceneManager();
    WindowModule* windowModule = WindowModule::getWindowModule();

    std::string iconFilePath = "Assets/HorrorEngine_icon.jpg"; // J'ai un resourceManager ! :D
    sf::Image icon;
    std::string windowTitle;

    void Init();
};
