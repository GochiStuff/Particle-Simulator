#pragma once

#include<SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>

class BoundaryRectangle
{
private:
	sf::RectangleShape rectangle;

public:
	BoundaryRectangle(sf::Vector2f size, int boundaryWidth, sf::Color boundaryColor, sf::Vector2f windowSize);

	sf::RectangleShape DrawTheBoundaries() const;
};
