#pragma once
#include "Core/Scene.h"
#include "Core/GameObject.h"

#include "Components/SpriteRenderer.h"
#include "Components/TextComponent.h"
#include "Components/InputComponent.h"
#include "Components/ButtonComponent.h"

#include "Levels/Level1.h"

class GameOver : public Scene
{
private:
	WindowModule* windowModule = WindowModule::getWindowModule();

	GameObject* background = nullptr;
	GameObject* title = nullptr;
	GameObject* subTitle = nullptr;
	GameObject* buttonStart = nullptr;
	GameObject* buttonLeave = nullptr;
public:
	GameOver() : Scene("Game Over") {};

	void OnEnter() override;
};

