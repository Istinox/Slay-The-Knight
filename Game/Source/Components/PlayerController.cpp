#include "Components/PlayerController.h"

// Le PlayerController nous servira à gérer chacun des inputs du joueur, dont ces animations selon ces actions.
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

	else if (input->isMouseHelds(sf::Mouse::Button::Left)) {
		std::cout << "Attaque !" << "\n";
	}
}
