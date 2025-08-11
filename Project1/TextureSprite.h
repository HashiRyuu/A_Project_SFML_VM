#ifndef TEXTURESPRITE_H
#define TEXTURESPRITE_H
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>

class textureSprite
{
public:
	textureSprite( const sf::Texture& texture, const sf::Sprite& sprite) : textureShapeShip(texture), shapeShipSprite(sprite)
	{
		shapeShipSprite.setTexture(textureShapeShip);
	}

	virtual sf::Sprite& getSprite()
	{
		return shapeShipSprite;
	}

protected:
	sf::Sprite shapeShipSprite;
	sf::Texture textureShapeShip;
};

#endif 
