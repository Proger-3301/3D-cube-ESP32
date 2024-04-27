struct vec3 {
    float x, y, z;
};

vec3 add(vec3 a, vec3 b);
vec3 sub(vec3 a, vec3 b);
vec3 mul(vec3 a, float t);
float len(vec3 a);
vec3 rotateXZ(vec3 v, float angle);
vec3 rotateYZ(vec3 v, float angle);