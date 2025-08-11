#ifndef CONTROL_H
#define CONTROL_H
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>
#include "Game.h"
#include "TextureSprite.h"
#include <cmath>

class control
{
public:

    control(sf::CircleShape& circle, textureSprite& x) : shape(circle), ship(x){};

    void controler()
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) && shape.getPosition().x <= 780)
        {
            shape.move(sf::Vector2f(0.1, 0));
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) && shape.getPosition().x >= 0)
        {
            shape.move(sf::Vector2f(-0.1, 0));
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) && shape.getPosition().y <= 580 )
        {
            shape.move(sf::Vector2f(0, 0.1));
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) && shape.getPosition().y > 0)
        {
            shape.move(sf::Vector2f(0, -0.1));
        }
    }

    void controlerSprite()
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) && ship.getSprite().getPosition().x <= 780)
        {
            ship.getSprite().move(sf::Vector2f(0.1, 0));
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) && ship.getSprite().getPosition().x >= 0)
        {
            ship.getSprite().move(sf::Vector2f(-0.1, 0));
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) && ship.getSprite().getPosition().y <= 580)
        {
            ship.getSprite().move(sf::Vector2f(0, 0.1));
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) && ship.getSprite().getPosition().y > 0)
        {
            ship.getSprite().move(sf::Vector2f(0, -0.1));
        }
    }

    void rotateSprite()
    {
        ship.getSprite().setRotation(ship.getSprite().getRotation() + sf::degrees(0.1f));
    }

    void autoMove(bool& collisionX, float& x , float& y, float& vx, float& vy)
    {

        sf::Vector2f movement;
        sf::Vector2f pos = shape.getPosition();

        // x movement
        if (pos.x > 780)
        {
            collisionX = true;
            x += vx;
            
        }
        else if (pos.x < 0)
        {
            collisionX = false;
            if(x > 0.1f) x -= vx;
           
        }

        // y movement
        if (pos.y > 580)
        {
            collisionX = true;
            y += vy;
            
        }
        else if (pos.y < 0)
        {
            collisionX = false;
            if (y > 0.1f) y -= vy;
        }

        
        movement.x = collisionX ? -x : x;
        movement.y = collisionX ? -y : y;
        

        // Move shape
        shape.move(movement);
    }

private:
    sf::CircleShape& shape;
    textureSprite& ship;
    bool keyPress = false;
};

#endif // !

