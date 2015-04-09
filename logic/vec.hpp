#ifndef VEC_HPP_
#define VEC_HPP_

class vec2 {
    public:
        float x;
        float y;
		vec2();
		vec2(float x, float y);
		static vec2 add(vec2 lhs, vec2 rhs);
		static vec2 sub(vec2 lhs, vec2 rhs);
		static vec2 scalarMult(vec2 vec, float scalar);
		static float dot(vec2 lhs, vec2 rhs);
};

// Overload vec2 operators
vec2 operator+(vec2 lhs, vec2 rhs);
vec2 operator-(vec2 lhs, vec2 rhs);
float operator*(vec2 lhs, vec2 rhs);
vec2 operator*(float scalar, vec2 vec);

#endif
