#include "logic.hpp"
#include <math.h>
#include <cmath>
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

vec2 HitBox::rot(float x, float y){
    vec2 vec_result= {};
    vec_result.x = x * cos(this->angle) - y * sin(this->angle);
    vec_result.y = x * sin(this->angle) + y * cos(this->angle);
    return vec_result;
}

bool HitBox::checkWithin(float x_given, float y_given, float rad) {
    vec2 x_basis = rot(1, 0);
    vec2 y_basis = rot(0, 1);
    vec2 missile = {x_given-this->x, y_given - this->y};
    vec2 proj_x = (x_basis * missile) * x_basis;
    vec2 proj_y = (y_basis * missile) * y_basis;
    vec2 xdim = (this->width / 2) * x_basis;
    vec2 ydim = (this->height / 2) * y_basis;
    bool result = (abs(proj_x.x) <= abs(xdim.x)) && (abs(proj_x.y) <= abs(xdim.y)) && (abs(proj_y.x) <= abs(ydim.x)) && (abs(proj_y.y) <= abs(ydim.y));
    return result;
}

Ship::Ship (int type, float x_pos, float y_pos) {
    hitboxes.push_back(HitBox());
    for (int i=0;i<hitboxes.size();i++) {
        hitboxes[i].setFields(x_pos,y_pos,30,15);
    }
    speed = 5;
    damage = 0;
}

void Ship::updateHitboxes(float x_pos, float y_pos, float angle) {
    for (int i=0;i<hitboxes.size();i++) {
        hitboxes[i].updatePos(x_pos, y_pos);
        hitboxes[i].angle = angle;
    }
}

int Ship::checkHit (float hit_x, float hit_y, float rad) {
    for (int i=0;i<hitboxes.size();i++) {
        if (hitboxes[i].alive && hitboxes[i].checkWithin(hit_x, hit_y, rad)) {
            hitboxes[i].alive = false;
            return i;
        }
    }
    return -1;
}

int Ship::checkMissile(float hit_x, float hit_y, float rad) {
    for (int i=0;i<hitboxes.size();i++) {
        if(hitboxes[i].checkWithin(hit_x, hit_y, rad)!=-1) {
            return i;
        }
    }
    return -1;
}

void Sea::update() {

}

Sea::Sea(int x, int y) {
    height = y;
    width = x;
}
