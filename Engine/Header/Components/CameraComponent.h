#pragma once
#include "Core/GameObject.h"
#include "Core/Component.h"
#include "Modules/InputModule.h"
#include "Modules/WindowModule.h"

class CameraComponent : public Component
{
private:
	float speed = 200.f;
	sf::FloatRect PositionAndSize;

	sf::View camera;
	WindowModule* windowModule = nullptr;

	enum class TypeMovement {Manual = 0, Automatic = 1};
	TypeMovement movementMode = TypeMovement::Manual;
public:

	CameraComponent(float _speed, sf::FloatRect _PositionAndSize, TypeMovement _movementMode = TypeMovement::Manual);

	void Start() override;
	void Update(float deltaTime) override;

	// Si factor < 1, on parle d'un zoom. Si factor > 1, c'est un dezoom.
	void SetZoom(float factor);
	sf::View& GetCamera() { return camera; }
	TypeMovement GetTypeMovement() { return movementMode; }
};