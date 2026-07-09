#include "Components/HealthComponent.h"

void HealthComponent::Update(float dt)
{
	if (health <= 0 && owner->getName() == "Player") {
		std::cout << "DEBUG : Le joueur est mort.";
		owner->setActive(false);
	}
	else if (health <= 0)
	{
		owner->setActive(false);
	}
}
