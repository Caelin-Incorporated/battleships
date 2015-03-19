#include <vector>


class Ship {
    private:
        float height, width, x, y, angle, speed, damage;

    public:
        Ship ( int type, float x_pos, float y_pos );
        bool checkHit ( float hit_x, float hit_y, float rad );
        bool isDead ();
        ~Ship ();
};

class Sea {
    private:

    public:
        std::vector<Ship*> ships;
        void update ();
};






