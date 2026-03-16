#ifndef RAYTRACING_RAY_H
#define RAYTRACING_RAY_H

#include "vec3.h"

class ray {
public:
    ray() {}
    ray (const point3 &origin, const vec3 &direction) : origin(origin), direction(direction) {}

    const point3 &origin() const { return this->origin; }
    const vec3 &direction() const { return this->direction; }

    point3 at(float t) const {
        return origin + t * direction;
    }

private:
    point3 origin;
    vec3 direction;
};

#endif //RAYTRACING_RAY_H