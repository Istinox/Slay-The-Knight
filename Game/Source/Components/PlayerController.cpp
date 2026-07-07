#include "Components/PlayerController.h"
#include <Components/AnimationComponent.h>
#include <Components/HealthComponent.h>

// Le PlayerController nous servira à gérer chacun des inputs du joueur, dont ces animations selon ces actions.
void PlayerController::Update(float dt)
{
	InputModule* input = InputModule::getInputModule();
	Transform* transform = owner->getComponent<Transform>();
	AnimationComponent* animation = owner->getComponent<AnimationComponent>();

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

	if (input->isKeyHeld(sf::Keyboard::Key::LShift) && !isRunning)
	{
		SetSpeed(325.f);
		isRunning = true;
	}
	else if (input->isKeyReleased(sf::Keyboard::Key::LShift) && isRunning)
	{
		SetSpeed(200.f);
		isRunning = false;
	}

	// Touche de debug à supprimer.
	else if (input->isKeyPressed(sf::Keyboard::Key::H))
	{
		owner->getComponent<HealthComponent>()->health = 0;
	}
}
