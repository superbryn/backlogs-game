#pragma once
#include <SFML/Graphics.hpp>
#include <map>
#include <string>
#include <lua/lua.hpp>

class ResourceManager
{
public:
    static void init(lua_State *L);
    static sf::Texture& getTexture(const std::string& key);
    static sf::Font& getFont(const std::string& key);

private:
    static std::map<std::string, sf::Texture> _textures;
    static std::map<std::string, sf::Font> _fonts;
    static std::map<std::string, std::string> _assetPaths;
};