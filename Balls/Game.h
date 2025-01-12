#pragma once


#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

class Game {

private:
    bool Vsync = true;
    sf::RenderWindow* window;
    sf::Event event;
    sf::ContextSettings settings;
    void InitWindow();
    sf::Font font;
    sf::Clock clock;



public:
    Game();
    virtual ~Game();

    void CheckWindowPoll();
    bool isWindowOpen();

    void Update();
    void Render();
    void Draw(sf::RectangleShape& circle);
};

static void GameInit();
