#pragma once
#include "Core/Component.h"
#include "Core/GameObject.h"

// Pour le moment, ce component ne fait que les rectangles, ne pas utiliser.
class ShapeComponent : public Component
{
private:
	Transform* transform = nullptr;
	sf::RectangleShape* rectangle = nullptr;
public:
	ShapeComponent(sf::Vector2f size = {1.f, 1.f});

	void Start() override;
	void Update(float deltaTime) override;
	void Render(sf::RenderWindow& window) override;

	sf::RectangleShape* GetShape();
};

