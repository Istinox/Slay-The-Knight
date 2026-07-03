#include "Modules/WindowModule.h"

WindowModule* WindowModule::windowModule = nullptr;

WindowModule::WindowModule() { }

WindowModule* WindowModule::getWindowModule()
{
	if (windowModule == nullptr)
	{
		windowModule = new WindowModule();
	}
	return windowModule;
}

sf::RenderWindow& WindowModule::getWindow() { return window; }

void WindowModule::create(sf::Vector2u size, const std::string& title) { window.create(sf::VideoMode(size), title); }

void WindowModule::setWindowZise(sf::Vector2u size) { window.setSize(size); }

void WindowModule::setWindowName(const std::string& title) { window.setTitle(title); }

void WindowModule::setWindowIcon(const std::string& iconPath)
{
	sf::Image icon;

	if (icon.loadFromFile(iconPath)) {
		window.setIcon(icon);
	}

	else {
		std::cout << "ERREUR : Repertoire invalide." << std::endl;
	}
}

void WindowModule::display() { window.display(); }
void WindowModule::clear() { window.clear(); }
