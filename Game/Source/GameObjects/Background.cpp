#include "GameObjects/Background.h"

Background::Background(const std::string& texturePath)
{
	createComponent<Transform>(1280.f / 2.f, 720.f / 2.f);
	createComponent<SpriteRenderer>(texturePath);
}
