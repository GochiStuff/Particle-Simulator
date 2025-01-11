#pragma once

#include <SFML/Graphics.hpp>

class Game {

private:
    bool Vsync = true;
    sf::RenderWindow* window;
    sf::Event event;
    sf::ContextSettings settings;
    void InitWindow();



public:
    Game();
    virtual ~Game();

    void CheckWindowPoll();
    bool isWindowOpen();

    void Update();
    void Render();
};

static void GameInit();
