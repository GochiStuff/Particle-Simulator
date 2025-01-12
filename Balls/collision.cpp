#include "collision.h"


// object partision approch 

//Bounding Volume Hierarchy

// trying to use two bounding volume - Box  OR CIRCLE 


//CIRCLE ONE





CollsionCheck::CollsionCheck(std::vector<Ball>& balls)
{
	float radius = balls[0].getRadius();
	float xMin = balls[0].getPosition().x, xMax = balls[0].getPosition().x;
	float yMin = balls[0].getPosition().y, yMax = balls[0].getPosition().y;

	for (const auto& ball : balls) {
		xMin = std::min(xMin, ball.getPosition().x - radius);
		xMax = std::min(xMax, ball.getPosition().x + radius);
		yMin = std::min(yMin, ball.getPosition().y + radius); // The screen is in -ve of y axis , so I think this will be much better 
		yMax = std::min(yMax, ball.getPosition().y - radius);
	}

	this->x = (xMin + xMax) / 2.0f;
	this->y = (yMin + yMax) / 2.0f;
	this->radius = std::max(xMax - x, yMin - y);
}

CollsionCheck::~CollsionCheck()
{

}