#ifndef RAYTRACINGPROJECT_APPLAYER_H
#define RAYTRACINGPROJECT_APPLAYER_H

#include "Layer.h"
#include "InputEvents.h"
#include "WindowEvents.h"

#include <glm/glm.hpp>

#include "Camera.h"
#include "hittable_list.h"
#include "glad/glad.h"

class AppLayer : public Core::Layer{
public:
    AppLayer();
    virtual ~AppLayer() override = default;

    void on_event(Core::Event &event) override;
    void on_update(float timestamp) override;
    void on_render() override;

private:
    void init_scene();

private:
    hittable_list m_world;
    Camera m_camera;

    std::vector<uint32_t> m_framebuffer;

    GLuint m_texture = 0;
    bool m_rendered = false;
};

#endif //RAYTRACINGPROJECT_APPLAYER_H
