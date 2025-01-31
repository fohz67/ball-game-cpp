#include "geometry/Quadtree.hpp"
#include <iostream>

Quadtree::Quadtree(float x, float y, float width, float height, int level, int maxObjects)
    : x(x), y(y), width(width), height(height), level(level), maxObjects(maxObjects), divided(false),
      topLeft(nullptr), topRight(nullptr), bottomLeft(nullptr), bottomRight(nullptr) {}

void Quadtree::insert(Cell* cell) {
    if (!contains(cell)) {
        return;
    }
    if (objects.size() < maxObjects || level >= 5) {
        objects.push_back(cell);
        return;
    }
    if (!divided) {
        subdivide();
    }
    topLeft->insert(cell);
    topRight->insert(cell);
    bottomLeft->insert(cell);
    bottomRight->insert(cell);
}

std::vector<Cell*> Quadtree::retrieve(Cell* cell) {
    std::vector<Cell*> foundObjects;
    if (!contains(cell)) {
        return foundObjects;
    }
    foundObjects.insert(foundObjects.end(), objects.begin(), objects.end());
    if (divided) {
        auto addObjects = [&](Quadtree* qt) {
            std::vector<Cell*> subObjects = qt->retrieve(cell);
            foundObjects.insert(foundObjects.end(), subObjects.begin(), subObjects.end());
        };
        addObjects(topLeft);
        addObjects(topRight);
        addObjects(bottomLeft);
        addObjects(bottomRight);
    }
    return foundObjects;
}

void Quadtree::clear() {
    objects.clear();
    if (divided) {
        topLeft->clear();
        topRight->clear();
        bottomLeft->clear();
        bottomRight->clear();
        delete topLeft;
        delete topRight;
        delete bottomLeft;
        delete bottomRight;
        topLeft = topRight = bottomLeft = bottomRight = nullptr;
        divided = false;
    }
}

void Quadtree::subdivide() {
    float halfW = width / 2;
    float halfH = height / 2;
    topLeft = new Quadtree(x, y, halfW, halfH, level + 1, maxObjects);
    topRight = new Quadtree(x + halfW, y, halfW, halfH, level + 1, maxObjects);
    bottomLeft = new Quadtree(x, y + halfH, halfW, halfH, level + 1, maxObjects);
    bottomRight = new Quadtree(x + halfW, y + halfH, halfW, halfH, level + 1, maxObjects);
    divided = true;
}

bool Quadtree::contains(Cell* cell) {
    float cx = cell->getPosition().x;
    float cy = cell->getPosition().y;
    return cx >= x && cx <= x + width && cy >= y && cy <= y + height;
}
