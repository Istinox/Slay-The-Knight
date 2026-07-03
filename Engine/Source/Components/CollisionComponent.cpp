#include "Components/CollisionComponent.h"

CollisionComponent::CollisionComponent(sf::Vector2f collisionSize, 
    sf::Color outline, 
    float thickness)
{
    collisionBox.size = collisionSize;
    outlineColor = outline;
    outlineThickness = thickness;
}

void CollisionComponent::Start()
{
    collisionBoxBorder.setFillColor(sf::Color::Transparent);
    collisionBoxBorder.setOutlineColor(outlineColor);
    collisionBoxBorder.setOutlineThickness(outlineThickness);

    CollisionManager::getCollidersVector().push_back(this);
}

void CollisionComponent::Update(float deltaTime)
{
    collisionBox.position = owner->getComponent<Transform>()->getPosition() - collisionBox.size / 2.f;
    collisionBoxBorder.setPosition(collisionBox.position);
    collisionBoxBorder.setSize(collisionBox.size);
}

void CollisionComponent::Render(sf::RenderWindow& window)
{
    window.draw(collisionBoxBorder);
}

sf::FloatRect CollisionComponent::getCollisionBox() const { return collisionBox; }

CollisionType CollisionComponent::getCollisionType() const
{
    return collisionType;
}

void CollisionComponent::setCollisionType(CollisionType _collisionType) 
{
    collisionType = _collisionType;
}
