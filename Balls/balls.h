#pragma once

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics.hpp>

class Ball
{

private:

	sf::CircleShape circle;
	sf::Vector2f velocity;
	
public:
	Ball(float radius, sf::Vector2f startPosition, sf::Vector2f startVelocity, sf::Color color);
	~Ball();

	void move(sf::Vector2f boundX, sf::Vector2f boundY, float deltaTime);
	sf::CircleShape draw();
	sf::Vector2f getPosition() const;
	float getRadius() const;
		
	 sf::Vector2f getVelocity() const;
	 void setVelocity(const sf::Vector2f& vel);

};
