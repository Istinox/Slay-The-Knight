#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <unordered_map>
#include <iostream>

class ResourceManager
{
private:
	static std::unordered_map<std::string, sf::Texture> textures;
	static std::unordered_map<std::string, sf::Font> fonts;
	static std::unordered_map<std::string, sf::Shader> shaders;
public:
	static sf::Texture& getTexture(const std::string& path);
	static sf::Font& getFont(const std::string& path);
	static sf::Shader& getShader(const std::string& path);
};

