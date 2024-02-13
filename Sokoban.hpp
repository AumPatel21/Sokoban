// Copyright [2023] Aum Patel
#ifndef AUMPATEL_PS2B_SOKOBAN_HPP_
#define AUMPATEL_PS2B_SOKOBAN_HPP_

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

enum KEYBOARD {
    UP, LEFT, DOWN, RIGHT
};

class Sokoban : public sf::Drawable {
 public:
    Sokoban();
    Sokoban(const Sokoban &game);
    int getWidth() const;           // returns the width of the map
    int getHeight() const;          // returns the height of the map
    int getPlayerLocation() const;  // returns the location of the player

    void movePlayer(KEYBOARD direction, sf::RenderWindow &window);   // moves the player
    void moveUp(int playerLocation);       // moves the player up
    void moveLeft(int playerLocation);     // moves the player left
    void moveDown(int playerLocation);     // moves the player down
    void moveRight(int playerLocation);    // moves the player right
    const bool isWon(sf::RenderWindow &window);    // checks if the game is won
    void reset(Sokoban& oldData);    // resets the game

    // Sokoban& operator= (const Sokoban &game);
    friend std::istream &operator>>(std::istream &CIN, Sokoban &game);
    friend std::ostream &operator<<(std::ostream &COUT, const Sokoban &game);

 private:
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
    sf::Texture textureWall;        // wall texture
    sf::Texture textureBox;         // box texture
    sf::Texture textureGoal;        // storage location texture
    sf::Texture textureGround;      // ground texture
    sf::Texture textureBoxOnGoal;   // box already on storege location
    sf::Texture texturePlayer;      // player texture
    // std::vector<sf::Texture> playerTextures;
    // sf::Sprite player;
    int width;                      // width of the map
    int height;                     // height of the map
    char *lvl;                      // map of the game
};

#endif  // AUMPATEL_PS2B_SOKOBAN_HPP_
