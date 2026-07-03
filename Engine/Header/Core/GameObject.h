#pragma once
#include <vector>
#include <iostream> // pour les debugs, supprime pas.
#include "Core/Component.h"

class RenderWindow;

class Transform : public Component {
private:
	sf::Vector2f previousPosition = { 0.f, 0.f };
	sf::Vector2f position = {0.f, 0.f};
	sf::Vector2f scale = {1.f, 1.f};
	float rotation = 0.f;

	float width = 0.f;
	float height = 0.f;

public:
	Transform(float x = 0.f, float y = 0.f) : position(x, y) {}

	void Update(float deltaTime) override;

	void setAxisX(float value) { position.x = value; }
	void setAxisY(float value) { position.y = value; }

	float getAxisX() { return position.x; }
	float getAxisY() { return position.y; }

	sf::Vector2f getPosition() { return position; }
	void setPosition(sf::Vector2f newPosition) { position = newPosition; }

	sf::Vector2f getPreviousPosition() { return previousPosition; }
	void setPreviousPosition() { previousPosition = position; }

	void setWidth(float value) { width = value; }
	void setHeight(float value) { height = value; }

	float getWidth() { return width; }
	float getHeight() { return height; }

	sf::Vector2f getScale() { return scale; }
	void setScale(float w, float h) { scale = { w, h }; }

	float getRotation() { return rotation; }
	void setRotation(float r) { rotation = r; }
};


class GameObject
{
private:
	std::vector<Component*> components;
	std::string name = "???";
	bool active = true;

public:
	~GameObject() {
		for (Component* c : components)
		{
			delete c;
		}
	};

	template<typename T, typename ...Params>
	T* createComponent(Params... parameters) {
		T* component = new T(parameters...);
		component->SetOwner(this);
		components.push_back(component);
		return component;
	}

	template<typename T>
	T* getComponent() {
		for (Component* c : components) {
			if (T* targetComponent = dynamic_cast<T*>(c)) {
				return targetComponent;
			}
		}
		return nullptr;
	}

	void Update(float dt);
	void Render(sf::RenderWindow& window);
	void Start();

	std::string getName();
	void setName(std::string& newName);
	void setActive(bool state);
	bool getActive();

	void OnCollision(GameObject* other);
};

