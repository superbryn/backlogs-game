#pragma once
#include "core/StateManager.hpp"
#include "core/State.hpp"
#include <SFML/Graphics.hpp>

class MainMenuState : public State
{
public:
    MainMenuState(StateManager& stateManager, sf::RenderWindow& window);

    void init() override;
    void handleInput() override;
    void update(float dt) override;
    void draw() override;

private:
    StateManager& _stateManager;
    sf::RenderWindow& _window;
    
    sf::Font _font;
    sf::Text _menuText;
};
