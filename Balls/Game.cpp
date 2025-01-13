#include "Game.h"
#include "Boundries.h"
#include "balls.h"
#include "collision.h"
#include <iostream>
#include <random>
#include<algorithm>

//IMPORTANT
constexpr auto WindowH = 600;
constexpr auto WindowW = 800;
const float fps_limit = 60;
bool isCollisionAllowed = true;
bool showGrid = true;
const float cor = 1;
bool showStats = false; // S for showing the stats .

//Controls 
/*
	-R restart - Yet to implement
	-S stats toogle  - Done
	-D Collision toogle - Done
	-G Show Grid - Done 
	-F Change the Balls Number 
	-C Change the ball Radius 
	-Esc Exit - Done
	-X Gravity 
	-V start Velocity 
	-N Combine the ball of same colour 
	-M change Mass
	-B Change the balls color as per the velocity changes 
*/ 



// Balls
const int numberOfBalls = 4;
const float radius = 30;
const sf::Vector2f startPos = { 300, 300 };
const sf::Vector2f startVel = { 100, 100 };
const int velRandomFactor = 169; 
const int posRandomFactor = 169; 
std::vector<sf::Color> colours = {
	sf::Color(58, 255, 122),  // Neon Green
	sf::Color(70, 130, 255), // Electric Blue
	sf::Color(255, 66, 165), // Hot Pink
	sf::Color(0, 212, 255),  // Bright Cyan
	sf::Color(230, 255, 80), // Lime Yellow
	sf::Color(191, 64, 255), // Violet Purple
	sf::Color(255, 203, 165) // Soft Peach
};

// Random number generator
std::random_device rd;
std::mt19937 gen(rd());
std::uniform_real_distribution<float> velDist(-velRandomFactor, velRandomFactor);
std::uniform_real_distribution<float> posDist(-posRandomFactor, posRandomFactor);

std::vector<Ball> balls;

sf::Color bg_colour(35, 37, 43);

void Game::InitWindow()
{
	this->settings.antialiasingLevel = 4;
	this->window = new sf::RenderWindow(sf::VideoMode(WindowW, WindowH), "TheGame", sf::Style::Close, settings);
	this->window->setVerticalSyncEnabled(this->Vsync);
	this->window->setFramerateLimit(fps_limit);

	if (!this->font.loadFromFile("assets/myfont.ttf")) {
		std::cerr << " ERROR : NO FONT LOADED !!";
		this->window->close();
	}


	GameInit();
}

Game::Game()
{
	this->window = nullptr;
	this->InitWindow();
}

Game::~Game()
{
	delete this->window;
}

void Game::CheckWindowPoll()
{
	while (this->window->pollEvent(this->event))
	{
		switch (this->event.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;

		case sf::Event::KeyPressed:
			if (this->event.key.code == sf::Keyboard::Escape)
				this->window->close();
			if (this->event.key.code == sf::Keyboard::S) {
				showStats = !showStats;
			}if (this->event.key.code == sf::Keyboard::G) {
				showGrid = !showGrid;
			}if (this->event.key.code == sf::Keyboard::D) {
				isCollisionAllowed = !isCollisionAllowed;
			}

			break;
		}
	}
}

bool Game::isWindowOpen()
{
	return this->window->isOpen();
}

static void GameInit()
{
	const int t = colours.size();
	for (int i = 0; i < numberOfBalls; i++) {

		int colorIndex = rand() % t;
		sf::Vector2f randomVel = { startVel.x + velDist(gen), startVel.y + velDist(gen) };
		sf::Vector2f randomPos = {
			startPos.x + posDist(gen),
			startPos.y + posDist(gen)
		};
		if (randomPos.x < radius) randomPos.x = radius;
		if (randomPos.x > WindowW - radius) randomPos.x = WindowW - radius;
		if (randomPos.y < radius) randomPos.y = radius;
		if (randomPos.y > WindowH - radius) randomPos.y = WindowH - radius;

		balls.emplace_back(radius, randomPos, randomVel, colours[colorIndex]);
	}
	std::cout << balls.size() << " Balls initiated !!" << std::endl;

}

void Game::Update()
{
	// Window check and update
	this->CheckWindowPoll();
	this->window->clear(bg_colour);

	if (isCollisionAllowed) {
		//Check for collision 
		
		CollisionCheck collision(balls , *this ,showGrid);
	}

	float deltaTime = this->clock.restart().asSeconds();
	for (auto& ball : balls) {
		ball.move({ 0 , WindowW },
			{ 0,WindowH}, deltaTime);

	}
	for (auto& ball : balls) {
		this->window->draw(ball.draw());
	}

	//print stats
	//TODO : add the feature to see the current stats  !! i.e. FPS and load REALTIME STATS
	if (showStats)
	{
		sf::Text windowDimText, fpsText, nOfBalls, collisionText, showGrid_, corText, statsToggleText;

		// Initialize stats texts in GameInit() or InitWindow()

		windowDimText.setCharacterSize(12);
		fpsText.setCharacterSize(12);
		collisionText.setCharacterSize(12);
		corText.setCharacterSize(12);
		statsToggleText.setCharacterSize(12);
		nOfBalls.setCharacterSize(12);
		showGrid_.setCharacterSize(12);


		windowDimText.setFont(font);
		fpsText.setFont(font);
		collisionText.setFont(font);
		corText.setFont(font);
		statsToggleText.setFont(font);
		showGrid_.setFont(font);
		nOfBalls.setFont(font);

		windowDimText.setFillColor(sf::Color::White);
		fpsText.setFillColor(sf::Color::White);
		collisionText.setFillColor(sf::Color::White);
		corText.setFillColor(sf::Color::White);
		statsToggleText.setFillColor(sf::Color::White);
		nOfBalls.setFillColor(sf::Color::White);
		showGrid_.setFillColor(sf::Color::White);

		// Set positions
		windowDimText.setPosition(10, 10);
		fpsText.setPosition(10, 30);
		collisionText.setPosition(10, 50);
		corText.setPosition(10, 70);
		statsToggleText.setPosition(10, 90);
		nOfBalls.setPosition(10, 90);
		showGrid_.setPosition(10, 110);


		// Update strings based on values
		std::string windowDimensions = "( use S to toogle the stats ) || Window: " + std::to_string(WindowW) + " x " + std::to_string(WindowH);
		std::string fpsStr = "FPS Limit: " + std::to_string(fps_limit);
		std::string collisionStr = "Collision ( use D to toogle ) : " + std::string(isCollisionAllowed ? "ON" : "OFF");
		std::string grid = "Show Grid ( use G to toogle ) : " + std::string(showGrid ? "ON" : "OFF");
		std::string corStr = "Coff of restitution : " + std::to_string(cor);
		std::string ballstr = "Number of balls : " + std::to_string(numberOfBalls);

		// Set strings to text objects
		windowDimText.setString(windowDimensions);
		fpsText.setString(fpsStr);
		collisionText.setString(collisionStr);
		corText.setString(corStr);
		nOfBalls.setString(ballstr);
		showGrid_.setString(grid);


		// In the Update method, draw the stats if showStats is true

		this->window->draw(windowDimText);
		this->window->draw(fpsText);
		this->window->draw(collisionText);
		this->window->draw(corText);
		this->window->draw(nOfBalls);
		this->window->draw(showGrid_);

	}

}

void Game::Render()
{
	this->window->display();
}

void Game::Draw( sf::RectangleShape& rect)
{
	this->window->draw(rect);
}
