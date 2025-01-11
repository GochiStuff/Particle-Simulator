#include "Boundries.h"

BoundaryRectangle::BoundaryRectangle(sf::Vector2f size, int boundaryWidth, sf::Color boundaryColor, sf::Vector2f windowSize)
{
	this->rectangle.setSize(size);
	this->rectangle.setFillColor(sf::Color::Transparent);
	this->rectangle.setOutlineThickness(boundaryWidth);
	this->rectangle.setOutlineColor(boundaryColor);

	// Center the rectangle in the window
	this->rectangle.setOrigin(size.x / 2, size.y / 2);
	this->rectangle.setPosition(windowSize.x / 2, windowSize.y / 2);
}

sf::RectangleShape BoundaryRectangle::DrawTheBoundaries() const
{
	return this->rectangle;
}
