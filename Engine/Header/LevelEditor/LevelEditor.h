#pragma once
#include <fstream>
#include <iostream>

#include "Core/GameObject.h"
#include "Core/Component.h"
#include "Components/CameraComponent.h"

class LevelEditor : public Component
{
private:
	InputModule* inputModule = InputModule::getInputModule();
	WindowModule* windowModule = WindowModule::getWindowModule();

	struct Cell 
	{
		sf::RectangleShape CellShape;
		sf::Vector2i cellCoord;
	};

	const int MAX_CELL_X = 50; // 50 par défaut.
	const int MAX_CELL_Y = 50; // 25 par défaut.
	const int SIZE_CELL = 50;

	const std::string filePath;
	std::ofstream file;

	std::vector<Cell> grid;
public:
	void Start() override;
	void Update(float deltaTime) override;
	void Render(sf::RenderWindow& window) override;

	void SaveFile(const std::string& filePath);
	void LoadFile(const std::string& filePath);
	sf::Vector2i GetTileByCoord(sf::Vector2i coords);
};

