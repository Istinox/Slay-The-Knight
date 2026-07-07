#pragma once
#include "Core/Component.h"
#include "Core/GameObject.h"
#include "Components/SpriteRenderer.h"
#include <map>

class AnimationComponent : public Component
{
private:
	int imageHeight = 0;
	int imageWidth = 0;
	int positionDraw = 0; // Coordonnée X de départ pour le dessin du sprite.
	float timer = 0.f;
	float cooldown = 4.f;

	std::unordered_map<std::string, sf::Texture> animations; // Pour stocker toute les animations du gameObject.

public:
	void Start() override;
	void Update(float dt) override;
	void AnimateSprite(float dt);

	void ChangeAnimation(std::string name);
	void AddAnimation(std::string animationName, std::string filePath);
};