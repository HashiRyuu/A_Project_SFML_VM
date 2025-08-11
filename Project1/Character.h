#ifndef CHARACTER_H
#define CHARACTER_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>  // for rand()
#include "ScriptRead.h"



class Character
{
public:
    Character(const std::vector<std::string>& imageFiles, const sf::Sprite& dump)
        : sprite(dump), currentTextureIndex(0), isBlinking(false), blinkDuration(0.15f), blinkInterval(3.5f)
    {
        for (const auto& filename : imageFiles)
        {
            sf::Texture tex;
            if (!tex.loadFromFile("D:/A_Project_SFML/Project1/image/" + filename))
            {
                std::cerr << "Failed to load " << filename << std::endl;
            }
            else
            {
                textures.push_back(tex);
            }
        }
    }

    // Access the sprite to draw it
    sf::Sprite& getSprite()
    {
        return sprite;
    }

    // Call this every frame to update blinking
    void updateBlinking()
    {
        float elapsed = blinkClock.getElapsedTime().asSeconds();

        if (!isBlinking && elapsed >= blinkInterval)
        {
            isBlinking = true;
            currentTextureIndex = 1 % textures.size();  // safely switch to second texture if exists
            sprite.setTexture(textures[currentTextureIndex]);
            sprite.setPosition(sf::Vector2f(500, 140.f));
            sprite.setScale(sf::Vector2f(.3f, .3f));
            blinkClock.restart();
        }
        else if (isBlinking && elapsed >= blinkDuration)
        {
            isBlinking = false;
            currentTextureIndex = 0;
            sprite.setTexture(textures[currentTextureIndex]);
            sprite.setPosition(sf::Vector2f(500, 140.f));
            sprite.setScale(sf::Vector2f(.3f, .3f));
            blinkInterval = 3.0f + static_cast<float>(rand() % 3000) / 1000.0f; // random 3-6 sec
            blinkClock.restart();
        }
    }

 

private:
    std::vector<sf::Texture> textures;
    sf::Sprite sprite;

    size_t currentTextureIndex;

    sf::Clock blinkClock;
    bool isBlinking;
    float blinkDuration;  // seconds
    float blinkInterval;  // seconds
};

#endif
