#pragma once 

#include "balls.h"
#include <vector>
#include <memory> 
#include "Game.h"


class CollisionNode {
public:
    std::vector<Ball> balls;
    std::unique_ptr<CollisionNode> Left;
    std::unique_ptr<CollisionNode> Right;
    float x, y, radius;

    CollisionNode(std::vector<Ball>& balls, Game& game);

    
};

class CollisionCheck {
public:
    std::unique_ptr<CollisionNode> root;

    CollisionCheck(std::vector<Ball>& balls , Game& game , bool& b);
    ~CollisionCheck() = default;

    void checkCollisions(const CollisionNode* n1, const CollisionNode* n2);
};