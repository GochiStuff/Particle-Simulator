#pragma once 

#include <vector>
#include <memory>
#include <iostream>
#include <algorithm>
#include <cmath>
#include "game.h"
#include "balls.h"

class CollisionNode {
public:

    float x, y; 
    float width, height; 

    std::vector<Ball> balls;
    std::unique_ptr<CollisionNode> Left;
    std::unique_ptr<CollisionNode> Right;

    CollisionNode(std::vector<Ball>& balls, Game& game, int depth = 0, int maxDepth = 10);
};

class CollisionCheck {
public:
    explicit CollisionCheck(std::vector<Ball>& balls, Game& game, bool& isGrid);
    void checkCollisions(const CollisionNode* n1, const CollisionNode* n2);

private:
    std::unique_ptr<CollisionNode> root;
};