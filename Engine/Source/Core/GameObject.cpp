#include "Core/GameObject.h"

void Transform::Update(float deltaTime)
{
	setPreviousPosition();
}

std::string GameObject::getName() {
	return name;
}

bool GameObject::getActive() {
	return active;
}

void GameObject::setName(std::string& newName) {
	name = newName;
}

void GameObject::setActive(bool state) {
	active = state;
}

void GameObject::Start() {
	for (Component* c : components)
	{
		c->Start();
	}
}


void GameObject::Update(float dt) {
	for (Component* c : components)
	{
		c->Update(dt);
	}
}

void GameObject::Render(sf::RenderWindow& window) {
	for (Component* c : components)
	{
		c->Render(window);
	}
}

void GameObject::OnCollision(GameObject* other) {
	for (Component* c : components)
	{
		c->OnCollision(other);
	}
}

