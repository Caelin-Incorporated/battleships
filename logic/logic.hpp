#include <vector>

class HitBox {
    private:
        float height, width, x, y;
    public:
        float angle;
        void setFields(float x, float y, float height, float width);
        void updatePos(float x, float y);
        bool checkWithin(float x_given, float y_given);
};

class Ship {
    private:
        float speed, damage;
        HitBox h;
    public:
        Ship ( int type, float x_pos, float y_pos );
        bool checkHit (float hit_x, float hit_y, float rad);
        void updateHitboxes(float x, float y, float angle);
        bool isDead ();
        ~Ship ();
};


// For now, standard Sea is: Sea mainSea(param1,...,paramn)
class Sea {
    private:
    public:
        std::vector<Ship> ships;

        Sea (int x, int y);
        void update ();
};






