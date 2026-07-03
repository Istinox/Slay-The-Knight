#include "Core/Component.h"
#include "Core/GameObject.h"

void Component::SetOwner(GameObject* owner) {
	this->owner = owner;
}

GameObject* Component::GetOwner() {
	return this->owner;
}