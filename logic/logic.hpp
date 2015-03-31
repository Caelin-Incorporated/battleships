#ifndef LOGIC_HPP_
#define LOGIC_HPP_
#include <vector>
#include "vec.hpp"


class HitBox {
    private:
        float height, width, x, y;
        vec2 rot(float x, float y);
    public:
            //radians pls
        float angle;
        bool alive;
        void setFields(float x, float y, float height, float width);
        void updatePos(float x, float y);
        bool checkWithin(float x_given, float y_given, float rad);
};

class Ship {
    private:
        float speed, damage;
        std::vector<HitBox> hitboxes;
        // checkHit returns the index of whichever hitbox was hit, or -1 if none were.
        int checkHit (float hit_x, float hit_y, float rad);
    public:
        Ship (int type, float x_pos, float y_pos);
        int checkMissile(float x, float y, float rad);
        void updateHitboxes(float x, float y, float angle);
        bool isDead ();
        ~Ship ();
};


// For now, standard Sea is: Sea mainSea(param1,...,paramn)
class Sea {
    private:
    public:
        int height, width;
        std::vector<Ship> ships;
        Sea (int x, int y);
        void update();
};

#endif
