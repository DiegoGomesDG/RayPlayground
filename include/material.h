#ifndef RAYTRACING_MATERIAL_H
#define RAYTRACING_MATERIAL_H

#include "hittable.h"

class material {
public:
    virtual ~material() = default;

    virtual bool scatter(
        const ray           &r_in,
        const hit_record    &rec,
        color               &attenuation,
        const ray           &scattered) const {
        return false;
    }
};

#endif //RAYTRACING_MATERIAL_H