#pragma once
#include <Core/GameObject.h>
#include <Components/SpriteRenderer.h>

class Background : public GameObject
{
public:
	Background(const std::string& texturePath);
};

