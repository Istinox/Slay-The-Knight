#pragma once
#include <Core/Component.h>
#include <Core/GameObject.h>
#include <Modules/WindowModule.h>
#include <Modules/InputModule.h>

class RotateToMouse : public Component
{
private:
	WindowModule* windowModule = WindowModule::getWindowModule();
	InputModule* inputModule = InputModule::getInputModule();

	float rotationSpeed;
public:
	void Start() override;
	void Update(float deltaTime) override;
};

