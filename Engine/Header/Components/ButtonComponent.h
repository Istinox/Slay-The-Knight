#pragma once
#include "Core/Component.h"
#include "Modules/InputModule.h"
#include "Modules/WindowModule.h"
#include "Managers/SceneManager.h"
#include "Components/SpriteRenderer.h"

class ButtonComponent : public Component
{
private:
	using Event = std::function<void()>;
	InputModule* inputModule = InputModule::getInputModule();
	WindowModule* windowModule = WindowModule::getWindowModule();
	sf::Vector2i mousePosition;
	sf::FloatRect bounds;

	Event buttonContent;
public:
	ButtonComponent(Event event)
	{
		buttonContent = event;
	}

	void Start() override;
	void Update(float dt) override;

	void OnClick(Event buttonContent);
};

