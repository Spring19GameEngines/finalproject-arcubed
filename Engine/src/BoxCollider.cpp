#include "BoxCollider.h"

BoxCollider::BoxCollider(float x, float y, float width, float height): x(x), y(y), width(width), height(height) {};

/**
 * Collision function. Currently assumes that x and y are at the top left of the sprite
 *
 * @param x2
 * @param y2
 * @param width2
 * @param height2
 * @return
 */
BoxCollider::checkCollision(float x2, float y2, float width2, float height2) {
    return x < x2 + width2 && x + width > x2 && y < y2 + height2 && y + height > y2;
}