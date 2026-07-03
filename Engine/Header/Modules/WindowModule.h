#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"

class WindowModule
{
private:
	static WindowModule* windowModule;
	sf::RenderWindow window;

public:
	WindowModule();

	static WindowModule* getWindowModule();
	sf::RenderWindow& getWindow();

	void create(sf::Vector2u size, const std::string& title);

	void setWindowZise(sf::Vector2u size);
	void setWindowName(const std::string& title);
	void setWindowIcon(const std::string& iconPath);

	void display();
	void clear();
};

