#ifndef RAYTRACING_SPHERE_H
#define RAYTRACING_SPHERE_H

#include "hittable.h"

class Sphere : public hittable {
public:
    Sphere(const point3 &center, float radius);
    bool hit(const ray &ray, interval ray_t, hit_record &rec) const override;

private:
    point3  center;
    float   radius;
};

#endif //RAYTRACING_SPHERE_H