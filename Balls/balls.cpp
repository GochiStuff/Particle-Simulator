#include "balls.h"
#include <cstdlib>
#include <iostream>
#include <random>


Ball::Ball(float radius, sf::Vector2f startPosition, sf::Vector2f startVelocity, sf::Color color)
{


	this->circle.setRadius(radius);
	this->circle.setOrigin(radius, radius);
	this->circle.setPosition(startPosition);
	this->circle.setFillColor(color);
    this->velocity = startVelocity;


}

Ball::~Ball()
{

}

void Ball::move(sf::Vector2f boundX, sf::Vector2f boundY, float deltaTime) {
    sf::Vector2f position = this->circle.getPosition();

    position += velocity * deltaTime;

    if (position.y + this->circle.getRadius() >= boundY.y) {
        static const float bounceFactor = -0.99f;
        position.y = boundY.y - this->circle.getRadius();
        velocity.y *= bounceFactor;
    }
    if (position.y - this->circle.getRadius() <= boundY.x) {
        static const float bounceFactor = -0.99f;
        position.y = boundY.x + this->circle.getRadius();
        velocity.y *= bounceFactor;
    }

    if (position.x + this->circle.getRadius() >= boundX.y) {
        static const float bounceFactor = -0.99f;
        position.x = boundX.y - this->circle.getRadius();
        velocity.x *= bounceFactor;
    }
    if (position.x - this->circle.getRadius() <= boundX.x) {
        static const float bounceFactor = -0.99f;
        position.x = boundX.x + this->circle.getRadius();
        velocity.x *= bounceFactor;
    }

    this->circle.setPosition(position);
}

sf::CircleShape Ball::draw()
{
    return this->circle;
}

sf::Vector2f Ball::getPosition() const
{
	return this->circle.getPosition();
}

float Ball::getRadius() const
{
	return this->circle.getRadius();
}

sf::Vector2f Ball::getVelocity() const
{
    return this->velocity;
}

void Ball::setVelocity(const sf::Vector2f& vel)
{
    this->velocity = vel;
}



