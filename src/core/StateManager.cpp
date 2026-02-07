#include "core/StateManager.hpp"
#include "core/State.hpp"
#include <memory>

void StateManager::addState(std::unique_ptr<State> newState, bool isReplacing)
{
    _isAdding = true;
    _isReplacing = isReplacing;
    _newState = std::move(newState);
}

void StateManager::removeState()
{
    _isRemoving = true;
}

void StateManager::processStateChanges()
{
    if(_isRemoving && !_states.empty())
    {
        _states.pop();
        if(!_states.empty())
        {
            _states.top() -> resume();
        }
        _isRemoving = false;
    }
    
    if(_isAdding)
    {
        if(!_states.empty())
        {
            if(_isReplacing)
            {
                _states.pop();
            }
            else
            {
                _states.top() -> pause();
            }
        }
        _states.push(std::move(_newState));
        _states.top() -> init();
        _isAdding = false;
    }
}

std::unique_ptr<State>& StateManager::getActiveState(){
    return _states.top();
}