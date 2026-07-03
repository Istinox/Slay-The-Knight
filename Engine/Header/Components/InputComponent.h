#pragma once
#include "Core/GameObject.h"

class InputComponent : public Component
{
private:
	float speed = 200.f;

	sf::Vector2f maxPosition; 
	sf::Vector2f minPosition;

public:
	void Start() override;
	void Update(float dt) override;
	
	void handleInputPlayer(float dt);
	bool InputChangeScene(sf::Keyboard::Key);
};

