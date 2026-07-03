#include "Components/RotateToMouse.h"

void RotateToMouse::Start()
{
	float direction = 0.f;
}

void RotateToMouse::Update(float deltaTime)
{
	float ownerPositionX = GetOwner()->getComponent<Transform>()->getAxisX();
	float mousePositionX = static_cast<float>(inputModule->getMousePosition(windowModule->getWindow()).x);

	float direction = atan2(mousePositionX, ownerPositionX);
	float radianToDegree = direction * 180.f / 3.14159265f;

	GetOwner()->getComponent<Transform>()->setRotation(radianToDegree);
}
