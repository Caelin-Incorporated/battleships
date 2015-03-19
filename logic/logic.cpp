#include "logic.hpp"
using namespace std;

void HitBox::setFields(float x, float y, float width, float height){
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    angle = 0;
    alive = true;
}

void HitBox::updatePos(float x, float y) {
    this->x = x;
    this->y = y;
}

2vector HitBox::rot(float x, float y){
    //Does some shit.
}

bool HitBox::checkWithin(float x_given, float y_given, rad) {
    2vector x_basis = rot(1, 0);
    2vector y_basis = rot(1, 0);

    // find (x_given, y_given) in terms of {x_basis, y_basis} and then
    //
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

void Ship::checkHit (float hit_x, float hit_y, float rad) {
    for (int i=0;i<hitboxes.size();i++) {
        if (hitboxes[i].alive && hitboxes[i].checkWithin(hit_x, hit_y, rad)) {
            hitboxes[i].alive = false;
            return i;
        }
    }
    return -1;
}

void Ship::checkMissile(float hit_x, float hit_y, float rad) {
    for (int i=0;i<hitboxes.size();i++) {
        hitboxes[i].checkHit(hit_x, hit_y, rad);
    }
}

void Sea::update() {

}

Sea::Sea(int x, int y) {
    height = y;
    width = x;
}
