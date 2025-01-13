#include "collision.h"

bool isGrid = false;

CollisionCheck::CollisionCheck(std::vector<Ball>& balls, Game& game, bool& b) {
    isGrid = b;
    this->root = std::make_unique<CollisionNode>(balls, game);
    checkCollisions(root.get(), root.get());
}

void CollisionCheck::checkCollisions(const CollisionNode* n1, const CollisionNode* n2) {
    if (!n1 || !n2) return;

    if (n1->balls.size() == 1 && n2->balls.size() == 1 && n1 != n2) {

        //Should be checking using the distance formula of circle but I am using a rectangle . 
        float dx = std::abs(n1->x - n2->x);
        float dy = std::abs(n1->y - n2->y);
        float widthSum = (n1->width + n2->width) / 2;
        float heightSum = (n1->height + n2->height) / 2;

        if (dx < widthSum && dy < heightSum) {
            
            //Collision Actions 
            //std::cout << "Collision Detected!" << std::endl;
            n1->balls[0].
            
        }
        return;
    }

    if (n1->Left) {
        checkCollisions(n1->Left.get(), n2->Left.get());
        checkCollisions(n1->Left.get(), n2->Right.get());
    }
    if (n1->Right) {
        checkCollisions(n1->Right.get(), n2->Left.get());
        checkCollisions(n1->Right.get(), n2->Right.get());
    }
}

CollisionNode::CollisionNode(std::vector<Ball>& balls, Game& game, int depth, int maxDepth) : balls(balls), Left(nullptr), Right(nullptr) {
    if (depth > maxDepth || balls.empty()) {
        this->width = 0;
        this->height = 0;
        this->x = 0;
        this->y = 0;
        return;
    }

    float xMin = balls[0].getPosition().x, xMax = balls[0].getPosition().x;
    float yMin = balls[0].getPosition().y, yMax = balls[0].getPosition().y;

    for (const auto& ball : balls) {
        float ballX = ball.getPosition().x;
        float ballY = ball.getPosition().y;
        xMin = std::min(xMin, ballX - ball.getRadius());
        xMax = std::max(xMax, ballX + ball.getRadius());
        yMin = std::min(yMin, ballY - ball.getRadius());
        yMax = std::max(yMax, ballY + ball.getRadius());
    }


    this->x = (xMin + xMax) / 2.0f;
    this->y = (yMin + yMax) / 2.0f;
    this->width = xMax - xMin;
    this->height = yMax - yMin;

    if (isGrid) {
        sf::RectangleShape rect(sf::Vector2f(this->width, this->height));
        rect.setFillColor(sf::Color::Transparent);
        rect.setOutlineColor(sf::Color::White);
        rect.setOutlineThickness(1);
        rect.setPosition(this->x - this->width / 2, this->y - this->height / 2);
        game.Draw(rect);
    }

    std::sort(balls.begin(), balls.end(), [](const Ball& a, const Ball& b) {
        return a.getPosition().x < b.getPosition().x;
        });

    int medianIndex = balls.size() / 2;
    float medianX = balls[medianIndex].getPosition().x;
    //Problem : this fails for the one ball if there are 3 ball , the collision btw 2 balls will always be rejected . ( not considered ) 
    //This problem do happen rarly as what I have obsereved and I think can be over come if I just both axis for analysis but that is just crap.

    std::vector<Ball> leftBalls, rightBalls;
    for (const auto& ball : balls) {
        if (ball.getPosition().x < medianX) {
            leftBalls.push_back(ball);
        }
        else {
            rightBalls.push_back(ball);
        }
    }

    if (!leftBalls.empty() && leftBalls.size() != balls.size()) {
        this->Left = std::make_unique<CollisionNode>(leftBalls, game, depth + 1, maxDepth);
    }
    if (!rightBalls.empty() && rightBalls.size() != balls.size()) {
        this->Right = std::make_unique<CollisionNode>(rightBalls, game, depth + 1, maxDepth);
    }
}
