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
		animation->ChangeAnimation("Walk");
		transform->setAxisY(transform->getAxisY() + speed * 1 * dt);
		isWalking = true;
	}

	else if (input->isKeyHeld(sf::Keyboard::Key::Z)) {
		animation->ChangeAnimation("Walk");
		transform->setAxisY(transform->getAxisY() + speed * -1 * dt);
		isWalking = true;
	}

	if (input->isKeyHeld(sf::Keyboard::Key::D)) {
		animation->ChangeAnimation("Walk");
		transform->setAxisX(transform->getAxisX() + speed * 1 * dt);
		isWalking = true;
	}

	else if (input->isKeyHeld(sf::Keyboard::Key::Q)) {
		animation->ChangeAnimation("Walk");
		transform->setAxisX(transform->getAxisX() + speed * -1 * dt);
		isWalking = true;
	}

	// Si aucune touche n'est pressée, le joueur ne marche pas.
	else if (!input->isKeyHeld(sf::Keyboard::Key::Z) &&
			 !input->isKeyHeld(sf::Keyboard::Key::S) &&
			 !input->isKeyHeld(sf::Keyboard::Key::Q) &&
			 !input->isKeyHeld(sf::Keyboard::Key::D)) 
	{
		isWalking = false;
	}

	if (input->isMouseHelds(sf::Mouse::Button::Left) && !isWalking) {
		std::cout << "Attaque !" << "\n";
		animation->ChangeAnimation("Attack");
		isAttacking = true;
	}
	else
	{
		isAttacking = false;
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
	if (input->isKeyPressed(sf::Keyboard::Key::H))
	{
		owner->getComponent<HealthComponent>()->health = 0;
	}

	if (!isWalking && !isAttacking) {
		animation->ChangeAnimation("Idle");
	}
}
