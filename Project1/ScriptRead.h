#ifndef SCRIPTREAD_H
#define SCRIPTREAD_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <fstream>
#include <string>
#include <iostream>


class ScriptReader
{
public:
    ScriptReader(sf::Text& t) : text(t), currentLine(0)
    {
        // Load the script once into memory
        std::ifstream file("D:/A_Project_SFML/Project1/script.txt");
        if (!file)
        {
            std::cerr << "Could not open file\n";
            return;
        }

        std::string line, name;
        while (!file.eof()) 
        {
            std::getline(file, name);
            names.push_back(name);
            std::getline(file, line);
            lines.push_back(line);
        }
    }

    void setText()
    {
       
        if (currentLine < lines.size()) {
            
            text.setString(lines[currentLine]);
            currentLine++;
        }
        else {
            std::cout << "End of script.\n";
        }
    }

    void setName()
    {

        if (currentLine < names.size()) {

            text.setString(names[currentLine]);
            currentLine++;
        }
        else {
            std::cout << "End of script.\n";
        }
    }

    sf::Text getText() const
    {
        return text;
    }

private:
    sf::Text& text;
    std::vector<std::string> lines;
    std::vector<std::string> names;
    size_t currentLine;
};

#endif // SCRIPTREAD_H
