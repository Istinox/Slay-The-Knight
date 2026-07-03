#pragma once
#include "Core/Component.h"

class SoundComponent : public Component
{
private:
	sf::SoundBuffer buffer;
	std::optional<sf::Sound> sound;
public:
	SoundComponent(const std::string& path) : buffer(path) {
		sound.emplace(buffer);
	}

	sf::Sound& getSound() {
		return sound.value();
	}
};

