#include <cmath>
#include "vector3.h"

vec3 add(vec3 a, vec3 b){
  return {a.x + b.x, a.y + b.y, a.z + b.z};
}

vec3 sub(vec3 a, vec3 b){
  return {a.x - b.x, a.y - b.y, a.z - b.z};
}

vec3 mul(vec3 a, float t){
  return {a.x * t, a.y * t, a.z * t};
}

float len(vec3 a){
  return sqrt(a.x * a.x + a.y * a.y + a.z * a.z);
}

vec3 rotateXZ(vec3 v, float angle) {
  float cosAngle = cos(angle);
  float sinAngle = sin(angle);

  float newX = v.x * cosAngle - v.z * sinAngle;
  float newZ = v.x * sinAngle + v.z * cosAngle;

  return {newX, v.y, newZ};
}

vec3 rotateYZ(vec3 v, float angle) {
  float cosAngle = cos(angle);
  float sinAngle = sin(angle);

  float newY = v.y * cosAngle - v.z * sinAngle;
  float newZ = v.y * sinAngle + v.z * cosAngle;

  return {v.x, newY, newZ};
}