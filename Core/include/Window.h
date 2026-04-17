#ifndef RAYTRACING_WINDOW_H
#define RAYTRACING_WINDOW_H

#include "Event.h"

#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include <string>
#include <functional>

namespace Core {

    struct WindowSettings {
        std::string title;
        uint32_t width = 1280;
        uint32_t height = 720;
        bool isResizable = true;
        bool VSync = true;

        using EventCallbackFunction = std::function<void(Event&)>;
    };

    class Window {
    public:
        Window(const WindowSettings& settings = WindowSettings());
        ~Window();

        void create();
        void destroy();

        void update();

        glm::vec2 getFramebufferSize() const;
        glm::vec2 getMousePosition() const;

        GLFWwindow* getHandle() const { return m_handle; }
    private:
        WindowSettings m_settings;
        GLFWwindow* m_handle = nullptr;
    };

}



#endif //RAYTRACING_WINDOW_H