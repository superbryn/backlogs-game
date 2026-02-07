#pragma once
#include <SFML/Graphics.hpp>

class State
{
public:
    virtual ~State() {}
    
    virtual void init() = 0;
    virtual void handleInput() = 0;
    virtual void update(float dt) = 0;
    virtual void draw() = 0;
     
    virtual void pause() {} // Pause the game during battle
    virtual void resume() {} // Resume the game
};