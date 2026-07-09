#include "Modules/InputModule.h"

InputModule* InputModule::inputModule;

void InputModule::HandleEvents(sf::RenderWindow& window)
{
    while (const std::optional event = window.pollEvent()) {
        if (event->is<sf::Event::Closed>())
            window.close();

        if (auto keyPressed = event->getIf<sf::Event::KeyPressed>())
        {
            keyPresseds.insert(keyPressed->code);
            keyHelds.insert(keyPressed->code);
        }

        if (auto keyReleased = event->getIf<sf::Event::KeyReleased>())
        {
            keyPresseds.erase(keyReleased->code);
            keyHelds.erase(keyReleased->code);
        }

        if (auto mousePressed = event->getIf<sf::Event::MouseButtonPressed>())
        {
            if (!mousePresseds.contains(mousePressed->button))
            {
                mousePresseds.insert(mousePressed->button);
            }
            mouseHelds.insert(mousePressed->button);
        }

        if (auto mouseReleased = event->getIf<sf::Event::MouseButtonReleased>())
        {
            mousePresseds.erase(mouseReleased->button);
            mouseHelds.erase(mouseReleased->button);
        }
    }
}

bool InputModule::isKeyPressed(sf::Keyboard::Key key) { return keyPresseds.contains(key); }

bool InputModule::isKeyHeld(sf::Keyboard::Key key) { return keyHelds.contains(key); }

bool InputModule::isKeyReleased(sf::Keyboard::Key key) { return !keyHelds.contains(key); }

bool InputModule::isMousePresseds(sf::Mouse::Button mouseKey) { return mousePresseds.contains(mouseKey); }

bool InputModule::isMouseHelds(sf::Mouse::Button mouseKey) { return mouseHelds.contains(mouseKey); }


InputModule* InputModule::getInputModule()
{
    if (inputModule == nullptr)
    {
        inputModule = new InputModule();
    }
    return inputModule;
}

sf::Vector2i InputModule::getMousePosition(sf::RenderWindow& window) { return sf::Mouse::getPosition(window); }

void InputModule::ClearPressed() { 
    keyPresseds.clear(); 
    mousePresseds.clear();
}