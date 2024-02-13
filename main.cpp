// Copyright [2023] Aum Patel
#include <fstream>
#include "Sokoban.hpp"

int main(int argc, char *argv[])
{
    // check if the user has entered the correct number of arguments
    if (argc != 2)
    {
        std::cout << "Error! not enough arguments" << std::endl;
        exit(1);
    }

    std::ifstream getLevel = std::ifstream(argv[1]);
    if (getLevel.is_open())
    {
        Sokoban sokoban;
        getLevel >> sokoban;

        // std::cout << sokoban;
        Sokoban tempSokoban(sokoban);
        // std::string level = "Sokoban " + argv[1];
        sf::RenderWindow window(sf::VideoMode(sokoban.getHeight() * 64,
                                              sokoban.getWidth() * 64),
                                "Sokoban");
        while (window.isOpen())
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if ((event.type == sf::Event::Closed) ||
                    (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)))
                {
                    window.close();
                }
                if (event.type == sf::Event::KeyPressed)
                {
                    if (event.key.code == sf::Keyboard::W ||
                        event.key.code == sf::Keyboard::Up)
                    {
                        sokoban.movePlayer(UP, window);
                    }
                    else if (event.key.code == sf::Keyboard::A ||
                             event.key.code == sf::Keyboard::Left)
                    {
                        sokoban.movePlayer(LEFT, window);
                    }
                    else if (event.key.code == sf::Keyboard::S ||
                             event.key.code == sf::Keyboard::Down)
                    {
                        sokoban.movePlayer(DOWN, window);
                    }
                    else if (event.key.code == sf::Keyboard::D ||
                             event.key.code == sf::Keyboard::Right)
                    {
                        sokoban.movePlayer(RIGHT, window);
                    }
                    else if (event.key.code == sf::Keyboard::R)
                    {
                        sokoban.reset(tempSokoban);
                    }
                }
                window.clear();
                window.draw(sokoban);
                window.display();
                sokoban.isWon(window);
            }
        }
    }
    else
    {
        std::cout << "Error: Failed to open the file" << std::endl;
        exit(1);
    }
    return 0;
}
