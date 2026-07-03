#pragma once
#include "Core/Component.h"

class MusicComponent : public Component
{
private:
	std::optional<sf::Music> music;
public:
	MusicComponent(const std::string& filePath) {
		music.emplace(filePath);
	}

	sf::Music& getMusic() {
		return music.value();
	}

	void Start() override;
	void Update(float deltaTime) override;
	void Render(sf::RenderWindow& window) override;
};

