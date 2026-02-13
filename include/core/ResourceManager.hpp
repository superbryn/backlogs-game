#pragma once
#include <SFML/Graphics.hpp>
#include <map>
#include <string>

class ResourceManager
{
public:
    static sf::Texture& getTexture(const std::string& filepath);
    static sf::Font& getFont(const std::string& filepath);

private:
    static std::map<std::string, sf::Texture> _textures;
    static std::map<std::string, sf::Font> _fonts;
};