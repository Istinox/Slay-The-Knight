#include "Components/SpriteRenderer.h"

void SpriteRenderer::Start() {
    sprite.emplace(ResourceManager::getTexture(texturePath));

    if (!owner->getComponent<Transform>()) {
        std::cerr << RED "Erreur : Un sprite depend d'un component Transform." RESET_COLOR << std::endl;
        return;
    }

    if (owner->getComponent<ShaderComponent>()) {
        shader = owner->getComponent<ShaderComponent>()->getShader();
    }

    sprite->setScale({ scaleX, scaleY });

    owner->getComponent<Transform>()->setWidth(sprite->getGlobalBounds().size.x);
    owner->getComponent<Transform>()->setHeight(sprite->getGlobalBounds().size.y); 

    sprite->setOrigin({ owner->getComponent<Transform>()->getWidth() / 2, owner->getComponent<Transform>()->getHeight() / 2 });
}

void SpriteRenderer::Update(float dt) {
    Transform* transform = owner->getComponent<Transform>();

    if (!transform)
        return;

    // À IMPÉRATIVEMENT garder. Sinon ça crash.
    if (!sprite.has_value())
        return;

    sprite->setPosition({ transform->getAxisX(), transform->getAxisY() });
}

void SpriteRenderer::Render(sf::RenderWindow& window) {
    if (!sprite.has_value())
        return;

    if (sprite)
        window.draw(*sprite, shader);
}

// À améliorer.
void SpriteRenderer::defineSpriteSize(int spriteSize)
{
    sprite.value().setTextureRect(sf::IntRect({ 0, 0 }, { spriteSize, spriteSize }));
}
