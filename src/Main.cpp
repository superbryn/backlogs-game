#include "core/Game.hpp"
#include <lua/lua.hpp>
#include <string>

int main() {
    int height = 100,width = 100;
    std::string title = "Script aint working properly";
    
    // The Lua Part (Might Change it after testing)
    lua_State *L = luaL_newstate();
    luaL_openlibs(L);
    
    if(luaL_dofile(L, "scripts/config.lua") != LUA_OK)
    {
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
    
    Game game(width, height, title);
    game.run();
    
    return 0;
}