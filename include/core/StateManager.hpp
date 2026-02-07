#pragma once

#include <stack>
#include <memory>
#include "State.hpp"

class StateManager
{
public:
    StateManager() {}
    ~StateManager() {}
    
    void addState(std::unique_ptr<State> newState, bool isReplacing = true);
    void removeState();
    void processStateChanges();
  
    std::unique_ptr<State>& getActiveState();
    
    bool isEmpty() const { return _states.empty(); }

private:
    std::stack<std::unique_ptr<State>> _states;
    std::unique_ptr<State> _newState;
    
    bool _isRemoving = false;
    bool _isAdding = false;
    bool _isReplacing = false;
};