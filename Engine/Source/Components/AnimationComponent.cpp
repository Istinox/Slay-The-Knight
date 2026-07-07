#include "Components/AnimationComponent.h"

void AnimationComponent::Start()
{
	if (!owner->getComponent<SpriteRenderer>())
	{
		std::cerr << RED << "ERREUR : AnimationComponent depend du component SpriteRenderer !" << RESET_COLOR << std::endl;
		exit(-1);
	}

	sf::Sprite& ownerSprite = owner->getComponent<SpriteRenderer>()->getSprite();
	sf::FloatRect bounds = ownerSprite.getLocalBounds();

	imageHeight = ownerSprite.getTexture().getSize().y;
	imageWidth = ownerSprite.getTexture().getSize().x;
	ownerSprite.setOrigin({ static_cast<float>(imageHeight) / 2.f, static_cast<float>(imageHeight) / 2.f });
	ownerSprite.setTextureRect(sf::IntRect({ 0, 0 }, { 192, 192 }));
}

void AnimationComponent::Update(float dt)
{
	AnimateSprite(dt);
}

void AnimationComponent::AnimateSprite(float dt)
{
	if (timer <= cooldown)
	{
		timer += 25 * dt;
		return;
	}

	timer = 0.f;
	sf::Sprite& ownerSprite = owner->getComponent<SpriteRenderer>()->getSprite();

	// on récupère la hauteur du fichier, qui correspond à la largueur d'un sprite.
	positionDraw = positionDraw + ownerSprite.getTexture().getSize().y;

	if (positionDraw >= imageWidth)
	{
		positionDraw = 0;
	}

	ownerSprite.setTextureRect(sf::IntRect({ positionDraw, 0 }, { 192, 192 }));
}

void AnimationComponent::ChangeAnimation(std::string name)
{
	if (!animations.contains(name)) return;

	auto spriteNamePair = animations.find(name); // La pair nom / sprite dans la liste.
	sf::Sprite sprite(spriteNamePair->second);

	owner->getComponent<SpriteRenderer>()->setSprite(sprite);
}

void AnimationComponent::AddAnimation(std::string animationName, std::string filePath)
{
	sf::Texture texture = ResourceManager::getTexture(filePath);
	animations.emplace(animationName, texture);
}

// Implémenter une méthode qui gère les états d'animations selon la gameState (vitesse, interaction etc..) ?