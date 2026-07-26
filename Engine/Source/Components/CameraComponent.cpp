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
	case TypeMovement::Automatic:
	{
		transform->setAxisX(transform->getAxisX());
		transform->setAxisY(transform->getAxisY());

		camera.setCenter({ transform->getAxisX(), transform->getAxisY() });
		windowModule->getWindow().setView(camera);

		break;
	}
	case TypeMovement::Manual:
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
