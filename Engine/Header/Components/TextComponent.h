#pragma once
#include "Core/Component.h"
#include "Core/GameObject.h"

class TextComponent : public Component
{
private:
    std::optional<sf::Text> text;
    std::string fontPath;
    std::string textContent;
    sf::Color fillColor;
    sf::Color outlineColor;
    float outlineThickness;
    unsigned int fontSize;
public:
    TextComponent(const std::string& path,
        std::string textC = "???",
        sf::Color fColor = sf::Color::White,
        sf::Color oColor = sf::Color::Black,
        float ot = 0.f, unsigned int fS = 30) : fontPath(path)
    { 
        textContent = textC;
        fillColor = fColor;
        outlineColor = oColor;
        outlineThickness = ot;
        fontSize = fS;
    }

    void Start() override;
    void Update(float) override;
    void Render(sf::RenderWindow& window) override;

    sf::Text& getText() { 
        return text.value();
    }
};