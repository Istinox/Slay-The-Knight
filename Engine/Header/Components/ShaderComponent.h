#pragma once
#include "Core/Component.h"
#include "Core/GameObject.h"

class ShaderComponent : public Component
{
private:
	sf::Shader* shader = nullptr;
	Transform* transform = nullptr;
public:
	// Répertoire du shader : "Assets/Shaders/Light.frag"
	ShaderComponent(const std::string& path) {
		shader = &ResourceManager::getShader(path);
	}

	void Start() override;
	void Update(float dt) override;
	void Render(sf::RenderWindow& window) override;

	sf::Shader* getShader() {
		if (shader != nullptr)
		{
			return shader;
		}
		
		return nullptr;
	}
};

