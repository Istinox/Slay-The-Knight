#include "Components/PlayerController.h"

// Le PlayerController sert à gérer chacun des inputs du joueur, dont ces animations selon ces actions.
void PlayerController::Update(float dt)
{
    InputModule* input = InputModule::getInputModule();
    Transform* transform = owner->getComponent<Transform>();
    AnimationComponent* animation = owner->getComponent<AnimationComponent>();
    SpriteRenderer* spriteRenderer = owner->getComponent<SpriteRenderer>();

    float moveX = 0.f;
    float moveY = 0.f;
    bool invertAxis = false;

    // Déplacements du joueur
    if (input->isKeyHeld(sf::Keyboard::Key::Q))
    {
        moveX -= 1.f;
        invertAxis = true;
    }

    if (input->isKeyHeld(sf::Keyboard::Key::D))
    {
        moveX += 1.f;
        invertAxis = false;
    }

    if (input->isKeyHeld(sf::Keyboard::Key::Z))
    {
        moveY -= 1.f;
    }

    if (input->isKeyHeld(sf::Keyboard::Key::S))
    {
        moveY += 1.f;
    }

    // Sprint
    isRunning = input->isKeyHeld(sf::Keyboard::Key::LShift);
    SetSpeed(isRunning ? 325.f : 200.f); // Si le joueur court --> Speed à 325.f, sinon 200.f

    // Animation de marche
    isWalking = (moveX != 0.f || moveY != 0.f);

    if (isWalking)
    {
        transform->setAxisX(transform->getAxisX() + moveX * speed * dt);
        transform->setAxisY(transform->getAxisY() + moveY * speed * dt);

        animation->ChangeAnimation("Walk");
    }

    // Animation d'attaque
    isAttacking = input->isMouseHelds(sf::Mouse::Button::Left) && !isWalking;

    if (isAttacking)
    {
        std::cout << "Attaque !" << std::endl;
        animation->ChangeAnimation("Attack");
    }

    // Animation Idle
    if (!isWalking && !isAttacking)
    {
        animation->ChangeAnimation("Idle");
    }

    // Touche de debug à supprimer.
    if (input->isKeyPressed(sf::Keyboard::Key::H))
    {
        owner->getComponent<HealthComponent>()->health = 0;
    }

    spriteRenderer->SetShouldInvertAxisX(invertAxis);
}
