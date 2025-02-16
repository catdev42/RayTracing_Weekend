#ifndef RAY_H
#define RAY_H

#include "vec3.h"

class ray {
  public:
    ray() {}

    ray(const point3& origin, const vec3& direction) : orig(origin), dir(direction) {}

    const point3& origin() const  { return orig; }
    const vec3& direction() const { return dir; }

    point3 at(double t) const {
        return orig + t*dir; 
    }

  private:
    point3 orig;
    vec3 dir;
};

/*
// P(t) = A + tb

P is a #d position alone the line in 3D
A is the ray origin
b is the ray direction
t is a real number (t moves the poing along the ray)
*/

#endif