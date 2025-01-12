#pragma once
#include "balls.h"


class CollsionCheck
{
private:
	float x, y;
	float radius;
	sf::CircleShape circle;

public:
	CollsionCheck(std::vector<Ball>& balls);
	~CollsionCheck();

};

