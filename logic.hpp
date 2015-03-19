#include <vector>


class Ship {
public:
  Ship ( int type, float x_pos, float y_pos );
  bool checkHit ( float hit_x, float hit_y, float rad );
  bool isDead ();

  ~Ship ();

private:
  float height, width, x, y, angle, speed, damage;
};


class Sea {
public:
  std::vector<Ship*> ships;
  void update ();
};






