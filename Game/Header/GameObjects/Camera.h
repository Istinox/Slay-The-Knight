#pragma once
#include <Core/GameObject.h>
class Camera : public GameObject
{
private:
	float speed;
	sf::FloatRect PositionAndSize;
public:
	Camera(float _speed, sf::FloatRect _PositionAndSize);
};

