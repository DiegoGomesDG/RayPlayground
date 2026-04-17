#ifndef RAYTRACINGPROJECT_APPLAYER_H
#define RAYTRACINGPROJECT_APPLAYER_H

#include "Layer.h"
#include "InputEvents.h"
#include "WindowEvents.h"

#include <glm/glm.hpp>

class AppLayer : public Core::Layer{
public:
    AppLayer();
    virtual ~AppLayer() override;

    void on_event(Core::Event &event) override;

    void on_update(float timestamp) override;
    void on_render() override;

private:
    bool on_mouse_button_pressed(Core::MouseButtonPressedEvent &event);
    bool on_mouse_moved(Core::MouseMovedEvent &event);
    bool on_key_pressed(Core::KeyPressedEvent &event);

private:
    uint32_t m_shader           = 0;
    uint32_t m_vertex_array     = 0;
    uint32_t m_vertex_buffer    = 0;

    float m_time = 0.0f;

    glm::vec2 m_pouse_position { 0.0f };

};

#endif //RAYTRACINGPROJECT_APPLAYER_H
