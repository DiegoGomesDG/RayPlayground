#ifndef RAYTRACINGPROJECT_VOIDLAYER_H
#define RAYTRACINGPROJECT_VOIDLAYER_H

#include "Layer.h"

class VoidLayer : public Core::Layer {
public:
    VoidLayer() {}
    virtual ~VoidLayer() {}

    void on_update(float timestamp) override;
    void on_render() override;
};

#endif //RAYTRACINGPROJECT_VOIDLAYER_H
