#include "logic.hpp"
using namespace std;

Ship::Ship ( int type, float x_pos, float y_pos ) {
    height = 30 * type; width = 15;
    x = x_pos; y = y_pos; angle = 90;
    speed = 5; damage = 0;
}


bool Ship::checkHit ( float hit_x, float hit_y, float rad ) {

}
