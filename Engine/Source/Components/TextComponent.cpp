#include "Components/TextComponent.h"

void TextComponent::Start()
{
	text.emplace(ResourceManager::getFont(fontPath));
	text->setString(textContent);
	text->setCharacterSize(fontSize);
	text->setFillColor(fillColor);
	text->setOutlineColor(outlineColor);
	text->setOutlineThickness(outlineThickness);

	text->setOrigin({ text->getGlobalBounds().size.x / 2, text->getGlobalBounds().size.y / 2 });
	text->setPosition(owner->getComponent<Transform>()->getPosition());
}

void TextComponent::Update(float)
{
	// ...
}

void TextComponent::Render(sf::RenderWindow& window)
{
	window.draw(*text);
}
