#include "core/ResourceManager.hpp"
#include <iostream>
#include <map>
#include <string>

std::map<std::string, sf::Texture> ResourceManager::_textures;
std::map<std::string, sf::Font> ResourceManager::_fonts;
std::map<std::string, std::string>ResourceManager::_assetPaths;

void ResourceManager::init(lua_State *L)
{
    lua_getglobal(L, "Assets");
    if(lua_istable(L, -1))
    {
        lua_pushnil(L);
        while(lua_next(L, -2) != 0)
        {
            
        }
    }
}

sf::Texture& ResourceManager::getTexture(const std::string &filepath)
{
    auto& textureMap = _textures;
    auto pairFound = textureMap.find(filepath);
    
    if(pairFound != textureMap.end())
    {
        return pairFound -> second;
    }

    sf::Texture& texture = _textures[filepath];
    if(!texture.loadFromFile(filepath))
    {
        std::cerr << "Error: Couldnt load texture" << filepath << std::endl;
    }
    
    return texture;
}

sf::Font& ResourceManager::getFont(const std::string &filepath)
{
    auto& fontMap = _fonts;
    auto pairFound = fontMap.find(filepath);
    
    if(pairFound != fontMap.end())
    {
        return pairFound -> second;
    }
    
    sf::Font& font = fontMap[filepath];
    if(!font.openFromFile(filepath))
    {
        std::cerr << "Error: Couldnt open font" << filepath << std::endl;
    }
    
    return font;
}