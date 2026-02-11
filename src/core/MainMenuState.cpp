#include <iostream>
#include "core/MainMenuState.hpp"
#include "core/StateManager.hpp"

MainMenuState::MainMenuState(StateManager& stateManager, sf::RenderWindow& window) : _stateManager(stateManager), _window(window), _menuText(_font) {}

void MainMenuState::init()
{
    if(!_font.openFromFile("assets/fonts/JacobyTTBGOBlack.ttf"))
    {
        std::cerr << "Error while opening font file!" << std::endl;
    }
    
    _menuText.setString("SSET Tour 2D");
    _menuText.setCharacterSize(50);
    _menuText.setFillColor(sf::Color::Blue);
    
    sf::FloatRect textRect = _menuText.getLocalBounds();
    _menuText.setOrigin({textRect.size.x / 2.0f, textRect.size.y / 2.0f});
    _menuText.setPosition({static_cast<float>(_window.getSize().x) / 2.0f, static_cast<float>(_window.getSize().y) / 2.0f});
}   

void MainMenuState::handleInput()
{
    
}

void MainMenuState::update(float dt)
{
    
}

void MainMenuState::draw()
{
    
}