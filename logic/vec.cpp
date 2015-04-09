#include "vec.hpp"

vec2::vec2(){
	this->x = 0;
	this->y = 0;
}

vec2::vec2(float x, float y){
	this->x = x;
	this->y = y;
}

vec2 vec2::add(vec2 lhs, vec2 rhs){
	vec2 out;
	out.x = lhs.x + rhs.x;
	out.y = lhs.y + rhs.y;
	return out;
}

vec2 vec2::sub(vec2 lhs, vec2 rhs){
	vec2 out;
	out.x = lhs.x - rhs.x;
	out.y = lhs.x - rhs.y;
	return out;
}

vec2 vec2::scalarMult(vec2 vec, float scalar){
	vec2 out;
	out.x = scalar*vec.x;
	out.y = scalar*vec.y;
	return out;
}

float vec2::dot(vec2 lhs, vec2 rhs){
	return lhs.x*rhs.x + lhs.y*rhs.y;
}

vec2 operator+(vec2 lhs, vec2 rhs){
	return vec2::add(lhs, rhs);
}

vec2 operator-(vec2 lhs, vec2 rhs){
	return vec2::sub(lhs, rhs);
}

float operator*(vec2 lhs, vec2 rhs){
	return vec2::dot(lhs, rhs);
}

vec2 operator*(float scalar, vec2 vec){
	return vec2::scalarMult(vec, scalar);
}

