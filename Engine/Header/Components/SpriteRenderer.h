#pragma once
#include <optional>
#include "Core/Component.h"
#include "Core/GameObject.h"

#include "ShaderComponent.h"

class SpriteRenderer : public Component
{
public:
    SpriteRenderer(const std::string& path, float sX = 1.f, float sY = 1.f) : texturePath(path) {
        scaleX = sX;
        scaleY = sY;
    }

    void Start() override;
    void Update(float dt);
    void Render(sf::RenderWindow& window);

    void defineSpriteSize(int spriteSize);

    sf::Sprite& getSprite() {
        if (sprite)
        {
            return *sprite;
        }
    }

    void setSprite(sf::Sprite& newSprite) { sprite = newSprite; }
    void setTexture(std::string filePath) {
        sprite.value().setTexture(ResourceManager::getTexture(texturePath));
    }

private:
    float scaleX;
    float scaleY;
    std::string texturePath;
    std::optional<sf::Sprite> sprite; // Absolute peak (made in chatGPT)
    sf::Shader* shader = nullptr;
};

