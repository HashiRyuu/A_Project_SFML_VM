#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>
#include <SFML\Audio.hpp>
#include <SFML\Network.hpp>
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>
#include "control.h"
#include "TextureSprite.h"
#include "ScriptRead.h"
#include "ScriptContainer.h"
#include "Character.h"
#include "TextureSet.h"


class Game
{
public:
	Game() : mWindow(sf::VideoMode({ 800, 600 }), "AYUMI's Date"), mPlayer()
	{

		Displace.setSize(sf::Vector2f(800.f, 150.f));
		Displace.setPosition(sf::Vector2f(0.f, 450.0f));
		Displace.setFillColor(sf::Color(0, 0, 0, 230));
		

		mPlayer.setRadius(10.f);
		mPlayer.setFillColor(sf::Color::Green);
	}

	void run()
	{
		std::vector<std::unique_ptr<textureSprite>> spriteV;

		sf::Texture texture;
		if (!texture.loadFromFile("D:/A_Project_SFML/Project1/image/spaceShip.jpg"))
		{
			std::cout << "error";
		}
		sf::Sprite sprite(texture);
		sprite.setPosition(sf::Vector2f(100.f, 100.f));
		sprite.setScale(sf::Vector2f(0.1f, 0.1f));
		textureSprite ship(texture, sprite);


		sf::Texture texture2;
		if (!texture2.loadFromFile("D:/A_Project_SFML/Project1/image/background.jpg"))
		{
			std::cout << "error";
		}

		sf::Sprite sprite2(texture2);
		// Calculate scaling factors
		float scaleX = static_cast<float>(800) / sprite2.getTexture().getSize().x;
		float scaleY = static_cast<float>(600) / sprite2.getTexture().getSize().y;
		sprite2.setPosition(sf::Vector2f(0.f, 0.f));
		sprite2.setScale(sf::Vector2f(scaleX, scaleY));
		textureSprite background(texture2, sprite2);


		sf::Texture texture3;
		if (!texture3.loadFromFile("D:/A_Project_SFML/Project1/image/akino.png"))
		{
			std::cout << "error";
		}

		sf::Sprite sprite3(texture3);
		sprite3.setPosition(sf::Vector2f(500, 140.f));
		sprite3.setScale(sf::Vector2f(.3f, .3f));

		std::vector<std::string> imageFiles = { "akino.png", "akinoCloseEyes.png" };
		Character character(imageFiles, sprite3);

		spriteV.push_back(std::make_unique<textureSprite>(ship));
		spriteV.push_back(std::make_unique<textureSprite>(background));


		sf::Font font("D:/A_Project_SFML/Project1/font/Raleway-Medium.ttf");
		sf::Text text(font);
		text.setPosition(sf::Vector2f(10.f, 500.f));
		text.setCharacterSize(20);

		sf::Font font2("D:/A_Project_SFML/Project1/font/Raleway-Medium.ttf");
		sf::Text name(font2);
		name.setPosition(sf::Vector2f(10.f, 417.f));
		name.setFillColor(sf::Color::White);
		name.setOutlineColor(sf::Color::Black);
		name.setOutlineThickness(0.5f);
		name.setCharacterSize(30);

		ScriptReader reader(text);
		ScriptReader names(name);

		ScriptContainer containScript;


		containScript.addScript(names);
		containScript.addScript(reader);




		bool collisionX = false;
		bool ispress = false;
		bool fKeyPreviouslyPressed = false;
		while (mWindow.isOpen())
		{
			
			processEvents();
			update(collisionX, ispress, ship, containScript, fKeyPreviouslyPressed, character);
			render(spriteV, containScript, character);
		}
	}
private:

	void processEvents()
	{
		while (const std::optional event = mWindow.pollEvent())
		{
			if (event->is<sf::Event::Closed>())
				mWindow.close();
			if (event->is<sf::Event::KeyPressed>() && event->getIf<sf::Event::KeyPressed>()->code == sf::Keyboard::Key::Escape)
				mWindow.close();
		}
	}

	sf::CircleShape& player()
	{
		return mPlayer;
	}

	void update(bool& collisionX, bool& ispress, textureSprite& ship, ScriptContainer& containScript, bool& fKeyPreviouslyPressed, Character& character)
	{

		bool fKeyNow = sf::Mouse::isButtonPressed(sf::Mouse::Button::Left);

		if (fKeyNow && !fKeyPreviouslyPressed) 
		{
			containScript.getScripts()[0].setName();
			containScript.getScripts()[1].setText();
		}

		fKeyPreviouslyPressed = fKeyNow;

		character.updateBlinking();
	}

	void render(const std::vector<std::unique_ptr<textureSprite>>& sprite, ScriptContainer& script, Character& character)
	{

		mWindow.clear();

		mWindow.draw(sprite[1]->getSprite());

		mWindow.draw(character.getSprite());

		mWindow.draw(Displace);
		for (auto sct : script.getScripts())
		{
			mWindow.draw(sct.getText());
		}
	
		mWindow.display();
	}

private:

	sf::RenderWindow mWindow;
	sf::CircleShape mPlayer;
	sf::RectangleShape Displace;
	float x = 0.2f, y = 0.2f, vy = 0.05f, vx = 0.05f;
	
};

#endif // !GAME_H