#ifndef RAYTRACINGPROJECT_APPLAYER_H
#define RAYTRACINGPROJECT_APPLAYER_H

#include "Layer.h"
#include "InputEvents.h"
#include "WindowEvents.h"
#include "GLImage.h"

#include "Camera.h"
#include "hittable_list.h"


class AppLayer : public Core::Layer{
public:
    AppLayer();
    virtual ~AppLayer() override = default;

    void on_event(Core::Event &event) override;
    void on_update(float timestamp) override;
    void on_render() override;

private:
    void init_scene();
    void init_texture(int width, int height);
    void upload_texture();

private:
    hittable_list m_world;
    Camera m_camera;

    std::shared_ptr<Core::GLImage> m_image;
    std::vector<uint32_t> m_framebuffer;

    bool m_rendered = false;
};

#endif //RAYTRACINGPROJECT_APPLAYER_H
