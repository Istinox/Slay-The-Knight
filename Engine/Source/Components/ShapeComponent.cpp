#include "Components/ShapeComponent.h"

ShapeComponent::ShapeComponent(sf::Vector2f size)
{
	rectangle = new sf::RectangleShape(size);
}

void ShapeComponent::Start() 
{
	transform = owner->getComponent<Transform>();
	sf::Vector2f rectangleSize = rectangle->getSize();
	rectangle->setOrigin(sf::Vector2f(rectangleSize.x / 2, rectangleSize.y / 2));
}

void ShapeComponent::Update(float deltaTime)
{
	if (!transform) return;

	rectangle->setPosition(transform->getPosition());
}

void ShapeComponent::Render(sf::RenderWindow& window)
{
	window.draw(*rectangle);
}

sf::RectangleShape* ShapeComponent::GetShape()
{
	return rectangle;
}
