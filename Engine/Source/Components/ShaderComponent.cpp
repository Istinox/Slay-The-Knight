#include "Components/ShaderComponent.h"

void ShaderComponent::Start() {
	transform = owner->getComponent<Transform>();
};

void ShaderComponent::Update(float dt) {
	// shader->setUniform("lightPos", sf::Vector2f(0.5f, 0.5f));
	// shader->setUniform("rayon", 100.f);
};

void ShaderComponent::Render(sf::RenderWindow& window) {};
