#include "logic.hpp"
using namespace std;

void HitBox::setFields(float x, float y, float width, float height){
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    angle = 0;
}

void HitBox::updatePos(float x, float y) {
    this->x = x;
    this->y = y;
}

Ship::Ship (int type, float x_pos, float y_pos) {
    h.setFields(x_pos,y_pos,30,15);
    speed = 5;
    damage = 0;
}

void Ship::updateHitboxes(float x_pos, float y_pos, float angle) {
    h.updatePos(x_pos, y_pos);
    h.angle = angle;
}

bool Ship::checkHit (float hit_x, float hit_y, float rad) {

}
