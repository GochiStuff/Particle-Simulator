#include "Game.h"
#include "Boundries.h"
#include "balls.h"
#include "collision.h"

constexpr auto WindowH = 600;
constexpr auto WindowW = 800;

std::vector<Ball> balls;

void Game::InitWindow()
{
	this->settings.antialiasingLevel = 4;
	this->window = new sf::RenderWindow(sf::VideoMode(WindowW, WindowH), "TheGame", sf::Style::Close, settings);
	this->window->setVerticalSyncEnabled(this->Vsync);

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
	while (this->window->pollEvent(this->event)) {
		if (this->event.type == sf::Event::Closed) {
			this->window->close();
		}
	}
}

bool Game::isWindowOpen()
{
	return this->window->isOpen();
}

static void GameInit()
{
	// Initialization logic if needed
	balls.emplace_back(20.f, sf::Vector2f(200, 100), sf::Vector2f(200, -300), sf::Color::Red );
	balls.emplace_back(20.f, sf::Vector2f(350, 200), sf::Vector2f(120, 500), sf::Color::Blue);
	balls.emplace_back(20.f, sf::Vector2f(500, 200), sf::Vector2f(400, -320), sf::Color::Yellow);
	balls.emplace_back(20.f, sf::Vector2f(650, 200), sf::Vector2f(320, 250), sf::Color::Green);


}

void Game::Update()
{
	// Window check and update
	this->CheckWindowPoll();
	this->window->clear(sf::Color::White);

	CheckCollisionPP(balls);

	float deltaTime = 1.0f / 60.0f;
	for (auto& ball : balls) {
		ball.move({ 0 , WindowW },
			{ 0,WindowH}, deltaTime);

	}
	for (auto& ball : balls) {
		this->window->draw(ball.draw());
	}

}

void Game::Render()
{
	this->window->display();
}
