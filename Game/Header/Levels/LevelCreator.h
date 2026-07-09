#pragma once

#include "Core/Scene.h"
#include "Core/GameObject.h"
#include "LevelEditor/LevelEditor.h"

#include <GameObjects/Background.h>
#include <GameObjects/Camera.h>
#include <Components/CameraComponent.h>
#include "Components/ShapeComponent.h"
#include <Components/CollisionComponent.h>

class LevelCreator : public Scene
{
private:
    GameObject* tileset = nullptr;
    Background* background = nullptr;
    Camera* camera = nullptr;
public:
    float zoom = 1.5f;

    LevelCreator() : Scene("Level Creator") {}
    void OnEnter() override;
};

