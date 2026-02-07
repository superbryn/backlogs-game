#pragma once
#include <SFML/Graphics.hpp>
#include "StateManager.hpp"
#include <string>

class Game
{
public:
    Game(int width, int height, std::string title);
    void run();
    
private:
    const float dt = 1.0f / 60.0f;
    sf::RenderWindow _window;
    StateManager _stateManager;
    
    void handleEvents();
};