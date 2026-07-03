#include "Components/InputComponent.h"
#include "Components/SpriteRenderer.h"

void InputComponent::Start() {

	if (!owner->getComponent<SpriteRenderer>())
	{
		std::cerr << RED "ERREUR : InputComponent depend de SpriteRenderer." RESET_COLOR << std::endl;
		return;
	}

	sf::Sprite sprite = owner->getComponent<SpriteRenderer>()->getSprite();

	maxPosition = { 1280.f - sprite.getGlobalBounds().size.x / 2, 720.f - sprite.getGlobalBounds().size.y / 2 };
	minPosition = { sprite.getGlobalBounds().size.x / 2, sprite.getGlobalBounds().size.y / 2 };
}

void InputComponent::Update(float dt) {
	// ...
}

void InputComponent::handleInputPlayer(float dt)
{
	Transform* transform = owner->getComponent<Transform>();

	if (!transform)
		return;

	// J'ai supprimé le clamp, parce que avec le spriteSheet ça faisait n'importe quoi.
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
		transform->setAxisY(transform->getAxisY() + speed * 1 * dt);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Z)) {
		transform->setAxisY(transform->getAxisY() + speed * -1 * dt);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
		transform->setAxisX(transform->getAxisX() + speed * 1 * dt);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q)) {
		transform->setAxisX(transform->getAxisX() + speed * -1 * dt);
	}
}

bool InputComponent::InputChangeScene(sf::Keyboard::Key)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::P))
	{
		return true;
	}
	return false;
}
