#pragma once
#include "Core/Scene.h"
#include "Core/GameObject.h"

#include "Components/SpriteRenderer.h"
#include "Components/TextComponent.h"
#include "Components/InputComponent.h"
#include "Components/ButtonComponent.h"

#include "LevelCreator.h"
#include "Level1.h"

class MainMenu : public Scene
{
private:
	GameObject* background = nullptr;
	GameObject* title = nullptr;
	GameObject* subTitle = nullptr;
	GameObject* button = nullptr;
public:
	MainMenu() : Scene("Main Menu") {};

	void OnEnter() override;
};