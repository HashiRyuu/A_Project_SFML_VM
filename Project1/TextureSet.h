#ifndef TEXTURESET_H
#define TEXTURESET_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <iostream>

class TextureSet
{
public:
    TextureSet(const std::string& basePath, const std::vector<std::string>& filenames)
    {
        textures.reserve(filenames.size());
        for (const auto& file : filenames)
        {
            sf::Texture tex;
            if (tex.loadFromFile(basePath + file))
                textures.push_back(std::move(tex));
            else
                std::cerr << "Failed to load " << file << std::endl;
        }
    }

    const sf::Texture& get(size_t index) const
    {
        if (index >= textures.size())
            throw std::out_of_range("TextureSet: index out of range");
        return textures[index];
    }

    size_t size() const { return textures.size(); }

private:
    std::vector<sf::Texture> textures;
};

#endif
