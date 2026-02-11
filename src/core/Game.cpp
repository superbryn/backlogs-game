#include "core/Game.hpp"
#include "core/MainMenuState.hpp"

Game::Game(int width, int height, std::string title)
{
    _window.create(sf::VideoMode({static_cast<unsigned int>(width), static_cast<unsigned int>(height)}), title, sf::Style::Close | sf::Style::Titlebar);
}

void Game::run()
{
    _stateManager.addState(std::make_unique<MainMenuState>(_stateManager, _window));
    sf::Clock clock;
    float dt;
    
    while (_window.isOpen())
    {
        dt = clock.restart().asSeconds();
        
        // 1. Process transitions
        _stateManager.processStateChanges();
        
        // 2. Standard Game Loop
        handleEvents();
        
        if(!_stateManager.isEmpty())
        {
            _stateManager.getActiveState() -> handleInput();
            _stateManager.getActiveState() -> update(dt);
            _window.clear(sf::Color::Black);
            _stateManager.getActiveState() -> draw();
            _window.display();
        }
    }
}


void Game::handleEvents() 
{
    // SFML 3.0 uses an optional to poll events
    while (const std::optional event = _window.pollEvent()) 
    {
        
        // Check if the window was closed
        if (event->is<sf::Event::Closed>()) 
        {
            _window.close();
        }

        // To handle other events (like keys), we check the type:
        if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) 
        {
            if (keyPressed->code == sf::Keyboard::Key::Escape) 
            {
                _window.close();
            }
        }
    }
}

