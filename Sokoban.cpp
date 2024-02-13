// Copyright [2023] Aum Patel
#include "Sokoban.hpp"

// default constructor
Sokoban::Sokoban() : width(0), height(0), lvl(nullptr)
{
    textureWall.loadFromFile("assets/images/block_06.png");
    textureBox.loadFromFile("assets/images/crate_03.png");
    textureGoal.loadFromFile("assets/images/ground_04.png");
    textureGround.loadFromFile("assets/images/ground_01.png");
    texturePlayer.loadFromFile("assets/images/player_05.png");
}

Sokoban::Sokoban(const Sokoban &game)
{
    width = game.width;
    height = game.height;
    lvl = new char[width * height];
    for (int i = 0; i < width * height; i++)
    {
        lvl[i] = game.lvl[i];
    }
}

int Sokoban::getHeight() const { return height; }

int Sokoban::getWidth() const { return width; }

int Sokoban::getPlayerLocation() const
{
    for (int row = 0; row < width; row++)
    {
        for (int col = 0; col < height; col++)
        {
            if (lvl[col + row * height] == '@')
            {
                return col + row * height;
            }
        }
    }
    return -1;
}

void Sokoban::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    sf::Sprite sprite;
    for (int row = 0; row < width; row++)
    {
        for (int col = 0; col < height; col++)
        {
            int location = col + row * height;
            switch (lvl[location])
            {
            case '#':
                sprite.setTexture(textureWall);
                sprite.setPosition(col * 64, row * 64);
                target.draw(sprite);
                break;
            case 'a':
                sprite.setTexture(textureGoal);
                sprite.setPosition(col * 64, row * 64);
                target.draw(sprite);
                break;
            case 'A':
                sprite.setTexture(textureGround);
                sprite.setPosition(col * 64, row * 64);
                target.draw(sprite);
                sprite.setTexture(textureBox);
                sprite.setPosition(col * 64, row * 64);
                target.draw(sprite);
                break;
            case '@':
                sprite.setTexture(textureGround);
                sprite.setPosition(col * 64, row * 64);
                target.draw(sprite);
                sprite.setTexture(texturePlayer);
                sprite.setPosition(col * 64, row * 64);
                target.draw(sprite);
                break;
            default:
                if ((lvl[location] != 'a'))
                {
                    sprite.setTexture(textureGround);
                    sprite.setPosition(col * 64, row * 64);
                    target.draw(sprite);
                    break;
                }
            }
        }
    }
}

void Sokoban::movePlayer(KEYBOARD direction, sf::RenderWindow &window)
{
    int playerLocation = getPlayerLocation();
    switch (direction)
    {
    case UP:
        moveUp(playerLocation);
        break;
    case LEFT:
        moveLeft(playerLocation);
        break;
    case DOWN:
        moveDown(playerLocation);
        break;
    case RIGHT:
        moveRight(playerLocation);
        break;
    default:
        break;
    }
}

void Sokoban::moveUp(int playerLocation)
{
    if (lvl[playerLocation - height] == '.')
    {
        lvl[playerLocation - height] = '@';
        lvl[playerLocation] = '.';
    }
    else if (lvl[playerLocation - height] == 'A')
    {
        if (lvl[playerLocation - 2 * height] == '.')
        {
            lvl[playerLocation - 2 * height] = 'A';
            lvl[playerLocation - height] = '@';
            lvl[playerLocation] = '.';
        }
        else if (lvl[playerLocation - 2 * height] == 'a')
        {
            lvl[playerLocation - 2 * height] = 'A';
            lvl[playerLocation - height] = '@';
            lvl[playerLocation] = '.';
        }
    }
    else if (lvl[playerLocation - height] == 'a')
    {
        lvl[playerLocation - height] = '@';
        lvl[playerLocation] = '.';
    }
}

void Sokoban::moveLeft(int playerLocation)
{
    if (lvl[playerLocation - 1] == '.')
    {
        lvl[playerLocation - 1] = '@';
        lvl[playerLocation] = '.';
    }
    else if (lvl[playerLocation - 1] == 'A')
    {
        if (lvl[playerLocation - 2] == '.')
        {
            lvl[playerLocation - 2] = 'A';
            lvl[playerLocation - 1] = '@';
            lvl[playerLocation] = '.';
        }
        else if (lvl[playerLocation - 2] == 'a')
        {
            lvl[playerLocation - 2] = 'A';
            lvl[playerLocation - 1] = '@';
            lvl[playerLocation] = '.';
        }
    }
    else if (lvl[playerLocation - 1] == 'a')
    {
        lvl[playerLocation - 1] = '@';
        lvl[playerLocation] = '.';
    }
}

void Sokoban::moveDown(int playerLocation)
{
    if (lvl[playerLocation + height] == '.')
    {
        lvl[playerLocation + height] = '@';
        lvl[playerLocation] = '.';
    }
    else if (lvl[playerLocation + height] == 'A')
    {
        if (lvl[playerLocation + 2 * height] == '.')
        {
            lvl[playerLocation + 2 * height] = 'A';
            lvl[playerLocation + height] = '@';
            lvl[playerLocation] = '.';
        }
        else if (lvl[playerLocation + 2 * height] == 'a')
        {
            lvl[playerLocation + 2 * height] = 'A';
            lvl[playerLocation + height] = '@';
            lvl[playerLocation] = '.';
        }
    }
    else if (lvl[playerLocation + height] == 'a')
    {
        lvl[playerLocation + height] = '@';
        lvl[playerLocation] = '.';
    }
    else if (lvl[playerLocation - height] == 'a')
    {
        lvl[playerLocation - height] = 'a';
        lvl[playerLocation] = '.';
    }
}

void Sokoban::moveRight(int playerLocation)
{
    if (lvl[playerLocation + 1] == '.')
    {
        lvl[playerLocation + 1] = '@';
        lvl[playerLocation] = '.';
    }
    else if (lvl[playerLocation + 1] == 'A')
    {
        if (lvl[playerLocation + 2] == '.')
        {
            lvl[playerLocation + 2] = 'A';
            lvl[playerLocation + 1] = '@';
            lvl[playerLocation] = '.';
        }
        else if (lvl[playerLocation + 2] == 'a')
        {
            lvl[playerLocation + 2] = 'A';
            lvl[playerLocation + 1] = '@';
            lvl[playerLocation] = '.';
        }
    }
    else if (lvl[playerLocation + 1] == 'a')
    {
        lvl[playerLocation + 1] = '@';
        lvl[playerLocation] = '.';
    }
}

const bool Sokoban::isWon(sf::RenderWindow &window)
{
    int numGoals = std::count_if(lvl, lvl + width * height, [](char c)
                                 { return c == 'a'; });
    int boxesOnGoalsCount = 0;
    bool check = false;

    auto boxesOnGoals = [&](char c)
    {
        if (c == 'A' || c == 'a')
        {
            // if any of the elements in the range contain 'A' and 'a' increment the count
            if (std::any_of(lvl, lvl + width * height, [](char c)
                            { return c == 'A' && c == 'a'; }))
            {
                boxesOnGoalsCount++;
            }
        }
    };
    // use the above lambda expression to count the number of boxes on goals
    std::for_each(lvl, lvl + width * height, boxesOnGoals);
    check = (boxesOnGoalsCount == numGoals) ? true : false;
    // if check is true, display the win message on the screen
    if (check)
    {
        sf::Vector2u windowSize = window.getSize();
        sf::Font font;
        if (!font.loadFromFile("assets/arial.ttf"))
        {
            std::cerr << "Error loading font" << std::endl;
            exit(1);
        }
        sf::Text text("You Win!", font, 50);
        text.setFillColor(sf::Color::White);
        text.setPosition((windowSize.x / 2) - 100, (windowSize.y / 2) - 50);
        window.draw(text);
        window.display();
    }
    return check;
}

void Sokoban::reset(Sokoban &oldData)
{
    width = oldData.width;
    height = oldData.height;
    lvl = new char[width * height];
    for (int i = 0; i < width * height; i++)
    {
        lvl[i] = oldData.lvl[i];
    }
}

std::istream &operator>>(std::istream &CIN, Sokoban &game)
{
    if (game.lvl != nullptr)
    {
        delete[] game.lvl;
    }
    CIN >> game.width >> game.height;
    game.lvl = new char[game.width * game.height];
    for (int row = 0; row < game.width; row++)
    {
        for (int col = 0; col < game.height; col++)
        {
            CIN >> game.lvl[col + row * game.height];
        }
    }
    return CIN;
}

std::ostream &operator<<(std::ostream &COUT, const Sokoban &game)
{
    COUT << game.width << " " << game.height << std::endl;
    for (int row = 0; row < game.width; row++)
    {
        for (int col = 0; col < game.height; col++)
        {
            COUT << game.lvl[col + row * game.height];
        }
        COUT << std::endl;
    }
    return COUT;
}
