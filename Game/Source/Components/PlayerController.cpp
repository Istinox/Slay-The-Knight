#include "Components/PlayerController.h"

void PlayerController::Update(float dt)
{
	InputModule* input = InputModule::getInputModule();
	Transform* transform = owner->getComponent<Transform>();

	if (input->isKeyHeld(sf::Keyboard::Key::S)) {
		transform->setAxisY(transform->getAxisY() + speed * 1 * dt);
	}
	else if (input->isKeyHeld(sf::Keyboard::Key::Z)) {
		transform->setAxisY(transform->getAxisY() + speed * -1 * dt);
	}

	if (input->isKeyHeld(sf::Keyboard::Key::D)) {
		transform->setAxisX(transform->getAxisX() + speed * 1 * dt);
	}
	else if (input->isKeyHeld(sf::Keyboard::Key::Q)) {
		transform->setAxisX(transform->getAxisX() + speed * -1 * dt);
	}
}
