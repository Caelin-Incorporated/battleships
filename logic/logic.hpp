#ifndef LOGIC_HPP_
#define LOGIC_HPP_
#include <vector>
#include "vec.hpp"

class HitBox {
    private:
        float height, width;
        vec2 rot(float x, float y);
    public:
		//degrees plz
        float angle;
		float x, y; 
        // Something we could use to detect whether the hitbox is a rectangle or an ellipse?
        int type;
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
        int checkHit(float hit_x, float hit_y, float rad);
    public:
        Ship(int type, float x_pos, float y_pos);
		vec2 getPos();
		float getRot();
        int checkMissile(float x, float y, float rad);
        void updateHitboxes(float x, float y, float angle);
        bool isDead ();
};

// For now, standard Sea is: Sea mainSea(param1,...,paramn)
class Sea {
    private:
        int height, width;
    public:
		std::vector<Ship> ships;
		void init(int width, int height);
        void update();
};

#endif
