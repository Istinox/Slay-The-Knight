#include "GameObjects/Camera.h"
#include <Components/CameraComponent.h>

Camera::Camera(float _speed, sf::FloatRect _PositionAndSize)
{
	speed = _speed;
	PositionAndSize = _PositionAndSize;
	createComponent<Transform>();
	createComponent<CameraComponent>(speed, PositionAndSize);
}
