#ifndef RAYTRACING_HITTABLE_H
#define RAYTRACING_HITTABLE_H

#include "ray.h"

struct hit_record {
    point3 p;
    vec3 normal;
    float t;
};

struct hittable {
    virtual ~hittable() = default;
    virtual bool hit(const ray &ray,
                    float ray_tmin,
                    float ray_tmax,
                    hit_record &rec) const = 0;
};

#endif //RAYTRACING_HITTABLE_H