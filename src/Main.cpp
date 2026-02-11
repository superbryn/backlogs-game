#include "core/Game.hpp"
#include <iostream>
#include <lua/lua.hpp>
#include <ostream>
#include <string>

int main() {
    int height,width;
    std::string title;
    
    // The Lua Part (Might Change it after testing)
    lua_State *L = luaL_newstate();
    luaL_openlibs(L);
    
    if(luaL_dofile(L, "./script/config.lua") != LUA_OK)
    {
        std::cerr << "Aint Working Dawg" << lua_tostring(L, -1) << std::endl;
        lua_close(L);
        return 1;
    }
    
    lua_getglobal(L, "Window");
    if(lua_istable(L, -1))
    {
        // Get Width of the Window
        lua_getfield(L, -1, "width");
        if(lua_isnumber(L, -1))
        {
            width = lua_tointeger(L, -1);
        }
        lua_pop(L, 1);
        
        // Get Height of the Window
        lua_getfield(L, -1, "height");
        if(lua_isnumber(L, -1))
        {
            height = lua_tointeger(L, -1);
        }
        lua_pop(L, 1);
        
        // Get Title of the Window (obviously for test purposes only)
        lua_getfield(L, -1, "title");
        if(lua_isstring(L, -1))
        {
            title = lua_tostring(L, -1);
        }
        lua_pop(L, 1);
    }
    lua_pop(L, 1);
    lua_close(L);
    
    Game game(1280, 720, "Test: Working");
    game.run();
    
    return 0;
}