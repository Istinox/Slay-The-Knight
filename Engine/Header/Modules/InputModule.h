#pragma once
#include <unordered_set>
#include "SFML/Graphics.hpp"
#include "WindowModule.h"

class InputModule
{
private:
	static InputModule* inputModule;

	std::unordered_set<sf::Keyboard::Key> keyHelds;
	std::unordered_set<sf::Keyboard::Key> keyPresseds;

	std::unordered_set<sf::Mouse::Button> mouseHelds;
	std::unordered_set<sf::Mouse::Button> mousePresseds;

	WindowModule* windowModule = WindowModule::getWindowModule();
public:
	static InputModule* getInputModule();

	void HandleEvents(sf::RenderWindow& window);
	bool isKeyPressed(sf::Keyboard::Key key);
	bool isKeyHeld(sf::Keyboard::Key key);

	bool isMousePresseds(sf::Mouse::Button mouseButton);
	bool isMouseHelds(sf::Mouse::Button mouseButton);

	sf::Vector2i getMousePosition(sf::RenderWindow& window);
	void ClearPressed();
};
