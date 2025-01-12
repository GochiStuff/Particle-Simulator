#include "collision.h"
#include <cmath>
#include <iostream>
#include <algorithm> 


bool isGrid = false;

CollisionCheck::CollisionCheck(std::vector<Ball>& balls , Game& game , bool& b) {

    isGrid = b;
    this->root = std::make_unique<CollisionNode>(balls , game);
    checkCollisions(root.get(), root.get()); 
}

void CollisionCheck::checkCollisions(const CollisionNode* n1, const CollisionNode* n2) {
    if (!n1 || !n2) {
        return;
    }

    if (n1->balls.size() == 1 && n2->balls.size() == 1 && n1 != n2) {
        float dx = n1->balls[0].getPosition().x - n2->balls[0].getPosition().x;
        float dy = n1->balls[0].getPosition().y - n2->balls[0].getPosition().y;
        float distance = std::sqrt(dx * dx + dy * dy);
        float collisionDistance = n1->balls[0].getRadius() + n2->balls[0].getRadius();



        if (distance < collisionDistance) {
            //std::cout << "Collision Detected!" << std::endl;
        }
    }
    else {
        checkCollisions(n1->Left.get(), n2->Left.get());
        checkCollisions(n1->Left.get(), n2->Right.get());
        checkCollisions(n1->Right.get(), n2->Left.get());
        checkCollisions(n1->Right.get(), n2->Right.get());
    }
}

CollisionNode::CollisionNode(std::vector<Ball>& balls, Game& game) : balls(balls), Left(nullptr), Right(nullptr) {
    if (balls.empty()) {
        this->radius = 0;
        this->x = 0;
        this->y = 0;
        return;
    }

    float radius = balls[0].getRadius();
    float xMin = balls[0].getPosition().x, xMax = balls[0].getPosition().x;
    float yMin = balls[0].getPosition().y, yMax = balls[0].getPosition().y;

    for (const auto& ball : balls) {
        float ballX = ball.getPosition().x;
        float ballY = ball.getPosition().y;

        xMin = std::min(xMin, ballX - radius);
        xMax = std::max(xMax, ballX + radius);
        yMin = std::min(yMin, ballY - radius);
        yMax = std::max(yMax, ballY + radius);
    }

    this->x = (xMin + xMax) / 2.0f;
    this->y = (yMin + yMax) / 2.0f;
    this->radius = std::max(xMax - x, yMax - y);

    // DRAW THE CIRCLE
    if (isGrid) {
        sf::CircleShape circle;
        circle.setRadius(this->radius);
        circle.setFillColor(sf::Color::Transparent);
        circle.setOutlineColor(sf::Color::White);
        circle.setOutlineThickness(1);
        circle.setPosition(this->x - this->radius, this->y - this->radius);

        game.Draw(circle);
    }

    int n = balls.size();
    if (n > 1) {
        n /= 2;

        std::vector<Ball> leftBalls(balls.begin(), balls.begin() + n);
        std::vector<Ball> rightBalls(balls.begin() + n, balls.end());

        this->Left = std::make_unique<CollisionNode>(leftBalls, game); // Corrected
        this->Right = std::make_unique<CollisionNode>(rightBalls, game); // Corrected
    }
}
