#include "Managers/ResourceManager.h"

std::unordered_map<std::string, sf::Texture> ResourceManager::textures;
std::unordered_map<std::string, sf::Font> ResourceManager::fonts;
std::unordered_map<std::string, sf::Shader> ResourceManager::shaders;

sf::Texture& ResourceManager::getTexture(const std::string& path)
{
    auto target = textures.find(path);
    if (target != textures.end())
    {
        return target->second;
    }

    sf::Texture texture;
    if (!texture.loadFromFile(path))
    {
        std::cerr << "Erreur : impossible de charger la texture : " << path << std::endl;
    }
    auto result = textures.emplace(path, std::move(texture));

    return result.first->second;
}

sf::Font& ResourceManager::getFont(const std::string& path)
{
    auto target = fonts.find(path);
    if (target != fonts.end())
    {
        return target->second;
    }

    sf::Font font;
    if (!font.openFromFile(path))
    {
        std::cerr << "Erreur : impossible de charger le font : " << path << std::endl;
    }
    auto result = fonts.emplace(path, std::move(font));

    return result.first->second;
}

sf::Shader& ResourceManager::getShader(const std::string& path)
{
    auto target = shaders.find(path);
    if (target != shaders.end())
    {
        return target->second;
    }

    sf::Shader shader;
    if (!shader.loadFromFile(path, sf::Shader::Type::Fragment))
    {
        std::cerr << "Erreur : impossible de charger le shader : " << path << std::endl;
    }
    auto result = shaders.emplace(path, std::move(shader));

    return result.first->second;
}