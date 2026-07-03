#include "Components/CameraComponent.h"

CameraComponent::CameraComponent(float _speed, sf::FloatRect _PositionAndSize, TypeMovement _movementMode)
{
	sf::View _camera(_PositionAndSize.position, _PositionAndSize.size);

	speed = _speed;
	camera = _camera;
	movementMode = _movementMode;
}

void CameraComponent::Start() {
	Transform* transform = owner->getComponent<Transform>();
	transform->setAxisX(camera.getCenter().x);
	transform->setAxisY(camera.getCenter().y);

	windowModule = WindowModule::getWindowModule();
	windowModule->getWindow().setView(camera);
}

void CameraComponent::Update(float deltaTime)
{
	InputModule* input = InputModule::getInputModule();
	Transform* transform = owner->getComponent<Transform>();

	switch (movementMode) 
	{
	case TypeMovement::Manual:
	{
		if (input->isKeyHeld(sf::Keyboard::Key::Down)) {
			transform->setAxisY(transform->getAxisY() + speed * 1 * deltaTime);
		}
		else if (input->isKeyHeld(sf::Keyboard::Key::Up)) {
			transform->setAxisY(transform->getAxisY() + speed * -1 * deltaTime);
		}

		if (input->isKeyHeld(sf::Keyboard::Key::Right)) {
			transform->setAxisX(transform->getAxisX() + speed * 1 * deltaTime);
		}
		else if (input->isKeyHeld(sf::Keyboard::Key::Left)) {
			transform->setAxisX(transform->getAxisX() + speed * -1 * deltaTime);
		}

		camera.setCenter({ transform->getAxisX(), transform->getAxisY() });
		windowModule->getWindow().setView(camera);

		break;
	}
	case TypeMovement::Automatic:
	{
		camera.setCenter({ transform->getAxisX(), transform->getAxisY() });
		windowModule->getWindow().setView(camera);

		break;
	}
	default:
		std::cout << "ERREUR : Type de deplacement inconnu." << std::endl;
	}

}

void CameraComponent::SetZoom(float factor)
{
	camera.zoom(factor);
}
