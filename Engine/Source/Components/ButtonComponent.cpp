#include "Components/ButtonComponent.h"

void ButtonComponent::Start()
{
	mousePosition = inputModule->getMousePosition(windowModule->getWindow());
}

void ButtonComponent::Update(float dt)
{
	mousePosition = inputModule->getMousePosition(windowModule->getWindow());
	bounds = owner->getComponent<SpriteRenderer>()->getSprite().getGlobalBounds();

	if (bounds.contains(static_cast<sf::Vector2f>(mousePosition)) && inputModule->isMouseHelds(sf::Mouse::Button::Left)) 
	{
		OnClick(buttonContent);
	}
}

void ButtonComponent::OnClick(Event buttonContent)
{
	buttonContent();
}
