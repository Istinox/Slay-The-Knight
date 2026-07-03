#pragma once
#include "Core/Component.h"
#include "Core/GameObject.h"
#include "Managers/CollisionManager.h"
#include "Components/SpriteRenderer.h"
#include "Components/CollisionComponent.h"

#include "CollisionType.h"

class CollisionComponent : public Component
{
private:
    sf::FloatRect collisionBox;
    sf::RectangleShape collisionBoxBorder;
    sf::Color outlineColor;
    float outlineThickness;

public:
    // Important pour gérer la collision entre les objets.
    CollisionType collisionType = CollisionType::None;

    CollisionComponent(sf::Vector2f collisionSize, sf::Color outline = sf::Color::Transparent, float thickness = 0.f);

    void Start() override;
    void Update(float deltaTime) override;
    void Render(sf::RenderWindow& window) override;

    sf::FloatRect getCollisionBox() const;
    CollisionType getCollisionType() const;

    void setCollisionType(CollisionType _collisionType);
};